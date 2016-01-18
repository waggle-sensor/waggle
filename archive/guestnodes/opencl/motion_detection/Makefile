# Makefile for the motion detector.
# Compiles both OpenCl and OpenCV libraries to use

ROOT:=../..

CC:=arm-linux-gnueabihf-g++

CFLAGS:=-c -Wall -I$(ROOT)/include -I.

LDFLAGS:=-L$(ROOT)/lib -lOpenCL

CVINC:=-I/usr/local/include/opencv -I/usr/local/include  /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgcodecs.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_shape.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_superres.so /usr/local/lib/libopencv_ts.a /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videoio.so /usr/local/lib/libopencv_videostab.so

SOURCES:=motion_detector.cpp

OBJECTS:=$(SOURCES:.cpp=.o)

EXECUTABLE:=motion_detector

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(CVINC)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
