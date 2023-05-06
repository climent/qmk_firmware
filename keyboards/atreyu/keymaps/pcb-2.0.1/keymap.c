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
#include QMK_KEYBOARD_H
#include "atreyu.h"
#include "eeconfig.h"

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _NAV 5
#define _SYM 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  CLMK,
  LWR,
  RSE,
  ADJ,
  NAV,
  SYM
};

#define KC_ KC_TRNS

#define KC_FN FN
#define KC_CLMK CLMK
#define KC_LWR LWR
#define KC_RSE RSE
#define KC_NAV NAV
#define KC_SYM SYM
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_BL_T BL_TOGG
#define KC_LCTL_T LCTL_T
#define KC_GUI_T GUI_T
#define KC_ALT_T ALT_T

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
     KC_ESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                KC_6   , KC_7   , KC_8   , KC_9   , KC_0    ,KC_GRV ,
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    ,KC_BSPC ,
     KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN ,LT(_SYM,KC_QUOT) ,
     KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                KC_N   , KC_M   , KC_COMM, KC_DOT  ,KC_SLSH ,KC_RSFT ,
     NAV,         LWR ,KC_LALT , KC_LGUI,KC_ENT , KC_LBRC ,                KC_RBRC, KC_SPC , RSE, OSL(_NAV) , KC_NO, KC_RCTL 
                
  ),


[_COLEMAK] = LAYOUT( \
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
     KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
     KC_LCTL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    LT(_SYM,KC_QUOT),
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
     NAV,      LWR,     KC_LALT, KC_LGUI, KC_ENT,  KC_LBRC,                    KC_RBRC, KC_SPC,  RSE,     NAV,  KC_NUM,  KC_RCTL
),

[_RAISE] = LAYOUT(\
  _______, _______, _______, _______, _______, _______,                    KC_HOME, KC_END , _______, KC_LCBR, KC_RCBR, KC_TILD, \
  _______, _______, _______, _______, KC_HOME, KC_END ,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
  _______, _______, _______, _______, _______, _______,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
  _______, _______, _______, _______, _______, _______,                    KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
  _______,          _______, _______, _______, KC_SPC , KC_HOME, KC_END  , _______, _______, KC_RGUI, KC_RALT,          _______
),

[_LOWER] = LAYOUT( \
  KC_GRV ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
  _______,    KC_F11 , KC_F12 , _______, TG(_RAISE), AG_TOGG,                      _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_DEL , \
  G(C(KC_Q)), _______, _______, _______, DF(_QWERTY), DF(_COLEMAK),                _______, C(KC_LEFT), _______, C(KC_RGHT), _______, _______, \
  _______,    KC_CAPS, _______, _______, C(KC_LEFT), C(KC_RGHT),                   _______, C(S(KC_TAB)), G(KC_R) , C(KC_TAB), _______, _______, \
  _______,                   _______, _______, _______, KC_SPC , KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______\
),

[_ADJUST] = LAYOUT(\
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, RGB_VAD, RGB_TOG, RGB_VAI, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, RGB_MOD, XXXXXXX, RGB_RMOD, XXXXXXX,                   XXXXXXX, C(S(KC_TAB)), XXXXXXX, C(KC_TAB), XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, RGB_HUI, XXXXXXX, RGB_HUD, XXXXXXX,                    XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  _______,          _______, _______, _______, KC_SPC , KC_HOME, KC_END  , _______, _______, KC_RGUI, KC_RALT, _______\
),

[_NAV] = LAYOUT(
  KC_TILD   , C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),                  C(KC_6),  C(KC_7),      C(KC_8), C(KC_9),    C(KC_0), KC_TILD,
  KC_BSPC   , XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP,                  XXXXXXX,  KC_VOLD,      KC_MUTE, KC_VOLU,    XXXXXXX, XXXXXXX,
  G(C(KC_Q)), XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                  XXXXXXX,  C(KC_LEFT),   XXXXXXX, C(KC_RGHT), XXXXXXX, XXXXXXX,
  XXXXXXX   , XXXXXXX, XXXXXXX, XXXXXXX, C(KC_LEFT), C(KC_RGHT),            XXXXXXX,  C(S(KC_TAB)), G(KC_R), C(KC_TAB),  XXXXXXX, _______,
  XXXXXXX   ,          KC_BTN1, KC_BTN2, KC_LGUI, KC_SPC, XXXXXXX, XXXXXXX, G(KC_SPC),XXXXXXX,      KC_ENT , XXXXXXX,             XXXXXXX
),

[_SYM] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, _______,
  KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, _______,
  XXXXXXX,         XXXXXXX, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

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


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

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
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;

    case LWR:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RSE:
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
      break;

    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;

    case ADJ:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

    case KC_ESC:
     if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI)) {
        if (record->event.pressed) {
          register_code(KC_GRV);
        } else {
          unregister_code(KC_GRV);
        }
        return false;
      }
      return true;
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
      return true;
      break;
}

  return true;
}

void led_set_user(uint8_t usb_led) {

}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [3] = { ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______) },
    [5] = { ENCODER_CCW_CW(_______, _______) },
    [6] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_RED}
);
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_PURPLE},
    {3, 1, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_raise_layer,
    my_lower_layer,
    my_adjust_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

//bool led_update_user(led_t led_state) {
//    rgblight_set_layer_state(0, led_state.caps_lock);
//    return true;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
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
    rgblight_set_layer_state(0, led_state.caps_lock);
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
