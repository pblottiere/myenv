#include QMK_KEYBOARD_H

#define BLUE MO(_BLUE)
#define MT_TAB MT(MOD_LSFT, KC_TAB)

enum custom_keycodes {
    M_GUI,
    _GREEN,
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
    case _GREEN:
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
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Red
 * ,-----------------------------------------------------------------------------------------.
 * | Esc        |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab/shift  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
 * |------------+------+------+------+------+------|------+------+------+------+------+------|
 * | <>         |   W  |   X  |   C  |   V  |   B  |   N  | , ?  | ; .  | : /  |   !  |      |
 * |------------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl       | GUI2 | GUI  | Blue |Green |    Space    |Black | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------------'
 */
  [_RED] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_LCTL, M_GUI,   KC_LGUI, BLUE,    _GREEN,  KC_SPC,  KC_SPC,  KC_ALGR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

/* Blue
 * ,-----------------------------------------------------------------------------------.
 * | &    |   é  |   "  |   '  |   (  |   -  |   è  |   _  |   ç  |   à  |   )  | =    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  $   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  *   |
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
