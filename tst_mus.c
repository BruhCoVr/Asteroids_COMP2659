#include "music.h"
#include "psg.h"
#include <osbind.h>


/*fix the get time function with what anthony gave me*/
UINT32 get_time() {
    return (UINT32) Tgettime();
}


int main() {
    UINT32 prev_time = get_time();
    UINT32 curr_time;

    start_music();

    while (!Cconis()) { 
        curr_time = get_time();
        
        update_music(curr_time - prev_time); 
        
    }

    return 0;
}
