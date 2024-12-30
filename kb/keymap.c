#include QMK_KEYBOARD_H
#include <print.h>

// debug parameters
void keyboard_post_init_user(void) {
  debug_enable=false;
  debug_matrix=false;
  debug_keyboard=false;
  debug_mouse=false;
}

enum layers {
    _MAIN,
};

bool switch_key(keyrecord_t *record, uint16_t kc_1, uint16_t kc_2, bool keep_on_sft)
{
  // kc_1
  // kc_1 + ALT : kc_2
  // kc_1 + SHIFT : kc_2 + SHIFT (or kc_1 + SHIFT according to keep_on_sft)
  // kc_1 + GUI : kc_2 + GUI
  uint16_t kc = kc_1;
  uint16_t mod = -1;

  if (keyboard_report->mods & MOD_MASK_SHIFT) {
    if (keep_on_sft)
      kc = kc_1;
    else
      kc = kc_2;
    mod = MOD_LSFT;
  } else if (keyboard_report->mods & MOD_MASK_ALT) {
    kc = kc_2;
    mod = MOD_LALT;
  } else if (keyboard_report->mods & MOD_MASK_GUI) {
    kc = kc_2;
    mod = MOD_LGUI;
  }

  if(record->event.pressed) {
    if (kc == kc_2  && mod == MOD_LALT) {
      unregister_mods(mod);
    }
    register_code(kc);
    if (kc == kc_2) {
      register_mods(mod);
    }
  } else {
    unregister_code(kc);
  }

  return false;
}

// switch/case on keyboard events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    case KC_Q:
    {
      return switch_key(record, KC_Q, KC_1, true);
    }
    case KC_W:
    {
      return switch_key(record, KC_W, KC_2, true);
    }
    case KC_E:
    {
      return switch_key(record, KC_E, KC_3, true);
    }
    case KC_R:
    {
      return switch_key(record, KC_R, KC_4, true);
    }
    case KC_T:
    {
      return switch_key(record, KC_T, KC_5, true);
    }
    case KC_Y:
    {
      return switch_key(record, KC_Y, KC_6, true);
    }
    case KC_U:
    {
      return switch_key(record, KC_U, KC_7, true);
    }
    case KC_I:
    {
      return switch_key(record, KC_I, KC_8, true);
    }
    case KC_O:
    {
      return switch_key(record, KC_O, KC_9, true);
    }
    case KC_P:
    {
      return switch_key(record, KC_P, KC_0, true);
    }
    case KC_ENT:
    {
      return switch_key(record, KC_ENT, KC_MINS, false);
    }
    case KC_UP:
    {
      return switch_key(record, KC_UP, KC_LBRC, false);
    }
    case KC_LEFT:
    {
      return switch_key(record, KC_LEFT, KC_QUOT, false);
    }
    case KC_RGHT:
    {
      return switch_key(record, KC_RGHT, KC_GRV, false);
    }
    case KC_DOWN:
    {
      return switch_key(record, KC_DOWN, KC_BSLS, false);
    }
    default:
    {
      return true;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,      KC_P,      KC_BSPC,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,      KC_K,    KC_L,      KC_SCLN,   KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,      KC_COMMA,KC_DOT,    KC_UP,     KC_RBRC,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_RALT, KC_RGUI, KC_SPC,  KC_SPC,  KC_SLSH,   KC_EQL,  KC_LEFT,   KC_DOWN,   KC_RGHT
  ),
};
