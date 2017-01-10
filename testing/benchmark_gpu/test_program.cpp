#include <iostream>
#include <ctime>
#include <signal.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>

volatile sig_atomic_t flag = 1;
void my_function(int sig){ // can be called asynchronously
  flag = 0; // set flag
}

using namespace std;
using namespace cv;

int main(int argc, char**argv) 
{
    signal(SIGINT, my_function); 
    cout << "Have OpenCL?: " << cv::ocl::haveOpenCL() << endl;

    cv::CommandLineParser parser(argc, argv, "{opencl cl||}");
    if (parser.has("opencl"))
    {
        cout << "OpenCL enabled" << endl;
        cv::ocl::setUseOpenCL(true);
    }
    else
    {
        cout << "OpenCL disabled" << endl;
        cv::ocl::setUseOpenCL(false);
    }
    int nBlurs = 50;
    /*
    cv::VideoCapture cam;

    if (!cam.open(0))
        std::cout << "Problem connecting to cam " << std::endl;
    else
        std::cout << "Successfuly connected to camera " << std::endl;
    */
    long frameCounter = 0;

    std::time_t timeBegin = std::time(0);
    int tick = 0;

    cv::UMat fake;
    cv::UMat frame;
    cv::UMat frameGray;
    cv::UMat frameSobelx;
    cv::UMat frameSobely;

    cv::UMat frameSobel;
    cv::UMat blurredSobel;

    frame = imread("res/lena_color.tiff").getUMat(ACCESS_READ);

    while (flag)
    {
        //cam.read(fake);
        cv::cvtColor(frame, frameGray, cv::COLOR_BGR2GRAY);

        cv::Sobel(frameGray, frameSobelx, frameGray.depth(), 1, 0, 3);
        cv::Sobel(frameGray, frameSobely, frameGray.depth(), 0, 1, 3);

        //for (int n = 0; n < 200; n++)
        //{

        cv::bitwise_or(frameSobelx, frameSobely, frameSobel);

        //for (int n = 0; n < nBlurs; n++)
            cv::medianBlur(frameSobel, blurredSobel, 3);
            cv::blur(frameSobel, blurredSobel, cv::Size(3,3));
            //cv::blur(frameGray, blurredSobel, cv::Size(3,3));
        //}
        //cv::imshow("Sobel blurred Frame", blurredSobel);
        //cv::waitKey(1);

        frameCounter++;

        std::time_t timeNow = std::time(0) - timeBegin;

        if (timeNow - tick >= 1)
        {
            tick++;
            cout << "Frames per second: " << frameCounter << endl;
            frameCounter = 0;
            if (tick > 10)
            {
                flag = false;
            }
        }
        //frameGray.release();
        //frameSobelx.release();
        //frameSobely.release();
        //frameSobel.release();
        //blurredSobel.release();
    }
    //imwrite("result.jpg", blurredSobel);

    return 0;
}
