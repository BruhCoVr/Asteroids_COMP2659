#include "psg.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>
#include "types.h"

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
    enable_channel(C_CHANNEL, 1, 1);
    enable_channel(B_CHANNEL, 1, 1);
    set_envelope(0xC, 200);   
}

void explosion_effect() {
    set_tone(C_CHANNEL, noteTunings[E][OCTAVE_3]);
    set_volume(C_CHANNEL, 0x1F); 
    enable_channel(C_CHANNEL, 0, 1);
    set_envelope(0xD, 300);   
}

