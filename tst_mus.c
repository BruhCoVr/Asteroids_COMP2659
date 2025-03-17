#include "music.h"
#include "psg.h"
#include <osbind.h>

UINT32 get_time() {
    return (UINT32) Tgettime();
}


int main() {
    UINT32 prev_time = get_time();
    UINT32 curr_time;

    start_music();

    while (!Cconis()) { 
        curr_time = get_time();
        
        update_music(curr_time); 
        
    }

    return 0;
}
