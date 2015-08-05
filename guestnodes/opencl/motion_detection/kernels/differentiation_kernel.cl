/*
 * differentiation_kernel finds the difference between two frames to determine if any movement has occured
 * Input: Background image, current image
 * Output: Abs. value of difference between two frames
 */

#pragma OPENCL EXTENSION cl_khr_fp64 : enable

//Main kernel
__kernel void differentiation_kernel(__global uchar* in,
				     __global uchar* out,
				     __global uchar* background,
				     const double alpha,
				     const int threshold,
				     const int rows,
				     const int cols)
{
	size_t col = get_global_id(0);
	size_t row = get_global_id(1);
	size_t pos = row*cols + col;
	double delta = 0;

	//Account for changing background conditions (daylight, etc.)
	background[pos] = (1 - alpha)*background[pos] + alpha*in[pos];

	//Calculate absolute value of difference between background and in data
	delta = abs(in[pos] - background[pos]);

	//Enhance the delta by maxing value if over threshold or ignoring change in value
	(delta > threshold) ? (out[pos] = 255) : (out[pos] = 0);
}
