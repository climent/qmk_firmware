#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/


//#define USE_MATRIX_I2C

#define EE_HANDS

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 150
#endif

//#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

//#define SPLIT_TRANSACTION_IDS_KB MOUSE_SYNC
//#define SPLIT_LAYER_STATE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
    #define SPLIT_POINTING_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
    #define POINTING_DEVICE_LEFT
    #define POINTING_DEVICE_ROTATION_90
    #define POINTING_DEVICE_TASK_THROTTLE_MS 8
#endif
