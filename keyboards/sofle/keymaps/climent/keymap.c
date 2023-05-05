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
    _COLEMAK,
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
    KC_COLEMAK,
    KC_RAISE,
    KC_ADJUST,
    KC_SYM,
    KC_D_MUTE,
    KC_NAV,
    KC_VIMZ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_SYM,KC_QUOT),
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, C(KC_LALT),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	 KC_NAV, KC_LOWER, KC_LALT ,KC_LGUI, KC_ENT,                           KC_SPC,KC_RAISE,KC_NAV, KC_NUM, KC_RCTL
),

[_COLEMAK] = LAYOUT( \
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
     KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
     KC_LCTL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    LT(_SYM,KC_QUOT),
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, C(KC_LALT),  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	 KC_NAV, KC_LOWER, KC_LALT ,KC_LGUI, KC_ENT,                           KC_SPC,KC_RAISE,KC_NAV, KC_NUM, KC_RCTL
),
[_RAISE] = LAYOUT(\
  _______, _______, _______, _______, _______, _______,                    KC_HOME, KC_END , _______, KC_LCBR, KC_RCBR, KC_TILD, \
  _______, _______, _______, _______, KC_HOME, KC_END ,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
  _______, _______, _______, _______, _______, _______,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
  _______, KC_VIMZ, _______, _______, _______, _______, KC_MPLY, _______ , KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                    _______, _______, _______, _______, KC_SPC , _______ , _______, KC_RGUI, KC_RALT, _______ \
),

[_LOWER] = LAYOUT( \
  KC_GRV ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  ,      KC_F8,   KC_F9,      KC_F10 , _______,
  _______,    KC_F11 , KC_F12 , _______, TG(_RAISE), AG_TOGG,                      _______, KC_VOLD,      KC_MUTE, KC_VOLU,    _______, KC_DEL ,
  G(C(KC_Q)), _______, _______, _______, DF(_QWERTY), DF(_COLEMAK),                _______, C(KC_LEFT),   _______, C(KC_RGHT), _______, _______,
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
  KC_BSPC , XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, KC_PGUP,                      XXXXXXX, KC_VOLD,      KC_MUTE, KC_VOLU,    XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                      XXXXXXX, C(KC_LEFT),   XXXXXXX, C(KC_RGHT), XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, C(KC_LEFT), C(KC_RGHT), XXXXXXX,  XXXXXXX,   XXXXXXX, C(S(KC_TAB)), G(KC_R), C(KC_TAB),  XXXXXXX, _______,
                       XXXXXXX, KC_BTN1, KC_BTN2, KC_LGUI, KC_SPC,   G(KC_SPC), KC_RAISE, KC_ENT,       XXXXXXX, XXXXXXX
),
 
[_SYM] = LAYOUT(
  _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, _______,
  KC_LCTL, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   XXXXXXX, XXXXXXX,
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
    ED_F1,
    ED_F2,
    ED_F3,
    ED_F4,
    ED_F5,
    ED_F6,
    ED_F7,
    ED_F8,
    ED_F9,
    ED_F10,
    ED_F11,
    ED_F12,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM caps_lock[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM c_a_lock_r[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_a_lock_l[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_ESC, KC_GRV, COMBO_END};

const uint16_t PROGMEM combo_f1[] = {KC_1, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_f2[] = {KC_2, KC_W, COMBO_END};
const uint16_t PROGMEM combo_f3[] = {KC_3, KC_E, COMBO_END};
const uint16_t PROGMEM combo_f4[] = {KC_4, KC_R, COMBO_END};
const uint16_t PROGMEM combo_f5[] = {KC_5, KC_T, COMBO_END};
const uint16_t PROGMEM combo_f6[] = {KC_6, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_f7[] = {KC_7, KC_U, COMBO_END};
const uint16_t PROGMEM combo_f8[] = {KC_8, KC_I, COMBO_END};
const uint16_t PROGMEM combo_f9[] = {KC_9, KC_O, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_0, KC_P, COMBO_END};
const uint16_t PROGMEM combo_f11[] = {KC_1, KC_A, COMBO_END};
const uint16_t PROGMEM combo_f12[] = {KC_2, KC_S, COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_lock, KC_CAPS),
    COMBO(c_a_lock_r, C(KC_LALT)),
    COMBO(c_a_lock_l, C(KC_LALT)),
    COMBO_ACTION(email_combo),
    [ED_F1] = COMBO(combo_f1, KC_F1),
    [ED_F2] = COMBO(combo_f2, KC_F2),
    [ED_F3] = COMBO(combo_f3, KC_F3),
    [ED_F4] = COMBO(combo_f4, KC_F4),
    [ED_F5] = COMBO(combo_f5, KC_F5),
    [ED_F6] = COMBO(combo_f6, KC_F6),
    [ED_F7] = COMBO(combo_f7, KC_F7),
    [ED_F8] = COMBO(combo_f8, KC_F8),
    [ED_F9] = COMBO(combo_f9, KC_F9),
    [ED_F10] = COMBO(combo_f10, KC_F10),
    [ED_F11] = COMBO(combo_f11, KC_F11),
    [ED_F12] = COMBO(combo_f12, KC_F12),
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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static bool caps_lock_on = false;
static bool num_lock_on = false;

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

    static const char PROGMEM capslock_enabled_numlock_enabled[] = {
        0xb0, 0xb1, 0xb8, 0xb9,
        0xb2, 0xb3, 0xba, 0xbb,
        0x00,
    };

    static const char PROGMEM capslock_disabled_numlock_disabled[] = {
        0xb4, 0xb5, 0xbc, 0xbd,
        0xb6, 0xb7, 0xbe, 0xbf,
        0x00,
    };
    static const char PROGMEM capslock_disabled_numlock_enabled[] = {
        0xb4, 0xb5, 0xb8, 0xb9,
        0xb6, 0xb7, 0xba, 0xbb,
        0x00,
    };

    static const char PROGMEM capslock_enabled_numlock_disabled[] = {
        0xb0, 0xb1, 0xbc, 0xbd,
        0xb2, 0xb3, 0xbe, 0xbf,
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
    if (caps_lock_on) {
	if (num_lock_on) {
            oled_write_P(capslock_enabled_numlock_enabled, false);
	} else {
	    oled_write_P(capslock_enabled_numlock_disabled, false);
	}
    } else {
	if (num_lock_on) {
            oled_write_P(capslock_disabled_numlock_enabled, false);
	} else {
	    oled_write_P(capslock_disabled_numlock_disabled, false);
	}
    }
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    num_lock_on = led_state.num_lock;
    return true;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
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
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
            if ((get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL))) == (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL))) {
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

#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [3] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [4] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [5] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [6] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [7] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [8] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)}
};
#endif
