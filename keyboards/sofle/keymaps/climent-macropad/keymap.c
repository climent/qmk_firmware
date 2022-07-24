 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H
#include "report.h"
#include "transactions.h"
#include "timer.h"
#include <string.h>
#include "lib/lib8tion/lib8tion.h"


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _SYM,
    _NAV,
    _LAYER1,
    _LAYER2
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_SYM,
    KC_D_MUTE,
    KC_NAV,
    KC_VIMZ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_SYM,KC_QUOT),
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	 KC_NAV, KC_LOWER, KC_LALT ,KC_LGUI, KC_ENT,                       KC_SPC,KC_RAISE,KC_NAV, XXXXXXX, KC_RCTRL
),

[_RAISE] = LAYOUT(\
  _______, _______, _______, _______, _______, _______,                    KC_HOME, KC_END , _______, KC_LCBR, KC_RCBR, KC_TILD, \
  _______, _______, _______, _______, KC_HOME, KC_END ,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
  _______, _______, _______, _______, KC_NAV , _______,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
  _______, KC_VIMZ, _______, _______, _______,_______,KC_MPLY,   _______ , KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                    _______, _______, _______, _______, KC_SPC , _______ , _______, KC_RGUI, KC_RALT, _______ \
),

[_LOWER] = LAYOUT( \
  KC_GRV ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  ,      KC_F8,   KC_F9,      KC_F10 , _______,
  _______,    KC_VOLU, _______, _______, TG(_RAISE), AG_TOGG,                      _______, KC_VOLD,      KC_MUTE, KC_VOLU,    _______, KC_DEL ,
  G(C(KC_Q)), KC_VOLD, _______, _______, _______, _______,                         _______, C(KC_LEFT),   _______, C(KC_RGHT), _______, _______,
  _______,    KC_CAPS, _______, _______, C(KC_LEFT), C(KC_RGHT), _______, _______, _______, C(S(KC_TAB)), G(KC_R), C(KC_TAB),  _______, _______,
                    _______, _______, _______, _______, KC_SPC ,          _______, _______, _______, _______, _______ \
),

[_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_NAV] = LAYOUT( 
  KC_TILD , C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),                      C(KC_6), C(KC_7),      C(KC_8), C(KC_9),    C(KC_0), KC_TILD,
  KC_BSPC , C(KC_6), C(KC_7), C(KC_8), C(KC_9), C(KC_0),                      XXXXXXX, KC_VOLD,      KC_MUTE, KC_VOLU,    XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX,                      XXXXXXX, C(KC_LEFT),   XXXXXXX, C(KC_RGHT), XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, C(KC_LEFT), C(KC_RGHT), XXXXXXX,  XXXXXXX,   XXXXXXX, C(S(KC_TAB)), G(KC_R), C(KC_TAB),  XXXXXXX, _______,
                       XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, KC_SPC,   G(KC_SPC), XXXXXXX, KC_ENT,       XXXXXXX, XXXXXXX
),
 
[_SYM] = LAYOUT(
  _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, _______,
  KC_LCTRL,XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, _______,
                    KC_LOWER, XXXXXXX, KC_LALT, KC_LGUI, XXXXXXX,  KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX
),

[_LAYER1] = LAYOUT( \
  KC_GRV ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
  _______,    KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL ,
  KC_CAPS,    _______, _______, _______, _______, _______,                   _______, KC_HOME, _______, KC_END , _______, KC_ENT ,
  _______,    _______, _______, _______, _______, _______, _______, _______, _______, C(S(KC_TAB)), G(KC_R) , C(KC_TAB), _______, _______,
                    _______, _______, _______, _______, KC_SPC ,       _______, _______, TG(_LAYER2), _______, _______ \
),

[_LAYER2] = LAYOUT( 
  XXXXXXX , C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),                     C(KC_6), C(KC_7), C(KC_8), C(KC_9), C(KC_0), XXXXXXX,
  XXXXXXX , C(KC_6), C(KC_7), C(KC_8), C(KC_9), C(KC_0),                     C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5), XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, C(KC_LEFT),   XXXXXXX,C(KC_RGHT), XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, C(S(KC_TAB)), XXXXXXX, C(KC_TAB), XXXXXXX, XXXXXXX,
                   XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

#ifdef COMBO_ENABLE

enum combo_events {
    CAPS_LOCK,
    C_A_LOCK_L,
    C_A_LOCK_R,
    EM_EMAIL,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM caps_lock[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM c_a_lock_r[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_a_lock_l[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_ESC, KC_GRV, COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_lock, KC_CAPS),
    COMBO(c_a_lock_r, C(KC_LALT)),
    COMBO(c_a_lock_l, C(KC_LALT)),
    COMBO_ACTION(email_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EM_EMAIL:
      if (pressed) {
        SEND_STRING("climent@gmail.com");
      }
      break;
  }
}

#endif

#ifdef TAPPING_TERM_PER_KEY

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NAV,KC_SCLN):
            return TAPPING_TERM + 1500;
        default:
            return TAPPING_TERM;
    }
}

#endif

#ifdef OLED_ENABLE

/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}
*/

/*
static void print_status_narrow(void) {

    if (keymap_config.swap_lalt_lgui) {
        oled_write_ln_P(PSTR("SWAP"), true);
    } else {
        oled_write_ln_P(PSTR("swap"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navig"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}
*/

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static bool caps_lock_on = false;

static void print_status_narrow(void) {
    static const char PROGMEM hr[] = {
        0x81, 0x81, 0x81, 0x81, 
        0x00,
    };

    static const char PROGMEM logo[] = {
        0x80, 0x84, 0x85, 0x80,
        0x80, 0x86, 0x87, 0x80,
        0x00,
    };

    static const char PROGMEM empty [] = {
        0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80,
        0x00,
    };

    static const char PROGMEM layer0[] = {
        0x90, 0x91, 0x80, 0x80,
        0x92, 0x93, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM layer1[] = {
        0x80, 0x80, 0x94, 0x95, 
        0x80, 0x80, 0x96, 0x97, 
        0x00,
    }; 

    static const char PROGMEM layer01[] = {
        0x90, 0x91, 0x94, 0x95, 
        0x92, 0x93, 0x96, 0x97, 
        0x00,
    }; 

    static const char PROGMEM layer2[] = {
        0x98, 0x99, 0x80, 0x80,
        0x9a, 0x9b, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM layer3[] = {
        0x80, 0x80, 0x9c, 0x9d, 
        0x80, 0x80, 0x9e, 0x9f, 
        0x00,
    }; 

    static const char PROGMEM layer23[] = {
        0x98, 0x99, 0x9c, 0x9d, 
        0x9a, 0x9b, 0x9e, 0x9f, 
        0x00,
    }; 

    static const char PROGMEM mod0[] = {
        0xa0, 0xa1, 0x80, 0x80,
        0xa2, 0xa3, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM mod1[] = {
        0x80, 0x80, 0xa4, 0xa5, 
        0x80, 0x80, 0xa6, 0xa7, 
        0x00,
    }; 

    static const char PROGMEM mod01[] = {
        0xa0, 0xa1, 0xa4, 0xa5, 
        0xa2, 0xa3, 0xa6, 0xa7, 
        0x00,
    }; 

    static const char PROGMEM mod2[] = {
        0xa8, 0xa9, 0x80, 0x80,
        0xaa, 0xab, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM mod3[] = {
        0x80, 0x80, 0xac, 0xad, 
        0x80, 0x80, 0xae, 0xaf, 
        0x00,
    }; 

    static const char PROGMEM mod23[] = {
        0xa8, 0xa9, 0xac, 0xad, 
        0xaa, 0xab, 0xae, 0xaf, 
        0x00,
    }; 

    static const char PROGMEM capslock_enabled[] = {
        0x80, 0xb0, 0xb1, 0x80,
        0x80, 0xb2, 0xb3, 0x80,
        0x00,
    };

    static const char PROGMEM capslock_disabled[] = {
        0x80, 0xb4, 0xb5, 0x80,
        0x80, 0xb6, 0xb7, 0x80,
        0x00,
    };

    oled_write_P(logo, false);
    oled_write_P(hr, false);

    bool layer0_on = IS_LAYER_ON(_QWERTY);
    bool layer1_on = IS_LAYER_ON(_RAISE);
    bool layer2_on = IS_LAYER_ON(_LOWER);
    bool layer3_on = IS_LAYER_ON(_NAV);

    // we are not doing one shot mods here
    static uint8_t mods;
    mods = get_mods();
    bool mod0_on = mods & MOD_MASK_CTRL;
    bool mod1_on = mods & MOD_MASK_SHIFT;
    bool mod2_on = mods & MOD_MASK_ALT;
    bool mod3_on = mods & MOD_MASK_GUI;

    if (layer0_on) {
        oled_write_P(layer1_on ? layer01 : layer0, false);
    } else {
        oled_write_P(layer1_on ? layer1 : empty, false);
    }

    if (layer2_on) {
        oled_write_P(layer3_on ? layer23 : layer2, false);
    } else {
        oled_write_P(layer3_on ? layer3 : empty, false);
    }

    oled_write_P(hr, false);

    if (mod0_on) {
        oled_write_P(mod1_on ? mod01 : mod0, false);
    } else {
        oled_write_P(mod1_on ? mod1 : empty, false);
    }

    if (mod2_on) {
        oled_write_P(mod3_on ? mod23 : mod2, false);
    } else {
        oled_write_P(mod3_on ? mod3 : empty, false);
    }

    oled_write_P(hr, false);
    oled_write_P(caps_lock_on ? capslock_enabled : capslock_disabled, false);

    //return true;
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    return true;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
//    } else {
//        render_logo();
    }
    return false;
}

#endif

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case LT(_SYM,KC_QUOT):
          // Intercept hold action when shift is held.
          if ((get_mods() & MOD_MASK_SHIFT) != 0 &&
              !record->tap.count) {
	     if (record->event.pressed) {
                tap_code(KC_QUOT);  // Type Shift + quote.
	     }
             return false;  // Skip default handling.
          }
          break;  // Otherwise continue with default handling.
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                update_tri_layer(_NAV, _RAISE, _NAV);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                update_tri_layer(_NAV, _RAISE, _NAV);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
      case KC_ESC:
        if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI)) {
	  if ((get_mods() & MOD_BIT(KC_LALT)) != MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
              register_code(KC_GRV);
            } else {
              unregister_code(KC_GRV);
            }
            return false;
          }
	}
        return true;
        break;

      case KC_VIMZ:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_ESC)":w"SS_TAP(X_ENT));
            SEND_STRING(SS_LCTL("z"));
          }
        break;

      case KC_TAB:
        {
          static bool tab_key_registered;
          if (record->event.pressed) {
            if ((get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTRL))) == (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTRL))) {
              del_mods(MOD_MASK_GUI);
              add_mods(MOD_MASK_SHIFT);
              register_code(KC_TAB);
              tab_key_registered = true;
              set_mods(mod_state);
              return false;
            }
          } else {
            if (tab_key_registered) {
              unregister_code(KC_TAB);
              tab_key_registered = false;
              return false;
            }
            return true;
          }
        }

    }

    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
      } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
      }
    }
    if (index == 1) {
      if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
      } else if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
      } else {
        if (clockwise) {
            //tap_code(KC_VOLD);
            tap_code(KC_WH_D);
            tap_code(KC_WH_D);
        } else {
            //tap_code(KC_VOLU);
            tap_code(KC_WH_U);
            tap_code(KC_WH_U);
        }
      }
    }
    return true;
}

#endif

#ifdef POINTING_DEVICE_ENABLE

// Code to change scrolling_mode when the layer changes, and when RAISE is the highest layer
static bool scrolling_mode = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:  // If we're on the _RAISE layer enable scrolling mode
            scrolling_mode = true;
            pointing_device_set_cpi(1500);
            break;
        default:
            if (scrolling_mode) {  // check if we were scrolling before and set disable if so
                scrolling_mode = false;
                pointing_device_set_cpi(18000);
            }
            break;
    }
    return state;
}

// When scrolling_mode is active, stop updating .x and .y, and update .h and .v (horizontal and vertical scrolling)
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = - mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

/*
void housekeeping_task_user(void) {
    if (!is_keyboard_left()) {
      if (!IS_LAYER_ON(_NAV)) {
        if (IS_LAYER_ON(_RAISE) || IS_LAYER_ON(_LOWER)) {
	  if (IS_LAYER_ON(_RAISE) && !IS_LAYER_ON(_LOWER)) {
            pimoroni_trackball_set_rgbw(0,153,95,0);
          }
          if (IS_LAYER_ON(_LOWER) && !IS_LAYER_ON(_RAISE)) {
            pimoroni_trackball_set_rgbw(153,113,0,0);
          }
	  if (IS_LAYER_ON(_RAISE) && IS_LAYER_ON(_LOWER)) {
            pimoroni_trackball_set_rgbw(153,0,110,0);
          }
        } else {
          pimoroni_trackball_set_rgbw(0,0,0,100);
        }
      } else {
        pimoroni_trackball_set_rgbw(0,0,100,0);
      }
    }
}
*/
//void keyboard_post_init_user(void) {
//    if (!is_keyboard_left()) {
//            pimoroni_trackball_set_rgbw(0,0,95,0);
//    }
//}

#endif
