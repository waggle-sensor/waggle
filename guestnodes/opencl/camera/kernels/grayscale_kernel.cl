/*
 * Grayscale Kernel
 * Input: Image w/ 8-bit 3-channel data
 * Output: Grayscale Image w/ 8-bit 1-channel data
 */
__kernel void grayscale_kernel(__global uchar* in,
                               __global uchar* out,
                               size_t rows,
                               size_t cols)
{
    float value = 0;
    size_t col = get_global_id(0)*3;
    size_t row = get_global_id(1);
    size_t in_pos = row*cols + col;
    size_t out_pos = row*cols +(col/3);

    //Sum weighted BGR Channels to get grayscale value
    value += (float)in[in_pos]*0.299;
    value += (float)in[in_pos + 1]*0.587;
    value += (float)in[in_pos + 2]*0.114;

    out[out_pos] = (uchar)value;
}

