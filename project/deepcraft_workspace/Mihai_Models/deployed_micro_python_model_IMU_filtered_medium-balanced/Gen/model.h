/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/22/2026 16:44:38 UTC. Any changes will be lost.
* 
* Model ID  412c4a54-816c-4b2f-96c9-1a39fc311300
* 
* Memory    Size                      Efficiency
* Buffers   16000 bytes (RAM)         80 %
* State     1008 bytes (RAM)          100 %
* Readonly  94032 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-balanced-3
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | imbalance
* 2           | working
* 3           | impact
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [100,2]         float      dequeue
*    window_shape = [100,2]
*    stride = 160
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [100,2]         float      dequeue
*    contextual_length_sec = 0.25
*    prediction_freq = 5
* Input Layer                    [100,2]         float      dequeue
*    shape = [100,2]
* Convolution 1D                 [50,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,2,16]
* Batch Normalization            [50,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [50,16]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [50,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Convolution 1D                 [50,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [50,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [25,32]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [25,64]         float      dequeue
*    filters = 64
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,64]
* Convolution 1D                 [25,64]         float      dequeue
*    filters = 64
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,64,64]
* Batch Normalization            [25,64]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[64]
*    beta = float[64]
*    mean = float[64]
*    variance = float[64]
* Activation                     [25,64]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [12,64]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Global average pooling 1D      [64]            float      dequeue
*    trainable = True
* Dense                          [4]             float      dequeue
*    units = 4
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[64,4]
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
*    Parameter data_in is Input of size float[2].
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
* (ACC) Accuracy 91.092 %
* (F1S) F1 Score 91.204 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction                1246              445              355              623
* (FN) False Negative or Incorrect Negative Prediction               47               15               96              103
* (FP) False Positive or Incorrect Positive Prediction               17                0               95              149
* (TN) True Negative or Correct Negative Prediction                1620             2470             2384             2055
* (TPR) True Positive Rate or Sensitivity, Recall               96.37 %          96.74 %          78.71 %          85.81 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.96 %         100.00 %          96.17 %          93.24 %
* (PPV) Positive Predictive Value or Precision                  98.65 %         100.00 %          78.89 %          80.70 %
* (NPV) Negative Predictive Value                               97.18 %          99.40 %          96.13 %          95.23 %
* (FNR) False Negative Rate or Miss Rate                         3.63 %           3.26 %          21.29 %          14.19 %
* (FPR) False Positive Rate or Fall-Out                          1.04 %           0.00 %           3.83 %           6.76 %
* (FDR) False Discovery Rate                                     1.35 %           0.00 %          21.11 %          19.30 %
* (FOR) False Omission Rate                                      2.82 %           0.60 %           3.87 %           4.77 %
* (F1S) F1 Score                                                97.50 %          98.34 %          78.80 %          83.18 %
*/


#define IMAI_TEST_AVG_ACC 0.9109215017064847 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9120352454918249 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 1246, FN: 47, FP: 17, TN: 1620, TPR: 0.9636504253673, TNR: 0.9896151496640, PPV: 0.9865399841646, NPV: 0.9718056388722, FNR: 0.0363495746326, FPR: 0.0103848503359, FDR: 0.0134600158353, FOR: 0.0281943611277, F1S: 0.9749608763693, }, \
 {name: "imbalance", TP: 445, FN: 15, FP: 0, TN: 2470, TPR: 0.9673913043478, TNR: 1, PPV: 1, NPV: 0.9939637826961, FNR: 0.0326086956521, FPR: 0, FDR: 0, FOR: 0.0060362173038, F1S: 0.9834254143646, }, \
 {name: "working", TP: 623, FN: 103, FP: 149, TN: 2055, TPR: 0.8581267217630, TNR: 0.9323956442831, PPV: 0.8069948186528, NPV: 0.9522706209453, FNR: 0.1418732782369, FPR: 0.0676043557168, FDR: 0.1930051813471, FOR: 0.0477293790546, F1S: 0.8317757009345, }, \
 {name: "impact", TP: 355, FN: 96, FP: 95, TN: 2384, TPR: 0.7871396895787, TNR: 0.9616780960064, PPV: 0.7888888888888, NPV: 0.9612903225806, FNR: 0.2128603104212, FPR: 0.0383219039935, FDR: 0.2111111111111, FOR: 0.0387096774193, F1S: 0.7880133185349, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 88.848 %
* (F1S) F1 Score 88.878 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction                1257             1595             1509             3168
* (FN) False Negative or Incorrect Negative Prediction              181               25              413              326
* (FP) False Positive or Incorrect Positive Prediction               23                0              321              601
* (TN) True Negative or Correct Negative Prediction                7013             6854             6231             4379
* (TPR) True Positive Rate or Sensitivity, Recall               87.41 %          98.46 %          78.51 %          90.67 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.67 %         100.00 %          95.10 %          87.93 %
* (PPV) Positive Predictive Value or Precision                  98.20 %         100.00 %          82.46 %          84.05 %
* (NPV) Negative Predictive Value                               97.48 %          99.64 %          93.78 %          93.07 %
* (FNR) False Negative Rate or Miss Rate                        12.59 %           1.54 %          21.49 %           9.33 %
* (FPR) False Positive Rate or Fall-Out                          0.33 %           0.00 %           4.90 %          12.07 %
* (FDR) False Discovery Rate                                     1.80 %           0.00 %          17.54 %          15.95 %
* (FOR) False Omission Rate                                      2.52 %           0.36 %           6.22 %           6.93 %
* (F1S) F1 Score                                                92.49 %          99.22 %          80.44 %          87.24 %
*/


#define IMAI_TRAIN_AVG_ACC 0.8884824168043427 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.8887802775486803 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 1257, FN: 181, FP: 23, TN: 7013, TPR: 0.8741307371349, TNR: 0.9967310972143, PPV: 0.98203125, NPV: 0.9748401445649, FNR: 0.1258692628650, FPR: 0.0032689027856, FDR: 0.01796875, FOR: 0.0251598554350, F1S: 0.9249448123620, }, \
 {name: "imbalance", TP: 1595, FN: 25, FP: 0, TN: 6854, TPR: 0.9845679012345, TNR: 1, PPV: 1, NPV: 0.9963657508358, FNR: 0.0154320987654, FPR: 0, FDR: 0, FOR: 0.0036342491641, F1S: 0.9922239502332, }, \
 {name: "working", TP: 3168, FN: 326, FP: 601, TN: 4379, TPR: 0.9066971951917, TNR: 0.8793172690763, PPV: 0.8405412576280, NPV: 0.9307120085015, FNR: 0.0933028048082, FPR: 0.1206827309236, FDR: 0.1594587423719, FOR: 0.0692879914984, F1S: 0.8723667905824, }, \
 {name: "impact", TP: 1509, FN: 413, FP: 321, TN: 6231, TPR: 0.7851196670135, TNR: 0.9510073260073, PPV: 0.8245901639344, NPV: 0.9378386514148, FNR: 0.2148803329864, FPR: 0.0489926739926, FDR: 0.1754098360655, FOR: 0.0621613485851, F1S: 0.8043710021321, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 88.791 %
* (F1S) F1 Score 88.054 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction                  11              814              394              690
* (FN) False Negative or Incorrect Negative Prediction               53                0              115               73
* (FP) False Positive or Incorrect Positive Prediction                0                1               75              165
* (TN) True Negative or Correct Negative Prediction                2086             1335             1566             1222
* (TPR) True Positive Rate or Sensitivity, Recall               17.19 %         100.00 %          77.41 %          90.43 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.93 %          95.43 %          88.10 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          99.88 %          84.01 %          80.70 %
* (NPV) Negative Predictive Value                               97.52 %         100.00 %          93.16 %          94.36 %
* (FNR) False Negative Rate or Miss Rate                        82.81 %           0.00 %          22.59 %           9.57 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.07 %           4.57 %          11.90 %
* (FDR) False Discovery Rate                                     0.00 %           0.12 %          15.99 %          19.30 %
* (FOR) False Omission Rate                                      2.48 %           0.00 %           6.84 %           5.64 %
* (F1S) F1 Score                                                29.33 %          99.94 %          80.57 %          85.29 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8879069767441861 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8805369943917459 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 11, FN: 53, FP: 0, TN: 2086, TPR: 0.171875, TNR: 1, PPV: 1, NPV: 0.9752220663861, FNR: 0.828125, FPR: 0, FDR: 0, FOR: 0.0247779336138, F1S: 0.2933333333333, }, \
 {name: "imbalance", TP: 814, FN: 0, FP: 1, TN: 1335, TPR: 1, TNR: 0.9992514970059, PPV: 0.9987730061349, NPV: 1, FNR: 0, FPR: 0.0007485029940, FDR: 0.0012269938650, FOR: 0, F1S: 0.9993861264579, }, \
 {name: "working", TP: 690, FN: 73, FP: 165, TN: 1222, TPR: 0.9043250327653, TNR: 0.8810382119682, PPV: 0.8070175438596, NPV: 0.9436293436293, FNR: 0.0956749672346, FPR: 0.1189617880317, FDR: 0.1929824561403, FOR: 0.0563706563706, F1S: 0.8529048207663, }, \
 {name: "impact", TP: 394, FN: 115, FP: 75, TN: 1566, TPR: 0.7740667976424, TNR: 0.9542961608775, PPV: 0.8400852878464, NPV: 0.9315883402736, FNR: 0.2259332023575, FPR: 0.0457038391224, FDR: 0.1599147121535, FOR: 0.0684116597263, F1S: 0.8057259713701, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "imbalance", "working", "impact"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x54, 0x4a, 0x2c, 0x41, 0x6c, 0x81, 0x2f, 0x4b, 0x96, 0xc9, 0x1a, 0x39, 0xfc, 0x31, 0x13, 0x00}

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

// data_in [2] (8 bytes)
#define IMAI_DATA_IN_COUNT (2)
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

#define IMAI_KEY_MAX (39)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
