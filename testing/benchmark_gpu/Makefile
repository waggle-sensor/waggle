CXX ?= g++

CXXFLAGS += -c -Wall $(shell pkg-config --cflags opencv)
LDFLAGS += -L/usr/lib/arm-linux-gnueabihf/mali-egl $(shell pkg-config --libs --static opencv) -lmali -lOpenCL

all: test_program openCV_CL_ver

openCV_CL_ver: openCV_CL_ver.o; $(CXX) $< -o $@ $(LDFLAGS)

test_program: test_program.o; $(CXX) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

clean: ; rm -f *.o test_program openCV_CL_ver
