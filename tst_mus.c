#include "music.h"
#include "psg.h"
#include <osbind.h>
#include <stdio.h>
#include "types.h"

UINT32 getTime() {
    UINT32 *timer = (UINT32 *) 0x462; /* Address of the timer */
    UINT32 old_ssp, time;
    
    old_ssp = Super(0);
    time = *timer;
    Super(old_ssp);
    return time;
}

int main() {
    int choice;
    UINT32 start_time, current_time;
    int currentSong = 0; 
    
    printf("Music Test:\n");
    printf("1 - Start Death Music\n");
    printf("2 - Start Main Music\n");
    printf("0 - Exit\n");

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &choice);
        
        start_time = getTime();
        
        switch (choice) {
            case 1:
                currentSong = 1;
                start_Deathmusic();
                break;
            case 2:
                currentSong = 2;
                start_music();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                currentSong = 0;
        }
        
        do {
            current_time = getTime();
            if (currentSong == 1) {
                update_Deathmusic(current_time - start_time);
            } else if (currentSong == 2) {
                update_Mainmusic(current_time - start_time);
            }
        } while (current_time - start_time < 500);

        set_volume(A_CHANNEL, 0);
    }
    return 0;
}
