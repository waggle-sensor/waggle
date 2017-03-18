# GPU benchmark

This procedure describes how the GPU on XU4 works and measures performance of the GPU. The test program calls some of image processing functions without rendering. The performance is measured by utilization of processing cores in the range between 0 and 100, meaning percentage of its usage.

# Requirements

* Odroid XU4 with Waggle base image (version 2.1.4 or higher)
* OpenCV 3.1.0 or higher
* OpenCL 1.1 for Mali T-62X or higher
* Test scripts (test program and logger)

# Assumptions

* OpenCV libraries are (will be) installed under /usr/local/lib; includes are under /usr/local/include
* OpenCL libraries for Mali T-628 are (will be) under /usr/lib/arm-linux-gnueabihf/mali-egl
* The system has python3-dev and make

# Instructions

0. Install libraries and check GPU
```bash
./install
```

1. Run the script
```bash
./run
```

2.Wait for a couple of minutes (by default the code runs with/without GPU takes 30 seconds each and there are some ```sleep``` between execution of the test program). After the script finishes __result.log__ will be generated and will contain result of the execution.