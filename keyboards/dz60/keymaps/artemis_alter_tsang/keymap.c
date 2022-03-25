#include QMK_KEYBOARD_H

enum custom_keycodes {
    SIGN = SAFE_RANGE,
};

enum keyboard_layers {
  BASE = 0, // Base Layer
  SHIFT,      // Function Layer
  SUPER      // Super Layer
};

bool process_record_user(unint16_t keycode, keyrecord_t *record);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_60_tsangan(
		KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,         KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		MO(SHIFT),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(SUPER),
		KC_LCTL, XXXXXXX, KC_LALT,                             KC_SPC,                                                KC_RALT, XXXXXXX, KC_RCTL
	),
    [SHIFT] = LAYOUT_60_tsangan(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,         KC_DEL,
		_______,          KC_Q, KC_UP,   KC_ENT, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      RESET,
		_______,          KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_HOME, XXXXXXX,       _______,
		_______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  XXXXXXX,          _______, _______,
		_______, XXXXXXX, _______,                            DM_REC1,                                               _______, XXXXXXX, _______
	),
	[SUPER] = LAYOUT_60_tsangan(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,
		_______,          KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, KC_PMNS, KC_PENT, _______,
		_______,          KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, KC_PSLS,         _______,
		_______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_KP_7,  KC_KP_8, KC_KP_9, KC_P0,          _______, _______,
		_______, XXXXXXX,          _______,                   DM_PLY1,                                     _______,          XXXXXXX, _______
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SIGN:
            if(record->event.pressed) {
                SEND_STRING("Mit freundlichen Grüßen \n");
            } else {

            }
            break;
    }

    return true;
}