# Test Makefile to determine if we can mix OpenCV adn OpenCL together
# This uses a basic cross between an OpenCV project's Makefile and
# an OpenCL project's Makefile

ROOT:=../..

include $(ROOT)/platform.mk

CFLAGS:=-c -Wall -I$(ROOT)/include -I$(ROOT)/common -I.

LDFLAGS:=-L$(ROOT)/lib -L$(ROOT)/common -lOpenCL -lCommon

CVINC = -I/usr/local/include/opencv -I/usr/local/include  /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgcodecs.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_shape.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_superres.so /usr/local/lib/libopencv_ts.a /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videoio.so /usr/local/lib/libopencv_videostab.so

SOURCES:=motion_detector.cpp

OBJECTS:=$(SOURCES:.cpp=.o)

EXECUTABLE:=motion_detector

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) libOpenCL libCommon
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(CVINC)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS): $(HEADERS)

install: $(EXECUTABLE)
	-$(MKDIR) "$(ROOT)/bin/$(EXECUTABLE)/kernels"
	$(CP) "$(EXECUTABLE)" "$(ROOT)/bin/$(EXECUTABLE)/$(EXECUTABLE)"
	cd assets $(CONCATENATE) $(CP) * "../$(ROOT)/bin/$(EXECUTABLE)/kernels/"

.PHONY: clean libOpenCL libCommon

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)

libOpenCL:
	cd $(ROOT)/lib $(CONCATENATE) $(MAKE) libOpenCL.so

libCommon:
	cd $(ROOT)/common/ $(CONCATENATE) $(MAKE) libCommon.a
