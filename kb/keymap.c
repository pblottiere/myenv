#include QMK_KEYBOARD_H

#define BLUE   MO(_BLUE)

enum custom_keycodes {
    M_GUI,
    M_ALGR,
    M_SHIFT,
};

enum layers {
    _MAIN,
    _BLUE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    case M_GUI:
      if(record->event.pressed){
        layer_on(_BLUE);
        register_mods(MOD_LGUI);
      } else {
        layer_off(_BLUE);
        unregister_mods(MOD_LGUI);
      }
    case M_ALGR:
      if(record->event.pressed){
        layer_on(_BLUE);
        register_mods(MOD_RGUI);
      } else {
        layer_off(_BLUE);
        unregister_mods(MOD_RGUI);
      }
    case M_SHIFT:
      if(record->event.pressed){
        layer_on(_BLUE);
        register_mods(MOD_LSFT);
      } else {
        layer_off(_BLUE);
        unregister_mods(MOD_LSFT);
      }
      return false;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NUBS,
    KC_LCTL, M_GUI,   KC_LGUI, BLUE,    M_SHIFT, KC_SPC,  KC_SPC,  M_ALGR,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [_BLUE] = LAYOUT_ortho_4x12(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_NO,   KC_NO,   KC_GRV,  KC_BSLS, KC_EQL,  KC_MINS, KC_QUOT, KC_SLSH, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
  KC_LSFT, KC_NUBS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_RALT, _______, _______, _______, _______
  )
};
