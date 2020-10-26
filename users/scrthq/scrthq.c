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
