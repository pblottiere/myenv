#include QMK_KEYBOARD_H
#include <print.h>

// layers
#define BLUE MO(_BLUE)

// mod tap
#define M_TAB MT(MOD_LSFT, KC_TAB)

// debug parameters
void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  // debug_mouse=true;
}

// custom keycodes and layers
enum custom_keycodes {
    M_GUI = SAFE_RANGE,
    M_BSDEL, // backspace or del
    M_STAR, // * or !
    ALT_MINS,
    ALT_EQL,
    ALT_4,
    ALT_5,
    M_0 = SAFE_RANGE + KC_0,
    M_1 = SAFE_RANGE + KC_1,
    M_2 = SAFE_RANGE + KC_2,
    M_3 = SAFE_RANGE + KC_3,
    M_4 = SAFE_RANGE + KC_4,
    M_5 = SAFE_RANGE + KC_5,
    M_6 = SAFE_RANGE + KC_6,
    M_7 = SAFE_RANGE + KC_7,
    M_8 = SAFE_RANGE + KC_8,
    M_9 = SAFE_RANGE + KC_9,
};

enum layers {
    _RED,
    _BLUE,
};

// switch/case on keyboard events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    case M_0:
    case M_1:
    case M_2:
    case M_3:
    case M_4:
    case M_5:
    case M_6:
    case M_7:
    case M_8:
    case M_9:
    {
      const uint8_t kc = keycode - SAFE_RANGE;
      if(record->event.pressed){
        register_mods(MOD_LSFT);
        register_code(kc);
      } else {
        unregister_mods(MOD_LSFT);
        unregister_code(kc);
      }
      return false;
    }
    // switch to BLUE layer for numeric keys and set GUI modifier
    // useful for switching i3 tabs
    case M_GUI:
    {
      print("M_GUI\n");
      if(record->event.pressed){
        layer_on(_BLUE);
        register_mods(MOD_LGUI);
      } else {
        layer_off(_BLUE);
        unregister_mods(MOD_LGUI);
      }
      return false;
    }
    // ]
    case ALT_MINS:
    {
      print("ALT_MINS\n");
      uint8_t kc = KC_MINS;
      if(record->event.pressed){
        register_code(KC_RALT);
        register_code(kc);
      } else {
        unregister_code(KC_RALT);
        unregister_code(kc);
      }
      return false;
    }
    // }
    case ALT_EQL:
    {
      print("ALT_EQL\n");
      uint8_t kc = KC_EQL;
      if(record->event.pressed){
        register_code(KC_RALT);
        register_code(kc);
      } else {
        unregister_code(KC_RALT);
        unregister_code(kc);
      }
      return false;
    }
    // [
    case ALT_5:
    {
      print("ALT_5\n");
      uint8_t kc = KC_5;
      if(record->event.pressed){
        register_code(KC_RALT);
        register_code(kc);
      } else {
        unregister_code(KC_RALT);
        unregister_code(kc);
      }
      return false;
    }
    // {
    case ALT_4:
    {
      print("ALT_4\n");
      uint8_t kc = KC_4;
      if(record->event.pressed){
        register_code(KC_RALT);
        register_code(kc);
      } else {
        unregister_code(KC_RALT);
        unregister_code(kc);
      }
      return false;
    }
    // BACKSPACE or DEL with SHIFT modifier
    case M_BSDEL:
    {
      print("M_BSDEL\n");
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
    // * or ! with shift modifier
    case M_STAR:
    {
      print("M_STAR\n");
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
    default:
    {
      print("default\n");
      return true;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Red
 * ,----------------------------------------------------------------------------------------------.
 * | Esc/F5/Caps|   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp/Del |
 * |------------+------+------+------+------+-------------+------+------+------+------+----------|
 * | <  >       |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter     |
 * |------------+------+------+------+------+------|------+------+------+------+------+----------|
 * | Tab/Shift  |   W  |   X  |   C  |   V  |   B  |   N  | - _  | . ;  | / :  |  * $ | Tab/Shift|
 * |------------+------+------+------+------+------+------+------+------+------+------+----------|
 * | Ctrl       | GUI2 | GUI  | Blue |           Space           | Left | Down |  Up  |Right     |
 * `---------------------------------------------------------------------------------------------'
 */
  [_RED] = LAYOUT_ortho_4x12(
    KC_CAPS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BSDEL,
    KC_NUBS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    M_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  M_STAR,  M_TAB,
    KC_LCTL,  M_GUI,   KC_LGUI, BLUE,    KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

/* Blue
 * ,-----------------------------------------------------------------------------------.
 * |   °  |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   @  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   +  |   =  |   ~  |   #  |   ?  |   !  |  {   |    } |   [  |   ]  |   (  |   )  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ¨  |   é  |   è  |   à  |   ç  |   ù  |   ^  |   ,  |   "  |  '   |  `   |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |PgDown| PgUp |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_BLUE] = LAYOUT_ortho_4x12(
  KC_NO,   M_0,     M_1,     M_2,     M_3,     M_4,     M_5,     M_6,     M_7,     M_8,     M_9,     KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   ALT_4,   ALT_EQL, ALT_5,   ALT_MINS,KC_5,    KC_MINS,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};
