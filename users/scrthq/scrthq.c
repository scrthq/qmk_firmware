#include "scrthq.h"
#include "quantum.h"

/*---------------*\
|*-----MOUSE-----*|
\*---------------*/
#ifdef MOUSEKEY_ENABLE
#include "mousekey.h"
#endif

/*-------------------*\
|*-----TAP-DANCE-----*|
\*-------------------*/
#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [SPENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT)
};
#endif

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: [%u], col: [%u], row: [%u], pressed: [%u]\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
#ifdef USE_BABBLEPASTE
    if( keycode > BABBLE_START && keycode < BABBLE_END_RANGE )  {
        if (record->event.pressed)  {
            babblePaste ( keycode );
        } else {
            return true;
        }
    }
#endif
    switch (keycode) {
    case MOFO:
        if (record->event.pressed) {
            SEND_STRING("Mofo from QMK!");
        }
        return false;
        break;
    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FUNCTION);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FUNCTION);
        }
        return false;
        break;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FUNCTION);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FUNCTION);
        }
        return false;
        break;
    }
    // return true;
    return process_record_keymap(keycode, record);
}
