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

typedef enum{
    C = 0,
    C_SHARP,
    D,
    D_SHARP,
    E,
    F,
    F_SHARP,
    G,
    G_SHARP,
    A,
    A_SHARP,
    B,
    NUM_TONES
} Note;

typedef enum{
    OCTAVE_3 = 0,
    OCTAVE_4,
    OCTAVE_5,
    NUM_OCTAVES
} Octave;

typedef struct {
	Note note;
	Octave octave;
	unsigned long holdTime;
}PlayableNote;

const UINT16 noteTunings[NUM_TONES][NUM_OCTAVES] = {
    /* 0000cccc ffffffff*/

    /*                 3th        4th        5th */
    /* C */         {{0x03BE}, {0x01DC},  {0x00EF}},
    /* C_SHARP */   {{0x0387}, {0x01C3},  {0x00E1}},
    /* D */         {{0x0354}, {0x01A9},  {0x00D5}},
    /* D_SHARP */   {{0x0324}, {0x0192},  {0x00C8}},
    /* E */         {{0x02F8}, {0x017B},  {0x00BD}},
    /* F */         {{0x02CC}, {0x0164},  {0x00B2}},
    /* F_SHARP */   {{0x02A5}, {0x0150},  {0x00A8}},
    /* G */         {{0x027E}, {0x013E},  {0x009F}},
    /* G_SHARP */   {{0x025A}, {0x012D},  {0x0096}},
    /* A */         {{0x0239}, {0x011B},  {0x008E}},
    /* A_SHARP */   {{0x0219}, {0x010A},  {0x0085}},
    /* B */         {{0x01FA}, {0x00FD},  {0x007E}},
};

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