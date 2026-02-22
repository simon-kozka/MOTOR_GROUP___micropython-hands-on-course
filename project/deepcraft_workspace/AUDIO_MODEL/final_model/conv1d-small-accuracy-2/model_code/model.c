/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/21/2026 09:38:16 UTC. Any changes will be lost.
* 
* Model ID  fb9a648f-02e7-4ba0-bb42-05e94f32cea9
* 
* Memory    Size                      Efficiency
* Buffers   15360 bytes (RAM)         100 %
* State     16392 bytes (RAM)         100 %
* Readonly  29176 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-small-accuracy-2
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | imbalance
* 2           | working
* 3           | impact
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [512]           float      dequeue
*    window_shape = [512]
*    stride = 120
*    buffer_multiplier = 1
* Hann smoothing                 [512]           float      dequeue
*    sym = True
* Real Discrete Fourier Transform [257,2]         float      dequeue
*    axis = 0
* Frobenius norm                 [257]           float      dequeue
*    axis = 0
* Mel Filterbank                 [40]            float      dequeue
*    num_filters = 40
*    sample_rate = 16000
*    f_low = 150
*    f_high = 8000
*    htk = True
*    librosa = False
* Clip                           [40]            float      dequeue
*    min = 0.000316227766
*    max = 3.40282347E+38
* Logarithm                      [40]            float      dequeue
*    base = 0
* Sliding Window (data points)   [80,40]         float      dequeue
*    window_shape = [80,40]
*    stride = 120
*    buffer_multiplier = 1
* Input Layer                    [80,40]         float      dequeue
*    shape = [80,40]
* Convolution 1D                 [40,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,40,16]
* Batch Normalization            [40,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [40,16]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [40,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Batch Normalization            [40,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [40,32]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [40,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [40,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [40,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [20,32]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Dropout                        [20,32]         float      dequeue
*    rate = 0.05
*    trainable = True
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [4]             float      dequeue
*    units = 4
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,4]
*    bias = float[4]
* Activation                     [4]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[4].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[1].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 81.168 %
* (F1S) F1 Score 81.290 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction               56924            26192             3958            33323
* (FN) False Negative or Incorrect Negative Prediction             8738              124              345            18726
* (FP) False Positive or Incorrect Positive Prediction            18509             2388             5830             1206
* (TN) True Negative or Correct Negative Prediction               64159           119626           138197            95075
* (TPR) True Positive Rate or Sensitivity, Recall               86.69 %          99.53 %          91.98 %          64.02 %
* (TNR) True Negative Rate or Specificity, Selectivity          77.61 %          98.04 %          95.95 %          98.75 %
* (PPV) Positive Predictive Value or Precision                  75.46 %          91.64 %          40.44 %          96.51 %
* (NPV) Negative Predictive Value                               88.01 %          99.90 %          99.75 %          83.54 %
* (FNR) False Negative Rate or Miss Rate                        13.31 %           0.47 %           8.02 %          35.98 %
* (FPR) False Positive Rate or Fall-Out                         22.39 %           1.96 %           4.05 %           1.25 %
* (FDR) False Discovery Rate                                    24.54 %           8.36 %          59.56 %           3.49 %
* (FOR) False Omission Rate                                     11.99 %           0.10 %           0.25 %          16.46 %
* (F1S) F1 Score                                                80.69 %          95.42 %          56.18 %          76.98 %
*/

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "model.h"

// Working memory
static int8_t _buffer[15360];
static int8_t _state[16392];

// Parameters
static const uint32_t _K4[] = {
    0x00000000, 0x381e87c4, 0x391e863b, 0x39b25423, 0x3a1e8019, 0x3a77a0f6, 0x3ab2449b, 0x3af29a52, 
    0x3b1e6790, 0x3b487014, 0x3b776514, 0x3b95a260, 0x3bb2068a, 0x3bd0ddef, 0x3bf2275e, 0x3c0af0c6, 
    0x3c1e058c, 0x3c325144, 0x3c47d325, 0x3c5e8a59, 0x3c767600, 0x3c87ca96, 0x3c94f373, 0x3ca2b513, 
    0x3cb10eef, 0x3cc00079, 0x3ccf891c, 0x3cdfa83e, 0x3cf05d41, 0x3d00d3bf, 0x3d09c324, 0x3d12fc79, 
    0x3d1c7f61, 0x3d264b7e, 0x3d306070, 0x3d3abdd2, 0x3d45633d, 0x3d505049, 0x3d5b8488, 0x3d66ff8d, 
    0x3d72c0e4, 0x3d7ec81a, 0x3d858a5c, 0x3d8bd322, 0x3d923e20, 0x3d98cb17, 0x3d9f79c6, 0x3da649eb, 
    0x3dad3b42, 0x3db44d87, 0x3dbb8073, 0x3dc2d3c0, 0x3dca4724, 0x3dd1da56, 0x3dd98d0a, 0x3de15ef5, 
    0x3de94fc9, 0x3df15f37, 0x3df98cef, 0x3e00ec51, 0x3e0520fd, 0x3e096453, 0x3e0db62a, 0x3e121654, 
    0x3e1684a9, 0x3e1b00fb, 0x3e1f8b1e, 0x3e2422e6, 0x3e28c824, 0x3e2d7aab, 0x3e323a4b, 0x3e3706d7, 
    0x3e3be01f, 0x3e40c5f2, 0x3e45b820, 0x3e4ab678, 0x3e4fc0c8, 0x3e54d6df, 0x3e59f88a, 0x3e5f2596, 
    0x3e645dd0, 0x3e69a105, 0x3e6eeeff, 0x3e74478b, 0x3e79aa74, 0x3e7f1784, 0x3e824743, 0x3e8507a1, 
    0x3e87ccc2, 0x3e8a968a, 0x3e8d64dd, 0x3e9037a0, 0x3e930eb6, 0x3e95ea04, 0x3e98c96d, 0x3e9bacd4, 
    0x3e9e941e, 0x3ea17f2c, 0x3ea46de3, 0x3ea76026, 0x3eaa55d6, 0x3ead4ed8, 0x3eb04b0c, 0x3eb34a56, 
    0x3eb64c99, 0x3eb951b5, 0x3ebc598e, 0x3ebf6406, 0x3ec270fd, 0x3ec58056, 0x3ec891f3, 0x3ecba5b5, 
    0x3ecebb7e, 0x3ed1d32f, 0x3ed4ecaa, 0x3ed807cf, 0x3edb2480, 0x3ede429f, 0x3ee1620c, 0x3ee482a8, 
    0x3ee7a455, 0x3eeac6f2, 0x3eedea63, 0x3ef10e86, 0x3ef4333d, 0x3ef7586a, 0x3efa7dec, 0x3efda3a4, 
    0x3f0064ba, 0x3f01f79e, 0x3f038a6f, 0x3f051d1d, 0x3f06af97, 0x3f0841d0, 0x3f09d3b7, 0x3f0b653c, 
    0x3f0cf651, 0x3f0e86e5, 0x3f1016e9, 0x3f11a64e, 0x3f133504, 0x3f14c2fc, 0x3f165025, 0x3f17dc72, 
    0x3f1967d3, 0x3f1af237, 0x3f1c7b91, 0x3f1e03d0, 0x3f1f8ae6, 0x3f2110c4, 0x3f22955a, 0x3f241899, 
    0x3f259a73, 0x3f271ad8, 0x3f2899b9, 0x3f2a1709, 0x3f2b92b7, 0x3f2d0cb6, 0x3f2e84f6, 0x3f2ffb69, 
    0x3f317001, 0x3f32e2af, 0x3f345365, 0x3f35c214, 0x3f372eaf, 0x3f389927, 0x3f3a016e, 0x3f3b6776, 
    0x3f3ccb32, 0x3f3e2c94, 0x3f3f8b8d, 0x3f40e811, 0x3f424212, 0x3f439982, 0x3f44ee55, 0x3f46407c, 
    0x3f478fec, 0x3f48dc96, 0x3f4a266f, 0x3f4b6d69, 0x3f4cb177, 0x3f4df28e, 0x3f4f30a0, 0x3f506ba2, 
    0x3f51a386, 0x3f52d842, 0x3f5409c9, 0x3f553810, 0x3f56630a, 0x3f578aac, 0x3f58aeeb, 0x3f59cfbb, 
    0x3f5aed11, 0x3f5c06e2, 0x3f5d1d24, 0x3f5e2fcb, 0x3f5f3ecc, 0x3f604a1e, 0x3f6151b6, 0x3f62558a, 
    0x3f63558f, 0x3f6451bc, 0x3f654a07, 0x3f663e67, 0x3f672ed2, 0x3f681b3e, 0x3f6903a2, 0x3f69e7f7, 
    0x3f6ac831, 0x3f6ba44a, 0x3f6c7c39, 0x3f6d4ff4, 0x3f6e1f74, 0x3f6eeab2, 0x3f6fb1a4, 0x3f707443, 
    0x3f713289, 0x3f71ec6c, 0x3f72a1e7, 0x3f7352f3, 0x3f73ff87, 0x3f74a79e, 0x3f754b32, 0x3f75ea3b, 
    0x3f7684b4, 0x3f771a97, 0x3f77abdd, 0x3f783882, 0x3f78c080, 0x3f7943d1, 0x3f79c270, 0x3f7a3c5a, 
    0x3f7ab188, 0x3f7b21f6, 0x3f7b8da1, 0x3f7bf483, 0x3f7c5699, 0x3f7cb3df, 0x3f7d0c52, 0x3f7d5fee, 
    0x3f7daeaf, 0x3f7df893, 0x3f7e3d97, 0x3f7e7db8, 0x3f7eb8f4, 0x3f7eef48, 0x3f7f20b3, 0x3f7f4d32, 
    0x3f7f74c3, 0x3f7f9766, 0x3f7fb519, 0x3f7fcdda, 0x3f7fe1a9, 0x3f7ff085, 0x3f7ffa6d, 0x3f7fff61, 
    0x3f7fff61, 0x3f7ffa6d, 0x3f7ff085, 0x3f7fe1a9, 0x3f7fcdda, 0x3f7fb519, 0x3f7f9766, 0x3f7f74c3, 
    0x3f7f4d32, 0x3f7f20b3, 0x3f7eef48, 0x3f7eb8f4, 0x3f7e7db8, 0x3f7e3d97, 0x3f7df893, 0x3f7daeaf, 
    0x3f7d5fee, 0x3f7d0c52, 0x3f7cb3df, 0x3f7c5699, 0x3f7bf483, 0x3f7b8da1, 0x3f7b21f6, 0x3f7ab188, 
    0x3f7a3c5a, 0x3f79c270, 0x3f7943d1, 0x3f78c080, 0x3f783882, 0x3f77abdd, 0x3f771a97, 0x3f7684b4, 
    0x3f75ea3b, 0x3f754b32, 0x3f74a79e, 0x3f73ff87, 0x3f7352f3, 0x3f72a1e7, 0x3f71ec6c, 0x3f713289, 
    0x3f707443, 0x3f6fb1a4, 0x3f6eeab2, 0x3f6e1f74, 0x3f6d4ff4, 0x3f6c7c39, 0x3f6ba44a, 0x3f6ac831, 
    0x3f69e7f7, 0x3f6903a2, 0x3f681b3e, 0x3f672ed2, 0x3f663e67, 0x3f654a07, 0x3f6451bc, 0x3f63558f, 
    0x3f62558a, 0x3f6151b6, 0x3f604a1e, 0x3f5f3ecc, 0x3f5e2fcb, 0x3f5d1d24, 0x3f5c06e2, 0x3f5aed11, 
    0x3f59cfbb, 0x3f58aeeb, 0x3f578aac, 0x3f56630a, 0x3f553810, 0x3f5409c9, 0x3f52d842, 0x3f51a386, 
    0x3f506ba2, 0x3f4f30a0, 0x3f4df28e, 0x3f4cb177, 0x3f4b6d69, 0x3f4a266f, 0x3f48dc96, 0x3f478fec, 
    0x3f46407c, 0x3f44ee55, 0x3f439982, 0x3f424212, 0x3f40e811, 0x3f3f8b8d, 0x3f3e2c94, 0x3f3ccb32, 
    0x3f3b6776, 0x3f3a016e, 0x3f389927, 0x3f372eaf, 0x3f35c214, 0x3f345365, 0x3f32e2af, 0x3f317001, 
    0x3f2ffb69, 0x3f2e84f6, 0x3f2d0cb6, 0x3f2b92b7, 0x3f2a1709, 0x3f2899b9, 0x3f271ad8, 0x3f259a73, 
    0x3f241899, 0x3f22955a, 0x3f2110c4, 0x3f1f8ae6, 0x3f1e03d0, 0x3f1c7b91, 0x3f1af237, 0x3f1967d3, 
    0x3f17dc72, 0x3f165025, 0x3f14c2fc, 0x3f133504, 0x3f11a64e, 0x3f1016e9, 0x3f0e86e5, 0x3f0cf651, 
    0x3f0b653c, 0x3f09d3b7, 0x3f0841d0, 0x3f06af97, 0x3f051d1d, 0x3f038a6f, 0x3f01f79e, 0x3f0064ba, 
    0x3efda3a4, 0x3efa7dec, 0x3ef7586a, 0x3ef4333d, 0x3ef10e86, 0x3eedea63, 0x3eeac6f2, 0x3ee7a455, 
    0x3ee482a8, 0x3ee1620c, 0x3ede429f, 0x3edb2480, 0x3ed807cf, 0x3ed4ecaa, 0x3ed1d32f, 0x3ecebb7e, 
    0x3ecba5b5, 0x3ec891f3, 0x3ec58056, 0x3ec270fd, 0x3ebf6406, 0x3ebc598e, 0x3eb951b5, 0x3eb64c99, 
    0x3eb34a56, 0x3eb04b0c, 0x3ead4ed8, 0x3eaa55d6, 0x3ea76026, 0x3ea46de3, 0x3ea17f2c, 0x3e9e941e, 
    0x3e9bacd4, 0x3e98c96d, 0x3e95ea04, 0x3e930eb6, 0x3e9037a0, 0x3e8d64dd, 0x3e8a968a, 0x3e87ccc2, 
    0x3e8507a1, 0x3e824743, 0x3e7f1784, 0x3e79aa74, 0x3e74478b, 0x3e6eeeff, 0x3e69a105, 0x3e645dd0, 
    0x3e5f2596, 0x3e59f88a, 0x3e54d6df, 0x3e4fc0c8, 0x3e4ab678, 0x3e45b820, 0x3e40c5f2, 0x3e3be01f, 
    0x3e3706d7, 0x3e323a4b, 0x3e2d7aab, 0x3e28c824, 0x3e2422e6, 0x3e1f8b1e, 0x3e1b00fb, 0x3e1684a9, 
    0x3e121654, 0x3e0db62a, 0x3e096453, 0x3e0520fd, 0x3e00ec51, 0x3df98cef, 0x3df15f37, 0x3de94fc9, 
    0x3de15ef5, 0x3dd98d0a, 0x3dd1da56, 0x3dca4724, 0x3dc2d3c0, 0x3dbb8073, 0x3db44d87, 0x3dad3b42, 
    0x3da649eb, 0x3d9f79c6, 0x3d98cb17, 0x3d923e20, 0x3d8bd322, 0x3d858a5c, 0x3d7ec81a, 0x3d72c0e4, 
    0x3d66ff8d, 0x3d5b8488, 0x3d505049, 0x3d45633d, 0x3d3abdd2, 0x3d306070, 0x3d264b7e, 0x3d1c7f61, 
    0x3d12fc79, 0x3d09c324, 0x3d00d3bf, 0x3cf05d41, 0x3cdfa83e, 0x3ccf891c, 0x3cc00079, 0x3cb10eef, 
    0x3ca2b513, 0x3c94f373, 0x3c87ca96, 0x3c767600, 0x3c5e8a59, 0x3c47d325, 0x3c325144, 0x3c1e058c, 
    0x3c0af0c6, 0x3bf2275e, 0x3bd0ddef, 0x3bb2068a, 0x3b95a260, 0x3b776514, 0x3b487014, 0x3b1e6790, 
    0x3af29a52, 0x3ab2449b, 0x3a77a0f6, 0x3a1e8019, 0x39b25423, 0x391e863b, 0x381e87c4, 0x00000000
};

static const uint32_t _K11[] = {
    0x00000004, 0x00000006, 0x00000008, 0x00000009, 0x0000000b, 0x0000000d, 0x0000000f, 0x00000012, 
    0x00000014, 0x00000016, 0x00000019, 0x0000001c, 0x0000001f, 0x00000022, 0x00000025, 0x00000029, 
    0x0000002d, 0x00000031, 0x00000035, 0x00000039, 0x0000003e, 0x00000043, 0x00000048, 0x0000004e, 
    0x00000053, 0x0000005a, 0x00000060, 0x00000067, 0x0000006e, 0x00000076, 0x0000007f, 0x00000087, 
    0x00000090, 0x0000009a, 0x000000a5, 0x000000b0, 0x000000bb, 0x000000c7, 0x000000d4, 0x000000e2, 
    0x000000f1, 0x00000100
};

static const uint32_t _K18[] = {
    0xbb55207b, 0x3a670118, 0x3a86b002, 0xbb12c19e, 0xba5fb5c7, 0xb9c1fc4f, 0xbb1bfc97, 0xba402765, 
    0xbb3d49de, 0xbaa4bf3b, 0xbb56812c, 0xbb832591, 0xbb03658a, 0xbad0ba24, 0x39a2b232, 0xbb0dd15c, 
    0xba801e5e, 0xbbc16aac, 0xbbcae409, 0x39ab88b3, 0x394ab9aa, 0xba594941, 0xbb8b511f, 0xba98f809, 
    0xbaf8508d, 0xbb549425, 0xb9791fac, 0xb89c8842, 0xbaf228b6, 0xba80e065, 0xbb015088, 0xbbeada4b, 
    0xba15652c, 0x3a3099af, 0xbbb77512, 0xbccc8d0e, 0xbca029d3, 0xbbed383b, 0xbb86f6b7, 0xbbbcaeb4, 
    0xba9ebc4a, 0x3ae0372d, 0x3b4b06f7, 0x39d4e879, 0x3a990056, 0x3a057c07, 0xba8f9c7d, 0xba337ced, 
    0x3a8c0f92, 0x3adb9f84, 0xbb3754ed, 0xbb86d12d, 0xbae418be, 0xba15d548, 0x3b1efbe2, 0xb8a3bc9a, 
    0x3b1a5831, 0xba7bdae9, 0xbb669075, 0x3b3b40f3, 0x3af22e39, 0x3b0b4a66, 0x3a8ef5b2, 0x3b1aa214, 
    0x3b456ba2, 0x3ad86b62, 0x3b569195, 0x3be16ef3, 0x3b92a021, 0x3b3648a4, 0x3b7cd879, 0xbb2699c1, 
    0x3b2a22b3, 0x3b2c43b7, 0xbb930172, 0xbcbc4fbe, 0xbcabaa28, 0xbbc7ead4, 0xb9694fd2, 0xbb9f1f11, 
    0xb8d02e5c, 0x3b8d7313, 0x3aa293c5, 0xbae45a64, 0x3b143079, 0x39a858ea, 0x3ae63bf2, 0xb892a7bb, 
    0x3b366e13, 0x3b9ff9fb, 0x3a806597, 0xb9f4d2aa, 0x3a53dba2, 0xba9a041f, 0x3b4b73e4, 0x3b5e6d85, 
    0x3b1ed3ab, 0xbaa68a2f, 0xbb465ab9, 0x389bfc3b, 0xbb2ef702, 0xbad5d38e, 0xba9e9efe, 0x3a1735a7, 
    0x3ab769bc, 0x3a005c26, 0xbaef074b, 0x3b0c005c, 0xba0a5a8b, 0xbb51ba82, 0xbb1ce497, 0xbbf4a925, 
    0xbb9bc1f8, 0xbbac5474, 0xbc130811, 0xbcec75c4, 0xbccd90e4, 0xbc2c83dd, 0xbb988938, 0xbc2d1532, 
    0xbc8c92db, 0xbd308fa5, 0x3c80b1d9, 0xbc551cec, 0xbb3652b9, 0x3cb38c5d, 0xbcd73dd2, 0xbd1276d9, 
    0xbc7306a7, 0x3d155388, 0xbc579b9a, 0x3cdaf206, 0x3b2383b9, 0xbd3323c6, 0xbde091cb, 0xbd3e7cbb, 
    0xbc75a1fc, 0x3c8d79bf, 0xbdad0001, 0xbdbf1302, 0xbd07444d, 0x3b84cef5, 0xbd104c52, 0xbdd2386b, 
    0xbe02ab43, 0xbdafb97d, 0xbd39d6c4, 0xbda728ce, 0xbcd43d5c, 0xbd8a028f, 0xbd2c3b04, 0xbda4a99e, 
    0xbe128c0e, 0xbe072dc8, 0xbdf1ca36, 0xbe1c0f5e, 0xbd968901, 0xbe121762, 0xbde01b3e, 0xbdd110f1, 
    0xbcb464d7, 0xbd4c878d, 0x3b717179, 0x3c3f2e98, 0x3ca5d377, 0x3d059ea6, 0xbbce3110, 0xbce0701d, 
    0xbc0b4071, 0x3d848b86, 0xbb2a289c, 0x3a2d5a6e, 0x3c72b2d1, 0xbd6666c6, 0xbd88c484, 0x3d0bcd30, 
    0x3d28e664, 0x3da7ebdb, 0xbc9845da, 0xbd1c4293, 0xbc01d28a, 0x3d93562b, 0x3c987b46, 0xbcbf33a8, 
    0x3c37c18b, 0x3c363012, 0xbbc6fcb4, 0xbcbd1319, 0xbb90b62c, 0x3c2e3193, 0x3d67073c, 0xbd78e923, 
    0xbdee741d, 0xbddc40a1, 0xbd8cf902, 0xbe05232e, 0xbd9ec216, 0xbd6b04cb, 0xbc03667b, 0x3dde2612, 
    0x3d4700a0, 0x3d091b31, 0x3cef0f5e, 0x3d8b6d4b, 0x3cd3721f, 0x3d678ea4, 0xbc65c034, 0xbd3b1499, 
    0x3b9155f2, 0x3d5669cc, 0xbce8542b, 0xbc9eb0b3, 0x3cefbda6, 0xbcc439c6, 0x3c036d38, 0x3d46a56a, 
    0x3d901146, 0x3d8ebfb5, 0xbbbb84fd, 0x3cd3071c, 0x3da9c6ae, 0x3e22465f, 0x3d7bdfe1, 0x3d85b6d1, 
    0x3dcae77d, 0x3dd155e4, 0x3d921572, 0x3d713d7b, 0x3da26f63, 0x3dc2f20a, 0x3dfc794d, 0xbcb13c75, 
    0xbd050517, 0xbd1cecb2, 0xbb5e2889, 0x3d15873d, 0x3da4b50e, 0x3d1ae9d4, 0x3df678ff, 0x3e818e3e, 
    0xb8f937f0, 0x3d4234c3, 0xbbb76f62, 0xbcda8305, 0xbce8f5a8, 0xbcc771ce, 0xbc4e3198, 0x3cd7fcb1, 
    0xbc2d5262, 0x3c33fded, 0x3b363b6b, 0x3ca98cfa, 0xbc88dea4, 0xbd7e6cbb, 0xbd1909b9, 0xbcb18eb2, 
    0x3cbb5564, 0x3cd0288a, 0x3b861d54, 0xbe010316, 0x3d7e8056, 0x3d6c632d, 0xbd880c56, 0xbe22f380, 
    0xbe04aec0, 0x3d2641ea, 0xbd23a923, 0xbcc27b9f, 0xbd8678a1, 0xbd7a0e1a, 0xbd2e3fce, 0xbbac5b2d, 
    0xbe877765, 0xbe266b2b, 0xbdedbdc6, 0x3de3e712, 0x3dfd844d, 0xbe09d63c, 0xbe9a3123, 0xbdbf9c5e, 
    0xbc038700, 0xb9827305, 0x3c40a1e1, 0x3b9351d4, 0x3c156544, 0xbc19001d, 0xbccd275d, 0x3cee9dbd, 
    0x3cc22064, 0xbb05f141, 0xbb0716f2, 0xbcdef5a1, 0xbc1456cc, 0xbd0f9fa9, 0x3c246b82, 0x3d4d5e83, 
    0x3d7f5250, 0x3daea67e, 0x3d06c2d7, 0xbd43e3bf, 0x3e113ded, 0x3e0b24f9, 0x3d149236, 0xbda56542, 
    0x39b60de1, 0x3dfc84c2, 0x3d41a1e0, 0x3d84e80a, 0xbd953a06, 0xbce90a6b, 0x3d97f695, 0x3d1cebe7, 
    0xbe653c20, 0xbe226d18, 0xbdeaa0fc, 0x3df49cbb, 0x3e186059, 0xbdcd671e, 0xbe71db1b, 0x3d304b97, 
    0x3d332f8c, 0x3da5b90f, 0x3da20864, 0x3dd34079, 0x3ce25777, 0xbcf269c2, 0xbd2b2253, 0x3b974906, 
    0x3bafa312, 0xbc97d2c6, 0xbdcb1fb5, 0xbe0853e7, 0xbd8e073b, 0xbd684183, 0x3d039f7b, 0x3d768c94, 
    0xbc40f90a, 0xbcb752ad, 0xbd38aab6, 0xbcfae390, 0x3e3eaeef, 0x3e52ef06, 0x3d96c829, 0xbcd99d63, 
    0x3d9b44ce, 0x3e362873, 0x3db11537, 0x3e048191, 0x3d29bc98, 0x3d87e6c3, 0x3e2c01ec, 0x3daaec06, 
    0xbd5e8cfc, 0xbc273080, 0xbd119999, 0x3e915fdc, 0x3e88970c, 0x3d7e4793, 0xbe1e0fe7, 0x3e0002bd, 
    0x3afa7245, 0x3a26237e, 0x39bf49c3, 0x3aa4b344, 0x3ab2609e, 0x3aec92e5, 0x3ae91557, 0x3abac8ad, 
    0x3aeef9c8, 0x3b151640, 0x3b2af1a0, 0x3a9e2ca9, 0x3ac63ac4, 0x3a13d027, 0x3aa45874, 0x3aa05fdd, 
    0x3ae23304, 0x3998ee78, 0x38314fde, 0xb9fc641e, 0xba4f57d0, 0xb99e0f53, 0x3a49c39e, 0x3a13014e, 
    0x3a2c8095, 0x39d6cdb6, 0xba3c5fab, 0xba583d0f, 0xba9f7867, 0x36b531c9, 0xb9a5aa9c, 0xb9831cb5, 
    0xba93d6d0, 0xba827253, 0xb8bc72b4, 0x3af0bc1c, 0x3b164bb8, 0x3a9681a8, 0xb9a195bc, 0xba2c2b12, 
    0x3b09130d, 0x3aa06947, 0xb93ee394, 0xb902ef3c, 0x3a25e4d7, 0x3aa547aa, 0x3adeec73, 0x3b0b3e72, 
    0x3b00012e, 0x3af6c88c, 0x3b2b292e, 0x3a5d3226, 0x3a8b87f5, 0x39c15dd1, 0x3a74fd00, 0x3a9ceb77, 
    0x3ac96994, 0x373b1cd1, 0x3a1e0e75, 0x385c8ce7, 0xb8f9d7e6, 0xb9e3009b, 0x39bc6b04, 0x39543fb5, 
    0x3a272ed7, 0x39c8be44, 0xba521fc4, 0xba8da4a4, 0xba95543e, 0xb8baef1f, 0xb9bf9fab, 0xb9338f5d, 
    0xba4d0bfb, 0xbaaf5b53, 0x37211939, 0x3adb142e, 0x3b3dad41, 0x3acc1519, 0xb98eec7c, 0x38a78f81, 
    0x3af9b44d, 0x39b44fa6, 0xba730806, 0x3a23190b, 0x3a5be7b4, 0x3a6d9c6e, 0x3ab46b83, 0x3b187027, 
    0x3aaaf347, 0x3ae4dc6f, 0x3b30f1c8, 0x3ac0f959, 0x3ad4faeb, 0x3a5a4ef7, 0x3ad106dd, 0x3ae92633, 
    0x3ad2ddb2, 0x39fed1b8, 0x3a53fcad, 0x39f9b254, 0xba14b0ea, 0xb96dbebe, 0xb9813f1a, 0x3a236a5f, 
    0x396d6275, 0x3982cc37, 0xb9483569, 0xb9d74621, 0x383e7efd, 0xb8954dca, 0x373cea13, 0x3944f4a9, 
    0xb9d39b14, 0xba817afc, 0x3a1542d0, 0x3b11c4e7, 0x3b184165, 0x3a9d9141, 0x39e3fb56, 0x3890cdc5, 
    0xbbddeec4, 0x39ff8662, 0xbc175f3b, 0xbc54533f, 0xb9d9b7b3, 0xbb782948, 0x3931aaf0, 0xb9cf42f7, 
    0x3a380db8, 0x39adcc14, 0x3bdaff14, 0xbbf9ad12, 0xbc40e27e, 0xbc71d15c, 0xbc8efe1c, 0xbbb05302, 
    0xbbc01a19, 0xbbd3e0b0, 0xbcd4d6d5, 0xbcfb730e, 0xbca01bc8, 0xbd195bf2, 0xbcbc703c, 0xbc124534, 
    0x3b67e631, 0x3b9db738, 0x3c8f8a9c, 0xbc8f357a, 0x3c283610, 0x3bcb0460, 0xbbfe6fe3, 0xbd09648d, 
    0xbc14ffd3, 0x3d02fda3, 0xbc0ec07f, 0xbd443b60, 0xbc4c1f31, 0xbc7dd0bc, 0xbc16a09f, 0x3c2a9c71, 
    0xbb942bc9, 0x3b86cdcf, 0xb91fd14e, 0xbb086986, 0x3be89f3e, 0x3b30c187, 0x3ba7143f, 0x3b899d02, 
    0x3bd90f6f, 0x3bc2efb8, 0x3c21c6ba, 0x3b5aff8f, 0xbc03d25d, 0xbc827dd2, 0xbc7b601b, 0x3ae1fcb6, 
    0x3b9a3285, 0x3bca0479, 0xbca935ba, 0xbc77c066, 0xbb06e179, 0xbca898de, 0xbc57bb99, 0x3be8b22d, 
    0x3c22a181, 0x3c1893fc, 0x3ca51fad, 0xbc4f8969, 0x3c994839, 0x3b805095, 0xbc24d909, 0xbcd7f722, 
    0xbbe1b771, 0x3d1075de, 0xba78156e, 0xbd3f978a, 0xbc9872db, 0xbc392667, 0xbb889286, 0x3cbd9f5c, 
    0xbc3b2141, 0xbb7d12b3, 0xbb8fb8ee, 0xbbae5f87, 0x3c00e49d, 0x39c17521, 0xba5a568e, 0xbb6fa566, 
    0xbbebd8ac, 0x39f85efa, 0x3b1e93e6, 0xbbb2ae5c, 0xbc204d6d, 0xbcb6060a, 0xbc88a7cf, 0xba478b26, 
    0x3bf9deba, 0x3c01d9b3, 0xbcc5e6bc, 0xbb636288, 0x3c8b6548, 0xbbc6ac63, 0xbc1f7584, 0x3ca037cd, 
    0x3c857672, 0x3c1b0a75, 0x3cbe9832, 0xbc334bd9, 0x3c93fda3, 0x3bb46fca, 0xbc144909, 0xbcbbfbe6, 
    0xbbfc3d54, 0x3d04845a, 0xbc100b4b, 0xbd039b32, 0xbc4eb8b9, 0xbc0af69d, 0x3b7867e2, 0x3cefc5ed, 
    0xbcf97c8b, 0xbd1fdf5a, 0x3c6fc831, 0xba484326, 0xbbb08f70, 0xbc07114c, 0xbd893d7e, 0x3cd612ad, 
    0x3c89b1c8, 0x3c71999d, 0xbabc9504, 0x3cb83663, 0xbc914fac, 0xbc7e2d83, 0xbd64f350, 0xbd5f587f, 
    0xbc054f8e, 0xbcd4a038, 0xbd4e22da, 0xbd6f0d52, 0xbdf654ff, 0xbdab24d4, 0xbd8554b6, 0xbd20af0a, 
    0xbd6ffeec, 0xbdeb4347, 0xbc044c5b, 0x3c0b4175, 0xbc31b65e, 0x3c73b995, 0x3cc72bfd, 0x3c7ac89b, 
    0x3d8656b4, 0xbcada3f9, 0x3b89779e, 0xbc59c831, 0xbd6d11bf, 0x3c9b8335, 0xbaa37868, 0xbc973b77, 
    0xbaabdb3f, 0xbc5866ff, 0x3c8aeaf1, 0x3d25ccf7, 0x3a5280b2, 0xbc5f59f3, 0xbd60c57d, 0x3ca5f32c, 
    0x3b7e75dd, 0x3c1bef5b, 0x3ccd26db, 0x3d23a1a2, 0xbb99d61d, 0x3bf8acff, 0xbd5548db, 0xbd60f07d, 
    0xbcbd9b0a, 0xbcb91d61, 0xbdb19c31, 0xbd83be40, 0xbdaa99c4, 0xbd9487c6, 0xbd880196, 0xbca7b4d2, 
    0xbcbdd0f0, 0xbd807705, 0x3c905b93, 0x3d28ddc6, 0x3c3bb64e, 0x3d11ce2f, 0x3d182f44, 0x3cf7de33, 
    0x3dcbb160, 0x3b67086f, 0x3d08fac8, 0x3c3525f7, 0xbbe977df, 0x3d846b3e, 0x3d3ba685, 0x3caa98bd, 
    0xbc0f90ae, 0x3b8235f1, 0x3d4dbf93, 0x3c8119e4, 0xbb2a6dc7, 0x3c6829f2, 0xbcfafe47, 0x3d3048f6, 
    0xbc98b50f, 0xbb5d52f7, 0x3cfd189e, 0x3d4e86d7, 0x3d52ab53, 0x3cc13e9c, 0xbd175666, 0xbd21d18d, 
    0xbb2e75a3, 0xbc3a61cc, 0xbd765da9, 0xbd20109b, 0xbd070407, 0xbcee22ee, 0xbd5d7bf0, 0xbd1164d4, 
    0x3cae8b17, 0xbca1140c, 0x3da025cd, 0x3d9e1b74, 0x3c447f43, 0x3d99f1e6, 0x3dc25605, 0x3d7edc72, 
    0x3e1065ca, 0x3d177d39, 0x3dc55fb1, 0x3db49a86, 0x3da4d4b9, 0x3e1cb5c0, 0x3db36115, 0x3dceb0c8, 
    0xbd441747, 0xbd9f5898, 0x3974c62f, 0x3df2662f, 0x3b6ac77d, 0xbc1c11db, 0xbce391e4, 0xbd0e2964, 
    0x3c0174e3, 0xbcc2502d, 0xbcad46fd, 0xbced2513, 0xbd05119c, 0x3de3ac97, 0x3e304122, 0x3d1e7d0e, 
    0xbd763484, 0xbe1fda81, 0xbcaedb1a, 0x3e308fdf, 0xbcec3ad4, 0x3e144c97, 0x3e8d5e95, 0x3e0611bf, 
    0x3d8ff6c9, 0x3dbb347b, 0xbcf292d8, 0xbda663da, 0x3d3eebba, 0xbc6eaade, 0xbd0b1a98, 0xbccdfd6b, 
    0xbe012266, 0xbb73f684, 0xbdd482c1, 0xbc31b818, 0xbd9cdb69, 0xbda15c7d, 0x3e219c6e, 0x3e07d1ad, 
    0xbbbca490, 0xbcecf263, 0x3d502923, 0x3df42f7e, 0x3d3107ef, 0xbc7a5a09, 0xbcf13d57, 0xbca124d8, 
    0x3d121b07, 0xbcd5da14, 0xbd3877a2, 0xbcc67994, 0x3bdc0804, 0x3e1ad0b7, 0x3e4a7799, 0x3d8d1012, 
    0xbd8e4162, 0xbe0b5ec2, 0x3cfb7cf9, 0x3e2ad29a, 0xbd036f78, 0x3e339c16, 0x3e8061ee, 0x3dd54808, 
    0x3d827e4f, 0x3e092af6, 0x3bcc2d07, 0xbd117459, 0x3ddf8400, 0xbb9a84d3, 0xbd51252d, 0xbcfa9a33, 
    0xbde49d56, 0xbc750676, 0xbdd2fc74, 0x3da16c6d, 0xbc4cf7ea, 0xbd0e5705, 0x3e52d4d5, 0x3e27090e, 
    0xbd543cda, 0xbd1ae2be, 0xbbb1a77e, 0x3dbf87cf, 0x3d53a6ef, 0xbc381be6, 0xbca7f417, 0xbca26f61, 
    0x3ca04e1c, 0xbc735dc0, 0xbd2445cb, 0xbdb0c174, 0xbd95847c, 0x3d9d8e81, 0x3dc18090, 0x3cd88b24, 
    0xbdc3205f, 0xbe5c20f1, 0xbd4fe01c, 0x3cdbd9af, 0xbe41d64c, 0xbd0595d9, 0x3e0b51a3, 0x3d86270a, 
    0xbcfb0e76, 0x3cc25d10, 0xbd9374f6, 0xbdc014ae, 0x3d0afba3, 0xbd9b1c3c, 0xbdee0d1f, 0xbd5402c6, 
    0xbe14829e, 0xbcc05e05, 0xbe02ef85, 0x3b37e4d5, 0xbd9f29cd, 0xbdb3863d, 0x3deb82e6, 0x3d848a92, 
    0x3d11cdd1, 0x3ca1b114, 0x3cd5fb0d, 0x3d67627a, 0x3d10fe76, 0x3d3a523f, 0x3cdaba10, 0x3d11e308, 
    0xbb6fd223, 0x3d06e859, 0x3ce937a1, 0x3ceec143, 0x3cd3febe, 0x3bb85558, 0xbc41d55a, 0xbbb0f3e5, 
    0x3bed398c, 0x3cb247b5, 0x3c8c07ac, 0x3c45f339, 0x3bb52108, 0x3c621119, 0x3c9a75a9, 0x3c06acc0, 
    0x3d22093a, 0x3d13e2df, 0x3c6fd069, 0x3d081f85, 0x3ae8de06, 0x3bcdb1da, 0x3c87ab73, 0x3c9d6165, 
    0x3c9c5379, 0x3b82c07b, 0xbbdf3f5a, 0xbcbdd5bf, 0x3a848dbe, 0x3c04a593, 0xbb517341, 0xbd235dce, 
    0x3d37405a, 0x3d320d0a, 0x3d3af5e3, 0x3d38cce1, 0x3cb4e4bd, 0x3d29d94c, 0x3cb1ff09, 0x3bbd3c61, 
    0x3be122b7, 0x3d0e8b66, 0x3c2217ac, 0x3cf55573, 0x3cfbcf76, 0x3cc9b0d8, 0xbc1d053c, 0xbc1446b8, 
    0xbc2ebd9e, 0x3c2ebe22, 0x3c9bd990, 0x3c37d69f, 0x3bf91c21, 0x3c7b3d7f, 0x3c4e1f96, 0x3b341812, 
    0x3cc2dc09, 0x3cdb196a, 0x3bd59c88, 0x3c39f691, 0x3b99ceb5, 0xbb35ede9, 0x3bd00727, 0x3afed039, 
    0x39ab7106, 0xbae1b710, 0xbc45f9fd, 0xbd283b2f, 0xbb867156, 0xbb316a28, 0xbc28da36, 0xbd67b799, 
    0x3ce8edc4, 0x3c93eb7d, 0xbb38cf04, 0x3c8e7088, 0x3cc3a61a, 0x3d0f5fc6, 0x3c83d042, 0xbb5e2379, 
    0xbad6729b, 0x3c0874f0, 0x3b990c9e, 0x3c14b12d, 0x3c2c20f3, 0xbb489c60, 0xbd20195e, 0xbcf3e725, 
    0xbd0a4cab, 0xbccdf147, 0xbcb0a599, 0xbc434095, 0xbcfece2a, 0xbccbd1f3, 0xbcc6be41, 0xbc1295c9, 
    0xbc22ba7f, 0xbcc065ae, 0xbd1bcb7a, 0xbcde5acf, 0xbcec1470, 0xbd19f921, 0xbd26a863, 0xbcebd2f1, 
    0xbcfba7ea, 0xbccd8887, 0xbd17777f, 0xbd97e16c, 0xbd1fc4af, 0xbd1cdd09, 0xbd2f66d3, 0xbdbe52ea, 
    0x3d2822e4, 0xbcbdbc47, 0x3ca865fb, 0x3ca4f0c1, 0x3c27277e, 0xbbdaaaec, 0x3cb7a2a0, 0xbc12863e, 
    0x3bc7b096, 0x3d166f17, 0xbc2c35dc, 0xbb6fa376, 0xbbc2caf3, 0xbcd5fbb2, 0x3c2f39bb, 0xbc053bea, 
    0xbc6afd2f, 0xbc7205fd, 0x3c73daeb, 0xbce58fa2, 0xbd0b4ca6, 0x3d4f7924, 0x3d7834e3, 0x3b91d76e, 
    0x3c4956a7, 0xbd6a3504, 0xbd8c95db, 0x3d4d40c1, 0xbd4d6e88, 0x3c71a068, 0x3d2142fa, 0x3d6aa8e9, 
    0x3c6bb97f, 0xbcfe56ba, 0x3c61aaf9, 0x3dbc0aac, 0x3dc03c75, 0x3c272b17, 0xbe0f09aa, 0xbe7610cd, 
    0x3d17b4b8, 0xbce202be, 0x3c35407a, 0x3cb7ede5, 0x3cc2843d, 0xbb5f3c6c, 0xb956fd26, 0xbc704bd6, 
    0x3c1ebe17, 0x3c64a50d, 0xbafb4b9c, 0xbc10d487, 0xbc64ce38, 0xbd1cbd7e, 0x3c9e538f, 0x3a25f867, 
    0x3b525219, 0xbc12b6ee, 0x3ce5b513, 0xbc5b2cbc, 0xbd427977, 0x3d1c196f, 0x3d60af24, 0x3bbb2484, 
    0x3af331d4, 0xbd701e71, 0xbd9ea328, 0x3d847559, 0xbcc8a13b, 0x3ca95e31, 0x3d137191, 0x3d6ad6e4, 
    0x3c7a6f08, 0xbc074423, 0x3cd6f137, 0x3dd48596, 0x3dd619f8, 0x3cc81734, 0xbdee8910, 0xbe5d3a91, 
    0x3d283b6c, 0xbca140e8, 0xbc0f3b47, 0x3c6cee11, 0x3b54a4e7, 0xbca97b4e, 0xbcf8244f, 0xbd30272a, 
    0xbc858abe, 0xbb1ded95, 0xbcf51a4d, 0xbcd17862, 0xbd1a8dbd, 0xbd515c99, 0x3bd1a2ec, 0xbc4b1ffa, 
    0xbd1cec3e, 0xbce08265, 0x3ce871d4, 0xbd3c2201, 0xbd619e76, 0x3d36d066, 0x3d1830c6, 0xbc9454ff, 
    0xbcbd0707, 0xbd8640d0, 0xbde5464b, 0x3d317ab4, 0xbd81f0c0, 0x3b282273, 0x3cdbda47, 0x3d8e2b3b, 
    0x3c466095, 0x3b5d001a, 0x3cdded80, 0x3de2aafa, 0x3de6d391, 0x3cd46550, 0xbdddb06f, 0xbe4adda5, 
    0x3d4a1b9b, 0x3d773813, 0x3c50470d, 0x3cd77fca, 0x3c8cd3cb, 0x3d575072, 0x3c2f93b1, 0x3c1d51fa, 
    0xbca0580e, 0xbc5bcf5d, 0x3dae81aa, 0x3d604121, 0x3d377cc5, 0x3d8cc03e, 0x3da69976, 0x3d833492, 
    0x3b5448e9, 0x3cd7b068, 0x3c86af0b, 0xbc9d0187, 0x3cfacfd3, 0x3d401159, 0x3c93a5ff, 0x3add69e8, 
    0x3c5f44c3, 0x3c389ecf, 0xbbae1aeb, 0xbd0c6d49, 0xbc9a3c90, 0x3d2b7872, 0x3bd4c1f2, 0xbceb9432, 
    0xbd125e8d, 0xbc42e5d3, 0x3c9fe0db, 0x3d09231f, 0x3d962415, 0x3d9d4b3f, 0x3d673601, 0x3d76738e, 
    0x3c9b0019, 0x3cd970de, 0xbd222b95, 0xbcb47ee6, 0xbce0108c, 0x3d085a53, 0xba18e26a, 0x3c78b964, 
    0xbb23d375, 0x3bec2b1f, 0x3d7498bd, 0x3cba8e32, 0xbb51887d, 0x3b8c2074, 0x3d1e8e38, 0x3d0a46bc, 
    0xbc8ebb8e, 0x3b8ef412, 0xbca03389, 0xbd3e2e82, 0x3a955241, 0x3c6cb812, 0x3d04f61c, 0xbbaeb777, 
    0x3c7ff2f5, 0x3bf25d07, 0xbc8e9efb, 0xbd1a9a20, 0xbca8efac, 0x3cb7e1ec, 0xbc1993c8, 0xbca4d24b, 
    0xbccf50f0, 0xbc20e1c4, 0x3c9c4d3a, 0x3c176164, 0x3d492702, 0x3d17f137, 0x3cb4ba0c, 0x3d1057aa, 
    0xbd50a25b, 0xbd119312, 0xbdd5a38b, 0xbd860d41, 0xbd15050b, 0x3a9aab81, 0xbca184cb, 0xbb5f8253, 
    0xbc4f2058, 0x3c25e9d0, 0x3cd34a74, 0xbc9ebc74, 0xbcbd423c, 0xbd2cfeab, 0xbb3ab24c, 0xbba4f032, 
    0xbcea2e79, 0xbcd5fdcd, 0xbd5477c0, 0xbda14ffa, 0xbd3b02a2, 0xbd2eadab, 0xbc79fd5a, 0xbd529879, 
    0xbd016908, 0xbcde7ea0, 0xbd20cf92, 0xbd930a74, 0xbd3bb505, 0xbcdf3dfc, 0xbcf57337, 0xbd4932ae, 
    0xbd7054cb, 0xbd4aeef3, 0xbc1ca4e2, 0xbbe0e180, 0x3cf5908d, 0x3cb14811, 0xbc2bf16b, 0xba9a4acc, 
    0x3c2084aa, 0x3d33e800, 0x3cdfae9b, 0x3d947cde, 0x3ce72e39, 0xbb6d6451, 0x3bf0ff2b, 0x3c782104, 
    0xbd9a119c, 0xbccde3ed, 0xbd3a110f, 0xbd5af1a8, 0xbc6d3377, 0xbcb8c446, 0xbbba56df, 0xbd837a4e, 
    0x3c61bb40, 0x3c73bf32, 0xbde95cb7, 0x3d486683, 0x3d7f4db5, 0x3d698a7b, 0xbd11d595, 0xbcc654c8, 
    0x3d12e94f, 0x3d05dff6, 0x3c82219a, 0x3db35d16, 0x3d3b00c9, 0x3d5a4263, 0x3e1c2a3c, 0x3dc80617, 
    0x3e86e480, 0x3e1d9db9, 0x3df04b2a, 0xbe35bafa, 0xbe5b4931, 0xbd355cc6, 0xbc90a0b8, 0xbd720868, 
    0xba3c9901, 0x3c9a5389, 0x3da2d805, 0x3d39e2c1, 0x3bb7ea1b, 0xbd1ff9c0, 0xbd519a7c, 0xbca2cbb0, 
    0x3c91dfd5, 0xbb974279, 0xbdc01040, 0xbdc40641, 0xbc7e8b7a, 0xbbef239a, 0xbce4b49b, 0xbd927c87, 
    0x3d95b166, 0x3cfda542, 0xbd1f398f, 0x3da7312a, 0x3d27c444, 0x3db075ab, 0xbbff2578, 0xbbcd28e3, 
    0x3d99d92f, 0x3ded345c, 0x3dda117d, 0x3e3e142a, 0x3e00bd90, 0x3e207c51, 0x3e348ffd, 0x3e179ab2, 
    0x3e9e4ebe, 0x3e2440c2, 0x3dce28f5, 0xbe088792, 0xbe07b9c3, 0xbc89fd4a, 0xbc53076d, 0xbe011130, 
    0x3d285f59, 0x3e08bd4f, 0x3c236bda, 0x3cac062a, 0x3dbb2ad0, 0xbc2bfc84, 0xbb96ae62, 0xbbab5254, 
    0x3d5d6818, 0x3ca15342, 0x3b92d72e, 0x3cd8bbf2, 0x3c3f13ec, 0x3cf38dbf, 0xbca744bc, 0x3d24c929, 
    0x3d4d6b57, 0xbc100602, 0xbd79adb0, 0xbd915285, 0xbe1c09ff, 0xbd9a9ed2, 0xbc84bc11, 0x3d07e061, 
    0xbc1924b3, 0x3c9687a4, 0xbca18c2d, 0x3d7e052e, 0x3d4793d8, 0xbacf5941, 0x3c4ad158, 0xbcbe9ee6, 
    0x3dc87d96, 0xbc97431e, 0xbd032845, 0xbec63887, 0xbed1d0fb, 0xbe481c52, 0xbdfc2933, 0xbe94627b, 
    0x3b3f8bbf, 0x3b39b716, 0x3b2060e5, 0x3a340bb3, 0x3af670fc, 0x3b1e829f, 0x3ad87c39, 0xba5758e8, 
    0x3aa4fe0e, 0x3b3addd8, 0x3b43413d, 0x3ad4627b, 0x3b32060d, 0x3b0ed3e3, 0x3a87367f, 0x3a575942, 
    0x3a82c523, 0x39c24573, 0x3a463c80, 0x3b00d001, 0x3aedd4df, 0x3b165936, 0x3b56483a, 0x3aaa593d, 
    0x3ab9e406, 0xb9df19a1, 0x3a16cf48, 0x39c9fc46, 0xb956bf0f, 0x399992dc, 0xba560020, 0xba6b1ea2, 
    0xbac2f407, 0xba74f8b5, 0xbaa79e9f, 0xb90d1828, 0x3ac710c7, 0x37c70d0d, 0xbaca631d, 0xbb803456, 
    0x3b088489, 0x3a7bba69, 0x3b1b2f1a, 0x3b1211fc, 0x3b6d430b, 0x3ab14e21, 0xba35c4d9, 0xbaabc4b5, 
    0x38ccbfbf, 0x3af315f6, 0x3b0d8e03, 0x3ad3f4c2, 0x3ad22342, 0x3b029e7d, 0x3b4e9b21, 0x3a1c768d, 
    0x3acc2f1e, 0x3a8edf8c, 0x3ae64545, 0x3b4387f6, 0x3a9b9637, 0x3adec776, 0x3b2de43d, 0x3b30e4ac, 
    0x3a3019fb, 0x3a70c2ed, 0x394fbbdc, 0x3a3fd8a7, 0x3a24ad54, 0x3a2ef8f3, 0xba29cd58, 0xb95906b5, 
    0xba8c2aed, 0xb974e235, 0xba341273, 0x3b108201, 0x3b2f38a7, 0x3af79ba6, 0xba8c8944, 0xbb3544cd, 
    0x3b4ef029, 0x3b10225d, 0x3ac2a87e, 0x3b1edb79, 0x3b8d5f6d, 0x3b2064d9, 0x3ad4e4d1, 0x3a7ede3b, 
    0x3ad707a9, 0x3b26f323, 0x3ba2e30a, 0x3aa26d72, 0x3b698050, 0x3b935b8f, 0x3b47f942, 0x3b2bfde3, 
    0x3a495a8e, 0x3acd2210, 0x3b1d06df, 0x3b3889bc, 0x3b32c9be, 0x3b99cf89, 0x3b786019, 0x3b358e5f, 
    0x3b6e031d, 0x3a2fdc74, 0x3ad8770f, 0x3b1d34e0, 0x3a37192d, 0x3af9833e, 0xba44b14c, 0x3a8fc142, 
    0xbadc8e1b, 0x39f07ea3, 0x3740e1f7, 0x3ad2cc1f, 0x3a8b3cd6, 0x3ae00ea4, 0xbaa32202, 0xbaf060f1, 
    0xbd8ce023, 0xbce2568e, 0x3d7f1bfb, 0xbce17f99, 0x3d4aba72, 0xbd0c4c41, 0xbc4a51d9, 0xbcd3e46f, 
    0x3d23037f, 0x3d129b62, 0xbd2e0a01, 0xbd06755f, 0xbd1bbb8e, 0x3b632820, 0xbc8ac55e, 0xbd03e20b, 
    0x3d6daa77, 0x3a962619, 0xbc00b226, 0x3d3c481d, 0xbbf67946, 0xbe380e0b, 0xbd85a2d5, 0x3dcc300a, 
    0xbbd4292a, 0xbd65f74e, 0xbce66cde, 0x3c98471b, 0xbdd344c5, 0xbbe20324, 0x3ca22f6a, 0x3d9c5381, 
    0x3d2b4301, 0xbda7abda, 0xbdd180bd, 0x3e22dce4, 0x3d0c31e6, 0x3cc78a4d, 0xbdac0fd3, 0xbdc86124, 
    0xbd4f0e2d, 0xbd322093, 0x3d7ea167, 0xbc910aa1, 0x3d935e73, 0xbc39aae8, 0xbb92b85d, 0x3b266c4a, 
    0x3d4df08e, 0x3cb27c4e, 0xbcdd296f, 0xbb91c151, 0xbc8edac7, 0x3ce99acf, 0xbc665337, 0xbcbeeeaf, 
    0x3da751b6, 0x3cb955ee, 0x3bcef280, 0x3c959993, 0x3d0dc993, 0xbe205844, 0xbd8d7de2, 0x3de18b5b, 
    0x3b7d7d6a, 0xbc5608eb, 0xbc0b0b4c, 0x3d4bcfd9, 0xbdbc20b3, 0xbc204294, 0x3d0bef98, 0x3dabae06, 
    0x3d995312, 0xbd558f12, 0xbda330f0, 0x3e3c9de8, 0x3d958c4f, 0x3da53281, 0xbd8b9221, 0xbd98bda2, 
    0xbd37c46a, 0x3b9a4f9b, 0x3da8b8eb, 0xbc901a96, 0x3d50d7fa, 0x3987a5de, 0x3c28864c, 0x3d3cb58a, 
    0x3d5a38d1, 0x3d8be28d, 0xbc418ad8, 0x3c824ccb, 0x3bdf0a42, 0x3d0de296, 0xbb2485a7, 0xbc4cee37, 
    0x3d69a75c, 0x3c5bbcc7, 0x3d352cda, 0x3d0b981e, 0x3d81be27, 0xbe17cce7, 0xbd83afee, 0x3dbea76b, 
    0x3d0b37fc, 0xbc3f77ac, 0x3c549b1d, 0x3d95605c, 0xbd982a06, 0x3ce65d23, 0x3d47ff02, 0x3da29880, 
    0x3dcf3de3, 0xbba44095, 0xbd5bb319, 0x3e5036ea, 0x3dd3b81e, 0x3db936ce, 0xbd873057, 0xbd78f92a, 
    0xbc3ed8b2, 0xbcdde16c, 0xbd432a56, 0xbc3e44c0, 0xbba1d068, 0xbc0c18fa, 0xbd3f7db2, 0xbc834525, 
    0xbc6c7b90, 0x3bd1d6c1, 0x3c65c2c8, 0xbb4b240c, 0xbc833c9b, 0xbd070884, 0xbd44f0ec, 0x3caa54c6, 
    0xbcc14f16, 0x3c312ee8, 0xbd08b897, 0xbd6056c1, 0xbda16049, 0xbd25cb81, 0xbd09b479, 0xbcbfab30, 
    0xbce9294d, 0xbd5f5ec8, 0xbca8c2eb, 0xbd63cae1, 0xbd0f565c, 0xbd0c0e3e, 0xbd89c7d5, 0xbd89ec06, 
    0xbd71108e, 0xbcc20e69, 0xbd178d0b, 0xbd9b4bde, 0xbd488947, 0x3aff4354, 0x3d7b4b20, 0x3d16fde1, 
    0x3cd5b4b6, 0x3ccbeaba, 0x3ca92eea, 0x3d31b067, 0x3cdb13e8, 0x3d1fd1f5, 0xbce79595, 0xbc8675bf, 
    0xbcc499ef, 0xbb985d42, 0x3d56cb9c, 0x3d855686, 0x3c11922b, 0x3c7f69cd, 0xbc076228, 0x3d926187, 
    0xbc081db8, 0x3d524a35, 0x3a498d08, 0xbc91e771, 0x3ac63cbd, 0x3c86c6a8, 0xbc038bbd, 0x3ab80e08, 
    0x3c1e52e0, 0xbccc7453, 0x3a5200eb, 0xbd68d120, 0xbd0d9dd1, 0x385e0f43, 0xbcfea8bb, 0xbd7ae285, 
    0xbda525c2, 0xbc0fd099, 0x3ba64468, 0xbd3ee435, 0xbb2f8879, 0x3d5de16f, 0x3ded89e4, 0x3dbcddb6, 
    0x3ca95496, 0x3d576bdc, 0x3d67d694, 0x3d71c3e8, 0x3c820e25, 0x3d5e0763, 0xbc7c5fd9, 0xbc893962, 
    0xbd48df9f, 0xbc226e00, 0x3da5bd99, 0x3d914384, 0x3c08f09d, 0x3c770478, 0xb9c59e24, 0x3d698a67, 
    0x3c102439, 0x3d7a024b, 0x3c391078, 0x3d160f0a, 0x3d89f7f5, 0x3d618461, 0xbca2f6b8, 0x3bff5ae9, 
    0x3cdfa202, 0xbbbce079, 0x3c8f901a, 0xbd4e257b, 0xbb3a6623, 0x3d01aae1, 0xbb71221a, 0xbd0d10d4, 
    0xbd036097, 0x3d31cfa0, 0x3d2cde31, 0x3cef0d81, 0x3d73635a, 0x3dbd2c7b, 0x3e1283c5, 0x3e005c93, 
    0x3cb2ef49, 0xbbfb7b69, 0xbd85ab00, 0xbc9be43f, 0xbcf3a27e, 0x3d2acd8f, 0x3ac4947e, 0xbc855026, 
    0xbcbef097, 0xbd4819b5, 0x3c99f3b0, 0x3be1ea7a, 0x3a38815d, 0xbd4d1c57, 0x3b9585b8, 0x3d86da4b, 
    0xbcb6715e, 0x3d2726d7, 0xbcebef58, 0xbdc9ee70, 0x3a729998, 0xbcd0becf, 0x3c99c12c, 0xba158bae, 
    0x3d467bb3, 0x3d61185f, 0x3aee0492, 0xbd64df10, 0xbd632b72, 0x3d290a6f, 0xbd131fe2, 0xbdb5f0a8, 
    0xbe1b2703, 0xbd7f3564, 0x3d413fff, 0x3dac18e6, 0x3e42c7b3, 0x3d835e20, 0xbd8a56f8, 0x3c85d003, 
    0x3d32ab43, 0x3d451b25, 0xbc122711, 0x3c373b17, 0xbc947c12, 0x3d4297bd, 0x3cded01f, 0x3b9b794b, 
    0xbbf9897d, 0xbcbbdd73, 0x3d42e40d, 0x3d18f39b, 0x3cff6b1a, 0xbd250d17, 0x3ce2b620, 0x3dac7f97, 
    0xbb0ec4ac, 0x3d60288e, 0xbbd8aa0f, 0xbdaf918c, 0x3d5e2f95, 0x3cff0bc1, 0x3d238c47, 0x3c9a5ec3, 
    0x3db08c25, 0x3da40ae5, 0x3d324251, 0xbd0cf963, 0xbc8b6446, 0x3d77b660, 0xbc180f31, 0xbdc49aef, 
    0xbe0dd9af, 0xbd0e3530, 0x3d60723a, 0x3dd62a02, 0x3e6306a8, 0x3db476e8, 0xbd3e580e, 0x3ba1283b, 
    0x3cc54452, 0x3cee1edd, 0xbced1758, 0xbc70406e, 0xbc6b1061, 0x3d7894aa, 0x3cf75f9e, 0x3c339adc, 
    0xbca23bee, 0xbc2e1810, 0x3d412751, 0xbc5e0df1, 0x3aec5ab5, 0xbd6a5d3d, 0xbcd3c3f0, 0x3d55fe97, 
    0xbc7ee76e, 0x3d2252a5, 0xbb195bac, 0xbdbba1c4, 0x3cac3e84, 0x3a8d2c96, 0x3d0e9308, 0x3c75c01b, 
    0x3d5d982d, 0x3d9c623f, 0x3cfef549, 0xbd50658b, 0xbd0e9d3b, 0x3d54e149, 0xbd107551, 0xbdfc39fe, 
    0xbe367327, 0xbd907eb6, 0x3d1ffec1, 0x3d7ee5a2, 0x3e430ab3, 0x3d4e4542, 0xbda2edef, 0xbcdf0f58, 
    0xbc14c4f1, 0xbc9719d4, 0xbcdcc479, 0xbd43985d, 0xbd1b0b44, 0x3b1f5dc2, 0xbc9c1878, 0x3c0b0ee5, 
    0xbc7b0941, 0xbaf0104f, 0x3d474284, 0xbc6615ee, 0xbcd6a73a, 0xbca8ea71, 0xbd23913e, 0x3c89e0bd, 
    0x3ce2f8c5, 0x3dd30a27, 0x3beab24a, 0xbb4de58f, 0x3cff0bb3, 0x3c920e7f, 0xbc8f9ec4, 0x3cc21faf, 
    0xbcc5da67, 0xbd95fe9e, 0xbc4d501d, 0xbd03b06f, 0xbda7be64, 0x3d5025d9, 0xbca03066, 0xbcb45525, 
    0x3d88c8a7, 0x3ce7d525, 0x3cfb334e, 0x3d142b46, 0xbd3667ec, 0x3c1abd02, 0x3b9cca4d, 0x3c506e04, 
    0xbc00a66e, 0xbc6d4ab8, 0xbd3964f4, 0xbcde6a2a, 0xbc82efa9, 0x3caa2923, 0xbb9dbcd0, 0x3c0b3fc5, 
    0xbc6ce506, 0x3a700c74, 0x3d0d0ac8, 0xbc36b314, 0xbcb7d8b8, 0xbcac84e2, 0xbd72fc37, 0x3b79a5ca, 
    0x3c5bb5cd, 0x3d9308ff, 0xbd6e7b37, 0xbd3a9fec, 0xbb1dbc65, 0xbb801382, 0xbd05f8f1, 0x3c4d0a62, 
    0xbd30ad50, 0xbdb1d836, 0xbc1f6412, 0xbd24ef66, 0xbda7b6c6, 0x3b1eb9d0, 0xbd9242ce, 0xbd626aef, 
    0x3cd11058, 0x3baea92c, 0x3d53811c, 0x3d8e4056, 0xbd1f2158, 0x3ca9b423, 0x3c899052, 0x3cae43f6, 
    0x3b8d93f0, 0xbbc6e4a1, 0xbb2f53d2, 0xbcaf9d80, 0xbb07c47e, 0x3cec060a, 0x3b56924c, 0x3c5dba9d, 
    0xbc9e8d2b, 0xb97511e1, 0x3d5116dd, 0x3b014b4f, 0xbc149252, 0x3bad9ac1, 0xbcf075c9, 0x3c882e71, 
    0x3d2282c2, 0x3dea231f, 0x39c5b0d7, 0x3d1a0b6e, 0x3dc08a1c, 0x3d9b7ad6, 0x3c260934, 0x3d42ec92, 
    0x3cf59ab6, 0x3abff5c8, 0x3d971b7c, 0x3ce63afa, 0xbd612b13, 0x3db12875, 0x3cf6db31, 0x3ca53fa8, 
    0x3dff56e4, 0x3d8b0eb3, 0x3e1a5b1e, 0x3e2e0807, 0x3d21f9eb, 0x3ddddb46, 0x3d9036e6, 0x3dbe70a5
};

static const uint32_t _K21[] = {
    0xbfa4f908, 0x3efaf124, 0x3fa1af51, 0xbf177d22, 0xbf345d17, 0x3ef7a112, 0x3f85c6f1, 0x3d9baec4, 
    0xbf39203c, 0xbf169465, 0x4004cdee, 0xbf156e5c, 0x3f89cb2a, 0xbeeafc76, 0x3f5f464e, 0x3eec1b0e
};

static const uint32_t _K25[] = {
    0x3db92e3f, 0xbdcab956, 0xbe3d4fff, 0x3b251247, 0x3e19985d, 0x3e8cbfca, 0xbdfacaf1, 0x3cc64751, 
    0xbd54ba71, 0xbd5ccfd4, 0x3dab91a2, 0x3d42a38a, 0xbda49598, 0xbe3572fd, 0xbc2ef5c7, 0xbd98962b, 
    0x3dd8fac3, 0x3b969419, 0xbe1b93b6, 0xbd363d7f, 0x3e1b050a, 0x3e0134fb, 0xbdf6b2cc, 0x3c9069dc, 
    0xbc26ad1e, 0xbd8266c7, 0x3dbf9684, 0x3cdbcf86, 0xbe329fae, 0xbe820580, 0xbdb54bb2, 0xbe3a25a6, 
    0x3d240fa3, 0x3d65fba0, 0xbdd4394c, 0xbd37c517, 0x3d8dddcb, 0xbc582c8d, 0xbdf39885, 0x3d4fb544, 
    0xbd7270ba, 0xbd691a36, 0xbc7d16cc, 0x3d2063ac, 0xbe792c71, 0xbe39f3f5, 0xbe04e59f, 0xbe92de8a, 
    0xbb146ce5, 0x3db58a0d, 0xbeb30dee, 0x3c4cca4b, 0xbdac5a1f, 0x3e536b62, 0x3e0eaee8, 0x3d1d32d6, 
    0xbd8bf046, 0x3e7e2178, 0x3de30a58, 0x3bc77824, 0xbcb0a53b, 0x3e83da6a, 0xbd6e7157, 0xbe91197b, 
    0x3d2fb4cb, 0x3ea3eb42, 0xbd55e458, 0x3d1b1f53, 0xbdc59c2f, 0x3e500638, 0xbdb5ac0b, 0x3ddc0c9c, 
    0xbd536ca1, 0x3e3dd749, 0x3e064582, 0x3d931c1b, 0x3d7690f9, 0x3e36462c, 0x3c65c25a, 0xbe54e0ef, 
    0xbbbaa03b, 0x3db409f1, 0xbb870114, 0x3c31a02d, 0xbe832ef0, 0x3c20ca67, 0x3e527ace, 0x3e818171, 
    0x3cc325e1, 0x3f0d47f0, 0x3eaa81a0, 0x3d847d9c, 0x3d7502f1, 0x3e14302b, 0x3d699829, 0xbedb56c8, 
    0x3e8ad736, 0xbe85dd6b, 0xbeabf961, 0xbdb10d2e, 0xbe368597, 0xbd8c225b, 0x3eadb728, 0xbdd18dbc, 
    0xbe93e5ca, 0xbe896a94, 0x3e9fa484, 0x3c22d6b7, 0x3e170a04, 0x3dbcdcc4, 0xbe6b955b, 0x3ca56b4f, 
    0x3de3a82f, 0xbcb47448, 0xbde6e241, 0xbd8b63f7, 0x3bf777bd, 0xbc3bff67, 0x3cd67e7e, 0xbedc1c26, 
    0xbe21dcb9, 0x3d1da896, 0xbe091b04, 0xbc9777ef, 0x3dd6b3f6, 0x3d46b917, 0xbe8a8866, 0x3d847325, 
    0x3df1b69c, 0xbe4c46ff, 0xbe86fbe2, 0xbda234ba, 0xbdbb3869, 0x3d093735, 0x3c68acef, 0xbe689d8a, 
    0xbcdce467, 0xbe6c9098, 0x3e2d5e57, 0x3cab7b33, 0x3e279ad8, 0x3d17b4dd, 0xbe696e07, 0x3c050772, 
    0xbc6b3ed9, 0xbf07b70a, 0x3e077468, 0xbdeef944, 0xbe841bac, 0x3efe7879, 0xbe1ae008, 0xbcdf7a2a, 
    0xbe961336, 0x3bb849ad, 0x3e955dc5, 0xbda8c662, 0x3e2d470b, 0xbee8ccb3, 0xbd2b5d88, 0x3ed05bb9, 
    0x3e65e450, 0xbda6d46d, 0xbe1ce865, 0xbe7a122f, 0x3dd971a9, 0x3dfe0b42, 0xbdb1e6c1, 0x3d39f27f, 
    0xbe69aa00, 0xbe82d435, 0x3f0d3380, 0x3bca976b, 0xbe28861f, 0xbeb7c32d, 0x3da60577, 0xbd8d236c, 
    0xbc3c1e49, 0x3ec99757, 0xbc1d64de, 0xbe909d2c, 0xbc0c98d7, 0xbe4db2fd, 0xbeabda02, 0x3e001657, 
    0xbe9715f9, 0x3dc35b28, 0x3da387d7, 0xbbf59b73, 0xbf225ff2, 0xbe6c3c45, 0xbf072383, 0xbef65029, 
    0xbf075cb7, 0xbe9546f3, 0x3eff1a3a, 0x3e20df6f, 0xbef17404, 0xbe54e9a3, 0xbee1cfc0, 0xbed7f0b8, 
    0x3db48a98, 0xbe4c5526, 0xbf0646b7, 0x3dd254bd, 0xbd1abb25, 0xbde8ef7f, 0x3e3eb1b8, 0xbe270c94, 
    0xbd9407e7, 0xbb12b620, 0x3deb4aad, 0x3d4567c9, 0xbe3e091d, 0x3e01c2e2, 0xbec1c314, 0xbf02fdd9, 
    0x3c1f8510, 0x3d82eede, 0x3e66effd, 0x3d69b8ae, 0x3e78d227, 0xbe933f58, 0xbe8e4a19, 0x3efc5a3e, 
    0x3ca8d07e, 0xbe91167c, 0xbec1a09a, 0xbe1540ef, 0xbe510ece, 0xbd51544a, 0xbe7232bc, 0xbec86882, 
    0xbdb4c7ee, 0xbf7d5253, 0x3f35aa89, 0x3dae7a8e, 0xbd98de43, 0xbe4d78f6, 0xbec424e0, 0x3db94f4e, 
    0xbd6f66d8, 0x3d94d967, 0x3e263837, 0xbd8669d9, 0xbdbb7d5f, 0x3c2b1dae, 0x3d904b45, 0xbdac9a29, 
    0xbe57b8ec, 0xbd9baaae, 0xbd748666, 0xbc446b8e, 0x3cf68dc8, 0xbdea272c, 0xbe6aa973, 0x3b91969e, 
    0xbc514043, 0xbe45478f, 0xbe5b9c68, 0xbd6c2029, 0xbd114196, 0x3d59ea50, 0x3d1d1937, 0xbbd11252, 
    0xbe3bd6e7, 0xbcad3cd7, 0x3cdf5616, 0xbd26f2ea, 0xbcdfaea8, 0x3d89c78b, 0xbe0e6282, 0x3dc9f730, 
    0xba8fe1e9, 0xbd14d5f5, 0xbddfcce5, 0xbcf3dcb5, 0x3bf94ae9, 0x3d175fa7, 0x3dfca94b, 0x3e180231, 
    0xbd852a9c, 0xbe1d6c27, 0x3dca9823, 0xbc99170a, 0xbd244dc6, 0x3e6fd84e, 0xbe0c5382, 0xbc85dc59, 
    0xbd938756, 0xbd2f3bc1, 0xbc0f77f5, 0x3daf0b2a, 0x3d4dd66f, 0x3cd44475, 0xbebadb85, 0xbc4774da, 
    0x3dbef44d, 0xbd874b68, 0xbd01d4ec, 0x3dfd48df, 0x3d0ec7ee, 0xbeadb28d, 0xbe72063a, 0x3e311cf0, 
    0xbcb7a346, 0x3eb50f2f, 0x3e0e1f9f, 0x3c016709, 0x3e4ae25c, 0x3e2096fd, 0xbe0c124e, 0xbeb45403, 
    0xbe6c787e, 0x3d982932, 0xbe2e3bb1, 0x3bfccc57, 0x3dbbf9b7, 0xbe60aad2, 0xbd91321f, 0x3e95034d, 
    0x3dff66ea, 0xbf13d1c6, 0xbe8d89fe, 0x3d1d3cd0, 0xbc0dc5b2, 0xbeafdf3a, 0x3e4e9d8a, 0xbca5ffd9, 
    0x3db99e0a, 0xbdfbf58a, 0x3eae170b, 0x3b34bd79, 0xbe2ca034, 0xbe1cc054, 0x3e3459bb, 0xbd6d06ce, 
    0x3db10adf, 0xbe912daa, 0xbee9da8e, 0xbd9355a0, 0x3bb4c3c9, 0xbebc1446, 0x3e495a0e, 0xbe8c58fb, 
    0xbc1978d5, 0x3d4a3b43, 0xbd8bac07, 0xbca241c9, 0xbea4daba, 0x3cd33ba9, 0x3d42d61a, 0xbe3fe3bc, 
    0xbe169c0a, 0x3b83f9b8, 0x3dd78f9e, 0x3c810062, 0x3db3b24a, 0xbe045afb, 0xbb136e15, 0xbd0eb3ab, 
    0xbd58651a, 0xbe528cdd, 0xbdda3d16, 0xbc784425, 0xbe9333b5, 0x3eb4cb5c, 0x3e23b4b8, 0xbeb69c87, 
    0x3de4c3a2, 0x3e2ba089, 0x3f09c428, 0xbd4c601e, 0xbe465906, 0xbecf2427, 0x3ea1c2af, 0xbe59e217, 
    0xbd07a1ac, 0x3f0260c0, 0x3e404719, 0xbd0a1939, 0x3cb095f4, 0x3de8ce80, 0x3e1aa559, 0xbe27a816, 
    0xbdf4bca6, 0xbca89b2b, 0x3e067714, 0xbd94c798, 0xbf047acb, 0xbd69832e, 0xbe0015e0, 0xbdb8d7f2, 
    0x3e357fbb, 0xbe25b432, 0xbcdc02ac, 0x3c332e5a, 0x3e91f8ab, 0xbf16e8d6, 0xbe349a9d, 0xbd04dcd2, 
    0xbde6e5db, 0xbebbcfdb, 0xbe13208b, 0xbd074d84, 0xbf26bd95, 0xbe81cc2e, 0x3e20e573, 0x3df4b7e2, 
    0x3e831ef0, 0xbf0ad8b2, 0x3d560c87, 0xbd660825, 0x3e3c4ebf, 0xbc8846cd, 0xbdc63aca, 0xbeb6694a, 
    0xbe6caee9, 0xbe15a2bf, 0x3d3fad0c, 0xbd56627f, 0xbf223400, 0xbeb3db29, 0xbd74e964, 0x3dbb0c9d, 
    0x3de1f15b, 0xbe13b54b, 0xbe9ab19b, 0x3d4bfd75, 0x3de7fdec, 0xbe92a3f6, 0xbdb073ad, 0xbeb2ef27, 
    0xbe3a1a95, 0xbe2e1cf9, 0x3e819825, 0x3cc892ce, 0xbe6e9d36, 0xbdcda60a, 0x3d455d6c, 0x3e18e0f3, 
    0x3e7cd6ee, 0xbdf2d719, 0xbe030a37, 0x3dca2882, 0x3e85e228, 0xbe804729, 0x3daf6b5a, 0xbe0e2590, 
    0xbe2d2a6f, 0xbdfd1c31, 0x3e2262ce, 0x3cf5662d, 0xbe25e348, 0xbcec873f, 0xbcc7e598, 0x3e0c326a, 
    0x3e820a9d, 0xbd9126a5, 0xbda43877, 0x3d624f7f, 0x3e5d4f77, 0xbea0ac9a, 0x3d50c5c6, 0xbe43d92d, 
    0xbe80e16c, 0xbdfaf81a, 0x3ea733dc, 0x3cc4aa9f, 0xbe272cf9, 0x3e07b322, 0xbdd883b6, 0x3e0abb4e, 
    0x3e9c41e4, 0xbd6a95de, 0xbeb17c3d, 0x3da3233a, 0x3e11e3a7, 0xbcc070a5, 0x3cd6cf98, 0xbdbefc61, 
    0x3d416ec9, 0x3d6a19f7, 0xbd09da84, 0xbc874549, 0x3dce44c7, 0xbd8e6617, 0xbd18d7ac, 0x3d6006c9, 
    0xbd218bd5, 0xbdd4a103, 0x3d17dd23, 0x3d25ba0f, 0xbe735cb7, 0xbde403d9, 0xbdf382a6, 0xbde3a627, 
    0x3c9787f9, 0x3dd7ca96, 0xbd0d727b, 0xbd1539cd, 0x3db0d9d7, 0xbdd36819, 0x3d8054af, 0x3d173747, 
    0xbd955ec4, 0xbd8ce0cf, 0x3d45fc98, 0x3d1b61c1, 0xbe71e2d8, 0xbcb19bba, 0xbe18a816, 0xbe1dd39e, 
    0x3d08b932, 0x3deb4eff, 0x3ac6977d, 0xbcfcc4d4, 0x3d92bfad, 0xbe2aba0f, 0x3da893e4, 0xbbcf6025, 
    0xbdd22a71, 0xbc7acff6, 0xbd090fe4, 0x3c392060, 0xbe6493c7, 0xbd72af45, 0xbe23ff1d, 0xbdd9e79d, 
    0xbe05db36, 0xbe8edc82, 0xbde1df8b, 0xbcee6416, 0xbd8bba3c, 0x3922823d, 0x3db93e8c, 0xbde52832, 
    0x3c01251b, 0x3de4fa89, 0xbd3b564a, 0xbc042550, 0x3e2020aa, 0xbc7a5bbd, 0xbcf3f2c1, 0xbd86c0af, 
    0xbd481e68, 0xbe4d10ea, 0xbe1fcbd7, 0xbd16be8e, 0x3c52cbfd, 0xbc814ff6, 0xbcc1b927, 0xbe099e52, 
    0x3d10d147, 0x3d4032e7, 0xbcb16192, 0xbcc390f6, 0x3e2384ae, 0xbc89b6b4, 0xbd6a393d, 0xbd4e18bc, 
    0xbd30529b, 0xbe0fdeb8, 0xbe20d1d9, 0xbc91211a, 0x3c9f37be, 0xbc5affdf, 0xbd496ac6, 0xbe11be0a, 
    0x3dc3d6ca, 0x3cf8badb, 0xbd341abc, 0xbceab647, 0x3e0b2015, 0xbc9fc31b, 0xbd798561, 0xbd87de79, 
    0xbe0e85bf, 0x3f1a02c4, 0x3e4a09f1, 0x3e02b98f, 0x3d6f96a7, 0xbe8d6cba, 0xbee295ac, 0x3ea238fd, 
    0x3e81efd0, 0xbf3f2a0a, 0x3ef12664, 0x3e31894b, 0xbe767b54, 0xbbf45118, 0xbf3f3e10, 0xbe186f9a, 
    0xbe611790, 0x3e4e3880, 0xbe4fbfa9, 0x3e30f5d9, 0x3de7d67e, 0x3e15f3fd, 0xbdab9b69, 0x3c82f870, 
    0xbdc07510, 0xbf258557, 0xbeb245bd, 0x3d9c3e64, 0xbe7767a3, 0x3ea9ce2d, 0xbe3c96ac, 0x3e2aeb77, 
    0x3e458195, 0xbe4eb0a2, 0x3e75a871, 0x3da5034a, 0x3d71dc60, 0x3e31dbb1, 0x3eca1a8b, 0xbeb9fc0f, 
    0xbe9fd2a3, 0xbd11a82c, 0xbeb20947, 0x3dd0645f, 0x3e6e10da, 0x3eeeab1f, 0x3f62d6a0, 0x3e9f57e3, 
    0xbf1e0d0f, 0xbee4e80d, 0xbe5e5d77, 0xbd8d519b, 0x3c92c0e0, 0x3e3d9902, 0x3d528f27, 0x3e0afecb, 
    0xbd33ec1e, 0x3ecf50e6, 0x3e160dce, 0xbe378ad3, 0x3de273f6, 0x3da4e066, 0x3f067926, 0xbcb4175e, 
    0xbee598db, 0x3eae1a05, 0x3e68a1d6, 0xbd23aece, 0x3dd0978f, 0x3e3b04a6, 0xbe1a3b85, 0x3c675b3f, 
    0xbe176b4b, 0x3e2ff45d, 0xbe0cce33, 0xbdb4e4b1, 0xbcb9efe0, 0x3eded4a6, 0x3f02cfe6, 0x3df82754, 
    0xbe9ff81b, 0x3e1ae851, 0xbe1844f0, 0xbd4a497f, 0x3d1be253, 0xbd76d279, 0xbe017c05, 0x3dadfe11, 
    0xbe54f3e8, 0x3e4a648f, 0xbf031312, 0xbe044e84, 0xbec81d90, 0x3af50cd0, 0x3e1f386e, 0xbe65f3dc, 
    0xbea6fba1, 0x3de2d0d9, 0x3e368824, 0x3e12d4b9, 0xbd8073f8, 0xbe62306f, 0xbe3af9d0, 0xbe9510ca, 
    0x3e502f89, 0xbe211e63, 0x3bb16321, 0xbafb0e2d, 0xbd03f8a1, 0x3bb94d60, 0x3e829a79, 0xbcc0e11a, 
    0xbecccbbc, 0x3dc65da5, 0x3e7e3b3e, 0x3e035130, 0xbcfb40ac, 0x3e396efc, 0xbdc8bfba, 0xbe98a9f2, 
    0x3e772586, 0xbe1722b6, 0xbe713084, 0xbcc37976, 0x3ca50212, 0x3dd6a77b, 0x3e8ab9ab, 0x3e7a7c92, 
    0xbe41fe8e, 0xbd10abcf, 0x3e4821b6, 0x3d763e97, 0xbd8c73c6, 0x3e4c2aca, 0x3e615694, 0xbe88107e, 
    0x3e9ec44a, 0xbdcb2894, 0xbcf320ba, 0xbd4267e7, 0x3e01474d, 0x3e3503ce, 0x3ef68559, 0x3e970946, 
    0xbe16f0d2, 0xbf1e0f10, 0xbd37bb88, 0x3d238de3, 0xbe0a5b49, 0x3f1ad299, 0xbecd5ded, 0xbf177880, 
    0xbe5e0b01, 0xbdf56ee0, 0xbc3e22a4, 0x3dbe45ce, 0x3c188446, 0xbf33dd34, 0xbe02fd38, 0x3ecc338d, 
    0x3d78cc4e, 0xbeab13a9, 0xbdf7fe44, 0xbbefc41f, 0x3e7b5355, 0x3e29092e, 0xbec4690e, 0x3e2e5e48, 
    0xbc3d8ca4, 0xbedaf8d8, 0x3dd1264e, 0x3e059a39, 0xbe92ed87, 0xbd6ad5a1, 0x3e6339e8, 0xbe650a49, 
    0x3ed25f79, 0x3f4c2767, 0x3f0e13be, 0x3df80374, 0x3e316bf4, 0xbf2a67b3, 0x3e8940b6, 0x3de6b694, 
    0xbe6ff526, 0xbe809a0c, 0x3ebc6f87, 0x3e21ca09, 0xbde82413, 0xbee661d3, 0xbebc121a, 0x3e53e7b9, 
    0xbdb4fe4b, 0x3d9d3656, 0x3f08a772, 0x3a935b7e, 0xbd27b229, 0xbe7ca660, 0xbeb86588, 0xbea0c795, 
    0x3d3402a0, 0xbd8677eb, 0xbd651c3a, 0x3caebc28, 0x3eb21a42, 0xbd3e7ed5, 0x3dd921d3, 0x3e9ff25d, 
    0xbc4a4231, 0xbe189ee7, 0x3d4fe6c3, 0xbd62971e, 0x3cb5be5d, 0xbdd2730a, 0xbe495d9d, 0x3d3f2505, 
    0x3e8e99e9, 0xbd8d52ea, 0xbe059eb2, 0x3ccd34a6, 0x3e332d4d, 0xbe26278a, 0xbdad4c1f, 0x3eef9a5a, 
    0xbcc56a1c, 0xbe9d3098, 0xbd144754, 0xbda42a66, 0xbd8b4c99, 0xbdc373ab, 0x3e82f324, 0xbca70cfc, 
    0x3e07b533, 0xbe41391d, 0x3f0372c3, 0xbcac8e7e, 0x3d3368da, 0xbe915a57, 0x3e9a2415, 0x3d518bb5, 
    0xbeac7819, 0xbd896802, 0xbdacaff1, 0x3d018343, 0xbe3ffc7a, 0xbd7c20b2, 0xbdacf567, 0xbde152b2, 
    0xbe64ece3, 0x3e41b3e0, 0xbd4c778c, 0xbd50943f, 0xbe50e9b6, 0x3dee105b, 0xbdf845ef, 0xbd8c6949, 
    0xbe858878, 0xbe1b6cdd, 0xbe8be3ec, 0xbd08a6ed, 0xbd8af61a, 0x3dc98570, 0xbe00563d, 0xbe08438e, 
    0xbea9f92f, 0x3e3594c7, 0xba9ac84e, 0xbcdd487e, 0xbdcd6d24, 0x3e05be8b, 0xbe224f9d, 0x3e4beb8c, 
    0xbe8aee39, 0x3d7fcad4, 0xbd223c54, 0xbcee72cf, 0xbcd8a84e, 0x3ed85b3d, 0xbdb7f0e3, 0xbe47f2cf, 
    0xbeb8dae4, 0x3e001bd7, 0xbd701878, 0xbd8eed3a, 0x3d2de431, 0x3e544cbc, 0xbdad4f79, 0x3ea60c49, 
    0xbeaf8503, 0x3e2984e6, 0x3e81bff6, 0x3d879f86, 0xbea786bf, 0xbe943119, 0xbe9c7b90, 0x3e5fdffe, 
    0x3e7fb90c, 0xbdbbff9e, 0xbe9fb661, 0x3c8ba5e1, 0xbe046a95, 0x3dd71b88, 0xbea16d13, 0xbf1edb65, 
    0xbdbc3581, 0x3df3f822, 0x3e5ad252, 0x3db868e1, 0xbe7ff28c, 0x3e4140f8, 0xbc17e84d, 0xbd95c28a, 
    0x3d8d4023, 0xbe9bdddf, 0xbd671c0c, 0x3d3d05ee, 0x3e1ef5e7, 0xbdad64b2, 0xbdaa8b53, 0xbe222b50, 
    0x3d7f1c08, 0x3d818cb7, 0xbdaa6e00, 0x3dab09b6, 0xbe4d8657, 0x3f170837, 0xbe38e9ee, 0xbef0dfde, 
    0xbf0d6bca, 0x3de27767, 0x3e91d8ae, 0xbd2cdbee, 0x3e94edd1, 0x3ec796b3, 0xbd523fcb, 0x3e9c56aa, 
    0x3dfc9d83, 0xbcd64784, 0xbdda22db, 0x3bef6057, 0x3d93cda3, 0xbe173aef, 0x3ddaaadc, 0x3d23f98f, 
    0x3d3284bb, 0x3e6e0598, 0x3d23bed1, 0x3e128c1e, 0x3d182051, 0x3e1761c0, 0x3e292043, 0x3e880688, 
    0x3de8cd22, 0x3e056704, 0x3e85deed, 0x3d4999c8, 0x3db303dd, 0x3e23f918, 0xbcb54f7b, 0x3d6ad2df, 
    0x3e0a82f7, 0x3e63f6ca, 0xbd78e58b, 0x3e252a7f, 0x3e415c47, 0x3e726e1b, 0x3e6795d3, 0x3f1a7f61, 
    0x3de84d32, 0xba7bca06, 0x3e4f7009, 0x3d0f5c3d, 0x3e362f46, 0x3ec578f5, 0xbd22558b, 0x3e2a5f37, 
    0x3ea1bfe1, 0x3e3bf75d, 0xbe01faac, 0x3e2fbd3e, 0x3e71e922, 0x3e5d369c, 0x3e571fb4, 0x3f2ecffd, 
    0xbe592da5, 0x3a38e8db, 0xbccbcb15, 0x3d0ccac9, 0xbdcd37d2, 0x3ed32007, 0xbea8e783, 0xbe3df09b, 
    0x3de1ce47, 0xbea2e747, 0xbe4e9225, 0xbdf7c7d8, 0x3e4c31ad, 0xbf2a085f, 0xbe24d1ba, 0x3e15a5c7, 
    0x3e16eaa0, 0xbe02a2eb, 0xbf0668b0, 0x3ce1941a, 0xbe9e8cce, 0x3db1cd82, 0xbda336ea, 0xbd8f6b42, 
    0xbe2d31d3, 0x3ba5e209, 0x3ed7815a, 0xbe42c394, 0x3e107ec5, 0xbe71761a, 0x3ed36c00, 0xbed8feaf, 
    0xbe9e106c, 0x3d313de0, 0xbf01e0c4, 0x3da9972e, 0xbe2d8d43, 0xbddcea1c, 0xbede661e, 0x3f0f0fa5, 
    0xbefc429c, 0x3d12131f, 0xbdfeac76, 0xbc2df4e2, 0xbf4dc8a1, 0x3e9d5107, 0x3e26f0c1, 0xbef04a6b, 
    0x3cc84768, 0x3e42b350, 0x3e8346d2, 0xbda494ce, 0xbd9365c1, 0x3d33044d, 0xbe00cec8, 0x3db8e0a9, 
    0x3d0a6d3c, 0xbd0e78c4, 0x3daece13, 0x3d01f3f9, 0xbcb77e1a, 0x3cd3fa7e, 0xbca0c403, 0xbc0ce7e7, 
    0x3d407500, 0x3d07a2a0, 0x3cb6b9a6, 0xbd826d18, 0xbcc0b353, 0x3d0d1c83, 0xbddd7053, 0x3ddc5712, 
    0xbbc58546, 0xbd5161b4, 0x3df8dd89, 0x3ca4c828, 0xbe055ec4, 0x3dac37b2, 0xbcc633eb, 0x3c76b3f9, 
    0x3d7e3c14, 0xbd427497, 0x3b03da13, 0xbdc3b242, 0xbd9dbea2, 0xbd0e677b, 0xbcddfb7b, 0x3e0c311c, 
    0x3bd18166, 0xbd49d8d3, 0x3e9a6f5a, 0x3ce751ed, 0xbe28a7da, 0xbda6cc79, 0xbde5c057, 0xbcce0b44, 
    0x3e40b3db, 0x3f35cb17, 0x3f152a1e, 0x3d4d2c13, 0x3ebc684f, 0x3ea9abf7, 0x3dd6a0ec, 0xbed69c75, 
    0x3e8279af, 0x3ed0ab6d, 0xbf4b70e1, 0x3e7698f1, 0x3e7ce291, 0xbe61b236, 0x3e124299, 0xbdf96f6a, 
    0x3ee1a123, 0xbe5725a3, 0x3e3b1251, 0x3c6ddf2d, 0x3bc34b3f, 0x3d874a88, 0x3dabdc0a, 0xba8e6a79, 
    0xbea3c582, 0xbd9c6846, 0x3f4bb95c, 0x3e18e5ed, 0x3e742644, 0x3d839469, 0x3e8c1388, 0xbeb1967c, 
    0xbe1b25a5, 0xbed88f3f, 0xbf237b6c, 0xbd836341, 0x3c7ffa87, 0xbd1c6ed4, 0xbf250a17, 0xbe1705ef, 
    0xbe65ccb8, 0xbf4e3774, 0x3d9b2733, 0x3d60815a, 0xbe5e6d5e, 0xbe8f7403, 0xbf01a259, 0xbe73528b, 
    0x3e0278d3, 0x3c9ff413, 0xbdc63131, 0x3b17080a, 0x3e03a18d, 0xbda20bd6, 0xbbcfd886, 0xbd1cb0cf, 
    0x3bdbad66, 0xbd8b6dd7, 0xbafc2562, 0x3c6e0184, 0xbe5cedf5, 0xbd5dedba, 0x3d1f9810, 0xbe6f0ce9, 
    0x3db4cc7f, 0x3d656124, 0xbc395c86, 0xbd05fd8a, 0x3dd9b8c0, 0xbe27098a, 0xbac9870f, 0xbcc39e1c, 
    0xb7cdf3d3, 0xbd8d2290, 0xbc4f5f08, 0x3b69077f, 0xbe829642, 0xbd6d394e, 0x3c577d7a, 0xbea9630f, 
    0x3dc16644, 0x3d901e97, 0x3c5dd4a3, 0xbd15a25a, 0x3d5e017c, 0xbe290fb6, 0x3d85b72d, 0xbc7e4c29, 
    0x3c7cd99f, 0xbd4daaa4, 0xbcf9fd27, 0x3c8ee0df, 0xbe496eb6, 0xbd2180d7, 0x3d706c85, 0xbe9a698e, 
    0x3d2927d1, 0xbe842d50, 0xbe4452dc, 0xbd6bbc6e, 0xbd10ebc6, 0xbc45f7bf, 0x3d400e22, 0x3de952a6, 
    0xbdbc09a3, 0x3da41f9e, 0x3e762639, 0xbc008bd1, 0xbe19ecd6, 0x3e4ac9ee, 0xbe82a314, 0xbba6c5ad, 
    0xbd6ddcb6, 0x3ee6f38f, 0x3eb0789c, 0xbd5914a9, 0x3df8b6fd, 0x3d9ccd6e, 0x3be99d23, 0xbeb7ae63, 
    0xbe4446ea, 0xbe38b0a6, 0xbe904727, 0xbc1075c8, 0xbd5e476b, 0x3ec0c26c, 0xbe67a121, 0x3ea55307, 
    0xbde72fd5, 0xbe19bb10, 0xbe7f88ab, 0xbd4a4486, 0x3c0c416a, 0x3e12a296, 0x3d27356c, 0x3d1b513a, 
    0xbda311c1, 0xbe81bd60, 0x3cf54e5f, 0xbcf3782a, 0xbcbaab1b, 0x3e63e17e, 0xbe1ac12c, 0x3ee78c2f, 
    0xbe1aaba0, 0xbdd8ad1f, 0x3c896c9b, 0x3d3ccbb0, 0x3c97fa5d, 0x3d2c1421, 0xbdd5474b, 0xbdad8f84, 
    0x3d8ee281, 0x3dc21745, 0xbe4154d3, 0xbd834ef8, 0xbd2ba70d, 0x3d9c19a0, 0x3ec949b4, 0xbdbed201, 
    0xbe148ac5, 0xbdb923fe, 0x3ce2fc74, 0x3d5b953d, 0x3d4c4351, 0x3ca67ccb, 0xbced7704, 0xbd1aaff0, 
    0x3d554c53, 0x3dbe7f89, 0xbe305a71, 0xbd3f2df4, 0xbccd588d, 0x3d11d6f2, 0x3ecda87e, 0xbd8a357f, 
    0xbdfdddb8, 0xbd8074dc, 0x3a826449, 0x3d0d9713, 0x3d2c3a15, 0x3d2fc890, 0xbd9f6651, 0xbd9e4958, 
    0x3d9248a6, 0x3e0d2468, 0xbe2bc9e2, 0xbccf8902, 0xbd6e919b, 0x3d81533c, 0x3ebd8f74, 0xbd9b722e, 
    0xbed4e0b1, 0xbd05b139, 0xbdd001c0, 0xbd7ef80b, 0x3e129b94, 0xbd554a9b, 0x3e31c77a, 0xbe8a8d2e, 
    0xbecf711b, 0xbc8cfa13, 0xbec5bdfb, 0x3dd6a225, 0xbe7b7463, 0x3da5f23c, 0x3e299889, 0x3eab6190, 
    0xbd65410d, 0xbf2eff12, 0x3cc159ec, 0xbe09dc2e, 0xbe1da169, 0x3dfd68ec, 0x3ea0f375, 0x3e8c1b40, 
    0xbdf839cf, 0x3ebb545d, 0x3f1f8646, 0x3d8f5494, 0xbd2bb193, 0x3cf828ca, 0x3eb1e8d8, 0x3deb42f0, 
    0x3e5601de, 0x3f05a559, 0x3eb89859, 0xbda728e9, 0x3eb23c86, 0xbf00739a, 0xbf4cdced, 0xbebd47be, 
    0xbe4a6528, 0xbe819181, 0xbef89a1e, 0x3e06a722, 0xbe90cf47, 0xbe7ab66f, 0xbe182d9b, 0x3db7068b, 
    0x3c917f18, 0x3cad75a6, 0xbd3c5349, 0xbc1ec1c4, 0x3d500b2c, 0x3dd2f961, 0xbe4d0f70, 0x3cbc66af, 
    0x3d5fdd6c, 0xbd98ff6b, 0x3d169eb5, 0x3d5865b6, 0x3d8fbf5a, 0xbdc7a704, 0xbd811d91, 0x3db98d4c, 
    0x3d38dc20, 0xbde00647, 0xbe427530, 0xbcc2e5b3, 0x3cdcafbd, 0x3db61971, 0xbdb87186, 0x3d828888, 
    0x3d74ac7a, 0xbd92a2f4, 0x3e10e129, 0x3d6aff81, 0x3d05d728, 0xbe002f30, 0x3ab3bf50, 0x3dd0dc37, 
    0x3ca28688, 0x3d1acaac, 0xbd385143, 0xbcf45b8c, 0x3d9cabaa, 0x3d185a7f, 0xbe30402f, 0xbd1d849f, 
    0x3d779dc9, 0xbd3c778a, 0x3aecfd9b, 0x3d1889ee, 0x3bf07b94, 0xbe00c875, 0xbd6e1253, 0x3d9cc1d1, 
    0xbe3e0921, 0xbe5e9c95, 0xbd51f7b5, 0x3c542552, 0xbd987ed4, 0xbda9f5e4, 0xbe4b9573, 0xbd8e78de, 
    0x3db99a27, 0x3c45f8c5, 0x3d8e72ef, 0x3c85aa46, 0x3e48bed0, 0xbd5edcfe, 0x3cdfb4e7, 0xbc7e0b0c, 
    0xbe4671a7, 0x3e202612, 0x3da0420b, 0x3b54e156, 0xbd961ad2, 0x3e46a738, 0xbe21cb2f, 0xbe19aeca, 
    0x3d023eaa, 0x3cbed2c9, 0xbd228554, 0xbb857dd4, 0x3e6a4d31, 0x3db5457b, 0xbb87635c, 0x3e31e445, 
    0xbe354749, 0xbdd35c5e, 0xbd4c655d, 0xbb686aa8, 0xbd9e372c, 0x3d48bc38, 0xbdcea4cf, 0xbe94fa8a, 
    0xbd95d9b5, 0xbc96d16a, 0xbc24d526, 0xbc30e97a, 0x3d7a4626, 0xbdeb8352, 0xbc234de2, 0x3d64ce3f, 
    0xbe0d2e81, 0x3d649349, 0x3da397bf, 0x3bbc4e96, 0xbe0a56fe, 0xbcf68f53, 0xbb077327, 0xbcaf6f57, 
    0xbc5853f8, 0xbd847467, 0xbeb4f439, 0xbce115e7, 0x3d144444, 0x3da34669, 0xbdfaccc5, 0xbd98e65d, 
    0xbe1ddf1c, 0xbcae6094, 0x3d620d13, 0x3b8e3e73, 0xbe0aec6e, 0x3cf683db, 0xbd6b190f, 0x3d1eeed5, 
    0xbd705380, 0x3d9faef2, 0xbec76f8f, 0x3c417db8, 0xbbfcaa4e, 0x3dc87863, 0xbd3d8425, 0xbdb624b6, 
    0xbd4f22ce, 0x3d00b5d4, 0x3d9f09eb, 0xbcd45b61, 0xbdad52bc, 0x3ca921fe, 0xbd32f35f, 0xbcdf7ddd, 
    0xbe69c143, 0x3e0c37a9, 0xbe2a5931, 0x3cb296ea, 0x3c3742ea, 0x3dda9a87, 0xbe04c96f, 0xbb1a4fcb, 
    0xbd2e62b8, 0x3d63202d, 0x3e01aa82, 0x3bfa94a9, 0xbda2f558, 0x3cacc606, 0x3e8287a4, 0x3ceca68a, 
    0xbd3fe095, 0x3a9ad9cf, 0x3c2e117c, 0xbcbddf9d, 0xbe12fbe1, 0x3c3d246e, 0x3d2289f2, 0xbd99ec39, 
    0xbc3ea18f, 0x3e1ee1a6, 0x3da84303, 0xbc514680, 0xbd993aa2, 0x3c4ba044, 0x3e0cb1a9, 0x3c935023, 
    0xbde04590, 0x3c55755b, 0x3cb55531, 0xbce9736e, 0xbd1ea747, 0x3d910a9c, 0xbd8d27b6, 0x3d2e3b7b, 
    0xbd678971, 0xbd7df9c9, 0xbde0e084, 0x3c8194ae, 0xbd9efa06, 0xbddb1f76, 0x3e572819, 0x3d5fa9e8, 
    0xbc5ca5e4, 0xbd27768b, 0xbbb0e543, 0x3c23e33e, 0xbe012af0, 0xbd4a66c6, 0xbda1d196, 0xbd6e28f0, 
    0x3e37c23e, 0xbda0e28d, 0xbd1504f0, 0x3ca069e8, 0xbd6294c6, 0x3ec9e6c6, 0xbed45765, 0x3e368a12, 
    0x3e9fb29e, 0x3bc45a33, 0x3df1e25c, 0x3dd050c1, 0x3d833b10, 0xbdad2714, 0x3e651812, 0xbea19b62, 
    0x3e3648c2, 0x3d12e07f, 0xbd5b5d60, 0xbc56c9b5, 0x3cd06c56, 0x3e5da17c, 0xbe3be2d6, 0x3e7f582f, 
    0x3ed46e6d, 0x3d7cdaa6, 0x3d64f57f, 0x3d9424c4, 0xbd1b1f05, 0xbd81e404, 0x3e30864c, 0xbecc13ae, 
    0x3e2edecd, 0x3d0c5e3e, 0xbceb26a5, 0xbc2f245b, 0xbaf6b105, 0x3e502e11, 0xbe9b718d, 0x3e444808, 
    0x3eebef4e, 0xbdd1c498, 0x3cce718a, 0x3d803725, 0xbd94f114, 0xbd7db207, 0x3e3812d2, 0xbea81c64
};

static const uint32_t _K28[] = {
    0x3fabba81, 0xbfd413c7, 0x3fad6f24, 0x3f0d0669, 0x3f91b40f, 0x3f3c6404, 0x3ee2faa7, 0x3e50a666, 
    0x3fcf1946, 0xbf2e5e8d, 0xbf0246b7, 0x3fd2e4cc, 0xc03b81cc, 0xbfaf14a5, 0xc04b1393, 0x3eb20ad4, 
    0xbfce2a92, 0x3f9912b9, 0xbf7e74f6, 0xc07a3e82, 0x3fac80cd, 0xbf9a8348, 0xbe930d5f, 0x3fbdd4ad, 
    0x3ecbb6f4, 0xc0028735, 0x3f478780, 0x3e5ae86f, 0xbdbb916c, 0x3f713d82, 0xbdffa581, 0xbf977f8b
};

static const uint32_t _K32[] = {
    0xbddf9781, 0xbd8e4a86, 0xbdcd1747, 0xbe367057, 0x3cc03cf0, 0xbe2dcb02, 0x3d17eedc, 0xbd2ad1d6, 
    0x3d0805c0, 0x3dd64f54, 0x3e026b2b, 0x3c825921, 0x3e8ad652, 0x3e1b8775, 0x3db4fe43, 0xbe273c12, 
    0x3e756d10, 0xbe995d90, 0x3e9d7273, 0xbdbf5476, 0xbde1ebc2, 0xbe385ef1, 0x3c0d0fde, 0x3d51572f, 
    0x3cc61a98, 0x3e05692c, 0xbd2d9ee1, 0xbe4ea4ec, 0x3e3ac3d7, 0x3d890473, 0xbd967794, 0xbe088da7, 
    0xbebd4085, 0xbe5f6cc4, 0xbe9e9e50, 0xbec1a92f, 0xbc78a217, 0xbdea37ef, 0xbdadb7c8, 0x3dd40f0a, 
    0xbe171512, 0x3d367e36, 0x3c875d0f, 0xbdea4e6d, 0xbe8a3c45, 0x3da7d69d, 0xbdfde2a5, 0x3d9dbb7e, 
    0x3ceb4dab, 0xbe1f8c50, 0x3e596cbb, 0xbe825da6, 0x3da959c6, 0x3eb62320, 0x3e67d9f2, 0xbe1952f4, 
    0xbd5ede49, 0x3d700d33, 0xbd23128c, 0xbe3afe82, 0x3c30142f, 0x3ea597e3, 0xbd0a8a87, 0xbda99b1d, 
    0xbeeb005d, 0xbe6109b9, 0xbe0c6d02, 0xbe9f26dc, 0x3ea787f5, 0x3d66b8de, 0x3e84d5ca, 0xbe08bcde, 
    0xbf1f830b, 0xbe97e557, 0x3d1f1957, 0xbdc659c7, 0xbe34f6e9, 0x3e4c8221, 0xbf159764, 0x3e8a63f2, 
    0xbe8e0f53, 0x3de75acc, 0x3d983055, 0xbf2dc332, 0xbd59550f, 0x3e8b7737, 0x3ee557c3, 0xbe9b4c68, 
    0x3e6646bf, 0x3d01691b, 0x3df89bf4, 0x3dfb5c21, 0x3d8373f8, 0x3e787ab3, 0x3e7af777, 0xbdcff199, 
    0x3bbb8349, 0xbb0e4867, 0x3a44c732, 0xba244569, 0xbba1564b, 0x3a1784a8, 0xbb7ebe7b, 0xbb95808a, 
    0x38963265, 0xbbf77bd1, 0x3ac8f7f6, 0xbbe5f2e5, 0xbc41f7cc, 0xbb767226, 0xbc578d99, 0x3af42353, 
    0xb9abf769, 0xbb1fc985, 0xbc0b8348, 0xb9e3af57, 0x3bb6179a, 0xba3995a1, 0xbb962f24, 0x3bbbf119, 
    0x389094bd, 0xbb751ec5, 0xbbb8a874, 0x3b84851f, 0xbbee9f0e, 0xbc276eff, 0xbb8d221d, 0x3b5f342c, 
    0x3b4ac00a, 0xbb8cec3d, 0x3b16b8d0, 0xba6788b9, 0xbbc5d5a3, 0x3b035d93, 0xbbd5c99e, 0xbb3a48d7, 
    0x3ac203c4, 0xbbc2d460, 0xba873586, 0xbbfdde1f, 0xbbd7dc12, 0xbbfbbd1b, 0xbc467b5a, 0xb7e6520a, 
    0x38d559b1, 0xbb176dda, 0xb80ab605, 0xba57b24b, 0x3ade627e, 0x38e74a81, 0xbb91981e, 0x3b5c4635, 
    0x385c2b40, 0xbb7c6a11, 0xbb230479, 0x3afe434c, 0xbbe7d446, 0xbba2aa62, 0xbaa35dfc, 0x3bcb703d, 
    0x3b536657, 0xbb4aa645, 0xb89777ce, 0x39d3685e, 0x398f680a, 0x3a855aa3, 0xbad5dd01, 0xbb8d01a8, 
    0xbac89282, 0xbbb97cae, 0x3a409816, 0xbbe4f1cb, 0x3a9ac38c, 0xba95e195, 0xbb8417df, 0x3bd07bcf, 
    0xb9d41f12, 0x3ac09ec3, 0x3b9fd34d, 0xba80b374, 0x3a1b4cf9, 0xba2e370c, 0xbb23da7d, 0x3b6e0e36, 
    0xbac4bdcc, 0xbb536ac9, 0x37a41dd8, 0x3b99b0ea, 0xba29f91d, 0xbac48e92, 0xbb6c853a, 0x3b772505, 
    0xbd8649c7, 0xbe304568, 0xbdaa9baf, 0xbc674eac, 0xbbbbcd96, 0xbdfb593c, 0xbd95a71d, 0xbc879e2c, 
    0x3d29ba7d, 0x3dba601f, 0xbe6a8690, 0x3d78ebd8, 0x3d1ec16f, 0x3e3a996f, 0x3d6b3617, 0x3c991277, 
    0x3d032fe8, 0xbd8f66ee, 0x3d607ef2, 0x3cc15dc1, 0x3db6cae5, 0xbde51271, 0x3cbb61a3, 0xbda43a38, 
    0xbdc76319, 0x3e7c0a24, 0x3d34da1c, 0xbddf8511, 0xbc1018c9, 0xbdab02bc, 0xbd0dde5c, 0xbc20ff11, 
    0xbdc8f7ad, 0xbd747ebf, 0xbe2f977e, 0xbe45e3ca, 0xbdf51285, 0xbd917c48, 0xbdb7e3d0, 0x3ca50030, 
    0x3d81db34, 0x3da33335, 0xbe5c73ad, 0x3d334b0e, 0x3d3c19e6, 0x3e7fbd9f, 0xbbc52186, 0x3d46f024, 
    0xbd04df57, 0xbd20c4c8, 0x3d850a83, 0xbce00f2f, 0x3cf6fe4f, 0xbc85c70e, 0x3d92e595, 0xbd799773, 
    0xbe08fbac, 0x3e63ee27, 0x3d9f4e95, 0xbdc1167f, 0xbd411c04, 0x3c5b7ba3, 0xbcdb0c0d, 0xbb9f7b65, 
    0xbdd063e5, 0xbdc125cd, 0xbe49a566, 0xbe2585b1, 0x3ddf467a, 0xbdba272a, 0x3d8b7572, 0xbc398c5d, 
    0xbd43af87, 0x3ccdb82b, 0xbe63fa49, 0x3d83c47e, 0xbd327b8f, 0x3e55e304, 0xbe017522, 0x3de4e46c, 
    0xbd7c7110, 0xbc3ebcb4, 0x3d50ab08, 0xbe48c196, 0x3c4131e8, 0x3c1dd49a, 0x3db6480b, 0xbdabcfa6, 
    0xbd7958ec, 0x3e7ae7a3, 0x3e1fcb97, 0xbd1259e3, 0x3ca63f05, 0x3d499eaa, 0x3d4217f8, 0x3d3ad520, 
    0x3d8e51e3, 0xb9da7230, 0xbd46f1a9, 0xbdad8a2d, 0x3e014e35, 0xbd3a9fdd, 0x3a1960b6, 0xbd458150, 
    0xbd43eddc, 0x3d843f93, 0xbbdda26b, 0x3e4928a1, 0xbda534b6, 0x3d9965b3, 0x3e5adec0, 0xbc3e3bdb, 
    0x3da1cb53, 0x3dc05b09, 0x3c978794, 0x3df2fb90, 0x3e1f740f, 0x3bd603ce, 0xbe4c6053, 0x3cf7397b, 
    0xbd4ac9c2, 0x3db32e75, 0xbdf590fd, 0x3e118ff0, 0x3e304aaa, 0xbc4af8f1, 0xbe99c308, 0x3e748d33, 
    0x3de6e702, 0xbc71820b, 0xbb2d0f78, 0xbd40669a, 0x3cf28117, 0xbb58f6ff, 0x3d2534e4, 0x3def2344, 
    0xbdab45af, 0xbc516275, 0x3d4476aa, 0x3e13e5f9, 0xbd6332c2, 0x3c84f4cf, 0x3dab4777, 0xbc8fc386, 
    0x3db50e89, 0x3d31e5b2, 0x3d9c2d2a, 0x3db22305, 0x3df2a9f7, 0x3d5aeb12, 0x3cd083ff, 0x3d964f9d, 
    0xbcbdf10b, 0x3d7f9d17, 0xbd78f714, 0x3dbfb437, 0x3dc95790, 0x3c4864f0, 0xbe31c9e8, 0x3e7a5358, 
    0x3df88045, 0xbd1edd96, 0x3cc3dd3b, 0xbb896c3e, 0x3d2879a0, 0x3cf53c6a, 0x3d61a68b, 0xbda87a51, 
    0xbd918e14, 0xbdab462c, 0x3b239831, 0x3e0ec9dd, 0x3df933e1, 0xbadc0e99, 0x3d660a1b, 0xbd3e86b8, 
    0x3d139ed4, 0x3cc7e025, 0x3e004f12, 0x3da31ef0, 0x3e73ee16, 0x38abf288, 0x3e046150, 0x3dce283f, 
    0x3cb5f87d, 0x3dc94a67, 0xbda07c8c, 0x3d82cd3b, 0xbc23bd98, 0xbccb1f59, 0xbdaa4d26, 0x3e540a31, 
    0xbe30c6a3, 0xbe49570e, 0xbe8b01da, 0xbdd8086d, 0x3e967c49, 0x3e6f124c, 0x3dc126d6, 0xbe145c5b, 
    0xbc399bbe, 0xbdb53de4, 0x3efdda46, 0xbcc86705, 0x3da71cb2, 0x3e174933, 0x3e06957b, 0x3dbaacc3, 
    0x3ec1222f, 0x3e17395d, 0x3ea93b6d, 0xbefcb88c, 0x3c6480cc, 0x3e008aa4, 0xbe8e9c1a, 0xbeacc4b5, 
    0xbe8235b3, 0xbe072269, 0xbde48e2e, 0xbdc727ae, 0xbd7b0e17, 0x3d0c7891, 0xbbbb09a7, 0x3e38c29d, 
    0x3ab5487f, 0x3dc1b4b7, 0xbe13aa36, 0x3e215091, 0xbd3429ed, 0xbc34bd17, 0x3c886824, 0xbde28e11, 
    0x3e6f271e, 0xbdf8e1a5, 0x3eab700a, 0x3c920af3, 0x3ec9de6c, 0x3d5c149a, 0x3dc04791, 0x3e3db341, 
    0xbeb74bc5, 0xbd83ec3a, 0x3dd31ae3, 0xbca5bbea, 0x3dbe1cf3, 0xbe1ead34, 0xbd278f27, 0xbef7706c, 
    0xbea972ea, 0xbdb682a4, 0x3ddc56b8, 0x3deb9eb7, 0xbe54ec1f, 0xbe48d40f, 0xbe4f4ca4, 0x3d2bdfe9, 
    0xbeb1427c, 0xbe6e31c0, 0xba28fc57, 0xbeb22edd, 0xbe37c29d, 0xbeb6e3d2, 0xbedce8f9, 0xbe708029, 
    0xbeb6455e, 0xbe198dd8, 0x3e6c428a, 0xbc79999c, 0xbee6b785, 0xbc7f3858, 0x3bcedb68, 0xbed2f4f0, 
    0xbe9b91c4, 0xbc5c38bc, 0x3e81b3ac, 0x3e7fd11f, 0xbd62e366, 0x3e863911, 0xbd79844c, 0xbf021791, 
    0x3cd8e975, 0xbe0d1cee, 0x3e96ecbc, 0xbe9cb3e0, 0xbcf216bf, 0xbd30d275, 0x3c513879, 0xbdb3c86c, 
    0x3dbc58f9, 0xbd336219, 0x3e094089, 0x3dab489f, 0x3dcf1f1f, 0x3d8724cb, 0x3d266f98, 0x3d125382, 
    0xbd380a52, 0xbe84ec47, 0x3ea2443b, 0x3e13eba9, 0x3da6b284, 0x3c703b42, 0x3e192169, 0xbb6c5c36, 
    0xbdc9923a, 0x3cc8931b, 0xbe013100, 0xbe9ce34d, 0x3a31f292, 0x3cb26fec, 0xbdebb26b, 0x3d9f0025, 
    0x3d1f70fa, 0xbe0a94bb, 0x3c7baf2e, 0x3d9c03b1, 0x3d2497bb, 0xbda56c92, 0xb988fc7d, 0x3cad8187, 
    0x3db3d558, 0x3bcfbb5d, 0x3d94054d, 0x3e2295aa, 0xbd29255a, 0x3d3dbf1d, 0xbd641f32, 0x3d46939e, 
    0xbb60b0cf, 0xbe9a8660, 0x3eaa28f7, 0x3dc1921d, 0x3df3699e, 0xbe1197c9, 0x3d1daa32, 0x3d98564d, 
    0xbe735485, 0xbd52f6fe, 0xbd45ba9c, 0xbeab7668, 0x3c418ed9, 0x3d875a5e, 0x3d89d96c, 0x3d57a41d, 
    0xbc2c1bb0, 0xbe193e36, 0x3dcf2d60, 0x3cd073b6, 0xbe3e8a67, 0xbdac66e9, 0x3d3e0452, 0x3c80c4bf, 
    0x3d91dbf2, 0x3bb26106, 0xbd51a21c, 0x3d900d8f, 0xbe24280c, 0x3b42ad7b, 0xbc47d24c, 0x3e182af5, 
    0x3c55bc2b, 0xbea8643f, 0x3ea9c8c1, 0xbd97bdd0, 0x3e7f8c74, 0xbd5d49c2, 0x3d983129, 0xbc9313ac, 
    0xbde30e07, 0xbe754eec, 0xbd927a1c, 0xbedf27c0, 0x3d201e6a, 0x3c5d1151, 0x3dc59d7a, 0x3d5e8775, 
    0xbe136c89, 0xbdfc8320, 0x39982a51, 0xbd884a8d, 0xbe92ffd4, 0xbd72a2f1, 0x3d4bb7e2, 0xbbfe9833, 
    0xbb92a9eb, 0xbe156fe5, 0xbde433c3, 0xbdb3a61f, 0xbaf4568a, 0xbda4e8de, 0xbd632d30, 0x3d2343c5, 
    0xbd1565d1, 0x3c2b689d, 0xbbd912a0, 0x3a384737, 0xbdfa56c7, 0x3df78e49, 0x3d7d5349, 0xbe01e119, 
    0x3db80410, 0x3d274a7e, 0x3db3ab3a, 0xbacb23f8, 0x3e1258b0, 0xbdd69bd8, 0xbdcc758d, 0x3d1cfa4a, 
    0xbddab93e, 0x3de30b61, 0xbc1561b4, 0xbdb2a586, 0xbcddc585, 0x3ce3470b, 0xbdc23386, 0x3c912846, 
    0xbbe06aff, 0xbdd16dfa, 0xbe171914, 0xbe0a6110, 0xbce78f63, 0xbd16b52c, 0xbda323f7, 0x3d932e3a, 
    0xbd81de68, 0x3d234574, 0x3b505ee1, 0xbd6b0d13, 0xbdbc0ffe, 0x3d5d2114, 0x3d327fae, 0x3c46910c, 
    0x3cbdaedf, 0x3c822a3b, 0x3d664493, 0xbd067f4a, 0x3e104a5f, 0x3db03453, 0x3dd8f2b0, 0xbccbe7b4, 
    0xbdaf80a6, 0x3deeb8e8, 0x3cb36246, 0xbd8dbe56, 0xbcf6d440, 0x3dff8e7c, 0xbe269b43, 0x3cc73c93, 
    0x3bf30d25, 0xbd6f1659, 0xbcadcf24, 0xbdb3ce39, 0x3e47d77c, 0x3d22e266, 0xba940b8c, 0xbd8d11b7, 
    0xbe791979, 0xbd836ce5, 0x3bd5daa6, 0x3cac6095, 0xbe42088e, 0x3d55354b, 0xbdcaa911, 0x3d9de0f5, 
    0xbda64532, 0x3c77598f, 0x3c318a34, 0xbe36f1f7, 0x3dc55e56, 0x3c9ccae1, 0x3deba56e, 0x3aafb95a, 
    0xbcea7ad2, 0x3db394ff, 0xbc429da4, 0x3c4a39ca, 0xbcd66398, 0x3d601ce0, 0x3d8fbb69, 0x3dc6ef91, 
    0xbe439ec3, 0x3e12200f, 0x3d1f8d0d, 0x3c39b91c, 0xbe397163, 0xbd157dbe, 0xbde7bb50, 0xbe1121f8, 
    0x3c92d0f4, 0x3da83356, 0xbdc745ea, 0xbe0e7e43, 0x3e8df860, 0x3dcf3d10, 0xbc627d29, 0xbd8bbc17, 
    0xbdf98c7e, 0xbe1b80aa, 0x3ea54b76, 0xbcadaad5, 0xbd13aafe, 0x3b1c2f63, 0xbdc2fa80, 0xbdc73666, 
    0x3df5380c, 0x3d4234f4, 0x3d02b6ea, 0xbec45a20, 0xbe38d7d1, 0xbd3e573d, 0x3daab7a2, 0xbe1dff34, 
    0xbe97dd8a, 0x3d1416ad, 0xbc8ffbae, 0xbdb8e607, 0xbe815f5c, 0xbca6a6d1, 0xbe64704b, 0x3ba1cae8, 
    0xbc9d91ba, 0x3dcb1079, 0xbdcacce6, 0xbe16f421, 0x3e11de23, 0x3d8bb8d3, 0xbd72d9fb, 0x3cb4976d, 
    0x3d02e68f, 0xbd8d68d2, 0x3e18d7cf, 0xbe26a519, 0xbd9bdb94, 0x3dbb5ee8, 0x3d0564b5, 0xbe2811b8, 
    0xbd972215, 0x3d190ac3, 0x3ce648d2, 0xbe914c59, 0xbe901c3b, 0x3d972838, 0xbc7f0072, 0xbdc3544a, 
    0xbecd823b, 0xbd305ba1, 0xbd14c05c, 0xbe4720dd, 0x3d81c54c, 0x3c380523, 0x3d356188, 0xbcff007c, 
    0xbe09076d, 0x3cbc48a7, 0xbd537cb7, 0xbde06190, 0x3d99f00b, 0x3e06d640, 0xbe4ea84a, 0x3deff1a8, 
    0xbe148c93, 0x3dd8b6a8, 0x3de99ae3, 0xbeb68b43, 0xbe23dab0, 0x3decaefe, 0x3db968b7, 0xbe74b439, 
    0x3d802382, 0x3d9ca096, 0x3d9a3dd1, 0xbe195900, 0xbdeb6082, 0x3dab366f, 0x3e125510, 0xbdbc9d1a, 
    0xbb9261d4, 0xbe93a898, 0xbe2eb735, 0xbe3701fc, 0x3d8070b5, 0xbe5c926a, 0xbd8ed27f, 0xbdbda3ca, 
    0x3cd5b8f2, 0xbd56b291, 0x3d588e16, 0x3de5fd37, 0x3d8ecc01, 0xbd03eff6, 0x3e4e9af8, 0x3c138db1, 
    0x3e0bcc9f, 0xbe5ee3ed, 0x3e4bb764, 0x3dbb4967, 0x3aabf97a, 0xbdaea63e, 0xbe34fc84, 0x3bc39ded, 
    0xbe586470, 0x3dcc409d, 0xbcd71154, 0x3d010c5d, 0x3d042264, 0xbdb1e428, 0xbe4113ab, 0x3e36b4b2, 
    0xbd0b3f7c, 0xbe7810b3, 0xbe89961c, 0xbea641c8, 0xbd0f22b3, 0xbe477edf, 0xbd1c1ab3, 0xbd91ff78, 
    0xbad40c10, 0xbd6a02ab, 0x3d8b8f96, 0x3d537c72, 0x3e2bd530, 0x3c807bbe, 0x3dace99f, 0x3c95f719, 
    0x3d88f81c, 0xbe31770c, 0x3e1c1d7a, 0xbd866478, 0xbd67c30d, 0xbcb4ce43, 0x3d470800, 0xbba81d46, 
    0xbdc4d99d, 0x3defbbc9, 0x3c1f9873, 0x3b868b7d, 0x3d34dc97, 0x3cf97b34, 0xbda5c0f8, 0x3e4f0fa6, 
    0xbd5f1e43, 0xbe8d549d, 0xbe4c7250, 0xbea98abb, 0x3e026877, 0xbe61a4e0, 0x3dc5ec7f, 0x3c0c3fbc, 
    0xbde6f55a, 0xbdb4435f, 0x3d9e9f92, 0x3d6e612a, 0x3cad1664, 0x3c9d748f, 0xbe0936be, 0x3dbb0aaf, 
    0xbba0962f, 0xbdfe36bb, 0x3dce2eb0, 0xbe8de201, 0xbdde286b, 0xbcc403f5, 0x3dee967f, 0xbd656429, 
    0xbdef3792, 0x3de9c4b7, 0x3d990fd5, 0x3d90ddfb, 0x3c59505a, 0x3c1a5c01, 0xbd3a46b6, 0x3e517471, 
    0x3cd8febb, 0xbcb1ec5a, 0xbe096a21, 0xbb3e57bc, 0x3cd1f220, 0xbd293a74, 0xbe72a619, 0x3dcfb96c, 
    0xbd5dfc8b, 0xbdba8a16, 0xbcbf4da4, 0xbb06e40d, 0xbe36f604, 0x3d2b8df6, 0xbdcb808a, 0x3e425e59, 
    0xbe0d6ee7, 0x3dacdbc6, 0xbdeb4ac4, 0xbdaad2cd, 0x3dcde277, 0xbcaadc8d, 0xbdc32b17, 0xbceebf33, 
    0xbe620c69, 0xbd28ad1e, 0x3dbba466, 0x3bf6289f, 0xbd4a0aa9, 0x3dd13876, 0xbe0a6680, 0x3d037b85, 
    0xbc4f5171, 0x3cfd9acf, 0xbd88da5f, 0xbe017737, 0x3df0fbc0, 0xbe4b94ae, 0xbd1a4a77, 0xbd1f0065, 
    0xbe694f37, 0xbda1b8fd, 0xbd427013, 0xbcc224c9, 0xbc8326aa, 0xbe32a672, 0xbd9ab440, 0xbcd71527, 
    0xbe58804b, 0x3d3dc97a, 0x3daad18f, 0xbd10cb52, 0xbd82c508, 0x3d1d700d, 0xbe01f664, 0xbcb43a80, 
    0x3d8a21f6, 0xbd93dcd4, 0x3cf61b07, 0xbb090f21, 0xbddbf882, 0xbe240db5, 0x3ca79272, 0xbc1d3b4f, 
    0x3c87b4c8, 0xbd4ba903, 0xbc5cb0bc, 0xbdb32a47, 0x3dd6d84a, 0x3e0178f8, 0x3c616edc, 0xbe613c69, 
    0x3e3e1758, 0xbdc96dab, 0xbbd933f9, 0xbce8e2eb, 0x3d29ce85, 0xbd212494, 0x3d3b174c, 0xbe5f6e40, 
    0x3cf36d21, 0xbd81b6af, 0xbc916862, 0xbd1d6bd0, 0xbc30458a, 0x3d011776, 0xbd429820, 0xbc8527b5, 
    0x3c96dba9, 0xbdcafdff, 0xbe08ab57, 0xbd30aa5a, 0x3d7befa4, 0xbe255bb2, 0x3c3b563c, 0x3d8332eb, 
    0x3d7758b5, 0x3bacf70c, 0xbcd2ac65, 0x3d192893, 0xbcf4ed69, 0x3bcb4a3a, 0xbd867723, 0xbd75830e, 
    0x3d373222, 0xbdd8b6d3, 0xbd88ef4d, 0xbe1ae201, 0xbd739872, 0xbe4e0d19, 0xbdc9a8d3, 0x3cfaff79, 
    0x3da8a2f4, 0xbded2821, 0xbdab469a, 0x3d739f9d, 0x3d63fa4c, 0xbd19936a, 0xbe1c5a0d, 0x3d708315, 
    0xbde17aef, 0xbd9f151d, 0xbddf9768, 0x3d74e9a1, 0xbdad0b5e, 0xbe225305, 0xbd72c86d, 0xbc7c0185, 
    0x3cd34df9, 0x3b8ae647, 0x3bd9cd58, 0x3ccb5246, 0xbd914a74, 0xbae0bd29, 0xbdd5d156, 0x3d9323c5, 
    0x3c2e5b3d, 0xbd2ee4d6, 0xbd9d2f31, 0xbe3c7060, 0xbd85594d, 0xbe4e77f5, 0xbdc4eded, 0x3d340408, 
    0x3c63db99, 0xbd9f3f73, 0xbba87b9c, 0x3d290fa7, 0xbcb45565, 0x3c9e5cd1, 0xbdd6f136, 0x3d7e8426, 
    0xbd1e8166, 0xbd912126, 0x3c3a7e8a, 0xbd20d207, 0xbd910261, 0x39c02930, 0xbd3019f7, 0xbc9ce25f, 
    0x3c43aacc, 0xbc88f428, 0xbcf9df58, 0x3d19caa3, 0x3d6037e0, 0x3c1e5127, 0x3cebfafe, 0x3c8c1d59, 
    0xbc3c9054, 0xbd2612c3, 0xbd8fce32, 0xbe1bdb1a, 0xbd1e689b, 0xbdc33135, 0xbdd19e64, 0x3e107187, 
    0x3d198354, 0xbbd151af, 0x3d1a0d48, 0xbd917067, 0xbd73139d, 0xbd5f8973, 0xbd02e484, 0x3d542fdc, 
    0xbcc95af0, 0xbd8b4b66, 0xbcd49f9f, 0x3d039bf9, 0x3c55b756, 0x3bd13b00, 0x3c92eafd, 0xbb5844d8, 
    0x3dbce3d0, 0xbe8a9c86, 0xbe0be2af, 0xbdeaa4ac, 0x3e4f2f9a, 0x3dbf87a2, 0x3e121f15, 0x3cf52fb5, 
    0xbd8807c9, 0xbe0a3611, 0xbcdf8a12, 0xbc5abdf6, 0xbe9be295, 0x3d2d408c, 0x3dbaac9c, 0xbe31ac90, 
    0x3ed4918e, 0xbdcc4a74, 0xbe8df030, 0x3bd8ca46, 0x3dd842d0, 0xbdd88e01, 0xbe28c176, 0x3c0eae1f, 
    0xbdad7655, 0x3d573ffb, 0xbe335256, 0xbcd80c21, 0xbdad7545, 0xbd086d8e, 0xbd5a6da2, 0x3dbe0f1b, 
    0x3d2aa0a3, 0xbe5adcdb, 0xbd980603, 0xbe39ae2a, 0xbea30c4b, 0xbdcc893c, 0xbe637045, 0x3d7ba7d2, 
    0x3d5ad174, 0xbd91cd17, 0xbb8ebf32, 0xbe4443cf, 0xbd07f287, 0xbe2f755d, 0xbc905a17, 0x3dd7ade3, 
    0x3dbc6b6d, 0xbe464105, 0xbdb17f9b, 0x3d568434, 0xbd63b6ce, 0x3cf71a72, 0x3e03cc27, 0xbcfa0538, 
    0xbeb24518, 0x3d83073b, 0x3cf6ab7c, 0x3e813bac, 0xbe94ec7c, 0xbde84c0e, 0xbea3b761, 0xbcbe0f72, 
    0x3e255314, 0xbe0a2fcc, 0x3e038db9, 0xbd30e849, 0x3eace882, 0xbdebc5a7, 0x3d054c51, 0xbeb4708f, 
    0xbdd66715, 0xbd964d2e, 0xbca3f2ed, 0xbd73bfa4, 0xbe392fcf, 0xbdfdc7a8, 0x3d081d24, 0xbe6c8fe0, 
    0x3d474a0c, 0xbe8ff903, 0xbdbe7c9b, 0x3dca2588, 0x3d99b71b, 0x3d9df79b, 0xbc97d093, 0x3ca73750, 
    0xbcb25a5d, 0x3d638382, 0x3dd851bf, 0x3c7ad37c, 0xbd3253cf, 0xbe7b4ac7, 0x3d082bd1, 0x3dd05bb1, 
    0x3d6340b6, 0xbe13b987, 0xbe9f9d70, 0xbeb5d11c, 0xbe006c22, 0xbe63a7f7, 0xbe7c2825, 0x3e0a3712, 
    0x3c45e549, 0x3e8cc33d, 0x3ea03a68, 0xbd80ee0a, 0xbe2d64ed, 0x3e8399a5, 0x3df8225b, 0xbe4d8e59, 
    0xbe244861, 0xbdcc1ad0, 0x3d6a9259, 0xbda9b403, 0xbe09653f, 0xbe17e4b9, 0x3d75a61f, 0x3e038fe6, 
    0xbe841f34, 0x3eb03265, 0x3c6daa64, 0xbde4ccb1, 0xbd7ebce8, 0x3e3836df, 0xbd98d0fd, 0x3c48a52e, 
    0xbd527f3f, 0xbe2e46eb, 0xbc7c40eb, 0xbe73bbfe, 0x3e535991, 0xbd2ca4a4, 0x3d3d700f, 0xbd30d2fc, 
    0xbe1403ea, 0x3d9150b9, 0x3e6d751d, 0x3d7a5751, 0x3e3b79ed, 0x3eed6fcf, 0x3d80c2c0, 0xbeb31a7b, 
    0xbc1eef80, 0x3cbe0517, 0x3e9c55a2, 0xbd45bc05, 0x3c732579, 0xbe20f7ff, 0xbdd3672a, 0x3d8af2a2, 
    0x3d95774f, 0x3eae4289, 0xbb206638, 0xbc8a576b, 0x3dca2976, 0xbdfa5410, 0xbd09a4a2, 0xbd894344, 
    0xba9bc9ff, 0xbe8ef0e8, 0x3e182753, 0x3e88c7ad, 0x3db59f8d, 0x3d7f0747, 0xbe122738, 0x3e007f7d, 
    0x3d2eb182, 0xbd504b76, 0x3de609a0, 0x3e19307a, 0x3e29eb4d, 0x3df08247, 0x3ddc5992, 0xbc5d6a7d, 
    0xbe25c70c, 0x3d9591ce, 0x3b575bbc, 0x3df478b9, 0x3e4af246, 0xbec2bc68, 0x3de1734e, 0x3d41f212, 
    0x3de2c0f7, 0x3e5bfedd, 0x3e67b192, 0x3d47c701, 0x3d50faba, 0xbd1f83e5, 0xbe2c3f9c, 0xbdb85ae2, 
    0x3d69ace1, 0x3e008559, 0x3da88845, 0x3e46abe4, 0x3d86ca05, 0xbd273494, 0xbdbf29ca, 0x3dc0c2fb, 
    0xbcb6d728, 0x3d8cd6b0, 0xbcbadc1e, 0x3e129409, 0x3e6c6652, 0x3d9b1dff, 0x3e7135cc, 0x3e4bd661, 
    0xbd814597, 0x3d56347d, 0x3d5b06f4, 0x3d1806e1, 0x3db7fd14, 0x3e24e4da, 0xbe8fc082, 0x3a152314, 
    0x3e31b498, 0x3e73830d, 0xbef67ad0, 0x3bd771a8, 0xbc4304dd, 0xbc2ace62, 0x3acaed45, 0x3e7a9176, 
    0xbd94de0c, 0xbdc00507, 0xbc507057, 0xbd6941ed, 0xbe6062e3, 0xbcc76b1b, 0xbe585a2b, 0xbe143926, 
    0x38e792d3, 0x3d3762c7, 0xbd04dbb4, 0x3e33d280, 0xbe26fb99, 0xbc9fee06, 0x3ddc3e79, 0xbdf0c197, 
    0xbdf4dd7e, 0xbe2592bd, 0x3e54255e, 0xbc973e20, 0xbd9233dd, 0x3e54fd16, 0xbf0e0023, 0xbd6244bd, 
    0xbe054670, 0x3e7af376, 0xbefaf087, 0x3dcfada6, 0xbd090238, 0x3dbf6026, 0x3d9f2971, 0x3e99786e, 
    0xbda6cc3a, 0x3d12fb48, 0xbb8661b8, 0xbdd34b5a, 0xbe5a4892, 0xbcaeff73, 0xbe096621, 0xbe8510b1, 
    0x3dc92171, 0x3d83d06d, 0xbd626603, 0x3e5e1306, 0x3d5f1d96, 0xbcbd218d, 0x3c7c5504, 0xbe940bc2, 
    0xbe20261e, 0xbd6f972c, 0x3d0406da, 0xbd6d615e, 0x3e358693, 0x3de5a309, 0xbeb575e8, 0xbd3b4b11, 
    0x3c30b27b, 0x3e79d374, 0xbedaeb52, 0x3db87fd5, 0xbda98d7f, 0xbd3db6f0, 0x3ddd3afc, 0x3e95211d, 
    0x3bb6cc3b, 0xbd98165a, 0xbdc21d70, 0xbce807c9, 0x3dcc6de5, 0xbcac8638, 0xbce08992, 0xbde4e31a, 
    0xbe163d3e, 0x3cee86f3, 0xbdb98827, 0xbd010eff, 0x3e094009, 0x3df69850, 0x3ce7a53a, 0xbbc6feaa, 
    0xbcfcf5ab, 0x3d997070, 0x3e12824f, 0xb8da9f8a, 0xbd066fd6, 0x3ccc3a55, 0xbc0dfd43, 0xbe01668e, 
    0xbb6e87db, 0x3dda7ff2, 0x3ca31bb6, 0xbcbc1705, 0x3d6f850f, 0xbd26da76, 0xbd9abe7e, 0x3d0a36bd, 
    0xbd325dcf, 0xbe049e50, 0xbd87b3b0, 0xbca660a3, 0x3d863239, 0x3bf94ab9, 0x3dd3c6a8, 0xbd666718, 
    0xbe0862e4, 0xbcc3b038, 0xbdf68dc8, 0xbd3136ec, 0x3d8d0616, 0x3d4519f7, 0xbc2a8ef9, 0x3d790a28, 
    0x3d60990a, 0x3d038123, 0x3c5581ab, 0x3cc9c378, 0xbd52d707, 0xbd98ed7d, 0xbdecf81b, 0xbe504994, 
    0x3d34995b, 0x3dcd6168, 0x3c9430a0, 0xbc9f3c4e, 0x3d9e169c, 0xbd915e98, 0xbdfed2ad, 0xbc013b28, 
    0x3ccba5e5, 0xbd721663, 0xbd78b5cf, 0x3d389dd1, 0x3db4ba47, 0x3d2991ee, 0x3dcd72e8, 0xbe00b26d, 
    0xbb9d515e, 0xbd3014eb, 0xbd9b4e7c, 0xbcfb11df, 0x3db4b11e, 0x3d81c59f, 0x3b4f5aad, 0x3da6df7a, 
    0x3d3ffdcc, 0xbcd7f2d6, 0x3cbc403a, 0x3c8a7d00, 0x3da286a1, 0xbdceda6d, 0xbcf47ebc, 0xbe2ef685, 
    0x3d8c0d31, 0x3dd2aa8a, 0x3d303721, 0xbd19b473, 0x3d5b2bb9, 0xbd61f5af, 0xbd53a010, 0xbd00b54f, 
    0x3d1df6e7, 0x3d976de7, 0x3d0e884b, 0x3e05631f, 0xbcc3da7e, 0x3be61468, 0xbe0a41ad, 0xbc0fd137, 
    0xbcf53fe1, 0x3ce07d82, 0xbbdec16a, 0x3cd13782, 0xbc87f43c, 0x3cc0da10, 0x3db0d360, 0x3d1e6794, 
    0xbe5996f2, 0x3da22970, 0xbd80ec52, 0xbe38206b, 0x3dcc19c9, 0x3dfb207f, 0xbe6405cd, 0x3d67d6ad, 
    0x3dac7585, 0x3e0b9592, 0xbe859770, 0x3db74c13, 0xbe1c7af9, 0xbde3c8bf, 0xbd5768c7, 0x3e7f4bee, 
    0xbdbb6a2c, 0x3c10f72d, 0xbd028461, 0xbdc7578c, 0xbe6cc3c2, 0xbced592f, 0xbe5f994f, 0xbd6d4d55, 
    0x3c17568f, 0x3d4d1692, 0xbd0df264, 0x3d51ba8a, 0x3c38126a, 0x3d593077, 0x3c99978f, 0xbe2fdda5, 
    0xbe56444a, 0xbd846cf3, 0x3e67ef5b, 0xbe4fd0e4, 0xbc6f7a0c, 0x3db2b1bb, 0xbed0dfa6, 0x3c45fd86, 
    0xbdf57942, 0x3e2a02e1, 0xbe5545fd, 0x3dc097fd, 0xbdb3fbde, 0x3d985532, 0x3c8c305b, 0x3e4c061d, 
    0xbdd26cb5, 0x3ce962a3, 0xbc289cbd, 0xbd180a2f, 0xbe5522d8, 0xbd58ab1e, 0xbe91c18f, 0xbd83a1c3, 
    0x3d9c0984, 0x3d8c26a7, 0xbde58fcc, 0x3ded8af1, 0x3df318bb, 0x3d207b8e, 0xbd19d2ed, 0xbe7e2015, 
    0xbe7479be, 0xbdf4e399, 0x3d972a16, 0xbe52c6d4, 0x3e1101b5, 0x3d519593, 0xbe8e6739, 0x3c818018, 
    0xbdfc53d7, 0x3e0ea016, 0xbe2185a5, 0xbbd48908, 0xbd977263, 0x3bd5612d, 0x3b09fdd7, 0x3e38362b, 
    0xbd9a157a, 0x3ca86e9c, 0xbd7a6a27, 0x3d9917af, 0x3d6ef121, 0xbc8a7d41, 0xbdc281ab, 0xbe5c409a, 
    0x3e465dea, 0x3e2fd519, 0xbc8252e6, 0xbd71556e, 0xbcbdd491, 0xbde2a186, 0x3e9b050e, 0xbc2bab0e, 
    0x3da69a8a, 0xbead83a6, 0x3e59bc04, 0x3e101441, 0x3e385695, 0x3d020291, 0xbec6db4e, 0xbd3d82fd, 
    0xbede376a, 0x3e2e25b1, 0xbe6df2b2, 0x3d8fbb1a, 0x3d17446e, 0xbd13bbaf, 0xbd831e60, 0x3e8fc849, 
    0xbe16efb6, 0xbd941456, 0xbdffaec3, 0x3d1553cd, 0x3e21b030, 0xbd4e82d9, 0xbdc05a0d, 0xbe0d62a4, 
    0x3df84450, 0x3dc364cb, 0xbd891521, 0xbdb619e7, 0xbdb42b9d, 0xbd246809, 0x3def0837, 0x3de3c3e7, 
    0x3dc7ed41, 0xbeb6bfc4, 0x3dc8439b, 0xbd7f8324, 0xbd07ca46, 0x3d646296, 0xbdee0093, 0xbcb32e4e, 
    0xbe32328a, 0x3e4c756c, 0xbe86b739, 0x3da1f50e, 0x3dd8a828, 0xbdb0c1bb, 0x3b9f026d, 0x3e7d0335, 
    0xbd8bb4ca, 0x3d4d6b12, 0xbdaf62ca, 0x3dd3338e, 0x3d425842, 0xbe5790cc, 0xbe6eb3a0, 0xbe249b9a, 
    0x3d9df52e, 0x3d952f87, 0xbce521bd, 0xbcd0fee6, 0x3d03e011, 0x3caa93df, 0xbc431346, 0xbda198a2, 
    0x3c2aed28, 0xbee85da5, 0x3d0c1943, 0xbe20176f, 0x3d0bb145, 0x3d44ea23, 0xbe83683b, 0x3c2974b8, 
    0xbe773221, 0x3e34bc2c, 0xbe8cafd6, 0x3d85ec21, 0x3c7781e6, 0xbea468e2, 0xbe50c7bf, 0x3e6a22c0, 
    0xbdff4d4d, 0x3c3da9ad, 0xbe2947a2, 0xbd83bd3b, 0xbe370405, 0xbd227790, 0xbe8383f2, 0x3ddfbd94, 
    0xbd333941, 0xbda7b277, 0xbe3412a5, 0xbe11a5a4, 0xbee07c1b, 0x3e315b52, 0x3c0fdc47, 0x39920cc9, 
    0x3c9265d1, 0xbc4bc593, 0xbdd33432, 0x3e190dc6, 0x3e1a4965, 0x3cf39b3d, 0xbe696086, 0x3cd96c8f, 
    0xbdd5f18c, 0x3aa8ba49, 0x3d40d8e1, 0xbe60d381, 0xbca2e412, 0x3cdf845d, 0xbe52e5ea, 0xbdfcd416, 
    0xbdf6b81d, 0x3d8dd28b, 0x3dcd3bb4, 0xbdb3378e, 0x3dff0734, 0xbe0df5ae, 0xbe0c7222, 0xbcb8a4e7, 
    0xbe315a62, 0xbcb71e0a, 0xbd16dec2, 0xbe3d2ca0, 0xbec3116a, 0xbd21aeae, 0xbd038ced, 0xbd715947, 
    0xbe11b797, 0xbddba7da, 0x3e130d20, 0xbc8a7ae0, 0x3e10a350, 0x3d4e49f3, 0x3e244d00, 0x3d2951a2, 
    0x3d805c0b, 0xbd818ead, 0x3ea27e11, 0xbed6b5ae, 0xbe2525a0, 0x3e009567, 0x3d6b9384, 0xbd9fa4d3, 
    0xbd626f08, 0x3d2eb0c2, 0xbdbfeef3, 0xbda20478, 0x3e6ac1c6, 0x3e37b75c, 0xbce63a4f, 0xbe672213, 
    0x3b91a573, 0xbd4d8462, 0x3d912a1b, 0xbe3934f0, 0xbea2be70, 0x3e220431, 0xbd92953d, 0xbea36f7d, 
    0x3d78f63f, 0x3ca61ca0, 0x3daeadd5, 0xbed231ff, 0x3d0bcf5e, 0x3e1e32be, 0x3d8b78f0, 0x3d6c6e35, 
    0xbd82935f, 0xbd7066d0, 0xbe4b192e, 0xbda483cf, 0x3dbca46d, 0xbd0f7277, 0x3d9b2fe8, 0xbe465b71, 
    0x3e13e516, 0x3cf671d2, 0xbe44908a, 0xbd889df5, 0x3e185dc8, 0xbe9cb0cc, 0x3dca331e, 0x3e4e623d, 
    0xbe6a2edc, 0x3e7b4b5a, 0x3dfe9f53, 0x3d050c98, 0xbda820c9, 0xbd00ebba, 0x3e0a5934, 0x3c9293df, 
    0x3dbfee5e, 0x3d875174, 0xbe538df5, 0x3d496674, 0xbe0df48c, 0xbdab2aca, 0xbe378b0a, 0x3e13ebb7, 
    0xbd5c0ab4, 0xbd2ac446, 0xbce3680e, 0x3e31bf1a, 0x3e8382d1, 0xbcb9ff74, 0xbefe9d64, 0x3dc0f39f, 
    0x3d6c56d8, 0xbe1433f8, 0xbcfd4720, 0xbea5ddcf, 0x3e6e8361, 0xbd6f3f41, 0x3e4e37aa, 0x3da9e15e, 
    0xbeab6f0d, 0xbe33bfec, 0x3dcf4dc1, 0x3db35256, 0x3e320994, 0xbc95ab41, 0x3deb6b86, 0xbe44f8b8, 
    0x3d9a1ae5, 0x3e288fa5, 0x3e2e9c26, 0x3d0e2ab9, 0xbcb86024, 0xbe12fc22, 0xbdcc12c3, 0x3e3dd3b7, 
    0x3e141182, 0xbe2375e7, 0xb9b267f2, 0x3dfa28e2, 0x3e015188, 0xbe48d1d6, 0xbeac64c6, 0x3d8e6cfa, 
    0x3db6ec75, 0xbe09b034, 0x3d9df1e5, 0x3e049b18, 0x3d80e9eb, 0x3ea9094d, 0x3e5c6fab, 0x3e45d37b, 
    0x3dd0db27, 0xbe60e8b6, 0x3dfcfbec, 0x3dd2f715, 0x3ec1f2e0, 0xbe52ff30, 0x3e4e85c9, 0x3ea667c5, 
    0x3983b096, 0x3e1b7bdc, 0x3cb1eee3, 0x3e212648, 0x3e504ea6, 0xbe8a2d14, 0x3e817a6c, 0x3e593f04, 
    0x3e2b87a0, 0xbe5c5763, 0x3dcd4682, 0x3e4111b1, 0x3e34fd78, 0xbdbad40e, 0xbe3c3be6, 0x3d174717, 
    0x3dc30a5a, 0xbd7e9d47, 0x3dd48789, 0xbe281a37, 0xbd8cfa8e, 0xbd27cf6d, 0xbe3e6df1, 0x3d9ddf68, 
    0xbcc8fe2c, 0x3e7d540f, 0x3eb67507, 0x3e0e1584, 0x3d9552ee, 0xbd935111, 0xbccc420a, 0xbd84db5a, 
    0xbe395172, 0x3da33489, 0x3d8fb91e, 0xbe242298, 0xbebb1ba2, 0xbc5dd1fe, 0x3cf47bdc, 0x3c253150, 
    0x3d2013dd, 0x3e4b821a, 0xbd66d9b7, 0x3e3a812b, 0x3e02c100, 0x3d4ac90d, 0xbda969da, 0x3e3b0527, 
    0xbd922daa, 0xbe101812, 0x3d851d6d, 0xbda278d3, 0x3d31f486, 0x3c72e8f9, 0x3e7d1657, 0xbd20fd81, 
    0xbe1d5f75, 0x3c3196e6, 0x3e69a40b, 0x3d62ba90, 0x3f0e4178, 0x3ea9eac5, 0x3e1d0c23, 0xbdc5cdc7, 
    0xbcc02625, 0xbd923d8b, 0x3e99b9f6, 0xbe2bbfb3, 0xbbe8c82e, 0xbd6f3a78, 0xbe23b8e4, 0xbe1fd4db, 
    0x3e0f1ff1, 0x3e8099c4, 0xbe892e8f, 0x3d801b62, 0x3e4c6ecc, 0xbe2fafb9, 0xbe09d718, 0x3ca2c367, 
    0x3e1d46c8, 0xbe05f2ac, 0x3d634e21, 0x3ebe82ef, 0xbde81432, 0x3e3a1e09, 0x3ddd70e3, 0x3dcf0565, 
    0x3e24cedc, 0xbcf47957, 0x3e134dca, 0x3db9ee6e, 0x3f15c53f, 0xbe4c4528, 0x3e755d0d, 0x3e21b8f3, 
    0xbe48e194, 0xbe834427, 0xbb5ee610, 0xbe0db61b, 0x3f1264a0, 0xbeffc517, 0x3e895de5, 0xbdd281cc, 
    0x3e180a7c, 0x3e17ce9f, 0x3ec4bb95, 0xbd23ed7e, 0xbe2aff5c, 0x3dc8e5e2, 0x3d3b93c8, 0xbd5f163a, 
    0xbd164f62, 0x3c0be3d2, 0xbc66d72f, 0xbe46caae, 0xbe97ebbb, 0xbd7900f2, 0xbdad88f5, 0xbdef877d, 
    0xbe2930b8, 0xbd0b4a32, 0xbe762b81, 0x3de7dab9, 0x3e073503, 0x3e47762c, 0x3ec6902f, 0xbe34d354, 
    0x3cfb6ed4, 0x3e67affc, 0x3d78a1f2, 0x3dedc186, 0x3e717076, 0xbda54025, 0xbe73b089, 0xbe218b68, 
    0xbd32f043, 0x3f02b0f6, 0x3e524d84, 0x3dd403fd, 0x3d42c615, 0xbc3789b4, 0xbd95b06f, 0xbd13f88f, 
    0xbd9c1dfd, 0x3dfa1a65, 0xbe190eac, 0xbdeb7c4a, 0x3e1ae76b, 0xbd9ad700, 0x3e6402fd, 0x3e86cdde, 
    0xbe97b7ab, 0x3844ae9b, 0xbe812b56, 0xbce857b4, 0x3b8b637a, 0x3ea1385e, 0x3eab3984, 0x3d666085, 
    0x3abca9e7, 0x3c57ddee, 0xbcdb0589, 0x3bb3823e, 0x3d5e1740, 0xbd0b7649, 0xbd0457b6, 0xbd662123, 
    0xbda5a5b0, 0x3ef08a70, 0x3d1bf9e3, 0xbe1d9bf5, 0x3e63cc3c, 0x3e164249, 0x3d71e26d, 0xbda940eb, 
    0x3de3d694, 0x3e86d815, 0xbda71496, 0x3d9dd3c2, 0xbe8c7d3a, 0xbde1f992, 0xbcc6df2a, 0x3e0fd11c, 
    0xbe3a81f4, 0x3d184a4f, 0xbdfe5a9c, 0xbe4b3cfb, 0x3da564c1, 0x3e52d753, 0x3eb927ee, 0x3d351671, 
    0xbe0efc9d, 0xbdc6bfcf, 0xbe90c464, 0xbd96b4dc, 0x3cf26835, 0x3d1dfcd3, 0xbe7b5241, 0xbccdbef4, 
    0xbe187b6e, 0x3eea0751, 0x3db34311, 0xbe12ae58, 0xbe1b858e, 0xbe70ac7a, 0x3c5bd1e3, 0xbd310ef5, 
    0xbcce98c8, 0xbcc1c058, 0xbd501fce, 0x3d3647a4, 0xbbc947ef, 0xbd1bd923, 0xbda39d23, 0xbe11b528, 
    0xbd2bcbba, 0xbc6fb359, 0xbe584d83, 0x3d9e2474, 0xbe27eeff, 0x3dd1f481, 0xbde4016a, 0x3d28fe9a, 
    0xbe1e879d, 0xbc313f85, 0xbe3b641e, 0xbda1e57f, 0xbc0d326f, 0xbe4d8968, 0xbca63ff7, 0xbe5eb41a, 
    0xbd3e18cd, 0x3e84e981, 0xbc49e032, 0xbc920771, 0xbd4ec4ba, 0xbdb216fb, 0xbe19c82a, 0xbdb8cdf6, 
    0xbd4bf8ca, 0xbd9a5760, 0xbdc33a25, 0xbcc9347a, 0xbc8209bc, 0xbd7f8dd3, 0xbd54ccb2, 0xbe1bc317, 
    0xbd6c9f78, 0xbb8a050d, 0xbe73c57c, 0x3d9c03f7, 0xbdba65f7, 0x3dbf6387, 0xbd3264fd, 0xbd30f32c, 
    0xbddf8ed4, 0x3c7a7526, 0xba7f1c62, 0xbd767ccc, 0xbd1a2daf, 0xbe28992d, 0x3ce3daef, 0xbe76a11e, 
    0xbd64c39e, 0x3e822101, 0xbd7ba7b8, 0xbcdd80bc, 0x3c2d4e63, 0xbe12566f, 0xbe32685a, 0xbe00951a, 
    0xbe13016c, 0xbd6a22bd, 0xbdbd4e49, 0xbe002f7a, 0xbc7d8cc7, 0xbd8c8815, 0xbcaae00d, 0xbe126b5b, 
    0xbdab1726, 0x3b582f4f, 0xbe82d9fe, 0x3d5fa1f6, 0xbd15eb0a, 0x3db6c400, 0xbd8510c4, 0xbd8b5836, 
    0xbdaa9665, 0xbbe9002c, 0x3d5fe768, 0x3caf3053, 0xbe162642, 0xbe48e9d2, 0xbe1691a7, 0xbe8201e4, 
    0x3ccd9110, 0x3e731b49, 0x3c057ffa, 0xbd3015ae, 0x3d906957, 0xbe133353, 0xbe8873ba, 0xbdc93cb5, 
    0xbdda26d8, 0xbddf9727, 0xbe2a3978, 0xbd82234c, 0xbd3d3ef9, 0xbe5066ea, 0xbd890e1b, 0xbe0891a5, 
    0x3de7ed9f, 0x3e17c7f3, 0xbe224d1d, 0x3bb4da7f, 0x3e43ab44, 0x3bcb4a2e, 0xbc5d99fe, 0xbe8137f6, 
    0xbd74570f, 0xbc0aeff1, 0x3e69ab2e, 0x3dcb3b79, 0x3c3dabb2, 0xbd73f2ba, 0xbe4c1601, 0xbcab6993, 
    0xbea312a0, 0x3e3f134b, 0xbdbacb49, 0xbd13bad5, 0x3d9f32c8, 0x3defd90f, 0x3b92218c, 0x3d9b169f, 
    0xbe1b2d85, 0xbcbc3978, 0xbe3f69f6, 0xbd85bc17, 0xbd80084f, 0xbe461df3, 0xbe4319ff, 0xbdced0f7, 
    0x3cb51426, 0x3dce027e, 0xbe311bcd, 0xbc7a30e5, 0xbd158891, 0x3da849c1, 0xbc41b143, 0xbe737bb7, 
    0xbc52acf6, 0xbdaaf9bb, 0x3e130dc9, 0xbcfe061f, 0x3d0c898c, 0xbded878f, 0xbdd6a064, 0xbe07cb19, 
    0xbe2be159, 0x3e50ce24, 0x3bb44eed, 0xbd5bfae3, 0x3dd901ea, 0x3d60d7db, 0xbd57b92b, 0x3d34c14c, 
    0xbe273471, 0xbda52f41, 0xbe159341, 0xbe317a86, 0x3debbf61, 0xbd896009, 0xbc5434b4, 0xbba1cec9, 
    0xbe146bc2, 0x3d0cefe0, 0xbe4b5f7e, 0x3bf54336, 0xbe5ef6ee, 0x3d9f6fe1, 0xbe2e28a9, 0xbd890577, 
    0xbd9148bb, 0x3d81ba72, 0x3d97ab45, 0xbe8ba31b, 0xbb04d77c, 0xbd709460, 0x3d7d255e, 0xbe1cf5d1, 
    0xbdb9cba0, 0x3e473491, 0x3d1f9430, 0x3d4197ce, 0x3dfd3e64, 0x3d4e792d, 0xbc24d851, 0x3cbe1a11, 
    0xbd5c4be6, 0xbdccbd5e, 0xbd03c6c3, 0xbe38b16f, 0xbe078e7a, 0x3c11d0ca, 0xbceb3b81, 0xbd8c0a95, 
    0xbe5987b4, 0xbe389006, 0xbe96bfc7, 0x3cc2a113, 0xbd7438d4, 0x3da24a9a, 0x3cf25508, 0x3cd57a90, 
    0xbe97d5ab, 0x3deddf6c, 0x3d66cdd8, 0xbd609969, 0x3e0bef17, 0xbe44f7be, 0x3d1ddea8, 0xbd5fa7db, 
    0x3deb3345, 0x3e470ecb, 0x3e364790, 0xbdf81af0, 0xbd900c9c, 0x3ccabd83, 0x3c6c94c9, 0x3dece0d2, 
    0xbca075d7, 0xbcfe638e, 0xbd7ed173, 0xbe015174, 0xbe7408f8, 0x3d2c9574, 0x3d4444c3, 0xbe66d261, 
    0xbe399ce6, 0xbe014eb8, 0xbeb1e7c7, 0xbcc8fdf3, 0x3cd0f700, 0x3e3ace94, 0x3da6d036, 0x3d487796, 
    0xbe7f48b0, 0x3dc0799d, 0x3e1ba973, 0xbc8441bc, 0x3dd269ba, 0x3be83a8a, 0x3c64550f, 0xbdc9925d, 
    0x3d06ca1a, 0x3e3bdeba, 0x3e0926cf, 0xbdd07a9d, 0xbd61cec3, 0xbcd66a37, 0xbcbc1081, 0x3dcc06e9, 
    0x3d13f2cb, 0x3c97e269, 0xbd0c6b32, 0xbccb552b, 0x3d416009, 0x3c7dde8c, 0x3e354946, 0xbe2fa36e, 
    0xbe7e99a2, 0xbe2f5041, 0xbea12b10, 0x3c8000e9, 0x3d1e43a8, 0x3e359a68, 0x3e37b2e6, 0x3d62f584, 
    0xbe8b7148, 0x3daacc39, 0xbd34ccdd, 0x3d3d410c, 0x3df8299f, 0x3cbb8452, 0x3ccffc9d, 0xbd6e1305, 
    0x3e024fdc, 0x3e49f46b, 0x3d33c4a1, 0xbe115b7d, 0x3e0b1cff, 0x3b9a9d51, 0xbd4ff045, 0x3e03a135, 
    0xbe17f6f8, 0x3cedf14e, 0xbd994156, 0xbdc7861b, 0x3dcfc4cb, 0xbd99dcda, 0x3d68ee71, 0x3dcc9748, 
    0xbe33a200, 0xbe3fd7d6, 0xbecb2c93, 0x3e27a5d3, 0xbe0c5cf0, 0x3e7e26c6, 0x3e3b351d, 0xbdf8ed01, 
    0xbd56b653, 0xbcb90ff3, 0xbea64352, 0xbc531a4c, 0x3d6922a4, 0xbe32cf8f, 0x3e5eeecb, 0xbe407cc5, 
    0xbdc426ca, 0x3f2c4861, 0x3e9890b8, 0x3dd04f96, 0x3d808b24, 0xbeb76112, 0xbdbc3981, 0x3daa47aa, 
    0xbe1525b4, 0x3ccc514e, 0xbe071b12, 0xbe97cb16, 0xbe47c051, 0xbd909df8, 0xbdc051de, 0x3e3d30b8, 
    0xbca812f3, 0xbe496f6a, 0xbed986e9, 0x3d47727c, 0x3cc23ba1, 0x3e975958, 0x3e4778c4, 0xbb87aef6, 
    0xbe1ce3a5, 0xbd53baee, 0xbdb52008, 0x3caf0515, 0xbe1618fd, 0xbe3a408e, 0xbd43c602, 0xbdea963a, 
    0xbdf6f150, 0x3f2c128e, 0x3df56aa3, 0x3dc86dec, 0x3cdd24b6, 0xbe922195, 0xbda6520d, 0x3d1bed32, 
    0xbd8d7372, 0xbd758133, 0xbe11bc26, 0xbd1e93b5, 0x3d3b0398, 0xbda3e320, 0x3e432aed, 0x3e228cd5, 
    0xbb32eb07, 0xbe2718b8, 0xbee1fe0f, 0xbd24ed81, 0xbc0e3a29, 0x3e992521, 0x3e137db3, 0x3d47a965, 
    0xbe26804e, 0xbe01ae93, 0xbd956281, 0xbd931baa, 0x3c9d5737, 0xbe5e701d, 0xbdc3337b, 0xbd5fa7ee, 
    0xbe257500, 0x3f2aedae, 0x3e998302, 0x3d514054, 0x3d556f6c, 0xbe48238f, 0x3ccb9209, 0x3d17ff65, 
    0x3d9edad8, 0x3c85155c, 0xbef6c011, 0xbdff234c, 0xbdb601be, 0xbf0f2132, 0xbdece049, 0x3d73f600, 
    0xbdbf9375, 0x3e83f92e, 0x3eab33ac, 0xbcfda991, 0x3ed9fd41, 0xbda91b4b, 0x3e7ad982, 0xbeccdde9, 
    0xbe396b10, 0xbdbb58de, 0x3dbe9d60, 0xbe45b953, 0xbe8817fc, 0xbd4f7b77, 0xbd03c46e, 0x3db82ee0, 
    0xbe1f6847, 0xbdac842a, 0xbdfdbee1, 0xbe314ce9, 0x3e22647d, 0x3d7cc08e, 0xbea90402, 0xbe11e6eb, 
    0xbdaddb4c, 0xbe2f2f51, 0xbd0d0d2a, 0xbed915bb, 0x3e93ce97, 0x3cf9d1f2, 0x3dcaba6d, 0xbe1a80ae, 
    0xbe009b06, 0xbeac561e, 0x3e2029e8, 0x3e845868, 0x3ee50e45, 0x3d4ee334, 0x3e5abd4c, 0xbeb1bdcd, 
    0xbdb764c3, 0x3e34d062, 0x3f2953d1, 0xbe3b747a, 0x3b8c2c47, 0xbe42ebc2, 0xbe6d899c, 0xbdb32960, 
    0x3d29fb50, 0xbe52b88d, 0x3dc85b0b, 0xbe2af75a, 0x3e391981, 0xbe0e979d, 0xbe69d2bd, 0xbe51eca4, 
    0x3e02c80b, 0xbe3bafe0, 0xbe0ea4a3, 0x3ed22c64, 0xbe417930, 0x3e50a3a2, 0xbdbceb13, 0x3dceaf53, 
    0x3f038507, 0xbf11a4ed, 0x3db331a6, 0x3ea74500, 0x3f2dbaa6, 0xbedf9d65, 0x3f08aba9, 0x3e9271be, 
    0xbe628df2, 0x3e1d1213, 0xbe1055d9, 0x3e29b6fc, 0x3f37ed8b, 0xbf47ce1f, 0x3e9241fe, 0x3d154418, 
    0x3c8230d8, 0xbeb7f65e, 0x3d4f773d, 0xbd5edc3b, 0x3e2a21e8, 0x3d8026e5, 0xbe397a7d, 0xbe74e196, 
    0xbd5bcb70, 0xbdab176f, 0xbe0e52df, 0xbdbd3ab7, 0xbd0d3e61, 0xbdbe5c75, 0xbd06177b, 0xbe9778da, 
    0xbd42b517, 0x3dee2f2b, 0xbe06252a, 0xbcb82a18, 0x3b916703, 0x3e003508, 0x3da2fe3d, 0xbda77cea, 
    0x3a61beae, 0xbce582d3, 0xba52653d, 0xbc2247c2, 0x3cae7077, 0x3dafc40b, 0xbe03a309, 0xbecdc05b, 
    0xbdb0e6f3, 0x3dd514b7, 0xbdcb6818, 0xbe098e4a, 0x3e1e316b, 0x3c3f8561, 0xbdd02786, 0x3d10c296, 
    0x3c45898c, 0xbe31ed42, 0xbd0bc316, 0x3d299e19, 0x3e0b01db, 0x3d73f12d, 0xbce5a069, 0xbe186a0e, 
    0xbd5acdc5, 0x3bfe8dba, 0xbdf4a401, 0x3dcf8419, 0x3c3a2af8, 0x3e260273, 0x3c3bbb22, 0x3c795e14, 
    0xbccb2568, 0x3dd0d609, 0x3e1ea6c1, 0x3cb4e0f9, 0x3d9f1305, 0x3d193421, 0xbcd7748d, 0xbeb03335, 
    0xbcc1bc82, 0x3dcffb41, 0xbce35c1e, 0xbdace4b1, 0x3dea85d2, 0x3d49e85d, 0xbe45ff73, 0x3d363b05, 
    0x3e26d56a, 0xbd77e866, 0x3d47c246, 0x3e7079bb, 0x3dba51b7, 0x3dc7a0d0, 0xbdd89be9, 0xbe5a42e6, 
    0xbd4f3442, 0xbd54ce84, 0xbe0031e4, 0x3de28975, 0x3d8dc3ca, 0x3ddef47e, 0xbb287b18, 0x3dad0a38, 
    0xbcb87f3d, 0x3d45a250, 0x3e2703a9, 0x3d39ef8b, 0x3e5c2da5, 0xbd001ed6, 0x3d89573d, 0xbe9b38c9, 
    0xbc0dc221, 0x3dc73c99, 0xbdbce72f, 0xbd58abdd, 0x3d93977d, 0xbcd43c3e, 0xbd3b5c01, 0x3d87b15c, 
    0x3dd866a9, 0xbe0072cf, 0xbe7f310b, 0x3d84fdac, 0x3dc2b130, 0xbe0bb24a, 0xbe5b894b, 0x3b27992b, 
    0x3d8e5ef9, 0xbe0fcace, 0x3e0035db, 0xbe519a83, 0xbc9b6a96, 0x3e27fc59, 0x3d810c0b, 0xbe1c5892, 
    0x3eb93b3b, 0xbe5e9c08, 0x3e71dada, 0xbd90f95f, 0x3e06ae39, 0xbea25a06, 0xbe3fd167, 0x3ed75279, 
    0xbe68ee94, 0x3e0e04af, 0xbdbb5c0f, 0xbde21049, 0x3dff83cf, 0xbe2a2d7d, 0x3c5f8325, 0xbe75df1d, 
    0x3c421dab, 0xbe5f1d3d, 0xbefde05f, 0xbe43b188, 0x3dc249d2, 0xbe458493, 0xbe06b449, 0x3ea1905d, 
    0xbbb5bf55, 0xbe190746, 0x3e80cd01, 0xbe908842, 0xbd600d6a, 0x3e287578, 0xbda6420f, 0x3cd1ad59, 
    0x3e347bec, 0xbd60d7c8, 0x3e3c0e35, 0xbebe6cb3, 0x3bc27dd3, 0x3e8043c7, 0x3e4c6975, 0x3e5a6481, 
    0xbec20933, 0x3dd4d0b6, 0xbd5ba174, 0xbdca851a, 0xbc66283f, 0x3e88cb95, 0xbe7b1262, 0xbe0b059b, 
    0xbe0f9f48, 0xbe7ddf01, 0xbeca14a8, 0xbea79b59, 0x3eeced40, 0xbd3a7898, 0x3e0dda85, 0x3e34da16, 
    0xbf1c12ba, 0xbf0083e8, 0x3e7a59df, 0xbe811bab, 0xbe089a71, 0x3d4292e9, 0xbf115836, 0x3ea19bde, 
    0xbe6ebf7e, 0x3e9974b6, 0x3e18e0c0, 0xbf4cc923, 0xbe849cde, 0x3e3b381f, 0x3ee239e6, 0x3e1344db, 
    0x3ca57da5, 0x3d9c2763, 0x3cfbe451, 0x3e804802, 0x3d936ce2, 0x3e295e46, 0x3e6244bc, 0xbe168a4f, 
    0x3de1273b, 0x3e706c08, 0x3d1e326a, 0x3c6a0513, 0xbe9675db, 0x3dbcaf32, 0xbd9df5d3, 0xbe201005, 
    0xbe8f5dae, 0xbe0c2e57, 0xbdf80d48, 0xbdac4528, 0xbcb8e69e, 0x3e23e74f, 0x3dd1af10, 0xbde8acb7, 
    0xbe14e061, 0x3da3de5e, 0xbe797dee, 0x3d2cb2ec, 0x3e32796a, 0xbdefa470, 0xbc2d52d8, 0xbda6f92d, 
    0x3e090e31, 0x3e4c891c, 0x3e0938c9, 0xbe4928f3, 0xbe581796, 0xbd9fc764, 0x3dd11f3b, 0x3d8b6c4c, 
    0x3dd151fc, 0x3e516d79, 0xbb1494dc, 0x3c85281a, 0xbe419cc3, 0x3dacb85d, 0xbdfdabec, 0xbe1d758e, 
    0xbe8bb359, 0xbe09b940, 0xbe17a506, 0xbdc3e7e1, 0x3d49ec08, 0x3e422b88, 0x3e5cb4ee, 0xbd7d5075, 
    0xbd455857, 0x3dde7c1a, 0xbe152438, 0x3dfd1f3d, 0x3dfb18fa, 0x3d035daa, 0xbd28fcee, 0xbd9a04d0, 
    0x3d8490aa, 0x3e3966ac, 0x3d9e9d9f, 0xbdb1ef32, 0xbe5e94b6, 0xbdaf39b1, 0x3cd9e6fd, 0x3d992d80, 
    0x3e1a9621, 0x3e6c02d6, 0x3d09f856, 0x3d7de2cf, 0xbe44d2d4, 0x3dcb8924, 0xbc8dbe47, 0xbe78217e, 
    0xbe883c95, 0xbdd70a64, 0xbdc0936b, 0xbd1484f5, 0x3bfdeed9, 0x3e1f9146, 0x3e960329, 0xbd8161a5, 
    0xbd23f7ea, 0x3e1c03d1, 0xbdb1aa62, 0x3e3252af, 0x3e1bbb9c, 0x3d982e54, 0x3d8b4d1f, 0xbdde2285, 
    0x3dce5d8a, 0x3e4e8a31, 0x3d8cb008, 0xbd8179f6, 0xbdcaa8ec, 0xbd3edb6a, 0x3cdaeaae, 0x3d8929aa, 
    0x3e84913c, 0xbe0a50a9, 0x3e8a2832, 0x3e25c1fa, 0x3e96fcf3, 0x3e1f74a3, 0x3de0ec8d, 0xbe1771e7, 
    0xb9cfb54e, 0xbde3bcdb, 0x3ef5efcd, 0x3d83d32e, 0xbe404941, 0xbd239aae, 0x3d68c075, 0x3d68f63f, 
    0x3d70ca0d, 0xbc953434, 0xbe288831, 0xbdee2b35, 0x3c2e186e, 0x3ddb63c7, 0xbe4f1f43, 0x3e3e8587, 
    0x3dbfee24, 0xbe802f45, 0xbd1ab3e5, 0x3d40d0e1, 0x3dbbae18, 0xbe00b74c, 0xbcfb2136, 0x3d97c38b, 
    0x3e5d6a57, 0x3d62c3b1, 0xbde48aa3, 0x3e7d3761, 0x3d873664, 0xbd2b30bb, 0x3e45cf07, 0xbd864973, 
    0x3e53ee3d, 0xbeb029bd, 0x3f0bfc6d, 0xbb96f62e, 0x3dab5e34, 0xbdccf376, 0xbdac8231, 0x3ec414b8, 
    0xbeb2c60b, 0xbdddd3b9, 0xbea3a4a9, 0x3e143d3f, 0x3e45d5db, 0xbc6861e7, 0x3e00ba69, 0x3e6859ae, 
    0xbe2c8db1, 0xbe582840, 0x3e530338, 0x3e216243, 0xbe2a0d15, 0xbe5510c3, 0x3d6eb040, 0xbd3536e1, 
    0x3dc2044d, 0x3daaf82b, 0xbebacd22, 0xbd268c1d, 0xbe431f2f, 0xbee47c10, 0x3de477ea, 0xbb5dc184, 
    0xbdc5039b, 0xbe935a7d, 0x3f0701c3, 0xbef3d3ca, 0x3e352cbc, 0xbc951f96, 0xbd4d78c8, 0xbd954c67, 
    0xbdd8da42, 0xbebc7e8a, 0xbdb0b1fd, 0x3dd14bc3, 0x3c27431b, 0xbd8c0bd3, 0x3dc6793f, 0x3daa7d95, 
    0xbce353a6, 0xbe675cc2, 0x3cd908f1, 0xbdc81b63, 0xbeb9195d, 0xbe7da27e, 0xbd91fc34, 0xbd012bcb, 
    0xbccbd19c, 0xbee4b06c, 0xbde9176e, 0x3e2f04bb, 0x3d8ef93c, 0xbdadb382, 0xbea791a0, 0xbebf9685, 
    0x3e1518c3, 0x3d6645bd, 0x3e89cff9, 0xbe89dcef, 0x3e3ae7c0, 0x3d382331, 0xbd24773d, 0xbe9adbf1, 
    0xbf015db1, 0xbe90d41e, 0x3e5e3333, 0x3e81e52f, 0x3e88410b, 0x3d510093, 0x3e20e73f, 0xbd37908a, 
    0x3eb9325a, 0x3d9b3314, 0xbe56447a, 0x3e33b79f, 0xbc00c26c, 0xbd92f3e8, 0x3de6cf2a, 0xbe02cd3b, 
    0xbdcc511e, 0xbcfdcd1f, 0x3e933a0b, 0xbe3372fb, 0x3d35472f, 0x3de9db3c, 0x3e5f158d, 0xbcc30957, 
    0xbe38dff6, 0x3d857bf8, 0x3d60ce48, 0x3ac93096, 0x3e1d4e26, 0x3e929ccd, 0x3e32bfbc, 0xbf0e74a4, 
    0x3f2023eb, 0x3e12b50d, 0xbe33402d, 0xbe4d78c8, 0x3ddc03bb, 0x3c15c4de, 0xbe864095, 0xbc95849b, 
    0xbe115485, 0x3dd3dba5, 0xbde67353, 0xbe9b8db8, 0xbd956bc7, 0x3e130aef, 0x3dd280ec, 0x3d93ff92, 
    0x3d8830bd, 0x3d0517ed, 0xbe7bf9d8, 0x3de4fa17, 0xbe15c320, 0xbdca717d, 0xbf0bc218, 0x3e5a8eb2, 
    0x3d918a90, 0x3c5ef7fe, 0x3e119b80, 0xbda79181, 0xbea06c9c, 0x3e67fbaf, 0xbe2fd71a, 0x3e1965f6, 
    0x3c5793bd, 0x3d7e0a78, 0xbf19da65, 0xbbc6839c, 0x3ec2edb1, 0x3ead78cf, 0xbe624b6a, 0x3d7aedd9, 
    0xbec36254, 0x3e00a8e6, 0x3d3dc9b8, 0x3e8425eb, 0xbe618bff, 0x3e951e39, 0xbeab1bab, 0xbc11b3d5, 
    0x3e19dccf, 0x3d15f3e2, 0xbc88ccef, 0x3d6b8bcc, 0xbd577448, 0x3d58f564, 0x3cd6189d, 0xbdb90440, 
    0x3c1b6474, 0xbe3a4d4b, 0x3e342358, 0xbd448f3d, 0x3dbb912c, 0x3da7f3a8, 0x3dca069a, 0x3cd50bbc, 
    0xbdb005a9, 0xbdca4ff2, 0xbda8d578, 0xbe0ac789, 0x3d2cd327, 0xbbb0a29d, 0xbda41e5d, 0x3de80af4, 
    0x3e1b61a6, 0xbd75af08, 0xbc071e6e, 0x3d8fa259, 0xbd527ccd, 0xbdcd48e6, 0xbd77dce1, 0x3c3a3219, 
    0x3cfd2a0a, 0x3b4ecd1b, 0xbda79db4, 0xbd5ec5ac, 0xbe629f79, 0x3afbacdf, 0xbd632eed, 0xbdb33a38, 
    0x3c82b431, 0xbe15ef28, 0x3e31ff99, 0xbd4f1749, 0x3e27c2d6, 0x3d668b98, 0x3d2cced8, 0xbd839bf0, 
    0xbd5b0baf, 0xbe1026e7, 0x3cc05ffc, 0xbe4b6a8e, 0xbd87b989, 0x3a7b581b, 0xbd894631, 0x3d3a1732, 
    0xbc285774, 0xbd2ff9ff, 0x3bc3b50d, 0xbcdf1fee, 0xbd8c2f0c, 0xbd924c6a, 0xbd89c7af, 0xbcce1825, 
    0xbd40c611, 0xbd36271e, 0xbe12fd3e, 0xbdd2b013, 0xbe89807e, 0xbcaa91c4, 0xbd8f3663, 0x3c31ef86, 
    0x3da85e99, 0xbdd6b928, 0x3e11f122, 0xbdb62d1f, 0x3e27169c, 0x3d90ba6c, 0x3cc001d1, 0xbdd566cc, 
    0xbd852630, 0xbe4becca, 0x3cc80999, 0xbe4471db, 0x39953fe1, 0xbd9fdd24, 0xbd836a84, 0x3d76fcde, 
    0xbd1b73c0, 0xbd884e70, 0xbc2a94a7, 0xbdfe7a33, 0xbd2876c6, 0x3d094895, 0xbd830e25, 0xbdc320ad
};

static const uint32_t _K35[] = {
    0x3e42cfc8, 0xbe807dd1, 0x3f3912dc, 0xbfc4d915, 0x3f8cbfd3, 0x3dbcd372, 0xbe8345a6, 0x3fee18ca, 
    0x3f75c644, 0x3eb062d1, 0x3ee682cf, 0x3f050e78, 0xbfb45ea2, 0x3f4ff7ab, 0x3dee23d8, 0x3f2d74e4, 
    0x3f98501f, 0x3ecd3c14, 0xbfb131a5, 0xbfb4e1dc, 0x3f21c4b6, 0x3ffb6430, 0x3f5952be, 0x3ef42ddc, 
    0x3f8829ff, 0xbf8fccb6, 0xbd978f38, 0x3df3f338, 0x3eb94dcc, 0xbeae6cb3, 0x3dca75e0, 0x3e4a5e5a
};

static const uint32_t _K41[] = {
    0x3f38cfa8, 0xbe35adc9, 0xbe2bd339, 0x3edc8c37, 0xbe65d3b4, 0x3ed4cdde, 0x3e56e1eb, 0x3f13ed2b, 
    0x3e372fab, 0xbe847e71, 0x3e202f79, 0xbf19a19f, 0x3e9409db, 0x3c83f170, 0xbe0d2cd1, 0x3f0e3bd1, 
    0x3e9fe9a9, 0xbd3dfeb6, 0x3e10d76a, 0x3e9bce00, 0xbef8b383, 0xbe7fd6f8, 0x3f008cd1, 0xbeec2642, 
    0xbf03ade0, 0x3befeb78, 0x3ea88125, 0x3eec14a2, 0xbe6df930, 0x3e8c74f8, 0xbf11e87b, 0x3f3806ab, 
    0x3ea3f4a4, 0x3d582d53, 0xbdc10b38, 0xc085af66, 0x408476f3, 0x3f09ba01, 0x3f020fca, 0x3ec9f6c3, 
    0xbefd89b1, 0x3f370105, 0x3f26ae5e, 0x4001c47e, 0xbea90522, 0xc0880cc8, 0xbe0ef051, 0xc04dec05, 
    0xc0520330, 0x3fb1c0a2, 0x3ea16b01, 0xbe0b5eeb, 0x3efda999, 0xc063f727, 0xc08214e7, 0xbf1d03e9, 
    0xbf3a69ba, 0xbe5c773f, 0xc0d659f3, 0x3f2b2ac8, 0xbed0b48c, 0x3f19effe, 0x400dd18f, 0x3e3f0cfa, 
    0x3f1a6354, 0xbd201ca8, 0x3f454986, 0xbf7dd385, 0xbfd4a4b8, 0xbfd92fca, 0x3e9faa92, 0x3e30ebba, 
    0x3f484a9c, 0xbf1e3bb1, 0x3ecccd3f, 0xbb04ef9b, 0xc0062716, 0x3e4026d7, 0xbfb77c02, 0x3e05c2cb, 
    0x3f2844a7, 0xbf1aad95, 0xc02ebfca, 0xc01a203c, 0x3f84ace3, 0x3ea48518, 0x3e01bfff, 0x3f8cc21b, 
    0x3f8d655e, 0xc03ca0df, 0xbff944ff, 0x3e970dfb, 0x3f993b34, 0xc018056d, 0xbf38fe7a, 0xbf8f49a3, 
    0xc02332a9, 0xbe224a70, 0xbfb13491, 0x3e8bf252, 0x3f441b8d, 0xbe103fbc, 0xbf86fe81, 0xbfc929b8, 
    0xbfa86e88, 0xbdab60f8, 0xbf7707fa, 0xbf2ef77a, 0x3f0fba2e, 0xbc98b495, 0x3efacdb0, 0xbe753556, 
    0xbf4c5b77, 0xbf9c3b47, 0x3e5dd531, 0x3f2407ed, 0xbf8876b9, 0x3f37bd8d, 0xbf935de4, 0xbec61883, 
    0xbe1fcf01, 0x3f446cc4, 0x3f363379, 0xc00b6103, 0xbf0ffbb2, 0xbe01be49, 0xbf432794, 0xbef5a5e3
};

static const uint32_t _K43[] = {
    0xbf6d1e44, 0x3dd90640, 0x3f0fe6d1, 0x3f16dce4
};

// Memory mapped buffers
#define _K11             ((int *)_K11)                       // s32[42] (168 bytes) 
#define _K18             ((float *)_K18)                     // f32[16,3,40] (7680 bytes) 
#define _K21             ((float *)_K21)                     // f32[16] (64 bytes) 
#define _K25             ((float *)_K25)                     // f32[32,3,16] (6144 bytes) 
#define _K28             ((float *)_K28)                     // f32[32] (128 bytes) 
#define _K32             ((float *)_K32)                     // f32[32,3,32] (12288 bytes) 
#define _K35             ((float *)_K35)                     // f32[32] (128 bytes) 
#define _K4              ((float *)_K4)                      // f32[512] (2048 bytes) 
#define _K41             ((float *)_K41)                     // f32[4,32] (512 bytes) 
#define _K43             ((float *)_K43)                     // f32[4] (16 bytes) 
#define _K16             ((int8_t *)(_state + 0x000008d0))   // s8[13008] (13008 bytes) 
#define _K3              ((int8_t *)(_state + 0x00000000))   // s8[2256] (2256 bytes) 
#define _K7              ((int *)(_state + 0x00003ba0))      // s32[24] (96 bytes) 
#define _K8              ((float *)(_state + 0x00003c00))    // f32[258] (1032 bytes) 
#define _K10             ((float *)(_buffer + 0x00000000))   // f32[257] (1028 bytes) 
#define _K12             ((float *)(_buffer + 0x00000404))   // f32[40] (160 bytes) 
#define _K13             ((float *)(_buffer + 0x00000000))   // f32[40] (160 bytes) 
#define _K14             ((float *)(_buffer + 0x000000a0))   // f32[40] (160 bytes) 
#define _K15             ((float *)(_buffer + 0x00000000))   // f32[80,40] (12800 bytes) 
#define _K17             ((float *)(_buffer + 0x00003200))   // f32[40,16] (2560 bytes) 
#define _K19             ((float *)(_buffer + 0x00000000))   // f32[40,16] (2560 bytes) 
#define _K2              ((float *)(_buffer + 0x00000000))   // f32[512] (2048 bytes) 
#define _K23             ((float *)(_buffer + 0x00000a00))   // f32[40,16] (2560 bytes) 
#define _K24             ((float *)(_buffer + 0x00001400))   // f32[40,32] (5120 bytes) 
#define _K26             ((float *)(_buffer + 0x00000000))   // f32[40,32] (5120 bytes) 
#define _K30             ((float *)(_buffer + 0x00001400))   // f32[40,32] (5120 bytes) 
#define _K31             ((float *)(_buffer + 0x00000000))   // f32[40,32] (5120 bytes) 
#define _K33             ((float *)(_buffer + 0x00001400))   // f32[40,32] (5120 bytes) 
#define _K37             ((float *)(_buffer + 0x00000000))   // f32[40,32] (5120 bytes) 
#define _K39             ((float *)(_buffer + 0x00001400))   // f32[20,32] (2560 bytes) 
#define _K40             ((float *)(_buffer + 0x00000000))   // f32[32] (128 bytes) 
#define _K42             ((float *)(_buffer + 0x00000080))   // f32[4] (16 bytes) 
#define _K44             ((float *)(_buffer + 0x00000000))   // f32[4] (16 bytes) 
#define _K5              ((float *)(_buffer + 0x00000800))   // f32[512] (2048 bytes) 
#define _K6              ((float *)(_buffer + 0x00001000))   // f32[257,2] (2056 bytes) 
#define _K9              ((float *)(_buffer + 0x00000000))   // f32[512] (2048 bytes) 

// Represents a Circular Buffer
// https://en.wikipedia.org/wiki/Circular_buffer
typedef struct
{
	char *buf;
	int size;		// total bytes allocated in *buf
	int used;		// current bytes used in buffer.
	int read;
	int write;
} cbuffer_t;

#define CBUFFER_SUCCESS 0
#define CBUFFER_NOMEM -1

// Reset instance (clear buffer)
static inline void cbuffer_reset(cbuffer_t* buf) {
	buf->read = 0;
	buf->write = 0;
	buf->used = 0;
}

// Initializes a cbuffer handle with given memory and size.
static inline void cbuffer_init(cbuffer_t *dest, void *mem, int size) {
	dest->buf = mem;
	dest->size = size;
	cbuffer_reset(dest);
}

// Returns the number of free bytes in buffer.
static inline int cbuffer_get_free(cbuffer_t *buf) {
	return buf->size - buf->used;
}

// Returns the number of used bytes in buffer.
static inline int cbuffer_get_used(cbuffer_t *buf) {
	return buf->used;
}

// Writes given data to buffer.
// Returns CBUFFER_SUCCESS or CBUFFER_NOMEM if out of memory.
static inline int cbuffer_enqueue(cbuffer_t *buf, const void *data, int data_size) {
	int free = cbuffer_get_free(buf);

	// Out of memory?
	if (free < data_size)
		return CBUFFER_NOMEM;

	// Is the data split in the end?
	if (buf->write + data_size > buf->size) {
		int first_size = buf->size - buf->write;
		memcpy(buf->buf + buf->write, data, first_size);
		memcpy(buf->buf, ((char *)data) + first_size, data_size - first_size);
	}
	else {
		memcpy(buf->buf + buf->write, data, data_size);
	}
	buf->write += data_size;
	if (buf->write >= buf->size)
		buf->write -= buf->size;

	buf->used += data_size;
	return CBUFFER_SUCCESS;
}

// Advances the read pointer by given count.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data
static inline int cbuffer_advance(cbuffer_t *buf, int count) {
	int used = cbuffer_get_used(buf);

	if (count > used)
		return CBUFFER_NOMEM;

	buf->read += count;
	if (buf->read >= buf->size)
		buf->read -= buf->size;

	// Reset pointers to 0 if buffer is empty in order to avoid unwanted wrapps.
	if (buf->read == buf->write) {
		buf->read = 0;
		buf->write = 0;
	}

	buf->used -= count;
	return CBUFFER_SUCCESS;
}

// Returns a read pointer at given offset and  
// updates *can_read_bytes (if not NULL) with the number of bytes that can be read.
// 
// Note! Byte count written to can_read_bytes can be less than what cbuffer_get_used() returns.
// This happens when the read has to be split in two since it's a circular buffer.
static inline void* cbuffer_readptr(cbuffer_t* buf, int offset, int* can_read_bytes)
{
	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;
	if (can_read_bytes != NULL)
	{
		int c0 = buf->used;
		if (a0 + c0 > buf->size)
			c0 = buf->size - a0;

		*can_read_bytes = c0;
	}
	return buf->buf + a0;
}

// Copies given "count" bytes to the "dst" buffer without advancing the buffer read offset.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data.
static inline int cbuffer_copyto(cbuffer_t *buf, void *dst, int count, int offset) {
	
	if (count > cbuffer_get_used(buf))
		return CBUFFER_NOMEM;

	int can_read_bytes;
	void* src_ptr = cbuffer_readptr(buf, offset, &can_read_bytes);

	int c0 = (count < can_read_bytes) ? count : can_read_bytes;
	memcpy(dst, src_ptr, c0);
	
	int c1 = count - c0;

	if (c1 > 0)
		memcpy(((char *)dst) + c0, buf->buf, c1);

	return CBUFFER_SUCCESS;
}

typedef struct {
	cbuffer_t data_buffer;			// Circular Buffer for features
	int input_size;					// Number of bytes in each input chunk
	int window_count;				// Number of input chunks in output window.
} fixwin_t;

#ifdef _MSC_VER
static_assert(sizeof(fixwin_t) <= 64, "Data structure 'fixwin_t' is too big");
#endif

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_NOMEM -2

/*
* Try to dequeue a window.
*
* @param handle Pointer to an initialized handle.
* @param dst Pointer where to write window.
* @param stride_count Number of items (of size handle->input_size) to stride window.
* @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1) is no data is available.
*/
static inline int fixwin_dequeuef32(void* restrict handle, void* restrict dst, int stride_count)
{
	fixwin_t* fep = (fixwin_t*)handle;

	const int stride_bytes = stride_count * fep->input_size;
	const int size = fep->window_count * fep->input_size;
	if (cbuffer_get_used(&fep->data_buffer) >= size) {
		if (cbuffer_copyto(&fep->data_buffer, dst, size, 0) != 0)
			return IPWIN_RET_NOMEM;

		if (cbuffer_advance(&fep->data_buffer, stride_bytes) != 0)
			return IPWIN_RET_NOMEM;

		return IPWIN_RET_SUCCESS;
	}
	return IPWIN_RET_NODATA;
}

static inline void hannmul_f32(const float* restrict a, const float* restrict b, float* restrict result, int d0, int d1)
{
	for (int j = 0; j < d1; j++) {
		for (int i = 0; i < d0; i++) {
			*result++ = *a++ * b[i];
		}
	}
}

static void makeipt(int nw, int *ip)
{
    int j, l, m, m2, p, q;
    
    ip[2] = 0;
    ip[3] = 16;
    m = 2;
    for (l = nw; l > 32; l >>= 2) {
        m2 = m << 1;
        q = m2 << 3;
        for (j = m; j < m2; j++) {
            p = ip[j] << 2;
            ip[m + j] = p;
            ip[m2 + j] = p + q;
        }
        m = m2;
    }
}

static void makewt(int nw, int *ip, float *w)
{
    void makeipt(int nw, int *ip);
    int j, nwh, nw0, nw1;
    float delta, wn4r, wk1r, wk1i, wk3r, wk3i;
    
    ip[0] = nw;
    ip[1] = 1;
    if (nw > 2) {
        nwh = nw >> 1;
        delta = atan(1.0) / nwh;
        wn4r = cos(delta * nwh);
        w[0] = 1;
        w[1] = wn4r;
        if (nwh == 4) {
            w[2] = cos(delta * 2);
            w[3] = sin(delta * 2);
        } else if (nwh > 4) {
            makeipt(nw, ip);
            w[2] = 0.5 / cos(delta * 2);
            w[3] = 0.5 / cos(delta * 6);
            for (j = 4; j < nwh; j += 4) {
                w[j] = cos(delta * j);
                w[j + 1] = sin(delta * j);
                w[j + 2] = cos(3 * delta * j);
                w[j + 3] = -sin(3 * delta * j);
            }
        }
        nw0 = 0;
        while (nwh > 2) {
            nw1 = nw0 + nwh;
            nwh >>= 1;
            w[nw1] = 1;
            w[nw1 + 1] = wn4r;
            if (nwh == 4) {
                wk1r = w[nw0 + 4];
                wk1i = w[nw0 + 5];
                w[nw1 + 2] = wk1r;
                w[nw1 + 3] = wk1i;
            } else if (nwh > 4) {
                wk1r = w[nw0 + 4];
                wk3r = w[nw0 + 6];
                w[nw1 + 2] = 0.5 / wk1r;
                w[nw1 + 3] = 0.5 / wk3r;
                for (j = 4; j < nwh; j += 4) {
                    wk1r = w[nw0 + 2 * j];
                    wk1i = w[nw0 + 2 * j + 1];
                    wk3r = w[nw0 + 2 * j + 2];
                    wk3i = w[nw0 + 2 * j + 3];
                    w[nw1 + j] = wk1r;
                    w[nw1 + j + 1] = wk1i;
                    w[nw1 + j + 2] = wk3r;
                    w[nw1 + j + 3] = wk3i;
                }
            }
            nw0 = nw1;
        }
    }
}

static void makect(int nc, int *ip, float *c)
{
    int j, nch;
    float delta;
    
    ip[1] = nc;
    if (nc > 1) {
        nch = nc >> 1;
        delta = atan(1.0) / nch;
        c[0] = cos(delta * nch);
        c[nch] = 0.5 * c[0];
        for (j = 1; j < nch; j++) {
            c[j] = 0.5 * cos(delta * j);
            c[nc - j] = 0.5 * sin(delta * j);
        }
    }
}

static void bitrv2(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    }
}

static void bitrv216(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x7r, x7i, x8r, x8i, x10r, x10i, 
        x11r, x11i, x12r, x12i, x13r, x13i, x14r, x14i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    a[2] = x8r;
    a[3] = x8i;
    a[4] = x4r;
    a[5] = x4i;
    a[6] = x12r;
    a[7] = x12i;
    a[8] = x2r;
    a[9] = x2i;
    a[10] = x10r;
    a[11] = x10i;
    a[14] = x14r;
    a[15] = x14i;
    a[16] = x1r;
    a[17] = x1i;
    a[20] = x5r;
    a[21] = x5i;
    a[22] = x13r;
    a[23] = x13i;
    a[24] = x3r;
    a[25] = x3i;
    a[26] = x11r;
    a[27] = x11i;
    a[28] = x7r;
    a[29] = x7i;
}

static void bitrv208(float *a)
{
    float x1r, x1i, x3r, x3i, x4r, x4i, x6r, x6i;
    
    x1r = a[2];
    x1i = a[3];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x6r = a[12];
    x6i = a[13];
    a[2] = x4r;
    a[3] = x4i;
    a[6] = x6r;
    a[7] = x6i;
    a[8] = x1r;
    a[9] = x1i;
    a[12] = x3r;
    a[13] = x3i;
}

static void cftf1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = a[j + 3] + a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = a[j + 3] - a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = a[j0 - 1] + a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = a[j0 - 1] - a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = a[j0 - 1] + a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = a[j0 - 1] - a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i + x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = a[j0 + 3] + a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = a[j0 + 3] - a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i + x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftmdl1(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    k = 0;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
    }
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
}

static void cftmdl2(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, kr, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i, wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, y0r, y0i, y2r, y2i;
    
    mh = n >> 3;
    m = 2 * mh;
    wn4r = w[1];
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] - a[j2 + 1];
    x0i = a[1] + a[j2];
    x1r = a[0] + a[j2 + 1];
    x1i = a[1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wn4r * (x2r - x2i);
    y0i = wn4r * (x2i + x2r);
    a[0] = x0r + y0r;
    a[1] = x0i + y0i;
    a[j1] = x0r - y0r;
    a[j1 + 1] = x0i - y0i;
    y0r = wn4r * (x3r - x3i);
    y0i = wn4r * (x3i + x3r);
    a[j2] = x1r - y0i;
    a[j2 + 1] = x1i + y0r;
    a[j3] = x1r + y0i;
    a[j3 + 1] = x1i - y0r;
    k = 0;
    kr = 2 * m;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        kr -= 4;
        wd1i = w[kr];
        wd1r = w[kr + 1];
        wd3i = w[kr + 2];
        wd3r = w[kr + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] - a[j2 + 1];
        x0i = a[j + 1] + a[j2];
        x1r = a[j] + a[j2 + 1];
        x1i = a[j + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wk1r * x0r - wk1i * x0i;
        y0i = wk1r * x0i + wk1i * x0r;
        y2r = wd1r * x2r - wd1i * x2i;
        y2i = wd1r * x2i + wd1i * x2r;
        a[j] = y0r + y2r;
        a[j + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wk3r * x1r + wk3i * x1i;
        y0i = wk3r * x1i - wk3i * x1r;
        y2r = wd3r * x3r + wd3i * x3i;
        y2i = wd3r * x3i - wd3i * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] - a[j2 + 1];
        x0i = a[j0 + 1] + a[j2];
        x1r = a[j0] + a[j2 + 1];
        x1i = a[j0 + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wd1i * x0r - wd1r * x0i;
        y0i = wd1i * x0i + wd1r * x0r;
        y2r = wk1i * x2r - wk1r * x2i;
        y2i = wk1i * x2i + wk1r * x2r;
        a[j0] = y0r + y2r;
        a[j0 + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wd3i * x1r + wd3r * x1i;
        y0i = wd3i * x1i - wd3r * x1r;
        y2r = wk3i * x3r + wk3r * x3i;
        y2i = wk3i * x3i - wk3r * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
    }
    wk1r = w[m];
    wk1i = w[m + 1];
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] - a[j2 + 1];
    x0i = a[j0 + 1] + a[j2];
    x1r = a[j0] + a[j2 + 1];
    x1i = a[j0 + 1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wk1r * x0r - wk1i * x0i;
    y0i = wk1r * x0i + wk1i * x0r;
    y2r = wk1i * x2r - wk1r * x2i;
    y2i = wk1i * x2i + wk1r * x2r;
    a[j0] = y0r + y2r;
    a[j0 + 1] = y0i + y2i;
    a[j1] = y0r - y2r;
    a[j1 + 1] = y0i - y2i;
    y0r = wk1i * x1r - wk1r * x1i;
    y0i = wk1i * x1i + wk1r * x1r;
    y2r = wk1r * x3r - wk1i * x3i;
    y2i = wk1r * x3i + wk1i * x3r;
    a[j2] = y0r - y2r;
    a[j2 + 1] = y0i - y2i;
    a[j3] = y0r + y2r;
    a[j3 + 1] = y0i + y2i;
}

static int cfttree(int n, int j, int k, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    int i, isplt, m;
    
    if ((k & 3) != 0) {
        isplt = k & 1;
        if (isplt != 0) {
            cftmdl1(n, &a[j - n], &w[nw - (n >> 1)]);
        } else {
            cftmdl2(n, &a[j - n], &w[nw - n]);
        }
    } else {
        m = n;
        for (i = k; (i & 3) == 0; i >>= 2) {
            m <<= 2;
        }
        isplt = i & 1;
        if (isplt != 0) {
            while (m > 128) {
                cftmdl1(m, &a[j - m], &w[nw - (m >> 1)]);
                m >>= 2;
            }
        } else {
            while (m > 128) {
                cftmdl2(m, &a[j - m], &w[nw - m]);
                m >>= 2;
            }
        }
    }
    return isplt;
}

static void cftf161(float *a, float *w)
{
    float wn4r, wk1r, wk1i, 
        x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    x0r = a[0] + a[16];
    x0i = a[1] + a[17];
    x1r = a[0] - a[16];
    x1i = a[1] - a[17];
    x2r = a[8] + a[24];
    x2i = a[9] + a[25];
    x3r = a[8] - a[24];
    x3i = a[9] - a[25];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y4r = x0r - x2r;
    y4i = x0i - x2i;
    y8r = x1r - x3i;
    y8i = x1i + x3r;
    y12r = x1r + x3i;
    y12i = x1i - x3r;
    x0r = a[2] + a[18];
    x0i = a[3] + a[19];
    x1r = a[2] - a[18];
    x1i = a[3] - a[19];
    x2r = a[10] + a[26];
    x2i = a[11] + a[27];
    x3r = a[10] - a[26];
    x3i = a[11] - a[27];
    y1r = x0r + x2r;
    y1i = x0i + x2i;
    y5r = x0r - x2r;
    y5i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y9r = wk1r * x0r - wk1i * x0i;
    y9i = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y13r = wk1i * x0r - wk1r * x0i;
    y13i = wk1i * x0i + wk1r * x0r;
    x0r = a[4] + a[20];
    x0i = a[5] + a[21];
    x1r = a[4] - a[20];
    x1i = a[5] - a[21];
    x2r = a[12] + a[28];
    x2i = a[13] + a[29];
    x3r = a[12] - a[28];
    x3i = a[13] - a[29];
    y2r = x0r + x2r;
    y2i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y10r = wn4r * (x0r - x0i);
    y10i = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y14r = wn4r * (x0r + x0i);
    y14i = wn4r * (x0i - x0r);
    x0r = a[6] + a[22];
    x0i = a[7] + a[23];
    x1r = a[6] - a[22];
    x1i = a[7] - a[23];
    x2r = a[14] + a[30];
    x2i = a[15] + a[31];
    x3r = a[14] - a[30];
    x3i = a[15] - a[31];
    y3r = x0r + x2r;
    y3i = x0i + x2i;
    y7r = x0r - x2r;
    y7i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y11r = wk1i * x0r - wk1r * x0i;
    y11i = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y15r = wk1r * x0r - wk1i * x0i;
    y15i = wk1r * x0i + wk1i * x0r;
    x0r = y12r - y14r;
    x0i = y12i - y14i;
    x1r = y12r + y14r;
    x1i = y12i + y14i;
    x2r = y13r - y15r;
    x2i = y13i - y15i;
    x3r = y13r + y15r;
    x3i = y13i + y15i;
    a[24] = x0r + x2r;
    a[25] = x0i + x2i;
    a[26] = x0r - x2r;
    a[27] = x0i - x2i;
    a[28] = x1r - x3i;
    a[29] = x1i + x3r;
    a[30] = x1r + x3i;
    a[31] = x1i - x3r;
    x0r = y8r + y10r;
    x0i = y8i + y10i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    x3r = y9r - y11r;
    x3i = y9i - y11i;
    a[16] = x0r + x2r;
    a[17] = x0i + x2i;
    a[18] = x0r - x2r;
    a[19] = x0i - x2i;
    a[20] = x1r - x3i;
    a[21] = x1i + x3r;
    a[22] = x1r + x3i;
    a[23] = x1i - x3r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x3r = wn4r * (x0r - x0i);
    x3i = wn4r * (x0i + x0r);
    x0r = y4r - y6i;
    x0i = y4i + y6r;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    a[8] = x0r + x2r;
    a[9] = x0i + x2i;
    a[10] = x0r - x2r;
    a[11] = x0i - x2i;
    a[12] = x1r - x3i;
    a[13] = x1i + x3r;
    a[14] = x1r + x3i;
    a[15] = x1i - x3r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    x3r = y1r - y3r;
    x3i = y1i - y3i;
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x0r - x2r;
    a[3] = x0i - x2i;
    a[4] = x1r - x3i;
    a[5] = x1i + x3r;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftf162(float *a, float *w)
{
    float wn4r, wk1r, wk1i, wk2r, wk2i, wk3r, wk3i, 
        x0r, x0i, x1r, x1i, x2r, x2i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[4];
    wk1i = w[5];
    wk3r = w[6];
    wk3i = -w[7];
    wk2r = w[8];
    wk2i = w[9];
    x1r = a[0] - a[17];
    x1i = a[1] + a[16];
    x0r = a[8] - a[25];
    x0i = a[9] + a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y0r = x1r + x2r;
    y0i = x1i + x2i;
    y4r = x1r - x2r;
    y4i = x1i - x2i;
    x1r = a[0] + a[17];
    x1i = a[1] - a[16];
    x0r = a[8] + a[25];
    x0i = a[9] - a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y8r = x1r - x2i;
    y8i = x1i + x2r;
    y12r = x1r + x2i;
    y12i = x1i - x2r;
    x0r = a[2] - a[19];
    x0i = a[3] + a[18];
    x1r = wk1r * x0r - wk1i * x0i;
    x1i = wk1r * x0i + wk1i * x0r;
    x0r = a[10] - a[27];
    x0i = a[11] + a[26];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y1r = x1r + x2r;
    y1i = x1i + x2i;
    y5r = x1r - x2r;
    y5i = x1i - x2i;
    x0r = a[2] + a[19];
    x0i = a[3] - a[18];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[10] + a[27];
    x0i = a[11] - a[26];
    x2r = wk1r * x0r + wk1i * x0i;
    x2i = wk1r * x0i - wk1i * x0r;
    y9r = x1r - x2r;
    y9i = x1i - x2i;
    y13r = x1r + x2r;
    y13i = x1i + x2i;
    x0r = a[4] - a[21];
    x0i = a[5] + a[20];
    x1r = wk2r * x0r - wk2i * x0i;
    x1i = wk2r * x0i + wk2i * x0r;
    x0r = a[12] - a[29];
    x0i = a[13] + a[28];
    x2r = wk2i * x0r - wk2r * x0i;
    x2i = wk2i * x0i + wk2r * x0r;
    y2r = x1r + x2r;
    y2i = x1i + x2i;
    y6r = x1r - x2r;
    y6i = x1i - x2i;
    x0r = a[4] + a[21];
    x0i = a[5] - a[20];
    x1r = wk2i * x0r - wk2r * x0i;
    x1i = wk2i * x0i + wk2r * x0r;
    x0r = a[12] + a[29];
    x0i = a[13] - a[28];
    x2r = wk2r * x0r - wk2i * x0i;
    x2i = wk2r * x0i + wk2i * x0r;
    y10r = x1r - x2r;
    y10i = x1i - x2i;
    y14r = x1r + x2r;
    y14i = x1i + x2i;
    x0r = a[6] - a[23];
    x0i = a[7] + a[22];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[14] - a[31];
    x0i = a[15] + a[30];
    x2r = wk1i * x0r - wk1r * x0i;
    x2i = wk1i * x0i + wk1r * x0r;
    y3r = x1r + x2r;
    y3i = x1i + x2i;
    y7r = x1r - x2r;
    y7i = x1i - x2i;
    x0r = a[6] + a[23];
    x0i = a[7] - a[22];
    x1r = wk1i * x0r + wk1r * x0i;
    x1i = wk1i * x0i - wk1r * x0r;
    x0r = a[14] + a[31];
    x0i = a[15] - a[30];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y11r = x1r + x2r;
    y11i = x1i + x2i;
    y15r = x1r - x2r;
    y15i = x1i - x2i;
    x1r = y0r + y2r;
    x1i = y0i + y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    a[0] = x1r + x2r;
    a[1] = x1i + x2i;
    a[2] = x1r - x2r;
    a[3] = x1i - x2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r - y3r;
    x2i = y1i - y3i;
    a[4] = x1r - x2i;
    a[5] = x1i + x2r;
    a[6] = x1r + x2i;
    a[7] = x1i - x2r;
    x1r = y4r - y6i;
    x1i = y4i + y6r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[8] = x1r + x2r;
    a[9] = x1i + x2i;
    a[10] = x1r - x2r;
    a[11] = x1i - x2i;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[12] = x1r - x2i;
    a[13] = x1i + x2r;
    a[14] = x1r + x2i;
    a[15] = x1i - x2r;
    x1r = y8r + y10r;
    x1i = y8i + y10i;
    x2r = y9r - y11r;
    x2i = y9i - y11i;
    a[16] = x1r + x2r;
    a[17] = x1i + x2i;
    a[18] = x1r - x2r;
    a[19] = x1i - x2i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    a[20] = x1r - x2i;
    a[21] = x1i + x2r;
    a[22] = x1r + x2i;
    a[23] = x1i - x2r;
    x1r = y12r - y14i;
    x1i = y12i + y14r;
    x0r = y13r + y15i;
    x0i = y13i - y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[24] = x1r + x2r;
    a[25] = x1i + x2i;
    a[26] = x1r - x2r;
    a[27] = x1i - x2i;
    x1r = y12r + y14i;
    x1i = y12i - y14r;
    x0r = y13r - y15i;
    x0i = y13i + y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[28] = x1r - x2i;
    a[29] = x1i + x2r;
    a[30] = x1r + x2i;
    a[31] = x1i - x2r;
}

static void cftf081(float *a, float *w)
{
    float wn4r, x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    x0r = a[0] + a[8];
    x0i = a[1] + a[9];
    x1r = a[0] - a[8];
    x1i = a[1] - a[9];
    x2r = a[4] + a[12];
    x2i = a[5] + a[13];
    x3r = a[4] - a[12];
    x3i = a[5] - a[13];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y2r = x0r - x2r;
    y2i = x0i - x2i;
    y1r = x1r - x3i;
    y1i = x1i + x3r;
    y3r = x1r + x3i;
    y3i = x1i - x3r;
    x0r = a[2] + a[10];
    x0i = a[3] + a[11];
    x1r = a[2] - a[10];
    x1i = a[3] - a[11];
    x2r = a[6] + a[14];
    x2i = a[7] + a[15];
    x3r = a[6] - a[14];
    x3i = a[7] - a[15];
    y4r = x0r + x2r;
    y4i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    x2r = x1r + x3i;
    x2i = x1i - x3r;
    y5r = wn4r * (x0r - x0i);
    y5i = wn4r * (x0r + x0i);
    y7r = wn4r * (x2r - x2i);
    y7i = wn4r * (x2r + x2i);
    a[8] = y1r + y5r;
    a[9] = y1i + y5i;
    a[10] = y1r - y5r;
    a[11] = y1i - y5i;
    a[12] = y3r - y7i;
    a[13] = y3i + y7r;
    a[14] = y3r + y7i;
    a[15] = y3i - y7r;
    a[0] = y0r + y4r;
    a[1] = y0i + y4i;
    a[2] = y0r - y4r;
    a[3] = y0i - y4i;
    a[4] = y2r - y6i;
    a[5] = y2i + y6r;
    a[6] = y2r + y6i;
    a[7] = y2i - y6r;
}

static void cftf082(float *a, float *w)
{
    float wn4r, wk1r, wk1i, x0r, x0i, x1r, x1i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    y0r = a[0] - a[9];
    y0i = a[1] + a[8];
    y1r = a[0] + a[9];
    y1i = a[1] - a[8];
    x0r = a[4] - a[13];
    x0i = a[5] + a[12];
    y2r = wn4r * (x0r - x0i);
    y2i = wn4r * (x0i + x0r);
    x0r = a[4] + a[13];
    x0i = a[5] - a[12];
    y3r = wn4r * (x0r - x0i);
    y3i = wn4r * (x0i + x0r);
    x0r = a[2] - a[11];
    x0i = a[3] + a[10];
    y4r = wk1r * x0r - wk1i * x0i;
    y4i = wk1r * x0i + wk1i * x0r;
    x0r = a[2] + a[11];
    x0i = a[3] - a[10];
    y5r = wk1i * x0r - wk1r * x0i;
    y5i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] - a[15];
    x0i = a[7] + a[14];
    y6r = wk1i * x0r - wk1r * x0i;
    y6i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] + a[15];
    x0i = a[7] - a[14];
    y7r = wk1r * x0r - wk1i * x0i;
    y7i = wk1r * x0i + wk1i * x0r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y4r + y6r;
    x1i = y4i + y6i;
    a[0] = x0r + x1r;
    a[1] = x0i + x1i;
    a[2] = x0r - x1r;
    a[3] = x0i - x1i;
    x0r = y0r - y2r;
    x0i = y0i - y2i;
    x1r = y4r - y6r;
    x1i = y4i - y6i;
    a[4] = x0r - x1i;
    a[5] = x0i + x1r;
    a[6] = x0r + x1i;
    a[7] = x0i - x1r;
    x0r = y1r - y3i;
    x0i = y1i + y3r;
    x1r = y5r - y7r;
    x1i = y5i - y7i;
    a[8] = x0r + x1r;
    a[9] = x0i + x1i;
    a[10] = x0r - x1r;
    a[11] = x0i - x1i;
    x0r = y1r + y3i;
    x0i = y1i - y3r;
    x1r = y5r + y7r;
    x1i = y5i + y7i;
    a[12] = x0r - x1i;
    a[13] = x0i + x1r;
    a[14] = x0r + x1i;
    a[15] = x0i - x1r;
}

static void cftleaf(int n, int isplt, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 512) {
        cftmdl1(128, a, &w[nw - 64]);
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
        cftmdl2(128, &a[128], &w[nw - 128]);
        cftf161(&a[128], &w[nw - 8]);
        cftf162(&a[160], &w[nw - 32]);
        cftf161(&a[192], &w[nw - 8]);
        cftf162(&a[224], &w[nw - 32]);
        cftmdl1(128, &a[256], &w[nw - 64]);
        cftf161(&a[256], &w[nw - 8]);
        cftf162(&a[288], &w[nw - 32]);
        cftf161(&a[320], &w[nw - 8]);
        cftf161(&a[352], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(128, &a[384], &w[nw - 64]);
            cftf161(&a[480], &w[nw - 8]);
        } else {
            cftmdl2(128, &a[384], &w[nw - 128]);
            cftf162(&a[480], &w[nw - 32]);
        }
        cftf161(&a[384], &w[nw - 8]);
        cftf162(&a[416], &w[nw - 32]);
        cftf161(&a[448], &w[nw - 8]);
    } else {
        cftmdl1(64, a, &w[nw - 32]);
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
        cftmdl2(64, &a[64], &w[nw - 64]);
        cftf081(&a[64], &w[nw - 8]);
        cftf082(&a[80], &w[nw - 8]);
        cftf081(&a[96], &w[nw - 8]);
        cftf082(&a[112], &w[nw - 8]);
        cftmdl1(64, &a[128], &w[nw - 32]);
        cftf081(&a[128], &w[nw - 8]);
        cftf082(&a[144], &w[nw - 8]);
        cftf081(&a[160], &w[nw - 8]);
        cftf081(&a[176], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(64, &a[192], &w[nw - 32]);
            cftf081(&a[240], &w[nw - 8]);
        } else {
            cftmdl2(64, &a[192], &w[nw - 64]);
            cftf082(&a[240], &w[nw - 8]);
        }
        cftf081(&a[192], &w[nw - 8]);
        cftf082(&a[208], &w[nw - 8]);
        cftf081(&a[224], &w[nw - 8]);
    }
}

static void cftrec4(int n, float *a, int nw, float *w)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m;
    
    m = n;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
}

static void cftfx41(int n, float *a, int nw, float *w)
{
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 128) {
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
    } else {
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
    }
}

static void cftf040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r - x3i;
    a[3] = x1i + x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftx020(float *a)
{
    float x0r, x0i;
    
    x0r = a[0] - a[2];
    x0i = a[1] - a[3];
    a[0] += a[2];
    a[1] += a[3];
    a[2] = x0r;
    a[3] = x0i;
}

#ifdef USE_CDFT_THREADS
struct cdft_arg_st {
    int n0;
    int n;
    float *a;
    int nw;
    float *w;
};
typedef struct cdft_arg_st cdft_arg_t;


static void cftrec4_th(int n, float *a, int nw, float *w)
{
    void *cftrec1_th(void *p);
    void *cftrec2_th(void *p);
    int i, idiv4, m, nthread;
    cdft_thread_t th[4];
    cdft_arg_t ag[4];
    
    nthread = 2;
    idiv4 = 0;
    m = n >> 1;
    if (n > CDFT_4THREADS_BEGIN_N) {
        nthread = 4;
        idiv4 = 1;
        m >>= 1;
    }
    for (i = 0; i < nthread; i++) {
        ag[i].n0 = n;
        ag[i].n = m;
        ag[i].a = &a[i * m];
        ag[i].nw = nw;
        ag[i].w = w;
        if (i != idiv4) {
            cdft_thread_create(&th[i], cftrec1_th, &ag[i]);
        } else {
            cdft_thread_create(&th[i], cftrec2_th, &ag[i]);
        }
    }
    for (i = 0; i < nthread; i++) {
        cdft_thread_wait(th[i]);
    }
}


static void *cftrec1_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    m = n0;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}


static void *cftrec2_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl2(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    k = 1;
    m = n0;
    while (m > 512) {
        m >>= 2;
        k <<= 2;
        cftmdl2(m, &a[n - m], &w[nw - m]);
    }
    cftleaf(m, 0, &a[n - m], nw, w);
    k >>= 1;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}
#endif /* USE_CDFT_THREADS */

static void cftfsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2(int n, int *ip, float *a);
    void bitrv216(float *a);
    void bitrv208(float *a);
    void cftf1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftf1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216(a);
        } else {
            cftf081(a, w);
            bitrv208(a);
        }
    } else if (n == 8) {
        cftf040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void bitrv2conj(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += nm;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    }
}

static void bitrv216neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i, x8r, x8i, 
        x9r, x9i, x10r, x10i, x11r, x11i, x12r, x12i, 
        x13r, x13i, x14r, x14i, x15r, x15i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x9r = a[18];
    x9i = a[19];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    x15r = a[30];
    x15i = a[31];
    a[2] = x15r;
    a[3] = x15i;
    a[4] = x7r;
    a[5] = x7i;
    a[6] = x11r;
    a[7] = x11i;
    a[8] = x3r;
    a[9] = x3i;
    a[10] = x13r;
    a[11] = x13i;
    a[12] = x5r;
    a[13] = x5i;
    a[14] = x9r;
    a[15] = x9i;
    a[16] = x1r;
    a[17] = x1i;
    a[18] = x14r;
    a[19] = x14i;
    a[20] = x6r;
    a[21] = x6i;
    a[22] = x10r;
    a[23] = x10i;
    a[24] = x2r;
    a[25] = x2i;
    a[26] = x12r;
    a[27] = x12i;
    a[28] = x4r;
    a[29] = x4i;
    a[30] = x8r;
    a[31] = x8i;
}

static void bitrv208neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    a[2] = x7r;
    a[3] = x7i;
    a[4] = x3r;
    a[5] = x3i;
    a[6] = x5r;
    a[7] = x5i;
    a[8] = x1r;
    a[9] = x1i;
    a[10] = x6r;
    a[11] = x6i;
    a[12] = x2r;
    a[13] = x2i;
    a[14] = x4r;
    a[15] = x4i;
}

static void cftb1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = -a[1] - a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = -a[1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    a[j2] = x1r + x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r - x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = -a[j + 1] - a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = -a[j + 1] + a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = -a[j + 3] - a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = -a[j + 3] + a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i - x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = -a[j0 + 1] - a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = -a[j0 + 1] + a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = -a[j0 - 1] - a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = -a[j0 - 1] + a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i - x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = -a[j0 - 1] - a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = -a[j0 - 1] + a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i - x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = -a[j0 + 1] - a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = -a[j0 + 1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = -a[j0 + 3] - a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = -a[j0 + 3] + a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i - x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftb040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r + x3i;
    a[3] = x1i - x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r - x3i;
    a[7] = x1i + x3r;
}

static void cftbsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2conj(int n, int *ip, float *a);
    void bitrv216neg(float *a);
    void bitrv208neg(float *a);
    void cftb1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftb040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftb1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2conj(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216neg(a);
        } else {
            cftf081(a, w);
            bitrv208neg(a);
        }
    } else if (n == 8) {
        cftb040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void rftfsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr - wki * xi;
        yi = wkr * xi + wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rftbsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr + wki * xi;
        yi = wkr * xi - wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rdft(int n, int isgn, float *a, int *ip, float *w)
{
    void makewt(int nw, int *ip, float *w);
    void makect(int nc, int *ip, float *c);
    void cftfsub(int n, float *a, int *ip, int nw, float *w);
    void cftbsub(int n, float *a, int *ip, int nw, float *w);
    void rftfsub(int n, float *a, int nc, float *c);
    void rftbsub(int n, float *a, int nc, float *c);
    int nw, nc;
    float xi;
    
    nw = ip[0];
    if (n > (nw << 2)) {
        nw = n >> 2;
        makewt(nw, ip, w);
    }
    nc = ip[1];
    if (n > (nc << 2)) {
        nc = n >> 2;
        makect(nc, ip, w + nw);
    }
    if (isgn >= 0) {
        if (n > 4) {
            cftfsub(n, a, ip, nw, w);
            rftfsub(n, a, nc, w + nw);
        } else if (n == 4) {
            cftfsub(n, a, ip, nw, w);
        }
        xi = a[0] - a[1];
        a[0] += a[1];
        a[1] = xi;
    } else {
        a[1] = 0.5 * (a[0] - a[1]);
        a[0] -= a[1];
        if (n > 4) {
            rftbsub(n, a, nc, w + nw);
            cftbsub(n, a, ip, nw, w);
        } else if (n == 4) {
            cftbsub(n, a, ip, nw, w);
        }
    }
}

// input array (any shape >= 1D)
// output array (shape = input.shape.replace(axis, n).insert(0,2))
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void rdft_ndim_f32(
    const float* restrict input, 
    float* restrict output, 
    int d0, int d1, int d2,
    int* restrict temp_ip, float* restrict temp_w, float* restrict temp_a)
{
    void rdft(int n, int isgn, float* a, int* ip, float* w);

    int d3 = d0 * d1;
    int d_out = (d1 >> 1) + 1;

    for (int k = 0; k < d2; k++)
    {
        int dk = k * d3;
        int dm = k * 2 * d_out * d0;
        for (int i = 0; i < d0; i++)
        {                	           
            for (int j = 0; j < d1; j++)
            {
                temp_a[j] = input[dk + j * d0 + i];
            }
            rdft(d1, 1, temp_a, temp_ip, temp_w);

            for (int m = 2; m < d1; m+=2)
            {
                int index = (m * d0) + 2 * i + dm;
                output[index] = temp_a[m];
                output[index + 1] = -temp_a[m + 1];
            }
            int beta = dm + 2 * i;
            output[beta] = temp_a[0];
            output[beta + 1] = 0;
            output[beta + d3] = temp_a[1];
            output[beta + d3 + 1] = 0;
        }
    }
}

static inline float __norm_f32(const float* input, int step, int count)
{
	float sum = 0;
	for (int j = 0; j < count; j++) {
		float item = input[j * step];
		sum += item * item;
	}
	return sqrtf(sum);
}

// input array (any shape >= 2D)
// output array (same shape as input array except with axis removed)
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void norm_f32(const float* restrict input, int d0, int d1, int d2, float* restrict output)
{
	const int d3 = d0 * d1;

	for (int k = 0; k < d2; k++) {
		int k3 = k * d3;
		int k0 = k * d0;
		for (int i = 0; i < d0; i++) {			
			*(output + i + k0) = __norm_f32(input + i + k3, d0, d1);
		}
	}
}

static inline float __mel_f32(const float* restrict input, const int* restrict filter_points, int filter)
{
	int n0 = filter_points[filter];
	int n1 = filter_points[filter+1];
	int n2 = filter_points[filter+2];
	int c0 = n1 - n0;
	int c1 = n2 - n1;
	float sum = 0;
	
	for (int i = 0; i <= c0; i++) {
		float rate = i / (float)c0;
		float value = input[i + n0];
		sum += value * rate;
	}

	for (int i = 1; i <= c1; i++) {
		float rate = i / (float)c1;
		float value = input[i + n1];
		sum += value * (1.0 - rate);
	}

	return sum;
}

// input array (any shape >= 1D)
// output array (same shape as input array except with 0 replaced with num_filter)
// size = input.shape.size(0)
// slot = input.shape.slot(0)
static inline void mel_f32(const float* restrict input, const int* restrict filter_points, int size, int slot, int num_filter, float* restrict output)
{	
	for (int k = 0; k < slot; k++) {
		const float *ip = input + k * size;
		for (int i = 0; i < num_filter; i++) {
			*output++ = __mel_f32(ip, filter_points, i);
		}
	}
}

static inline void clip_f32(const float* restrict input, int count, float min, float max, float* restrict output)
{	
	for (int i = 0; i < count; i++) {
		float value = input[i];
		if (value > max)
			value = max;
		if (value < min)
			value = min;

		output[i] = value;
	}
}

static inline void loge_f32(const float* restrict x, int count, float* restrict result)
{
	for (int i = 0; i < count; i++) {
		*result++ = logf(*x++);
	}
}

/**
 * Enqueue handle->input_size values from given *data pointer to internal window buffer.
 *
 * @param handle Pointer to an initialized handle.
 * @param data Data to enqueue.
 * @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NOMEM (-2) if internal buffer is out of memory.
 */
static inline int fixwin_enqueuef32(void* restrict handle, const void* restrict data)
{
	fixwin_t* fep = (fixwin_t*)handle;

	if (cbuffer_enqueue(&fep->data_buffer, data, fep->input_size) != 0)
		return IPWIN_RET_NOMEM;

	return IPWIN_RET_SUCCESS;
}

static inline float mac_f32(const float* restrict a, const float* restrict b, int count)
{
	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += *a++ * *b++;
	}
	return sum;
}

static inline void conv1d_flat_f32(
	const float* restrict input,
	const float* restrict weight,
	float* restrict output,
	int top,
	int bottom,
	int n_output_rows,
	int filters,
	int strides,
	int kernel_size)
{
	for (int i = 0; i < n_output_rows; i++) {
		const float* wp = weight;		// Weight matrix
		const float* bp = input;		// Input matrix
		const int step = i * strides;	// Row size
		int len = kernel_size;			// Normally do one kernel

		int skip = top - step;			// Pad top?
		if (skip > 0) {
			len -= skip;				// Trim kernel length
			wp += skip;					// Advance kernel
		}
		else {						// No top padding,
			bp -= skip;					// Rollback input
		}

		skip = step + len - bottom;		// Pad bottom?
		if (skip > 0)
			len -= skip;				// Just cut the kernel at end

		float* op = output + i * filters;
		for (int j = 0; j < filters; j++) {
			*op++ = mac_f32(wp + j * kernel_size, bp, len);
		}
	}
}

static inline void add_f32(
	const float* restrict a,
	const float* restrict b,
	int l, int g1, int m, int g2, int r,
	float* restrict output)
{
	int index = 0;
	for (int x = 0; x < l; x++) {
		for (int i = 0; i < g1; i++) {
			for (int y = 0; y < m; y++) {
				for (int j = 0; j < g2; j++) {
					for (int z = 0; z < r; z++) {
						output[index] = a[index] + b[x * m * r + y * r + z];
						index++;
					}
				}
			}
		}
	}
}

static inline void relu_f32(const float* restrict x, int count, float* restrict result)
{
	for (int i = 0; i < count; i++) {
		const float value = *x++;
		*result++ = value > 0 ? value : 0;
	}
}

static inline float maxpool1d_f32_max(const float *restrict x, int ncols, int pool_size)
{
    float max = -FLT_MAX;
    for (int i = 0; i < pool_size; i++) {
        const float value = *(x + i * ncols);
        if (value > max)
            max = value;
    }
    return max;
}

static inline void maxpool1d_f32_row(const float* restrict x, int pool_size, int ncols, float* restrict result)
{
    for (int i = 0; i < ncols; i++) {
        const float* xp = x + i;
        *result++ = maxpool1d_f32_max(xp, ncols, pool_size);
    }
}

static inline void maxpool1d_valid_f32(
    const float* restrict input,
    int pool_size,
    int strides,
    int ncols,
    int n_output_rows,
    float* restrict result)
{
    int input_pointer_step = ncols * strides;

    for (int i = 0; i < n_output_rows; i++) {
        const float* input_current = input + (i * input_pointer_step);
        float* rp = result + (i * ncols);
        maxpool1d_f32_row(input_current, pool_size, ncols, rp);
    }
}

static inline float _globav1d_f32_mean(const float *restrict x, int nchannel, int nsteps)
{
	float mean = 0.0;
	for (int i = 0; i < nsteps; i++) {
		const float value = *(x + i * nchannel);
		mean = mean + value;
	}
	mean = mean/(float)nsteps;
	return mean;
}

static inline void globav1d_f32(const float *restrict x, int nsteps, int nchannel, float *restrict result)
{
	// Loop over all channels
	for (int i = 0; i < nchannel; i++) {
		const float* xp = x + i;
		*result++ = _globav1d_f32_mean(xp, nchannel, nsteps);
	}
}

static inline void dott_f32(const float *restrict a, const float *restrict b, float *restrict out, int d0, int d1, int d2)
{
	for (int i = 0; i < d2; i++) {
		float* op = out;
		for (int j = 0; j < d1; j++) {
			*op++ = mac_f32(a + j * d0, b, d0);
		}
		out += d1;
		b += d0;
	}
}

static inline void softmax_f32(const float* restrict x, int count, float* restrict result)
{
	float sum = 0;
	for (int i = 0; i < count; i++) {
		float value = expf(x[i]);
		sum += value;
		result[i] = value;
	}
	for (int i = 0; i < count; i++) {
		result[i] /= sum;
	}
}

/**
* Initializes a fixwin sampler handle.
*
* @param handle Pointer to a preallocated memory area of fixwin_handle_size() bytes to initialize.
*
* @param input_size Number of bytes to enqueue.
* @param window_count Number of items (of size input_size) in each window
*/
static inline void fixwin_initf32(void* restrict handle, int input_size, int window_count)
{
	fixwin_t* fep = (fixwin_t*)handle;
	fep->input_size = input_size;
	fep->window_count = window_count;

	char* mem = ((char*)handle) + sizeof(fixwin_t);

	int data_buffer = input_size * window_count;
	
	cbuffer_init(&fep->data_buffer, mem, data_buffer);
}

#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) return __ret; } while(0)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) return __ret;  } 

int IMAI_dequeue(float *restrict data_out) {    
    while(1) {
        __RETURN_ERROR_BREAK_EMPTY(fixwin_dequeuef32(_K3, _K2, 120));
        hannmul_f32(_K2, _K4, _K5, 512, 1);
        rdft_ndim_f32(_K5, _K6, 1, 512, 1, _K7, _K8, _K9);
        norm_f32(_K6, 1, 2, 257, _K10);
        mel_f32(_K10, _K11, 257, 1, 40, _K12);
        clip_f32(_K12, 40, 0.000316227766, 3.40282347E+38, _K13);
        loge_f32(_K13, 40, _K14);
        __RETURN_ERROR_BREAK_EMPTY(fixwin_enqueuef32(_K16, _K14));
    }
    __RETURN_ERROR(fixwin_dequeuef32(_K16, _K15, 3));
    conv1d_flat_f32(_K15, _K18, _K17, 0, 3200, 40, 16, 80, 120);
    add_f32(_K17, _K21, 1, 1, 1, 40, 16, _K19);
    relu_f32(_K19, 640, _K23);
    conv1d_flat_f32(_K23, _K25, _K24, 16, 656, 40, 32, 16, 48);
    add_f32(_K24, _K28, 1, 1, 1, 40, 32, _K26);
    relu_f32(_K26, 1280, _K30);
    conv1d_flat_f32(_K30, _K32, _K31, 32, 1312, 40, 32, 32, 96);
    add_f32(_K31, _K35, 1, 1, 1, 40, 32, _K33);
    relu_f32(_K33, 1280, _K37);
    maxpool1d_valid_f32(_K37, 2, 2, 32, 20, _K39);
    globav1d_f32(_K39, 20, 32, _K40);
    dott_f32(_K41, _K40, _K42, 32, 4, 1);
    add_f32(_K42, _K43, 1, 1, 1, 1, 4, _K44);
    softmax_f32(_K44, 4, data_out);
    return 0;
}

int IMAI_enqueue(const float *restrict data_in) {    
    __RETURN_ERROR(fixwin_enqueuef32(_K3, data_in));
    return 0;
}

void IMAI_init(void) {    
    fixwin_initf32(_K3, 4, 512);
    fixwin_initf32(_K16, 160, 80);
}

