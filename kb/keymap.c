#include QMK_KEYBOARD_H

#define LOWER   MO(_LOWER)

enum custom_keycodes {
    M_GUI,
};

enum layers {
    _MAIN,
    _LOWER,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    case M_GUI:
      if(record->event.pressed){
        layer_on(_LOWER);
        register_mods(MOD_LGUI);
      } else {
        layer_off(_LOWER);
        unregister_mods(MOD_LGUI);
      }
      return false;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_DEL,  KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_PGUP, KC_UP,   KC_PGDOWN,
    KC_LCTL, M_GUI,   KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_DOT,  KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_LOWER] = LAYOUT_ortho_4x12(
  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
  KC_NO,   KC_NO,   KC_GRV,  KC_BSLS, KC_EQL,  KC_MINS, KC_QUOT, KC_SLSH, KC_SCLN, KC_LBRC, KC_RBRC, KC_NO,
  KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______, _______, _______, _______
  )
};
