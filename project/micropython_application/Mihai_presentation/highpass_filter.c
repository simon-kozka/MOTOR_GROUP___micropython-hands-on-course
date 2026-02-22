#include "highpass_filter.h"
#include <math.h>

#define PI 3.14159265358979f

void initHighPassFilter(HighPassFilter* filter, float cutoff, float fs) {
    filter->rc = 1.0f / (2.0f * PI * cutoff);
    filter->dt = 1.0f / fs;
    filter->alpha = filter->rc / (filter->rc + filter->dt);
    filter->prev = 0.0f;
    filter->prev_filt = 0.0f;
}

float filterHighPass(HighPassFilter* filter, float x) {
    float y = filter->alpha * (filter->prev_filt + x - filter->prev);
    filter->prev = x;
    filter->prev_filt = y;
    return y;
}