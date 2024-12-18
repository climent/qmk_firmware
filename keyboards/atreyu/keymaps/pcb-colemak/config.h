/* Copyright 2021 heyzeus <climent@gmail.com>
 * Copyright 2018 dek <dek@yolops.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

// place overrides here
#undef TAPPING_TERM
#define TAPPING_TERM 150

#define RETRO_TAPPING

// Underglow settings
#ifdef RGBLIGHT_ENABLE

// WS2812 RGB LED strip input and number of LEDs
#undef WS2812_DI_PIN
#define WS2812_DI_PIN C7
#define RGB_DI_PIN C7
#define RGBLED_NUM 5

#define RGBLIGHT_LIMIT_VAL 150

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
#define BACKLIGHT_LEVELS 3
#define RGBLIGHT_LAYERS

#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

#endif

#ifdef OLED_ENABLE
#define OLED_DISPLAY_64X128 
#define OLED_IC OLED_IC_SH1107
#define OLED_COLUMN_OFFSET 32
#define OLED_FONT_H "keyboards/sofle/keymaps/climent/glcdfont.c"
#define OLED_FONT_WIDTH 8
#define OLED_FONT_START 0x80
#define OLED_FONT_END 0xbf
#endif

#endif
