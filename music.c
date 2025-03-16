#include "psg.h"
#include "music.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>

int A_CHANNEL = 0;
int B_CHANNEL = 1;
int C_CHANNEL = 2;

typedef struct {
	char fine;
	char course;
}NoteProperty;

typedef struct {
	NoteEnum note;
	unsigned long holdTime;
}PlayableNote;

typedef enum{
	B4 = 0,
	B_FLAT4,
	A4,
	A_FLAT4,
	G4,
	G_FLAT4,
	F4,
	E4,
	E_FLAT4,
	D4,
	D_FLAT4,
	C4,
	B3,
	NUM_NOTES
}NoteEnum;

const NoteProperty notePropertities[NUM_NOTES] = {
	/*(fine,course)*/

	/* B4 = */ {0,1},
	/* B_FLAT4 = */ {10,1},
	/* A4 = */ {27,1},
	/* A_FLAT4 = */ {45,1},
	/* G4 = */ {62,1},
	/* G_FLAT4 = */ {80,1},
	/* F4 = */ {100,1},
	/* E4 = */ {123,1},
	/* E_FLAT4 = */ {146,1},
	/* D4 = */ {169,1},
	/* D_FLAT4 = */ {200,1},
	/* C4 = */ {220,1},
	/* B3 = */ {255,1}

};

//make a song here
const PlayableNote mainSong[] = {
    
}

void start_music(){
    enable_channel(A_CHANNEL, 1, 0);
    set_volume(A_CHANNEL, 11);

    
}

void update_music(UINT32 time_elapsed){
    int timeToPlayNext = 0;
    int timeElapsed = 0;
    int currNote = 0;

    if(timeToPlayNext <= timeElapsed){
        set_tone()
        currNote++;
        timeToPlayNext += 
    }
}

