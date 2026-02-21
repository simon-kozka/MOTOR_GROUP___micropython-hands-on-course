/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/21/2026 09:35:57 UTC. Any changes will be lost.
* 
* Model ID  64de05e4-9f6b-49a1-81a4-d269ac89245d
* 
* Memory    Size                      Efficiency
* Buffers   768 bytes (RAM)           100 %
* State     480 bytes (RAM)           100 %
* Readonly  19232 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-small-speed-1
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | imbalance
* 2           | working
* 3           | impact
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [6,6]           float      dequeue
*    window_shape = [6,6]
*    stride = 6
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [6,6]           float      dequeue
*    contextual_length_sec = 0.03
*    prediction_freq = 200
* Input Layer                    [6,6]           float      dequeue
*    shape = [6,6]
* Convolution 1D                 [3,16]          float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,6,16]
* Batch Normalization            [3,16]          float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [3,16]          float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [3,16]          float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Convolution 1D                 [3,16]          float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Batch Normalization            [3,16]          float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [3,16]          float      dequeue
*    activation = relu
*    trainable = True
* Long Short-Term Memory         [3,16]          float      dequeue
*    units = 16
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[16,64]
*    recurrent_kernel = float[16,64]
*    bias = float[64]
* Global average pooling 1D      [16]            float      dequeue
*    trainable = True
* Dense                          [40]            float      dequeue
*    units = 40
*    use_bias = False
*    activation = linear
*    trainable = True
*    weight = float[16,40]
* Batch Normalization            [40]            float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 1
*    gamma = float[40]
*    beta = float[40]
*    mean = float[40]
*    variance = float[40]
* Activation                     [40]            float      dequeue
*    activation = relu
*    trainable = True
* Dropout                        [40]            float      dequeue
*    rate = 0.1
*    trainable = True
* Dense                          [4]             float      dequeue
*    units = 4
*    use_bias = False
*    activation = linear
*    trainable = True
*    weight = float[40,4]
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
*    Parameter data_in is Input of size float[6].
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

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 88.259 %
* (F1S) F1 Score 89.166 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction               58246            47798            18927            86873
* (FN) False Negative or Incorrect Negative Prediction             6835             4981             2095            14271
* (FP) False Positive or Incorrect Positive Prediction             4562             1369            18478             3773
* (TN) True Negative or Correct Negative Prediction              170383           185878           200526           135109
* (TPR) True Positive Rate or Sensitivity, Recall               89.50 %          90.56 %          90.03 %          85.89 %
* (TNR) True Negative Rate or Specificity, Selectivity          97.39 %          99.27 %          91.56 %          97.28 %
* (PPV) Positive Predictive Value or Precision                  92.74 %          97.22 %          50.60 %          95.84 %
* (NPV) Negative Predictive Value                               96.14 %          97.39 %          98.97 %          90.45 %
* (FNR) False Negative Rate or Miss Rate                        10.50 %           9.44 %           9.97 %          14.11 %
* (FPR) False Positive Rate or Fall-Out                          2.61 %           0.73 %           8.44 %           2.72 %
* (FDR) False Discovery Rate                                     7.26 %           2.78 %          49.40 %           4.16 %
* (FOR) False Omission Rate                                      3.86 %           2.61 %           1.03 %           9.55 %
* (F1S) F1 Score                                                91.09 %          93.77 %          64.79 %          90.59 %
*/


#define IMAI_TEST_AVG_ACC 0.8825877196637031 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8916564762649238 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 58246, FN: 6835, FP: 4562, TN: 170383, TPR: 0.8949770286258, TNR: 0.9739232330160, PPV: 0.9273659406445, NPV: 0.9614316830118, FNR: 0.1050229713741, FPR: 0.0260767669839, FDR: 0.0726340593554, FOR: 0.0385683169881, F1S: 0.9108836569212, }, \
 {name: "imbalance", TP: 47798, FN: 4981, FP: 1369, TN: 185878, TPR: 0.9056253434130, TNR: 0.9926888014227, PPV: 0.9721561209754, NPV: 0.9739022000534, FNR: 0.0943746565869, FPR: 0.0073111985772, FDR: 0.0278438790245, FOR: 0.0260977999465, F1S: 0.9377121221038, }, \
 {name: "working", TP: 86873, FN: 14271, FP: 3773, TN: 135109, TPR: 0.8589041366764, TNR: 0.9728330525194, PPV: 0.9583765417117, NPV: 0.9044651225063, FNR: 0.1410958633235, FPR: 0.0271669474805, FDR: 0.0416234582882, FOR: 0.0955348774936, F1S: 0.9059179310704, }, \
 {name: "impact", TP: 18927, FN: 2095, FP: 18478, TN: 200526, TPR: 0.9003424983350, TNR: 0.9156271118335, PPV: 0.5060018714075, NPV: 0.9896604991585, FNR: 0.0996575016649, FPR: 0.0843728881664, FDR: 0.4939981285924, FOR: 0.0103395008414, F1S: 0.6478853954507, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 90.768 %
* (F1S) F1 Score 91.192 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction              158806           145160            56000           230128
* (FN) False Negative or Incorrect Negative Prediction            25716             1215             3528            29562
* (FP) False Positive or Incorrect Positive Prediction             5792              884            35947            17398
* (TN) True Negative or Correct Negative Prediction              459801           502856           554640           373027
* (TPR) True Positive Rate or Sensitivity, Recall               86.06 %          99.17 %          94.07 %          88.62 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.76 %          99.82 %          93.91 %          95.54 %
* (PPV) Positive Predictive Value or Precision                  96.48 %          99.39 %          60.90 %          92.97 %
* (NPV) Negative Predictive Value                               94.70 %          99.76 %          99.37 %          92.66 %
* (FNR) False Negative Rate or Miss Rate                        13.94 %           0.83 %           5.93 %          11.38 %
* (FPR) False Positive Rate or Fall-Out                          1.24 %           0.18 %           6.09 %           4.46 %
* (FDR) False Discovery Rate                                     3.52 %           0.61 %          39.10 %           7.03 %
* (FOR) False Omission Rate                                      5.30 %           0.24 %           0.63 %           7.34 %
* (F1S) F1 Score                                                90.98 %          99.28 %          73.94 %          90.74 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9076763341870284 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9119231374006519 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 158806, FN: 25716, FP: 5792, TN: 459801, TPR: 0.8606345042867, TNR: 0.9875599504288, PPV: 0.9648112370745, NPV: 0.9470337804855, FNR: 0.1393654957132, FPR: 0.0124400495711, FDR: 0.0351887629254, FOR: 0.0529662195144, F1S: 0.9097502291475, }, \
 {name: "imbalance", TP: 145160, FN: 1215, FP: 884, TN: 502856, TPR: 0.9916994022203, TNR: 0.9982451264541, PPV: 0.9939470296622, NPV: 0.9975896252710, FNR: 0.0083005977796, FPR: 0.0017548735458, FDR: 0.0060529703377, FOR: 0.0024103747289, F1S: 0.9928219438545, }, \
 {name: "working", TP: 230128, FN: 29562, FP: 17398, TN: 373027, TPR: 0.8861642727867, TNR: 0.9554383044118, PPV: 0.9297124342493, NPV: 0.9265702739021, FNR: 0.1138357272132, FPR: 0.0445616955881, FDR: 0.0702875657506, FOR: 0.0734297260978, F1S: 0.9074161698369, }, \
 {name: "impact", TP: 56000, FN: 3528, FP: 35947, TN: 554640, TPR: 0.9407337723424, TNR: 0.9391334384265, PPV: 0.6090465159276, NPV: 0.9936793223545, FNR: 0.0592662276575, FPR: 0.0608665615734, FDR: 0.3909534840723, FOR: 0.0063206776454, F1S: 0.7393959399240, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 88.588 %
* (F1S) F1 Score 89.118 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction               48387            45315            16623            69536
* (FN) False Negative or Incorrect Negative Prediction             9354             2269             3011             8535
* (FP) False Positive or Incorrect Positive Prediction             2075             1380            12696             7018
* (TN) True Negative or Correct Negative Prediction              143214           154066           170700           117941
* (TPR) True Positive Rate or Sensitivity, Recall               83.80 %          95.23 %          84.66 %          89.07 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.57 %          99.11 %          93.08 %          94.38 %
* (PPV) Positive Predictive Value or Precision                  95.89 %          97.04 %          56.70 %          90.83 %
* (NPV) Negative Predictive Value                               93.87 %          98.55 %          98.27 %          93.25 %
* (FNR) False Negative Rate or Miss Rate                        16.20 %           4.77 %          15.34 %          10.93 %
* (FPR) False Positive Rate or Fall-Out                          1.43 %           0.89 %           6.92 %           5.62 %
* (FDR) False Discovery Rate                                     4.11 %           2.96 %          43.30 %           9.17 %
* (FOR) False Omission Rate                                      6.13 %           1.45 %           1.73 %           6.75 %
* (F1S) F1 Score                                                89.44 %          96.13 %          67.91 %          89.94 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8858838595281485 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8911827637535279 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 48387, FN: 9354, FP: 2075, TN: 143214, TPR: 0.8380007273860, TNR: 0.9857181204358, PPV: 0.9588799492687, NPV: 0.9386896334749, FNR: 0.1619992726139, FPR: 0.0142818795641, FDR: 0.0411200507312, FOR: 0.0613103665250, F1S: 0.8943744628152, }, \
 {name: "imbalance", TP: 45315, FN: 2269, FP: 1380, TN: 154066, TPR: 0.9523159045057, TNR: 0.9911223190046, PPV: 0.9704465146161, NPV: 0.9854862954552, FNR: 0.0476840954942, FPR: 0.0088776809953, FDR: 0.0295534853838, FOR: 0.0145137045447, F1S: 0.9612957286352, }, \
 {name: "working", TP: 69536, FN: 8535, FP: 7018, TN: 117941, TPR: 0.8906764355522, TNR: 0.9438375787258, PPV: 0.9083261488622, NPV: 0.9325168411398, FNR: 0.1093235644477, FPR: 0.0561624212741, FDR: 0.0916738511377, FOR: 0.0674831588601, F1S: 0.8994147130153, }, \
 {name: "impact", TP: 16623, FN: 3011, FP: 12696, TN: 170700, TPR: 0.8466435774676, TNR: 0.9307727540404, PPV: 0.5669702240867, NPV: 0.9826666129375, FNR: 0.1533564225323, FPR: 0.0692272459595, FDR: 0.4330297759132, FOR: 0.0173333870624, F1S: 0.6791412170857, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "imbalance", "working", "impact"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xe4, 0x05, 0xde, 0x64, 0x6b, 0x9f, 0xa1, 0x49, 0x81, 0xa4, 0xd2, 0x69, 0xac, 0x89, 0x24, 0x5d}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [6] (24 bytes)
#define IMAI_DATA_IN_COUNT (6)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [4] (16 bytes)
#define IMAI_DATA_OUT_COUNT (4)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (77)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
