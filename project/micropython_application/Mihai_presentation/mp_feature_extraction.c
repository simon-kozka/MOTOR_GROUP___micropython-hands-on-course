#include "py/runtime.h"
#include "py/mphal.h"
#include "highpass_filter.h"
#include "feature_extraction.h"

#ifndef STATIC
#define STATIC static
#endif

#define WINDOW_SIZE 20
#define WARMUP_SAMPLES 40
#define HALF_WINDOW (WINDOW_SIZE / 2)

// -----------------------------
// High-pass filter wrappers
// -----------------------------
STATIC mp_obj_t mp_init_high_pass_filter(mp_obj_t cutoff_obj, mp_obj_t fs_obj) {
    float cutoff = mp_obj_get_float(cutoff_obj);
    float fs = mp_obj_get_float(fs_obj);

    HighPassFilter* filter = m_new_obj(HighPassFilter);
    initHighPassFilter(filter, cutoff, fs);
    return MP_OBJ_FROM_PTR(filter);
}
MP_DEFINE_CONST_FUN_OBJ_2(mp_init_high_pass_filter_obj, mp_init_high_pass_filter);

STATIC mp_obj_t mp_filter_high_pass(mp_obj_t filter_obj, mp_obj_t x_obj) {
    HighPassFilter* filter = MP_OBJ_TO_PTR(filter_obj);
    float x = mp_obj_get_float(x_obj);
    return mp_obj_new_float(filterHighPass(filter, x));
}
MP_DEFINE_CONST_FUN_OBJ_2(mp_filter_high_pass_obj, mp_filter_high_pass);

// -----------------------------
// Feature extraction wrapper
// -----------------------------
STATIC mp_obj_t mp_compute_features(mp_obj_t window_obj) {
    mp_obj_list_t* window = MP_OBJ_TO_PTR(window_obj);
    size_t window_size = window->len;

    float* window_data = m_new(float, window_size);
    for (size_t i = 0; i < window_size; i++) {
        window_data[i] = mp_obj_get_float(window->items[i]);
    }

    float rms, energy;
    computeFeatures(window_data, window_size, &rms, &energy);

    mp_obj_t items[2];
    items[0] = mp_obj_new_float(rms);
    items[1] = mp_obj_new_float(energy);

    return mp_obj_new_tuple(2, items);
}
MP_DEFINE_CONST_FUN_OBJ_1(mp_compute_features_obj, mp_compute_features);

// -----------------------------
// Module globals
// -----------------------------
STATIC const mp_rom_map_elem_t mp_module_feature_extraction_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR_init_high_pass_filter), MP_ROM_PTR(&mp_init_high_pass_filter_obj) },
    { MP_ROM_QSTR(MP_QSTR_filter_high_pass), MP_ROM_PTR(&mp_filter_high_pass_obj) },
    { MP_ROM_QSTR(MP_QSTR_compute_features), MP_ROM_PTR(&mp_compute_features_obj) },
};
STATIC MP_DEFINE_CONST_DICT(mp_module_feature_extraction_globals, mp_module_feature_extraction_globals_table);

const mp_obj_module_t mp_module_feature_extraction = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_feature_extraction_globals,
};

MP_REGISTER_MODULE(MP_QSTR_feature_extraction, mp_module_feature_extraction);