#ifndef FEATURE_EXTRACTION_H
#define FEATURE_EXTRACTION_H

#include <stddef.h>

// Compute RMS and total energy for a window
void computeFeatures(float* window, size_t window_size, float* rms, float* energy);

#endif // FEATURE_EXTRACTION_H