/*
Copyright 2021 heyzeus <climent@gmail.com>
Copyright 2018 dek <dek@yolops.net>

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

#ifndef CONFIG_H
#define CONFIG_H


/* key matrix size */
//#define MATRIX_ROWS 10
//#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
//#define MATRIX_ROW_PINS { F6, F7, B1, B3, D7, E6, B4, B5, B2, B6 }
//#define MATRIX_ROW_PINS { D7, E6, B4, B5, F6, F7, B1, B3, B6, B2 }
//#define MATRIX_COL_PINS { C6, D4, D0, D1, D2, D3 }

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
//#define DIODE_DIRECTION COL2ROW
 
// #define BACKLIGHT_PIN B7
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_LEVELS 3


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */


#endif
