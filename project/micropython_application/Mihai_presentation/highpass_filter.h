#ifndef HIGHPASS_FILTER_H
#define HIGHPASS_FILTER_H

typedef struct {
    float rc;
    float dt;
    float alpha;
    float prev;
    float prev_filt;
} HighPassFilter;

// Initialize the filter
void initHighPassFilter(HighPassFilter* filter, float cutoff, float fs);

// Apply the filter to a new sample
float filterHighPass(HighPassFilter* filter, float x);

#endif // HIGHPASS_FILTER_H