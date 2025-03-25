#include "time.h"
#include "types.h"
#include <osbind.h>

UINT32 getTime() {
    UINT32 *timer = (UINT32 *)0x462; /* Address of the timer */
    UINT32 old_ssp, time;

    old_ssp = Super(0);
    time = *timer;
    Super(old_ssp);
    return time;
}

