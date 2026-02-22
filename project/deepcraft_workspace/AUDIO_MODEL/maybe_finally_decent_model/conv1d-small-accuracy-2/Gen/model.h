/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/21/2026 12:08:47 UTC. Any changes will be lost.
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


#define IMAI_TEST_AVG_ACC 0.8116834086159239 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8128992207026247 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 56924, FN: 8738, FP: 18509, TN: 64159, TPR: 0.8669245530139, TNR: 0.7761044176706, PPV: 0.7546299364999, NPV: 0.8801322413816, FNR: 0.1330754469860, FPR: 0.2238955823293, FDR: 0.2453700635000, FOR: 0.1198677586183, F1S: 0.8068889755129, }, \
 {name: "imbalance", TP: 26192, FN: 124, FP: 2388, TN: 119626, TPR: 0.9952880376956, TNR: 0.9804284754208, PPV: 0.9164450664800, NPV: 0.9989645093945, FNR: 0.0047119623043, FPR: 0.0195715245791, FDR: 0.0835549335199, FOR: 0.0010354906054, F1S: 0.9542407461381, }, \
 {name: "working", TP: 33323, FN: 18726, FP: 1206, TN: 95075, TPR: 0.6402236354204, TNR: 0.9874741641653, PPV: 0.9650728373251, NPV: 0.8354496006186, FNR: 0.3597763645795, FPR: 0.0125258358346, FDR: 0.0349271626748, FOR: 0.1645503993813, F1S: 0.7697798516944, }, \
 {name: "impact", TP: 3958, FN: 345, FP: 5830, TN: 138197, TPR: 0.9198233790378, TNR: 0.9595214786116, PPV: 0.4043727012668, NPV: 0.9975097804275, FNR: 0.0801766209621, FPR: 0.0404785213883, FDR: 0.5956272987331, FOR: 0.0024902195724, F1S: 0.5617770207934, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 95.076 %
* (F1S) F1 Score 95.213 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction              157923            88897            10726           154641
* (FN) False Negative or Incorrect Negative Prediction            19214               82              726             1324
* (FP) False Positive or Incorrect Positive Prediction             1816             4332             7784             7414
* (TN) True Negative or Correct Negative Prediction              254580           340222           414297           270154
* (TPR) True Positive Rate or Sensitivity, Recall               89.15 %          99.91 %          93.66 %          99.15 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.29 %          98.74 %          98.16 %          97.33 %
* (PPV) Positive Predictive Value or Precision                  98.86 %          95.35 %          57.95 %          95.43 %
* (NPV) Negative Predictive Value                               92.98 %          99.98 %          99.83 %          99.51 %
* (FNR) False Negative Rate or Miss Rate                        10.85 %           0.09 %           6.34 %           0.85 %
* (FPR) False Positive Rate or Fall-Out                          0.71 %           1.26 %           1.84 %           2.67 %
* (FDR) False Discovery Rate                                     1.14 %           4.65 %          42.05 %           4.57 %
* (FOR) False Omission Rate                                      7.02 %           0.02 %           0.17 %           0.49 %
* (F1S) F1 Score                                                93.76 %          97.58 %          71.60 %          97.25 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9507626870388183 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9521338037875351 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 157923, FN: 19214, FP: 1816, TN: 254580, TPR: 0.8915302844690, TNR: 0.9929172061966, PPV: 0.9886314550610, NPV: 0.9298231517126, FNR: 0.1084697155309, FPR: 0.0070827938033, FDR: 0.0113685449389, FOR: 0.0701768482873, F1S: 0.9375734691696, }, \
 {name: "imbalance", TP: 88897, FN: 82, FP: 4332, TN: 340222, TPR: 0.9990784342372, TNR: 0.9874272247601, PPV: 0.9535337716804, NPV: 0.9997590389769, FNR: 0.0009215657627, FPR: 0.0125727752398, FDR: 0.0464662283195, FOR: 0.0002409610230, F1S: 0.9757749385317, }, \
 {name: "working", TP: 154641, FN: 1324, FP: 7414, TN: 270154, TPR: 0.9915109159106, TNR: 0.9732894281761, PPV: 0.9542501002745, NPV: 0.9951229933917, FNR: 0.0084890840893, FPR: 0.0267105718238, FDR: 0.0457498997254, FOR: 0.0048770066082, F1S: 0.9725237406452, }, \
 {name: "impact", TP: 10726, FN: 726, FP: 7784, TN: 414297, TPR: 0.9366049598323, TNR: 0.9815580421767, PPV: 0.5794705564559, NPV: 0.9982506993588, FNR: 0.0633950401676, FPR: 0.0184419578232, FDR: 0.4205294435440, FOR: 0.0017493006411, F1S: 0.7159735665175, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 82.532 %
* (F1S) F1 Score 82.854 %
* 
* Name of class                                               unlabeled        imbalance           impact          working
* (TP) True Positive or Correct Positive Prediction               51836            34570             4393            34914
* (FN) False Negative or Incorrect Negative Prediction             7778               50             1822            16957
* (FP) False Positive or Incorrect Positive Prediction            15904             1935             7061             1707
* (TN) True Negative or Correct Negative Prediction               76802           115765           139044            98742
* (TPR) True Positive Rate or Sensitivity, Recall               86.95 %          99.86 %          70.68 %          67.31 %
* (TNR) True Negative Rate or Specificity, Selectivity          82.84 %          98.36 %          95.17 %          98.30 %
* (PPV) Positive Predictive Value or Precision                  76.52 %          94.70 %          38.35 %          95.34 %
* (NPV) Negative Predictive Value                               90.80 %          99.96 %          98.71 %          85.34 %
* (FNR) False Negative Rate or Miss Rate                        13.05 %           0.14 %          29.32 %          32.69 %
* (FPR) False Positive Rate or Fall-Out                         17.16 %           1.64 %           4.83 %           1.70 %
* (FDR) False Discovery Rate                                    23.48 %           5.30 %          61.65 %           4.66 %
* (FOR) False Omission Rate                                      9.20 %           0.04 %           1.29 %          14.66 %
* (F1S) F1 Score                                                81.40 %          97.21 %          49.73 %          78.91 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8253216911764706 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8285423704830958 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 51836, FN: 7778, FP: 15904, TN: 76802, TPR: 0.8695272922467, TNR: 0.8284469182145, PPV: 0.7652199586654, NPV: 0.9080397257034, FNR: 0.1304727077532, FPR: 0.1715530817854, FDR: 0.2347800413345, FOR: 0.0919602742965, F1S: 0.8140458878401, }, \
 {name: "imbalance", TP: 34570, FN: 50, FP: 1935, TN: 115765, TPR: 0.9985557481224, TNR: 0.9835598980458, PPV: 0.9469935625256, NPV: 0.9995682769934, FNR: 0.0014442518775, FPR: 0.0164401019541, FDR: 0.0530064374743, FOR: 0.0004317230065, F1S: 0.9720913884007, }, \
 {name: "working", TP: 34914, FN: 16957, FP: 1707, TN: 98742, TPR: 0.6730928649919, TNR: 0.9830063017053, PPV: 0.9533874006717, NPV: 0.8534386641198, FNR: 0.3269071350080, FPR: 0.0169936982946, FDR: 0.0466125993282, FOR: 0.1465613358801, F1S: 0.7890882791664, }, \
 {name: "impact", TP: 4393, FN: 1822, FP: 7061, TN: 139044, TPR: 0.7068382944489, TNR: 0.9516717429246, PPV: 0.3835341365461, NPV: 0.9870657220337, FNR: 0.2931617055510, FPR: 0.0483282570753, FDR: 0.6164658634538, FOR: 0.0129342779662, F1S: 0.4972550795177, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "imbalance", "working", "impact"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x8f, 0x64, 0x9a, 0xfb, 0xe7, 0x02, 0xa0, 0x4b, 0xbb, 0x42, 0x05, 0xe9, 0x4f, 0x32, 0xce, 0xa9}

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

// data_in [1] (4 bytes)
#define IMAI_DATA_IN_COUNT (1)
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

#define IMAI_KEY_MAX (46)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
