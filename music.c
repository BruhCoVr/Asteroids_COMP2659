#include "psg.h"
#include "music.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>
#include "types.h"

#define D_FLAT C_SHARP
#define E_FLAT D_SHARP
#define G_FLAT F_SHARP
#define A_FLAT G_SHARP
#define B_FLAT A_SHARP

int currNote;
int deathNote;
UINT32 lastUpdateTime;
UINT32 UpdateDeathTime;


/*change hold time 1s = 70*/
PlayableNote mainSong[] = {
    {D, OCTAVE_4, 18},
    {G, OCTAVE_4, 18},
    {G, OCTAVE_4, 18},
    {D, OCTAVE_4, 18},
    {B, OCTAVE_4, 18},
    {D, OCTAVE_5, 18},
    {D, OCTAVE_4, 18},
    {B, OCTAVE_4, 18},
    {B, OCTAVE_4, 18},
    {D, OCTAVE_5, 18},
    {B, OCTAVE_4, 18},
    {G, OCTAVE_4, 18},
};

PlayableNote deathSong[] = {
    {E, OCTAVE_3, 36},
    {D, OCTAVE_3, 36},
    {C, OCTAVE_3, 36},
};


void start_music() {
    lastUpdateTime = 0;
    currNote = 0;
    
    enable_channel(A_CHANNEL, 1, 0);
    set_volume(A_CHANNEL, 11);
    set_tone(A_CHANNEL, noteTunings[mainSong[0].note][mainSong[0].octave]);
}

void update_Mainmusic(UINT32 time_elapsed) {

    if(time_elapsed >= lastUpdateTime){
        set_tone(A_CHANNEL, noteTunings[mainSong[currNote].note][mainSong[currNote].octave]);
        lastUpdateTime += mainSong[currNote].holdTime;
        currNote++; 
    }

    if(currNote >= 11) {
            currNote = 0; 
        }
    }

void start_Deathmusic() {
        UpdateDeathTime = 0;
        deathNote = 0;
        
        enable_channel(A_CHANNEL, 1, 0);
        set_volume(A_CHANNEL, 11);
        set_tone(A_CHANNEL, noteTunings[deathSong[0].note][deathSong[0].octave]);
    }    
    
void update_Deathmusic(UINT32 time_elapsed) {

    if(time_elapsed >= UpdateDeathTime){
        set_tone(A_CHANNEL, noteTunings[deathSong[deathNote].note][deathSong[deathNote].octave]);
        UpdateDeathTime += deathSong[deathNote].holdTime;
        deathNote++; 
    }

    if(deathNote >= 4){
        stop_sound();
    }

    }