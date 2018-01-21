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
	lyr_arrow,
	lyr_fn,
	lyr_mouse,
	lyr_COUNT
};
enum { // custom keycodes
	CKC_MOUSE_ON = SAFE_RANGE,
	CKC_MOUSE_OFF
};

#define shrt_cut    LCTL(KC_X)
#define shrt_copy   LCTL(KC_C)
#define shrt_paste  LCTL(KC_V)
#define shrt_save   LCTL(KC_S)
#define shrt_undo   LCTL(KC_Z)
#define shrt_find   LCTL(KC_F)
#define shrt_selAll LCTL(KC_A)

#define KC_lClick KC_BTN1
#define KC_mClick KC_BTN3
#define KC_rClick KC_BTN2




const uint16_t PROGMEM keymaps[lyr_COUNT][MATRIX_ROWS][MATRIX_COLS] = {
	[lyr_base] = {
	  {KC_ESC,        KC_G,          KC_T,         KC_H,            KC_W,            KC_Z,    KC_X,    KC_Y,        KC_O,      KC_U,      KC_J,    KC_BSPC},
	  {KC_TAB,        KC_D,          KC_L,         KC_R,            KC_S,            KC_P,    KC_K,    KC_E,        KC_A,      KC_I,      KC_N,    KC_ENT},
	  {MO(lyr_fn),    KC_C,          KC_M,         KC_V,            KC_F,            KC_V,    KC_J,    KC_QUOT,     KC_COMM,   KC_COMM,   KC_SLSH, MO(lyr_arrow)},
	  {TG(lyr_mouse), KC_LGUI,       KC_LALT,      KC_LCTL,         KC_LSFT,         KC_SPC,  KC_SPC,  MO(lyr_num), KC_RCTL,   KC_RALT,   KC_VOLD, KC_VOLU}
	},
	[lyr_num] = {
	  {KC_GRV,        KC_BSLASH,     KC_LCBR,      KC_RCBR,         KC_AMPR,         KC_PIPE, KC_CIRC, KC_7,        KC_8,      KC_9,      KC_PLUS, KC_DLR},
	  {KC_TILD,       KC_SCOLON,     KC_LPRN,      KC_RPRN,         KC_EXLM,         KC_AT,   KC_EQL,  KC_4,        KC_5,      KC_6,      KC_MINS, KC_PERC},
		{XXXXXX,        KC_COLN,       KC_LBRC,      KC_RBRC,         KC_UNDS,         KC_HASH, KC_0,    KC_1,        KC_2,      KC_3,      KC_ASTR, KC_CAPS},
	  {XXXXXX,        KC_LGUI,       KC_LALT,      KC_LCTL,         XXXXXX,          KC_SPC,  KC_SPC,  ______,      KC_RCTL,   KC_RALT,   KC_VOLD, KC_VOLU}
	},
	[lyr_arrow] = {
	  {XXXXXX,        XXXXXX,        DYN_REC_START1, DYN_REC_START2, XXXXXX,         XXXXXX,  XXXXXX,  XXXXXX,      XXXXXX,      KC_DEL,    XXXXXX,  XXXXXX},
	  {XXXXXX,        KC_LGUI,       KC_LALT,      KC_LCTL,          XXXXXX,         XXXXXX,  XXXXXX,  KC_PGUP,     KC_HOME,     KC_UP,     KC_END,  XXXXXX},
		{XXXXXX,        XXXXXX,        DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, DYN_REC_STOP, XXXXXX,  XXXXXX,  KC_PGDN,     KC_LEFT,     KC_DOWN,   KC_RGHT, ______},
		{XXXXXX,        KC_LGUI,       KC_LALT,      KC_LCTL,         KC_LSFT,         KC_SPC,  KC_SPC,  XXXXXX,      KC_PSCR,     XXXXXX,    XXXXXX,  XXXXXX}
	},
	[lyr_fn] = {
	  {XXXXXX,        XXXXXX,        XXXXXX,       XXXXXX,          XXXXXX,          XXXXXX,  XXXXXX,  KC_F9,       KC_F10,    KC_F11,    KC_F12,  XXXXXX},
	  {XXXXXX,        shrt_undo,     shrt_save,    shrt_find,       KC_WH_U,         XXXXXX,  XXXXXX,  KC_F5,       KC_F6,     KC_F7,     KC_F8,   XXXXXX},
		{______,        shrt_cut,      shrt_copy,    shrt_paste,      KC_WH_D,         XXXXXX,  XXXXXX,  KC_F1,       KC_F2,     KC_F3,     KC_F4,   XXXXXX},
	  {XXXXXX,        KC_LGUI,       KC_LALT,      KC_LCTL,         KC_LSFT,         KC_SPC,  KC_SPC,  XXXXXX,      XXXXXX,    XXXXXX,    XXXXXX,  XXXXXX}
	},
	[lyr_mouse] = {
	  {KC_ESC,        XXXXXX,        XXXXXX,       KC_MS_U,         XXXXXX,          XXXXXX,  XXXXXX,  XXXXXX,      KC_WH_U,   XXXXXX,    KC_DEL,  KC_BSPC},
	  {KC_TAB,        XXXXXX,        KC_MS_L,      KC_MS_D,         KC_MS_R,         XXXXXX,  XXXXXX,  KC_WH_L,     KC_WH_D,   KC_WH_R,   XXXXXX,  KC_ENT},
		{XXXXXX,        XXXXXX,        XXXXXX,       XXXXXX,          XXXXXX,          XXXXXX,  XXXXXX,  KC_lClick,   KC_mClick, KC_rClick, XXXXXX,  KC_RSFT},
	  {TG(lyr_mouse), KC_LGUI,       KC_LALT,      KC_LCTL,         KC_LSFT,         KC_ACL0, KC_ACL0, KC_ACL2,     KC_RCTL,   KC_RALT,   KC_VOLD, KC_VOLU}
	}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) return false;
  return true;
}
