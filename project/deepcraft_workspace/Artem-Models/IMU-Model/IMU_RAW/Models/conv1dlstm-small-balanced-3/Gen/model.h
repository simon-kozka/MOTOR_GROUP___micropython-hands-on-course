/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/18/2026 21:57:47 UTC. Any changes will be lost.
* 
* Model ID  2d8612f4-4a0a-4c6f-9a59-af17fcb7aeb0
* 
* Memory    Size                      Efficiency
* Buffers   3040 bytes (RAM)          84 %
* State     944 bytes (RAM)           100 %
* Readonly  66336 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-small-balanced-3
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | imbalance
* 2           | working
* 3           | impact
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [20,6]          float      dequeue
*    window_shape = [20,6]
*    stride = 120
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [20,6]          float      dequeue
*    contextual_length_sec = 0.1
*    prediction_freq = 10
* Input Layer                    [20,6]          float      dequeue
*    shape = [20,6]
* Convolution 1D                 [10,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,6,32]
* Batch Normalization            [10,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [10,32]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [10,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Convolution 1D                 [10,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [10,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [10,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [5,32]          float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Long Short-Term Memory         [32]            float      dequeue
*    units = 32
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = False
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[32,128]
*    recurrent_kernel = float[32,128]
*    bias = float[128]
* Flatten                        [32]            float      dequeue
* Dense                          [40]            float      dequeue
*    units = 40
*    use_bias = False
*    activation = linear
*    trainable = True
*    weight = float[32,40]
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
* (ACC) Accuracy 83.789 %
* (F1S) F1 Score 83.790 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction                 987             1031              371              795
* (FN) False Negative or Incorrect Negative Prediction              228                0              226              162
* (FP) False Positive or Incorrect Positive Prediction               84               38              131              363
* (TN) True Negative or Correct Negative Prediction                2501             2731             3072             2480
* (TPR) True Positive Rate or Sensitivity, Recall               81.23 %         100.00 %          62.14 %          83.07 %
* (TNR) True Negative Rate or Specificity, Selectivity          96.75 %          98.63 %          95.91 %          87.23 %
* (PPV) Positive Predictive Value or Precision                  92.16 %          96.45 %          73.90 %          68.65 %
* (NPV) Negative Predictive Value                               91.65 %         100.00 %          93.15 %          93.87 %
* (FNR) False Negative Rate or Miss Rate                        18.77 %           0.00 %          37.86 %          16.93 %
* (FPR) False Positive Rate or Fall-Out                          3.25 %           1.37 %           4.09 %          12.77 %
* (FDR) False Discovery Rate                                     7.84 %           3.55 %          26.10 %          31.35 %
* (FOR) False Omission Rate                                      8.35 %           0.00 %           6.85 %           6.13 %
* (F1S) F1 Score                                                86.35 %          98.19 %          67.52 %          75.18 %
*/


#define IMAI_TEST_AVG_ACC 0.8378947368421052 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8379036605460978 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 987, FN: 228, FP: 84, TN: 2501, TPR: 0.8123456790123, TNR: 0.9675048355899, PPV: 0.9215686274509, NPV: 0.9164529131550, FNR: 0.1876543209876, FPR: 0.0324951644100, FDR: 0.0784313725490, FOR: 0.0835470868449, F1S: 0.8635170603674, }, \
 {name: "imbalance", TP: 1031, FN: 0, FP: 38, TN: 2731, TPR: 1, TNR: 0.9862766341639, PPV: 0.9644527595884, NPV: 1, FNR: 0, FPR: 0.0137233658360, FDR: 0.0355472404115, FOR: 0, F1S: 0.9819047619047, }, \
 {name: "working", TP: 795, FN: 162, FP: 363, TN: 2480, TPR: 0.8307210031347, TNR: 0.8723179739711, PPV: 0.6865284974093, NPV: 0.9386828160484, FNR: 0.1692789968652, FPR: 0.1276820260288, FDR: 0.3134715025906, FOR: 0.0613171839515, F1S: 0.7517730496453, }, \
 {name: "impact", TP: 371, FN: 226, FP: 131, TN: 3072, TPR: 0.6214405360134, TNR: 0.9591008429597, PPV: 0.7390438247011, NPV: 0.9314736203759, FNR: 0.3785594639865, FPR: 0.0408991570402, FDR: 0.2609561752988, FOR: 0.0685263796240, F1S: 0.6751592356687, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 87.723 %
* (F1S) F1 Score 87.495 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction                3661             4027             1426             5727
* (FN) False Negative or Incorrect Negative Prediction              940               22              878              237
* (FP) False Positive or Incorrect Positive Prediction               56               99              241             1681
* (TN) True Negative or Correct Negative Prediction               12261            12770            14373             9273
* (TPR) True Positive Rate or Sensitivity, Recall               79.57 %          99.46 %          61.89 %          96.03 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.55 %          99.23 %          98.35 %          84.65 %
* (PPV) Positive Predictive Value or Precision                  98.49 %          97.60 %          85.54 %          77.31 %
* (NPV) Negative Predictive Value                               92.88 %          99.83 %          94.24 %          97.51 %
* (FNR) False Negative Rate or Miss Rate                        20.43 %           0.54 %          38.11 %           3.97 %
* (FPR) False Positive Rate or Fall-Out                          0.45 %           0.77 %           1.65 %          15.35 %
* (FDR) False Discovery Rate                                     1.51 %           2.40 %          14.46 %          22.69 %
* (FOR) False Omission Rate                                      7.12 %           0.17 %           5.76 %           2.49 %
* (F1S) F1 Score                                                88.03 %          98.52 %          71.82 %          85.66 %
*/


#define IMAI_TRAIN_AVG_ACC 0.8772313512235489 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.8749528864068185 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 3661, FN: 940, FP: 56, TN: 12261, TPR: 0.7956965876983, TNR: 0.9954534383372, PPV: 0.9849340866290, NPV: 0.9287932732368, FNR: 0.2043034123016, FPR: 0.0045465616627, FDR: 0.0150659133709, FOR: 0.0712067267631, F1S: 0.8802596778071, }, \
 {name: "imbalance", TP: 4027, FN: 22, FP: 99, TN: 12770, TPR: 0.9945665596443, TNR: 0.9923070945683, PPV: 0.9760058167716, NPV: 0.9982801751094, FNR: 0.0054334403556, FPR: 0.0076929054316, FDR: 0.0239941832283, FOR: 0.0017198248905, F1S: 0.9851987767584, }, \
 {name: "working", TP: 5727, FN: 237, FP: 1681, TN: 9273, TPR: 0.9602615694164, TNR: 0.8465400766843, PPV: 0.7730831533477, NPV: 0.9750788643533, FNR: 0.0397384305835, FPR: 0.1534599233156, FDR: 0.2269168466522, FOR: 0.0249211356466, F1S: 0.8565659587197, }, \
 {name: "impact", TP: 1426, FN: 878, FP: 241, TN: 14373, TPR: 0.6189236111111, TNR: 0.9835089640071, PPV: 0.8554289142171, NPV: 0.9424300045898, FNR: 0.3810763888888, FPR: 0.0164910359928, FDR: 0.1445710857828, FOR: 0.0575699954101, F1S: 0.7182070007554, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 84.381 %
* (F1S) F1 Score 84.007 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction                1190             1197              408             1338
* (FN) False Negative or Incorrect Negative Prediction              252               37              379               97
* (FP) False Positive or Incorrect Positive Prediction               62               50              116              537
* (TN) True Negative or Correct Negative Prediction                3394             3614             3995             2926
* (TPR) True Positive Rate or Sensitivity, Recall               82.52 %          97.00 %          51.84 %          93.24 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.21 %          98.64 %          97.18 %          84.49 %
* (PPV) Positive Predictive Value or Precision                  95.05 %          95.99 %          77.86 %          71.36 %
* (NPV) Negative Predictive Value                               93.09 %          98.99 %          91.34 %          96.79 %
* (FNR) False Negative Rate or Miss Rate                        17.48 %           3.00 %          48.16 %           6.76 %
* (FPR) False Positive Rate or Fall-Out                          1.79 %           1.36 %           2.82 %          15.51 %
* (FDR) False Discovery Rate                                     4.95 %           4.01 %          22.14 %          28.64 %
* (FOR) False Omission Rate                                      6.91 %           1.01 %           8.66 %           3.21 %
* (F1S) F1 Score                                                88.34 %          96.49 %          62.24 %          80.85 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8438138015516538 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8400659700036764 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 1190, FN: 252, FP: 62, TN: 3394, TPR: 0.8252427184466, TNR: 0.9820601851851, PPV: 0.9504792332268, NPV: 0.9308831596269, FNR: 0.1747572815533, FPR: 0.0179398148148, FDR: 0.0495207667731, FOR: 0.0691168403730, F1S: 0.8834446919079, }, \
 {name: "imbalance", TP: 1197, FN: 37, FP: 50, TN: 3614, TPR: 0.9700162074554, TNR: 0.9863537117903, PPV: 0.9599037690457, NPV: 0.9898657901944, FNR: 0.0299837925445, FPR: 0.0136462882096, FDR: 0.0400962309542, FOR: 0.0101342098055, F1S: 0.9649334945586, }, \
 {name: "working", TP: 1338, FN: 97, FP: 537, TN: 2926, TPR: 0.9324041811846, TNR: 0.8449321397632, PPV: 0.7136, NPV: 0.9679126695335, FNR: 0.0675958188153, FPR: 0.1550678602367, FDR: 0.2864, FOR: 0.0320873304664, F1S: 0.8084592145015, }, \
 {name: "impact", TP: 408, FN: 379, FP: 116, TN: 3995, TPR: 0.5184243964421, TNR: 0.9717830211627, PPV: 0.7786259541984, NPV: 0.9133516232281, FNR: 0.4815756035578, FPR: 0.0282169788372, FDR: 0.2213740458015, FOR: 0.0866483767718, F1S: 0.6224256292906, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "imbalance", "working", "impact"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xf4, 0x12, 0x86, 0x2d, 0x0a, 0x4a, 0x6f, 0x4c, 0x9a, 0x59, 0xaf, 0x17, 0xfc, 0xb7, 0xae, 0xb0}

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

#define IMAI_KEY_MAX (78)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
