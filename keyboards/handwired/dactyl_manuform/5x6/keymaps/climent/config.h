/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 200
#endif

#define USE_SERIAL

#define EE_HANDS
#define MASTER_LEFT

#define KINETIC_SPEED

#ifdef SOFT_SERIAL_PIN
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2
#endif

#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_ANIMATIONS

// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN D3
#ifdef RGBLED_NUM
#undef RGBLED_NUM
#define RGBLED_NUM 62
#endif
#define RGBLED_SPLIT {31, 31}
#define RGBLIGHT_DEFAULT_HUE 169

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
#define BACKLIGHT_LEVELS 3
#define RGBLIGHT_LAYERS
//#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
/* use general brightness for layers */
//#define RGBLIGHT_LAYERS_RETAIN_VAL
