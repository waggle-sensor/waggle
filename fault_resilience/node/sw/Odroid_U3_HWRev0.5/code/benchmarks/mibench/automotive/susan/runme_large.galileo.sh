#!/bin/sh
./susan.galileo.bin input_large.pgm output_large.smoothing.pgm -s
./susan.galileo.bin input_large.pgm output_large.edges.pgm -e
./susan.galileo.bin input_large.pgm output_large.corners.pgm -c

