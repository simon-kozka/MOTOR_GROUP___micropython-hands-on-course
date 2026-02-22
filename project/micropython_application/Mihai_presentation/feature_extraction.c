#include "feature_extraction.h"
#include <math.h>

void computeFeatures(float* window, size_t window_size, float* rms, float* energy) {
    float sq_sum = 0.0f;
    for (size_t i = 0; i < window_size; i++) {
        sq_sum += window[i] * window[i];
    }
    *rms = sqrtf(sq_sum / (float)window_size);
    *energy = (float)window_size * sq_sum / 2.0f;
}