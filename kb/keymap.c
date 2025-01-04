#include QMK_KEYBOARD_H
#include <print.h>
#include <timer.h>

static uint16_t pressed_timer;
static uint16_t pressed_key = -1;
static uint16_t pressed_enabled = false;

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

// specifically manage some long press key
void matrix_scan_user(void) {
  if (pressed_key != -1) {
    if (timer_elapsed(pressed_timer) > 200) {
      pressed_enabled = true;
      pressed_timer = timer_read();
    }
    if (pressed_enabled && timer_elapsed(pressed_timer) > 50) {
      pressed_timer = timer_read();
      if (pressed_key == KC_LEFT || pressed_key == KC_RIGHT || pressed_key == KC_DOWN || pressed_key == KC_UP) {
        unregister_mods(MOD_LALT);
        tap_code(pressed_key);
        register_mods(MOD_LALT);
      }
    }
  }
}

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
    pressed_timer = timer_read();
    pressed_key = kc;
    if (kc == kc_2  && mod == MOD_LALT) {
      unregister_mods(mod);
    }
    register_code(kc);
    if (kc == kc_2) {
      register_mods(mod);
    }
  } else {
    pressed_key = -1;
    pressed_enabled = false;
    unregister_code(kc);
  }

  return false;
}

bool switch_key2(keyrecord_t *record, uint16_t kc_1, uint16_t kc_2)
{
  uint16_t kc = kc_1;

  if (keyboard_report->mods & MOD_MASK_ALT) {
    kc = kc_2;
  }

  if(record->event.pressed) {
    if (kc == kc_2) {
      unregister_mods(MOD_LALT);
      register_mods(MOD_LSFT);
    }
    register_code(kc);
    if (kc == kc_2) {
      register_mods(MOD_LALT);
      unregister_mods(MOD_LSFT);
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
      uint16_t kc = KC_ENT;
      uint16_t mod = -1;

      if (keyboard_report->mods & MOD_MASK_ALT) {
        kc = KC_BSPC;
        mod = MOD_LALT;
      }

      if(record->event.pressed) {
        if (kc == KC_BSPC  && mod == MOD_LALT) {
          unregister_mods(mod);
        }
        register_code(kc);
        if (kc == KC_BSPC) {
          register_mods(mod);
        }
      } else {
        unregister_code(kc);
      }
      return false;
    }
    case KC_LBRC:
    {
      return switch_key(record, KC_LBRC, KC_UP, true);
    }
    case KC_QUOT:
    {
      return switch_key(record, KC_QUOT, KC_LEFT, true);
    }
    case KC_GRV:
    {
      return switch_key(record, KC_GRV, KC_RGHT, true);
    }
    case KC_BSLS:
    {
      return switch_key(record, KC_BSLS, KC_DOWN, true);
    }
    case KC_MINS:
    {
      return switch_key2(record, KC_MINS, KC_0);
    }
    case KC_SCLN:
    {
      return switch_key2(record, KC_SCLN, KC_9);
    }
    case KC_SLSH:
    {
      return switch_key2(record, KC_SLSH, KC_1);
    }
    case KC_EQL:
    {
      return switch_key2(record, KC_EQL, KC_8);
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
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,      KC_P,      KC_ENT,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,      KC_K,    KC_L,      KC_SCLN,   KC_MINS,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,      KC_COMMA,KC_DOT,    KC_LBRC,   KC_RBRC,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_RCTL, KC_RALT, KC_SPC,  KC_SPC,  KC_SLSH,   KC_EQL,  KC_QUOT,   KC_BSLS,   KC_GRV
  ),
};
