CXX ?= g++

CXXFLAGS += -c -Wall -I/usr/local/include/opencv -I/usr/local/include
LDFLAGS += -L/usr/lib/arm-linux-gnueabihf/mali-egl -L/usr/local/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn -lopencv_dpm -lopencv_fuzzy -lopencv_line_descriptor -lopencv_optflow -lopencv_plot -lopencv_reg -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_rgbd -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_face -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_xobjdetect -lopencv_objdetect -lopencv_ml -lopencv_xphoto -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_core -lpng -lz -ltiff -ljasper -ljpeg -ldc1394 -lv4l1 -lv4l2 -lavcodec-ffmpeg -lavformat-ffmpeg -lavutil-ffmpeg -lswscale-ffmpeg -ldl -lm -lpthread -lrt -lmali -lOpenCL

all: test_program openCV_CL_ver

openCV_CL_ver: openCV_CL_ver.o; $(CXX) $< -o $@ $(LDFLAGS)

test_program: test_program.o; $(CXX) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

clean: ; rm -f *.o test_program openCV_CL_ver
