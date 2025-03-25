#include "psg.h"
#include "effects.h"

#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include "types.h"

extern void shooting_effect();
extern void thrusting_effect();
extern void explosion_effect();

UINT32 getTime() {
    UINT32 *timer = (UINT32 *)0x462; /* Address of the timer */
    UINT32 old_ssp, time;

    old_ssp = Super(0);
    time = *timer;
    Super(old_ssp);
    return time;
}

int main() {
    int choice;
    UINT32 start_time, current_time;
    
    printf("Sound Effects Test:\n");
    printf("1 - Shooting Effect\n");
    printf("2 - Thrusting Effect\n");
    printf("3 - Explosion Effect\n");
    printf("0 - Exit\n");

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &choice);
        
        start_time = getTime();
        
        switch (choice) {
            case 1:
                shooting_effect();
                break;
            case 2:
                thrusting_effect();
                break;
            case 3:
                explosion_effect();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }

        do {
            current_time = getTime();
        } while (current_time - start_time < 33);

        stop_sound();
    }
    return 0;
}
