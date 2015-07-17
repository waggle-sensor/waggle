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

#include "common.h"
#include "image.h"

#include <CL/cl.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstddef>
#include <cmath>
#include <sys/time.h>

using namespace std;
using namespace cv;

//Global variables
const std::string kernel_canny_edges = "assets/canny_edges.cl";

//Function prototypes
void freeOpenCL(cl_context, cl_program*, cl_kernel*, cl_command_queue*, cl_mem*, const unsigned int);

int main(void)
{
    //OpenCV variables
    UMat frame, edges;

    int lowThreshold = 35;
    int ratio = 3;
    int kernel_size = 3;

    const std::string window = "Canny Edges GPU";

    //Open the default camera
    VideoCapture cap(0);
    (!cap.isOpened()) ? (cout <<
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

    cout << "=== " << num_platforms << " OpenCL platform(s) found: ==" << endl;
    for (int i = 0; i < num_platforms; i++)
    {
        char buffer[10240];
        cout << " -- " << i << " -- " << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_PROFILE, 10240, buffer, NULL);
        cout << " PROFILE = " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_VERSION, 10240, buffer, NULL);
        cout << " VERSION = " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, 10240, buffer, NULL);
        cout << " NAME = " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, 10240, buffer, NULL);
        cout << " VENDOR = " << buffer << endl;
        clGetPlatformInfo(platforms[i], CL_PLATFORM_EXTENSIONS, 10240, buffer, NULL);
        cout << " EXTENSIONS = " << buffer << endl << endl;
    }

    //Find Devices
    clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 2, devices, &num_devices);

    cout << "=== " << devices_n << " OpenCL device(s) found on platform 0: ===" << endl;
    for(int i = 0; i < num_devices; i++)
    {
        char buffer[10240];
        cl_uint buf_uint;
        cl_ulong buf_ulong;
        cout << " -- " << i << " -- " << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_NAME, sizeof(buffer), buffer, NULL);
        cout << " DEVICE NAME = " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR, sizeof(buffer), buffer, NULL);
        cout << " DEVICE VENDOR = " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_VERSION, sizeof(buffer), buffer, NULL);
        cout << " DEVICE VERSION = " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DRIVER_VERSION, sizeof(buffer), buffer, NULL);
        cout << " DRIVER VERSION = " << buffer << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(buf_uint), &buf_uint, NULL);
        cout << " MAX COMPUTE UNITS = " << buf_uint << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(buf_uint), &buf_uint, NULL);
        cout << " MAX CLOCK FREQUENCY = " << buf_uint << endl;
        clGetDeviceInfo(devices[i], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(buf_ulong), &buf_ulong, NULL);
        cout << " GLOBAL MEMORY SIZE = " << buf_ulong << endl << endl;
    }

    //Create a single context to work in
    cl_context_properties context_properties[] = {CL_CONTEXT_PLATFORM, (cl_context_properties)platforms, 0};
    *context = clGreateContextFromType(context_properties, CL_DEVICE_TYPE_GPU, NULL, NULL, &error);
    if(error != CL_SUCCESS)
    {
        freeOpenCL(context, program, kernel, command_queue, mem_objects, num_mem_objects);
        cout << "Could not create OpenCL context" << endl;
        return -1;
    }

    //Create and compile the kernel and create Command Queues for each device
    //(Mali T-628 GPU divided into 2 devices: devices[0] w/ 4 cores, devices[1] w/ 2cores)
    ifstream kernel_program(kernel_canny_edges.c_str(), ios::in);
    ostringstream kernel_stream << kernel_program.rdbuf();
    char* kernel_str = 
    for(int i = 0; i < num_platforms; i++)
    {
        //Create Program
        *program[i] = clCreateProgramWithSource(context, 1, &kernel_str, NULL, &error)
        

        if(!createProgram(context, devices[i], "assets/canny.cl", &program[1]))
        {
            cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
            cerr << "Failed to create OpenCL program. " << __FILE__ << ":" << __LINE__ << endl;
            return 1;
        }

        //Create Kernels
        kernel = clCreateKernel(program[0], "blur", &errorNumber);
        if(!checkSuccess(errorNumber))
        {
            cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
            cerr << "Failed to create OpenCL kernel. " << __FILE__ << ":" << __LINE__ << endl;
            return 1;
        }

        //Create Command Queue
        if(!createCommandQueue(context, &commandQueue, &devices[i]))
        {
            cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
            cerr << "Failed to create OpenCL command queue. " << __FILE__ << ":" << __LINE__ << endl;
            return 1;
        }
    }


    //Define some variables so they're not local scope in the loop
    //Width and Height of the Mandelbrot data you want to be produced
    cl_int width = 4096;
    cl_int height = 3280;

    //The output buffer is the size fo teh Mandelbrot data
    size_t bufferSize = width*height*sizeof(cl_uchar);

    //Output # of iterations completed
    int i = 0;

    //We will loop the program and continually to process new camera frames
    for(;;)
    {
        //Handle OpenCV processing first
        cap >> frame;
        cvtColor(frame, frame, CV_BGR2GRAY);
        GaussianBlur(frame, frame, Size(5, 5), 1.5, 1.5);
        Canny(frame, edges, lowThreshold, lowThreshold*ratio, kernel_size);

        imshow(window, edges);

    /* Create an output buffer for final data. */
    memoryObjects[0] = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_ALLOC_HOST_PTR, bufferSize, NULL, &errorNumber);
    if (!checkSuccess(errorNumber))
    {
        cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
        cerr << "Failed to create OpenCL buffer. " << __FILE__ << ":"<< __LINE__ << endl;
        return 1;
    }

    /* Setup the kernel arguments. */
    bool setKernelArgumentsSuccess = true;
    setKernelArgumentsSuccess &= checkSuccess(clSetKernelArg(kernel, 0, sizeof(cl_mem), &memoryObjects[0]));
    setKernelArgumentsSuccess &= checkSuccess(clSetKernelArg(kernel, 1, sizeof(cl_int), &width));
    setKernelArgumentsSuccess &= checkSuccess(clSetKernelArg(kernel, 2, sizeof(cl_int), &height));

    if (!setKernelArgumentsSuccess)
    {
        cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
        cerr << "Failed setting OpenCL kernel arguments. " << __FILE__ << ":"<< __LINE__ << endl;
        return 1;
    }

    /* An event to associate with the Kernel. Allows us to retreive profiling information later. */
    cl_event event = 0;

    /* [Kernel size] */
    /*
     * The OpenCL kernel calculates four pixels at a time (all in the same row).
     * Therefore, we only need to run the kernel width / 4 times in the x dimension.
     */
    size_t globalWorksize[2] = {width / 4, height};
    /* [Kernel size] */

    /* Enqueue the kernel */
    if (!checkSuccess(clEnqueueNDRangeKernel(commandQueue, kernel, 2, NULL, globalWorksize, NULL, 0, NULL, &event)))
    {
        cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
        cerr << "Failed enqueuing the kernel. " << __FILE__ << ":"<< __LINE__ << endl;
        return 1;
    }

    /* Wait for kernel execution completion. */
    if (!checkSuccess(clFinish(commandQueue)))
    {
        cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
        cerr << "Failed waiting for kernel execution to finish. " << __FILE__ << ":"<< __LINE__ << endl;
        return 1;
    }

    cout << "Iteration: " << i << endl;
    i++;

    //Wait for user to quit
    if(waitKey(30) > 0)
    {
    // Print the profiling information for the event
    printProfilingInfo(event);

    /* Release the event object. */
    if (!checkSuccess(clReleaseEvent(event)))
    {
        cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
        cerr << "Failed releasing the event object. " << __FILE__ << ":"<< __LINE__ << endl;
        return 1;
    }

    break;
    }
    }

    /* Map the output memory to a host side pointer. */
    cl_uchar* output = (cl_uchar*)clEnqueueMapBuffer(commandQueue, memoryObjects[0], CL_TRUE, CL_MAP_READ, 0, bufferSize, 0, NULL, NULL, &errorNumber);
    if (!checkSuccess(errorNumber))
    {
       cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
       cerr << "Mapping memory objects failed " << __FILE__ << ":"<< __LINE__ << endl;
       return 1;
    }

    /* Convert the output luminance array to RGB and save it out to a file. */
    unsigned char* rgbOut = new unsigned char[width * height * 3];
    luminanceToRGB(output, rgbOut, width, height);
    saveToBitmap("output.bmp", width, height, rgbOut);

    /* Unmap the output. */
    if (!checkSuccess(clEnqueueUnmapMemObject(commandQueue, memoryObjects[0], output, 0, NULL, NULL)))
    {
       cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);
       cerr << "Unmapping memory objects failed " << __FILE__ << ":"<< __LINE__ << endl;
       return 1;
    }

    /* Release OpenCL objects. */
    cleanUpOpenCL(context, commandQueue, program, kernel, memoryObjects, numberOfMemoryObjects);

    delete [] rgbOut;

    cout << endl << "Camera stopped" << endl;
    return 0;
}

//Function definitions
//freeOpenCL() releases all associated elements used to create and execute programs on the GPU
void freeOpenCL(cl_context context, cl_program* program, cl_kernel* kernel, cl_command_queue* command_queue, cl_mem* mem_object,
               const unsigned int num_programs, const unsigned int, num_kernels, const unsigned int num_queues, const unsigned int num_mem_objects)
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
    for(int i = 0; i < num_queues; i++)
    {
        if(command_queue[i] != 0)
        {
            switch(clReleaseCommandQueue(command_queue[i])
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
    for(int i = 0; i < num_kernels; i++)
    {
        if(kernel[i] != 0)
        {
            switch(clReleaseKernel(kernel[i])
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
    for(int i = 0; i < num_programs; i++)
    {
        if(program[i] != 0)
        {
            switch(clReleaseProgram(program[i])
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
    for(int i = 0; i < num_mem_objects; i++)
    {
        if(mem_objects[i] != 0)
        {
            switch(clReleaseMemObject(mem_object[i])
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
