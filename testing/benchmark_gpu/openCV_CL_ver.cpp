#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

using namespace std;

int main(int argc, char**argv) {

    cout << "OpenCV version=" << std::hex << CV_VERSION << std::dec << std::endl;

    if (!cv::ocl::haveOpenCL())
    {
        cout << "OpenCL is not avaiable..." << endl;
        return 0;
    }
    cv::ocl::Context context;
    if (!context.create(cv::ocl::Device::TYPE_GPU))
    {
        cout << "Failed creating the context..." << endl;
        return 0;
    }

    // In OpenCV 3.0.0 beta, only a single device is detected.
    cout << context.ndevices() << " GPU devices are detected." << endl;

    for (int i = 0; i < context.ndevices(); i++)   
    {
        cv::ocl::Device device = context.device(i);
        cout << "name                 : " << device.name() << endl;
        cout << "available            : " << device.available() << endl;
        cout << "imageSupport         : " << device.imageSupport() << endl;
        cout << "OpenCL_C_Version     : " << device.OpenCL_C_Version() << endl;
        cout << endl;
    }
    return 0;
}
