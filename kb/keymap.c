#include QMK_KEYBOARD_H
#include <print.h>

#define BLUE MO(_BLUE)
#define M_TAB MT(MOD_LSFT, KC_TAB)

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  // debug_mouse=true;
}

enum custom_keycodes {
    M_GUI,
    M_GREEN,
    M_BSDEL, // backspace or del
    M_STAR, // * or !
};

enum layers {
    _RED,
    _BLUE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    // switch to BLUE layer and set GUI modifier
    case M_GUI:
    {
      if(record->event.pressed){
        layer_on(_BLUE);
        register_mods(MOD_LGUI);
      } else {
        layer_off(_BLUE);
        unregister_mods(MOD_LGUI);
      }
      return false;
    }
    case M_GREEN:
    {
      if(record->event.pressed){
        layer_on(_BLUE);
        register_mods(MOD_LSFT);
      } else {
        layer_off(_BLUE);
        unregister_mods(MOD_LSFT);
      }
      return false;
    }
    // BACKSPACE or DEL with SHIFT modifier
    case M_BSDEL:
    {
      uint8_t temp_mods = get_mods();
      uint8_t kc = KC_BSPC;

      if (keyboard_report->mods & MOD_MASK_SHIFT) {
        clear_mods();
        kc = KC_DEL;
      }

      if (record->event.pressed) {
        register_code(kc);
      }
      else {
        unregister_code(kc);
      }

      unregister_code(KC_DEL);
      set_mods(temp_mods);
      return true;
    }
    case M_STAR:
    {
      uint8_t temp_mods = get_mods();
      uint8_t kc = KC_BSLS;

      if (keyboard_report->mods & MOD_MASK_SHIFT) {
        clear_mods();
        kc = KC_SLSH;
      }

      if (record->event.pressed)
        register_code(kc);
      else
        unregister_code(kc);

      set_mods(temp_mods);
      return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Red
 * ,----------------------------------------------------------------------------------------------.
 * | Caps       |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp/Del |
 * |------------+------+------+------+------+-------------+------+------+------+------+----------|
 * | <  >       |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter     |
 * |------------+------+------+------+------+------|------+------+------+------+------+----------|
 * | Tab/Shift  |   W  |   X  |   C  |   V  |   B  |   N  | , ?  | ; .  | : /  |  * ! | Tab/Shift|
 * |------------+------+------+------+------+------+------+------+------+------+------+----------|
 * | Ctrl       | GUI2 | GUI  | Blue |Green |    Space    |Black | Left | Down |  Up  |Right     |
 * `---------------------------------------------------------------------------------------------'
 */
  [_RED] = LAYOUT_ortho_4x12(
    KC_CAPS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BSDEL,
    KC_NUBS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    M_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  M_STAR,  M_TAB,
    KC_LCTL,  M_GUI,   KC_LGUI, BLUE,    M_GREEN, KC_SPC,  KC_SPC,  KC_ALGR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

/* Blue
 * ,-----------------------------------------------------------------------------------.
 * | &    |   é  |   "  |   '  |   (  |   -  |   è  |   _  |   ç  |   à  |   )  | =    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  $   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | GUI2 | GUI  | Blue |Green |    Space    |Black | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
  [_BLUE] = LAYOUT_ortho_4x12(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RBRC,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_RALT, _______, _______, _______, _______
  )

/* Green -> shifted blue
 * ,-----------------------------------------------------------------------------------.
 * | 1    |  2   | 3    |  4   |  5   |  6   |  7   | 8    |  9   | 0    |  °   |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | GUI2 | GUI  | Blue |Green |    Space    |Black | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
};
