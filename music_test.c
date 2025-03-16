#include "music.h"
#include <osbind.h>

int main() {
    UINT32 prev_time = 0;
    UINT32 curr_time;

    start_music();

    while (1) {
        curr_time = 0;
        update_music(curr_time);
        curr_time += 1;
    }

    return 0;
}