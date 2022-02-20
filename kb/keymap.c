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

// Custom keycodes.
//   - AltGr keycode: SAFE_RANGE + kc + 1000
//   - shifted keycode: SAFE_RANGE + kc
enum custom_keycodes {
    M_BSDEL = SAFE_RANGE, // backspace or del
    M_STAR, // * or !
    ALT_EQL = SAFE_RANGE + KC_EQL + 1000,
    ALT_4 = SAFE_RANGE + KC_4 + 1000,
    ALT_5 = SAFE_RANGE + KC_5 + 1000,
    ALT_MINS = SAFE_RANGE + KC_MINS + 1000,
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

bool switch_key(keyrecord_t *record, uint16_t keycode_1, uint16_t keycode_2, int mask, bool clear)
{
  uint16_t kc = keycode_1;
  uint8_t temp_mods = get_mods();

  if (keyboard_report->mods & mask) {
    kc = keycode_2;
  }

  if (record->event.pressed) {
    if ( clear ) {
      clear_mods();
    }

    register_code(kc);
  }
  else {
    unregister_code(kc);
  }

  if ( clear ) {
    set_mods(temp_mods);
  }

  return false;
}

// switch/case on keyboard events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    // i3 switch tab
    case KC_Q:
    {
      return switch_key(record, keycode, KC_1, MOD_MASK_GUI, false);
    }
    case KC_W:
    {
      return switch_key(record, keycode, KC_2, MOD_MASK_GUI, false);
    }
    case KC_E:
    {
      return switch_key(record, keycode, KC_3, MOD_MASK_GUI, false);
    }
    case KC_R:
    {
      return switch_key(record, keycode, KC_4, MOD_MASK_GUI, false);
    }
    case KC_T:
    {
      return switch_key(record, keycode, KC_5, MOD_MASK_GUI, false);
    }
    case KC_Y:
    {
      return switch_key(record, keycode, KC_6, MOD_MASK_GUI, false);
    }
    case KC_U:
    {
      return switch_key(record, keycode, KC_7, MOD_MASK_GUI, false);
    }
    case KC_I:
    {
      return switch_key(record, keycode, KC_8, MOD_MASK_GUI, false);
    }
    case KC_O:
    {
      return switch_key(record, keycode, KC_9, MOD_MASK_GUI, false);
    }
    // * or $ with shift modifier
    case M_STAR:
    {
      return switch_key(record, KC_BSLS, KC_RBRC, MOD_MASK_SHIFT, true);
    }
    // BACKSPACE or DEL with SHIFT modifier
    case M_BSDEL:
    {
      switch_key(record, KC_BSPC, KC_DEL, MOD_MASK_SHIFT, true);
      unregister_code(KC_DEL);
      return true;
    }
    // numeric values in blue layer
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
      const uint16_t kc = keycode - SAFE_RANGE;
      if(record->event.pressed){
        register_mods(MOD_LSFT);
        register_code(kc);
      } else {
        unregister_mods(MOD_LSFT);
        unregister_code(kc);
      }
      return false;
    }
    // AltGr symbols in blue layer
    case ALT_4:
    case ALT_5:
    case ALT_EQL:
    case ALT_MINS:
    {
      const uint16_t kc = keycode - SAFE_RANGE - 1000;
      if(record->event.pressed){
        register_code(KC_RALT);
        register_code(kc);
      } else {
        unregister_code(KC_RALT);
        unregister_code(kc);
      }
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
 * | Ctrl       | GUI  | BLUE |      |           Space           | Left | Down |  Up  |Right     |
 * `---------------------------------------------------------------------------------------------'
 */
  [_RED] = LAYOUT_ortho_4x12(
    KC_CAPS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BSDEL,
    KC_NUBS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    M_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  M_STAR,  M_TAB,
    KC_LCTL,  KC_LGUI, BLUE,    KC_SPC,    KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SLSH, ALT_4,   ALT_EQL, ALT_5,   ALT_MINS,KC_5,    KC_MINS,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};
