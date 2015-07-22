/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 *    (C) COPYRIGHT 2013 ARM Limited
 *        ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

/**
 * Take a live camera feed and apply Canny Edge detection utilizing OpenCL
 * Details: Mali T-628 GPU is split into 2 devices: dev[0] has 4 cores, dev[1] has 2.
 *          Creates 2 Command Queues to use both devices.
 *          Runs 3 kernels sequentially to convert image to grayscale, smooth, and apply edge detection
 *          Loop this process indefinitely until user exits program
 *          
 * Returns: 0, success. -1, failed execution with error details
 */

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/video.hpp"
#include "opencv2/core/ocl.hpp"

#include <CL/cl.h>

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <cstddef>
#include <cmath>
#include <sys/time.h>

using namespace std;
using namespace cv;

//Global variables
const std::string kernel_str[1] = {"kernels/grayscale_kernel.cl"};
const cl_int image_width = 642;
const cl_int image_height = 480;

//Function prototypes
void freeOpenCL(cl_context, cl_program*, cl_kernel*, cl_command_queue*, cl_mem*, const unsigned int, const unsigned int, const unsigned int, const unsigned int);
void eventInfo(cl_event*, const unsigned int);

int main(void)
{
    //OpenCV variables
    Mat frame, gray;
    Mat grayscale(Size(image_width, image_height), CV_8UC1);

    const std::string window_cpu = "Grayscale CPU";
    const std::string window_gpu = "Grayscale GPU";

    //Open the default camera
    VideoCapture cap(0);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, image_width);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, image_height);
    if(!cap.isOpened())
    {
        cout << "Could not open camera!" << endl;
        return -1;
    }
    else
    {
        cout << "Camera started..." << endl;
    }

    //OpenCL variables
    const unsigned int num_programs = 1;
    const unsigned int num_kernels = 1;
    const unsigned int num_queues = 2;
    const unsigned int num_mem_objects = 1;
    const unsigned int num_events = 1;
    const size_t buffer_size = image_width*image_height*sizeof(cl_uchar);
    const size_t global_work_size[2] = {image_width/3, image_height};
    cl_uchar* in_ptr = NULL;
    cl_uchar* out_ptr = NULL;

    cl_uint num_platforms = 1;
    cl_uint num_devices = 2;
    cl_int error;

    cl_context context;
    cl_program program[num_programs];
    cl_kernel kernel[num_kernels];
    cl_command_queue command_queue[num_queues];
    cl_mem mem_objects[num_mem_objects];
    cl_platform_id platforms[num_platforms];
    cl_device_id devices[num_devices];
    cl_event event[num_events];

    //Ensure we have OpenCL
    if(ocl::haveOpenCL())
    {
        cout << "OpenCL supported" << endl;
    }
    else
    {
        cout << "OpenCL not supported" << endl;
        return -1;
    }

    //Query the platforms and devices available to us
    //Find platforms
    clGetPlatformIDs(1, platforms, &num_platforms);

    cout << "=== " << num_platforms << " OpenCL platform(s) found ================" << endl;
    for (uint i = 0; i < num_platforms; i++)
    {
        char buffer[10240];
        cout << "\t-- " << i << " -- " << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_PROFILE, 10240, buffer, NULL);
        cout << "\tPROFILE:    " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_VERSION, 10240, buffer, NULL);
        cout << "\tVERSION:    " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, 10240, buffer, NULL);
        cout << "\tNAME:       " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, 10240, buffer, NULL);
        cout << "\tVENDOR:     " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_EXTENSIONS, 10240, buffer, NULL);
        cout << "\tEXTENSIONS: " << buffer << endl << endl;
    }

    //Find Devices
    clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 2, devices, &num_devices);

    cout << "=== " << num_devices << " OpenCL device(s) found on platform 0: ===" << endl;
    for(uint i = 0; i < num_devices; i++)
    {
        char buffer[10240];
        cl_uint buf_uint;
        cl_ulong buf_ulong;
        cout << "\t-- " << i << " -- " << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_NAME, sizeof(buffer), buffer, NULL);
        cout << "\tDEVICE NAME:         " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR, sizeof(buffer), buffer, NULL);
        cout << "\tDEVICE VENDOR:       " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_VERSION, sizeof(buffer), buffer, NULL);
        cout << "\tDEVICE VERSION:      " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DRIVER_VERSION, sizeof(buffer), buffer, NULL);
        cout << "\tDRIVER VERSION:      " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(buf_uint), &buf_uint, NULL);
        cout << "\tMAX COMPUTE UNITS:   " << buf_uint << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(buf_uint), &buf_uint, NULL);
        cout << "\tMAX CLOCK FREQUENCY: " << buf_uint << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(buf_ulong), &buf_ulong, NULL);
        cout << "\tGLOBAL MEMORY SIZE:  " << buf_ulong << endl << endl;
    }
    cout << "===============================================" << endl << endl;

    //Create a single context to work in
    cl_context_properties context_properties[] = {CL_CONTEXT_PLATFORM, (cl_context_properties)platforms[0]};
    context = clCreateContextFromType(context_properties, CL_DEVICE_TYPE_GPU, NULL, NULL, &error);
    if(error != CL_SUCCESS)
    {
        freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
        cout << "Could not create OpenCL context. Error #: " << error << endl;
        return -1;
    }

    //Create and build the programs to be run
    fstream in(kernel_str[0].c_str());
    string str((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    const char* cstr = str.c_str();

    cout << "Kernel program to load: " << endl;
    const char* char_ptr = cstr;
    while(*char_ptr != NULL)
    {
        if(*char_ptr == '\n')
        {
            cout << endl;
        }
        else
        {
            cout << *char_ptr;
        }
        char_ptr++;
    }
    cout << "===============================================" << endl << endl;


    //Create Programs
    program[0] = clCreateProgramWithSource(context, 1, &cstr, NULL, &error);
    if(error != CL_SUCCESS)
    {
        freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
        cout << "Could not load OpenCL program. Error #: " << error << endl;
        return -1;
    }

    //Build programs
    error = clBuildProgram(program[0], 0, NULL, NULL, NULL, NULL);
    if(error != CL_SUCCESS)
    {
        //Display error log
        size_t log_size = 0;
        clGetProgramBuildInfo(program[0], devices[0], CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
        if(log_size > 1)
        {
            char* log = new char[log_size];
            clGetProgramBuildInfo(program[0], devices[0], CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
            string* str = new string(log, log_size);
            cout << "Build log:" << endl;
            cout << *str << endl;
            delete[] log;
            delete str;
        }

        freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
        cout << "Could not build OpenCL program " << error << endl;
        return -1;
    }

    //Create kernels
    kernel[0] = clCreateKernel(program[0], "grayscale_kernel", &error);
    if(error != CL_SUCCESS)
    {
        freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
        cout << "Could not create OpenCL kernel. Error #" << error << endl;
        return -1;
    }

    //Create Command Queues for each device
    //(Mali T-628 GPU divided into 2 devices: devices[0] w/ 4 cores, devices[1] w/ 2cores)
    for(uint i = 0; i < num_platforms; i++)
    {
        command_queue[i] = clCreateCommandQueue(context, devices[i], CL_QUEUE_PROFILING_ENABLE, &error);
        if(error != CL_SUCCESS)
        {
            freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
            cout << "Could not create OpenCL command queue for device: " << i << ". Error #: " << error << endl;
            return -1;
        }
    }

    //Create an output buffers for input data and computed kernel data
    mem_objects[0] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_ALLOC_HOST_PTR, buffer_size, in_ptr, &error);
    if(error != CL_SUCCESS)
    {
        freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
        cout << "Could not create input OpenCL buffer object. Error #" << error << endl;
        return -1;
    }

    mem_objects[1] = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_ALLOC_HOST_PTR, buffer_size, out_ptr, &error);
    if(error != CL_SUCCESS)
    {
        freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
        cout << "Could not create output OpenCL buffer object. Error #: " << error << endl;
        return -1;
    }

    //Set up kernel arguments
    //grayscale_kernel
    clSetKernelArg(kernel[0], 0, sizeof(cl_mem), &mem_objects[0]);
    clSetKernelArg(kernel[0], 1, sizeof(cl_mem), &mem_objects[1]);
    clSetKernelArg(kernel[0], 2, sizeof(cl_int), &image_width);
    clSetKernelArg(kernel[0], 3, sizeof(cl_int), &image_height);

    //***TEST***//
    int iterations = 0;
    //***TEST***//

    //Capture new frames and process them until user quits
    for(;;)
    {
        //Handle OpenCV processing first
        cap.read(frame);
        cvtColor(frame, gray, CV_BGR2GRAY);

        //TODO: Create a for loop to enqueue both command_queues with in_ptr data
        //Map image to input buffer (mem_objects[0]);
        in_ptr = (cl_uchar*)clEnqueueMapBuffer(command_queue[0], mem_objects[0], CL_TRUE, CL_MAP_WRITE, 0, buffer_size, 0, NULL, NULL, &error);
        if(error != CL_SUCCESS)
        {
            freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
            cout << "Could not map input frame to buffer. Error #" << error << endl;
            return -1;
        }

        uchar* frame_ptr = frame.data;
        unsigned long i = 0;
        while(i < image_height*image_width)
        {
            in_ptr[i] = *frame_ptr;
            frame_ptr++;
            i++;
        }

        error = clEnqueueUnmapMemObject(command_queue[0], mem_objects[0], in_ptr, 0, NULL, NULL);
        if(error != CL_SUCCESS)
        {
            freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
            cout << "Could not unmap input memory object from buffer. Error#: " << error << endl;
            return -1;
        }

        //Enqueue the kernel
        cout << "cmdQ: " << (command_queue[0] != NULL) << " | kernel: " << (kernel[0] != NULL) << " | global_work_size: {" << global_work_size[0] << "," << global_work_size[1] << "}" << "\t(0 empty, 1 used)" << endl;
        error = clEnqueueNDRangeKernel(command_queue[0], kernel[0], 2, NULL, global_work_size, NULL, 0, NULL, &event[0]);
        if(error != CL_SUCCESS && error != CL_INVALID_KERNEL_ARGS)
        {
            freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
            cout << "Could not map data to kernel. Error #: " << error << endl;
            return -1;
        }

        //Wait for kernel to finish executing
        error = clFinish(command_queue[0]);
        if(error != CL_SUCCESS)
        {
            freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
            cout << "Kernel failed to execute. Error #: " << error << endl;
            return -1;
        }

        //Map output image
        out_ptr = (cl_uchar*)clEnqueueMapBuffer(command_queue[0], mem_objects[1], CL_TRUE, CL_MAP_READ, 0, buffer_size, 0, NULL, NULL, &error);
        if(error != CL_SUCCESS)
        {
            freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
            cout << "Could not map output frame to buffer. Error #: " << error << endl;
            return -1;
        }

        for(int i = 0; i < image_height; i++)
        {
            for(int j = 0; j < image_width; j++)
            {
                grayscale.at<uchar>(i, j) = out_ptr[image_width*i + j];
            }
        }

        error = clEnqueueUnmapMemObject(command_queue[0], mem_objects[1], out_ptr, 0, NULL, NULL);
        if(error != CL_SUCCESS)
        {
            freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
            cout << "Could not map input frame to buffer. Error #: " << error << endl;
            return -1;
        }

        //Display the images
        imshow(window_cpu, gray);
        imshow(window_gpu, grayscale);

        //***TEST***//
        cout << "Iteration: " << iterations << endl;
        iterations++;
        //***TEST***//

        //Wait for user to quit
        if(waitKey(30) > 0)
        {
            cout << endl << "...Camera stopped" << endl;

            // Print the profiling information for the event
            eventInfo(event, num_events);

            /* Release the event object. */
            error = clReleaseEvent(event[0]);
            if(error != CL_SUCCESS)
            {
                freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
                cout << "Failed releasing event object. Error #: " << error << endl;
                return -1;
            }

            break;
        }

/*
        //Sleep for 1 second
        time(&time_0);
        while(timer < 1)
        {
            time(&time_1);
            timer = difftime(time_0, time_1);
        }
*/

    }

    //Free all OpenCL objects
    freeOpenCL(context, program, kernel, command_queue, mem_objects, num_programs, num_kernels, num_queues, num_mem_objects);
    return 0;
}

//Function definitions
//freeOpenCL() releases all associated elements used to create and execute programs on the GPU
void freeOpenCL(cl_context context, cl_program* program, cl_kernel* kernel, cl_command_queue* command_queue, cl_mem* mem_objects,
               const unsigned int num_programs, const unsigned int num_kernels, const unsigned int num_queues, const unsigned int num_mem_objects)
{
    //Release the context
    if(context != 0)
    {
        switch(clReleaseContext(context))
        {
            case CL_SUCCESS:
                break;
            case CL_INVALID_CONTEXT:
                cout << "Invalid context provided" << endl;
                break;
            case CL_OUT_OF_RESOURCES:
                cout << "Failed allocating resources on device" << endl;
                break;
            case CL_OUT_OF_HOST_MEMORY:
                cout << "Failed allocating resources" << endl;
        }
    }

    //Release the command queues
    for(uint i = 0; i < num_queues; i++)
    {
        if(command_queue[i] != 0)
        {
            switch(clReleaseCommandQueue(command_queue[i]))
            {
                case CL_SUCCESS:
                    break;
                case CL_INVALID_COMMAND_QUEUE:
                    cout << "Invalid command queue provided" << endl;
                    break;
                case CL_OUT_OF_RESOURCES:
                    cout << "Failed allocating resources on device" << endl;
                    break;
                case CL_OUT_OF_HOST_MEMORY:
                    cout << "Failed allocating resources" << endl;
            }
        }
    }

    //Release the kernels
    for(uint i = 0; i < num_kernels; i++)
    {
        if(kernel[i] != 0)
        {
            switch(clReleaseKernel(kernel[i]))
            {
                case CL_SUCCESS:
                    break;
                case CL_INVALID_KERNEL:
                    cout << "Invalid kernel provided" << endl;
                    break;
                case CL_OUT_OF_RESOURCES:
                    cout << "Failed allocating resources on device" << endl;
                    break;
                case CL_OUT_OF_HOST_MEMORY:
                    cout << "Failed allocating resources" << endl;
            }
        }
    }

    //Release the programs
    for(uint i = 0; i < num_programs; i++)
    {
        if(program[i] != 0)
        {
            switch(clReleaseProgram(program[i]))
            {
                case CL_SUCCESS:
                    break;
                case CL_INVALID_PROGRAM:
                    cout << "Invalid program provided" << endl;
                    break;
                case CL_OUT_OF_RESOURCES:
                    cout << "Failed allocating resources on device" << endl;
                    break;
                case CL_OUT_OF_HOST_MEMORY:
                    cout << "Failed allocating resources" << endl;
            }
        }
    }

    //Release the memory objects
    for(uint i = 0; i < num_mem_objects; i++)
    {
        if(mem_objects[i] != 0)
        {
            switch(clReleaseMemObject(mem_objects[i]))
            {
                case CL_SUCCESS:
                    break;
                case CL_INVALID_MEM_OBJECT:
                    cout << "Invalid memory object provided" << endl;
                    break;
                case CL_OUT_OF_RESOURCES:
                    cout << "Failed allocating resources on device" << endl;
                    break;
                case CL_OUT_OF_HOST_MEMORY:
                    cout << "Failed allocating resources" << endl;
            }
        }
    }
}

//eventInfo() displays various timing information about the kernel execution
void eventInfo(cl_event* event, const unsigned int num_events)
{
    cl_ulong queued_time = 0;
    cl_ulong wait_time = 0;
    cl_ulong exec_time_start = 0;
    cl_ulong exec_time_end = 0;

    for(uint i = 0; i < num_events; i++)
    {
        //Display queued, waiting, and execution time for the kernel
        clGetEventProfilingInfo(event[i], CL_PROFILING_COMMAND_QUEUED, sizeof(cl_ulong), &queued_time, NULL);
        clGetEventProfilingInfo(event[i], CL_PROFILING_COMMAND_SUBMIT, sizeof(cl_ulong), &wait_time, NULL);
        clGetEventProfilingInfo(event[i], CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &exec_time_start, NULL);
        clGetEventProfilingInfo(event[i], CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &exec_time_end, NULL);

        cout << "=== Event " << i << " Information ===" << endl;
        cout << "Queued time:    " << (wait_time - queued_time)/1000000 << " ms" << endl;
        cout << "Wait time:      " << (exec_time_start - wait_time)/1000000 << " ms" << endl;
        cout << "Execution time: " << (exec_time_end - exec_time_start)/1000000 << " ms" << endl << endl;
    }
}
