#include "psg.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>
#include "types.h"

/**
 * Produces a shooting sound effect by configuring the tone, volume, and envelope
 * for the specified channel.
 */
void shooting_effect() {
    set_tone(C_CHANNEL, noteTunings[B][OCTAVE_5]); 
    set_volume(C_CHANNEL, 0x1C);
    enable_channel(C_CHANNEL, 1, 0); 
    set_envelope(0xE, 300); 
}

/**
 * Produces a thrusting sound effect by configuring the tone, volume, and envelope
 * for two channels.
 */
void thrusting_effect() {
    set_tone(C_CHANNEL, noteTunings[F][OCTAVE_3]);
    set_tone(B_CHANNEL, noteTunings[F_SHARP][OCTAVE_3]); 
    set_volume(C_CHANNEL, 0x14); 
    set_volume(B_CHANNEL, 0x14); 
    enable_channel(C_CHANNEL, 1, 1);
    enable_channel(B_CHANNEL, 1, 1);
    set_envelope(0xC, 200); 
}

/**
 * Produces an explosion sound effect by configuring the tone, volume, and envelope
 * for the specified channel.
 */
void explosion_effect() {
    set_tone(C_CHANNEL, noteTunings[E][OCTAVE_3]); 
    set_volume(C_CHANNEL, 0x1F);
    enable_channel(C_CHANNEL, 0, 1);
    set_envelope(0xD, 300); 
}

