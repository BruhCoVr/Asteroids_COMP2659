#include "psg.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>
#include "types.h"

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


void shooting_effect() {
    set_tone(C_CHANNEL, noteTunings[B][OCTAVE_5]);
    set_volume(C_CHANNEL, 0x1C); 
    enable_channel(C_CHANNEL, 1, 0);
    set_envelope(0xE, 1500); 
}

void thrusting_effect() {
    set_tone(C_CHANNEL, noteTunings[F][OCTAVE_3]);
    set_tone(B_CHANNEL, noteTunings[F_SHARP][OCTAVE_3]); 
    set_volume(C_CHANNEL, 0x1A);
    set_volume(B_CHANNEL, 0x1A);
    enable_channel(C_CHANNEL, 1, 0);
    enable_channel(B_CHANNEL, 1, 0);
    set_envelope(0xC, 6000);   
}

void explosion_effect() {
    set_tone(C_CHANNEL, noteTunings[E][OCTAVE_3]);
    set_tone(B_CHANNEL, noteTunings[G][OCTAVE_3]); 
    set_volume(C_CHANNEL, 0x1F); 
    set_volume(B_CHANNEL, 0x1C); 
    enable_channel(C_CHANNEL, 1, 0);
    enable_channel(B_CHANNEL, 1, 0);
    set_envelope(0xD, 300);   
}


the