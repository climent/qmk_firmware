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

#define SPLIT_LED_STATE_ENABLE

#ifdef RGBLIGHT_ENABLE

    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_LAYERS

    /* ws2812 RGB LED */
    #define RGB_DI_PIN D3


    //#define RGBLIGHT_ANIMATIONS
    //#define RGBLIGHT_EFFECT_BREATHING
    //#define RGBLIGHT_EFFECT_RAINBOW_MOOD
    //#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    //#define RGBLIGHT_EFFECT_SNAKE
    //#define RGBLIGHT_EFFECT_KNIGHT
    //#define RGBLIGHT_EFFECT_CHRISTMAS
    //#define RGBLIGHT_EFFECT_STATIC_GRADIENT
    //#define RGBLIGHT_EFFECT_RGB_TEST
    //#define RGBLIGHT_EFFECT_ALTERNATING
    //#define RGBLIGHT_EFFECT_TWINKLE

    #undef RGBLED_NUM
    #define RGBLED_NUM 14
    #define RGBLED_SPLIT { 7, 7 } // haven't figured out how to use this yet

    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef OLED_ENABLE
//    #define OLED_DISPLAY_128X64
//    #define OLED_IC OLED_IC_SH1106
    #define OLED_FONT_H "keyboards/sofle/keymaps/climent/glcdfont.c"
    #define OLED_FONT_WIDTH 8
    #define OLED_FONT_START 0x80
    #define OLED_FONT_END 0xbf
#endif

#ifdef POINTING_DEVICE_ENABLE
    #define SPLIT_POINTING_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
    #define POINTING_DEVICE_RIGHT
    #define POINTING_DEVICE_ROTATION_90
    #define POINTING_DEVICE_TASK_THROTTLE_MS 8
#endif
