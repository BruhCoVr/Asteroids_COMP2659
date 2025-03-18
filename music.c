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

int A_CHANNEL = 0;
int B_CHANNEL = 1;
int C_CHANNEL = 2;
static int currNote = 0;

void delay(unsigned int count) {
    while (count--) {
    }
}

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

const PlayableNote mainSong[] = {
    {D, OCTAVE_4, 250},
    {G, OCTAVE_4, 500},
    {G, OCTAVE_4, 500},
    {D, OCTAVE_4, 250},
    {B, OCTAVE_4, 500},
    {D, OCTAVE_5, 500},
    {D, OCTAVE_4, 250},
    {B, OCTAVE_4, 500},
    {B, OCTAVE_4, 500},
    {D, OCTAVE_5, 250},
    {B, OCTAVE_4, 250},
    {G, OCTAVE_4, 250},
};

void start_music() {
    enable_channel(A_CHANNEL, 1, 0);
    set_volume(A_CHANNEL, 11);
    set_tone(A_CHANNEL, noteTunings[mainSong[0].note][mainSong[0].octave]);
}

void update_music(UINT32 time_elapsed) {
    /*static UINT32 lastUpdateTime = 0;*/
    delay(noteTunings[mainSong[currNote].holdTime]);
    set_volume(A_CHANNEL, 0);

    set_tone(A_CHANNEL, noteTunings[mainSong[currNote].note][mainSong[currNote].octave]);
    set_volume(A_CHANNEL, 11);
    
    currNote++; 
    if (currNote >= sizeof(mainSong) / sizeof(mainSong[0])) {
        currNote = 0; 
        }
    }



