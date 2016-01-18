/*
 * blur_kernel smoothes a grayscale image by convolving each pixel with a 5x5 Gaussian kernel
 * Input: Image w/ 8-bit 1-channel data
 * Output: smoothed image w/ 8-bit 1-channel data
 */

#pragma OPENCL EXTENSION cl_khr_fp64 : enable

//Gaussian kernel
__constant float gaussian[5][5] = {{0.015026, 0.028569, 0.035391, 0.028569, 0.015026},
				   {0.028569, 0.054318, 0.067288, 0.054318, 0.028569},
				   {0.035391, 0.067288, 0.083355, 0.067288, 0.035391},
				   {0.028569, 0.054318, 0.067288, 0.054318, 0.028569},
				   {0.015026, 0.028569, 0.035391, 0.028569, 0.015026}};

//Main kernel
__kernel void gaussian_blur_kernel(__global uchar* in,
			      __global uchar* out,
			      const int rows,
			      const int cols)
{
	int value = 0;
	size_t col = get_global_id(0);
	size_t row = get_global_id(1);
	size_t pos = row*cols + col;

	//Apply the Gaussian kernel to the surrounding patch of pixels
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			value += gaussian[i][j]*in[(i + row - 1)*cols + (j + col - 1)];
		}
	}

	out[pos] = min(255, max(0, value));
}
