#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │
     * └───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x5(
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E
    )
};
