#include "planck.h"

#define ______ KC_TRNS
#define XXXXXX KC_NO

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
	DYNAMIC_MACRO_RANGE
};
#include "dynamic_macro.h"

enum { // layers
	lyr_base,
	lyr_num,
	lyr_fn,
	lyr_COUNT
};

const uint16_t PROGMEM keymaps[lyr_COUNT][MATRIX_ROWS][MATRIX_COLS] = {
	[lyr_base] = {
		{KC_ESC,    KC_W,      KC_T,            KC_H,            KC_G,         KC_Z,    KC_X,    KC_Y,       KC_O,    KC_U,    KC_Q,    KC_BSPC},
		{KC_TAB,    KC_R,      KC_L,            KC_N,            KC_S,         KC_P,    KC_K,    KC_SPC,     KC_A,    KC_I,    KC_E,    KC_ENT},
		{KC_LSFT,   KC_C,      KC_M,            KC_B,            KC_F,         KC_V,    KC_J,    KC_D,       KC_COMM, KC_DOT,  KC_UP,   KC_RSFT},
		{KC_VOLD,   KC_VOLU,   KC_HOME,         KC_END,          MO(lyr_num),  KC_LCTL, KC_LALT, MO(lyr_fn), KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT}
	},
	[lyr_num] = {
		{KC_TILD,   KC_EXLM,   KC_LCBR,         KC_RCBR,         KC_AMPR,      KC_PIPE, KC_ASTR, KC_7,       KC_8,    KC_9,    KC_PLUS, KC_DLR},
		{KC_COLN,   KC_SCOLON, KC_LPRN,         KC_RPRN,         KC_QUOT,      KC_AMPR, KC_SLSH, KC_4,       KC_5,    KC_6,    KC_MINS, KC_PERC},
		{KC_BSLASH, KC_UNDS,   KC_LBRC,         KC_RBRC,         KC_DQT,       KC_HASH, KC_0,    KC_1,       KC_2,    KC_3,    KC_EQL,  KC_CIRC},
		{XXXXXX,    XXXXXX,    KC_GRV,          KC_AT,           ______,       KC_LCTL, KC_LALT, XXXXXX,     KC_LGUI, XXXXXX,  XXXXXX,  XXXXXX}
	},
	[lyr_fn] = {
		{XXXXXX,    XXXXXX,    XXXXXX,          XXXXXX,          KC_PSCR,      XXXXXX,  XXXXXX,  KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_DEL},
		{XXXXXX,    XXXXXX,    DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, XXXXXX,       XXXXXX,  KC_PGUP, KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_CAPS},
		{KC_LSFT,   XXXXXX,    DYN_REC_START1,  DYN_REC_START2,  DYN_REC_STOP, XXXXXX,  KC_PGDN, KC_F9,      KC_F10,  KC_F11,  KC_F12,  KC_RSFT},
		{XXXXXX,    XXXXXX,    XXXXXX,          XXXXXX,          XXXXXX,       KC_LCTL, KC_LALT, ______,     KC_LGUI, XXXXXX,  XXXXXX,  XXXXXX}
	},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) return false;
  return true;
}
