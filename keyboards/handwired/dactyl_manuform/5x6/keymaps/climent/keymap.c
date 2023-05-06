#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _SYM 4

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
};

// The layout of the soldered switches is different from the standard 5x6, so we redefine the pin matrix here.
#undef LAYOUT_5x6
#define LAYOUT_5x6( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
                   L43, L44, L45,                          R40, R41, R42,                \
                        L54, L55,                          R50, R51                      \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { XXX, XXX, XXX, L43, L44, L45 }, \
    { XXX, XXX, XXX, XXX, L54, L55 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { R40, R41, R42, XXX, XXX, XXX }, \
    { R50, R51, XXX, XXX, XXX, XXX } \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_GRV ,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , KC_BSPC,
        KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  , KC_SCLN,LT(_SYM, KC_QUOT),
	KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  , KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
//                                 KC_LALT,KC_LGUI,KC_ENT,                         KC_ENT, KC_SPC, RAISE,                        
                                 KC_LALT,KC_LGUI,KC_ENT,                         KC_SPC, RAISE , KC_ENT,
                                         LOWER , KC_SPC,                         LOWER,  KC_RCTL
    ),

[_RAISE] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,                    KC_HOME, KC_END , _______, KC_LCBR, KC_RCBR, KC_TILD, \
    _______, _______, _______, _______, KC_HOME, KC_END ,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
    _______, _______, C(S(KC_TAB)), _______, C(KC_TAB), _______,             KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
    _______, _______, _______, _______, _______, _______,                    KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                                        _______,  _______,KC_SPC,            KC_RGUI ,KC_RALT, _______,
                                                  _______,_______,            KC_RGUI ,KC_RALT
    ),

[_LOWER] = LAYOUT_5x6(
  KC_GRV ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
  _______,    KC_VOLU, _______, _______, TG(_RAISE), KC_PGUP,                      _______, KC_VOLD,      KC_MUTE, KC_VOLU,    _______, KC_DEL ,
  G(C(KC_Q)), KC_VOLD, _______, _______, _______, KC_PGDN,                         _______, C(KC_LEFT),   _______, C(KC_RGHT), _______, _______,
  _______,    KC_CAPS, _______, _______, C(KC_LEFT), C(KC_RGHT),                   _______, C(S(KC_TAB)), G(KC_R), C(KC_TAB),  _______, _______,
                                        _______,  _______,_______,            KC_RGUI ,_______, KC_RALT,
                                                _______,_______,            _______,_______
    ),

[_ADJUST] = LAYOUT_5x6( \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, RGB_VAD, RGB_TOG, RGB_VAI, AG_TOGG,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, RGB_MOD, XXXXXXX, RGB_RMOD, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, RGB_HUI, XXXXXXX, RGB_HUD, XXXXXXX,                     XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                                        _______,  _______,_______,            KC_RGUI ,KC_RALT, _______,
                                                  _______,_______,            _______,_______
),
[_SYM] = LAYOUT_5x6(
  _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, _______,
  KC_LCTL, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, _______,
                                 KC_LALT,KC_LGUI,KC_ENT,                         KC_ENT, KC_SPC, RAISE,                        
                                         LOWER , KC_SPC,                         LOWER,  KC_RCTL
)

};


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
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

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

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {21, 10, HSV_RED},
    {52, 10, HSV_RED}    // Light 10 LEDs, starting with LED 21
);
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN},
    {31,3, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_ORANGE},
    {31,3, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED},
    {31,3, HSV_RED}
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

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}

#endif
