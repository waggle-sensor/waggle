#!/bin/sh
./susan.galileo.bin input_small.pgm output_small.smoothing.pgm -s
./susan.galileo.bin input_small.pgm output_small.edges.pgm -e
./susan.galileo.bin input_small.pgm output_small.corners.pgm -c

