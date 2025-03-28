#include "psg.h"
#include "music.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>
#include "types.h"

/** 
 * Defines alternative names for sharps using macros.
 */
#define D_FLAT C_SHARP
#define E_FLAT D_SHARP
#define G_FLAT F_SHARP
#define A_FLAT G_SHARP
#define B_FLAT A_SHARP

/** 
 * Current note being played in the main song.
 */
int currNote;

/** 
 * Current note being played in the death song.
 */
int deathNote;

/** 
 * Tracks the last update time for the main song.
 */
UINT32 lastUpdateTime;

/** 
 * Tracks the update time for the death song.
 */
UINT32 UpdateDeathTime;

/** 
 * Defines the main song using playable notes, including tones, octaves, 
 * and hold times for each note.
 */
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

/** 
 * Defines the death song using playable notes, including tones, octaves, 
 * and hold times for each note.
 */
PlayableNote deathSong[] = {
    {E, OCTAVE_3, 36},
    {D, OCTAVE_3, 36},
    {C, OCTAVE_3, 36},
};

/** 
 * Initializes and starts playing the main song by enabling the audio channel 
 * and setting the tone and volume for the first note.
 */
void start_music() {
    lastUpdateTime = 0;
    currNote = 0;

    enable_channel(A_CHANNEL, 1, 0);
    set_volume(A_CHANNEL, 11);
    set_tone(A_CHANNEL, noteTunings[mainSong[0].note][mainSong[0].octave]);
}

/** 
 * Updates the main song by changing the tone based on the elapsed time 
 * and advancing to the next note. Resets if the song ends.
 */
void update_Mainmusic(UINT32 time_elapsed) {
    if (time_elapsed >= lastUpdateTime) {
        set_tone(A_CHANNEL, noteTunings[mainSong[currNote].note][mainSong[currNote].octave]);
        lastUpdateTime += mainSong[currNote].holdTime;
        currNote++;
    }

    if (currNote >= 11) {
        currNote = 0;
    }
}

/** 
 * Initializes and starts playing the death song by enabling the audio channel 
 * and setting the tone and volume for the first note.
 */
void start_Deathmusic() {
    UpdateDeathTime = 0;
    deathNote = 0;

    enable_channel(A_CHANNEL, 1, 0);
    set_volume(A_CHANNEL, 11);
    set_tone(A_CHANNEL, noteTunings[deathSong[0].note][deathSong[0].octave]);
}

/** 
 * Updates the death song by changing the tone based on the elapsed time 
 * and advancing to the next note. Stops the sound when the song ends.
 */
void update_Deathmusic(UINT32 time_elapsed) {
    if (time_elapsed >= UpdateDeathTime) {
        set_tone(A_CHANNEL, noteTunings[deathSong[deathNote].note][deathSong[deathNote].octave]);
        UpdateDeathTime += deathSong[deathNote].holdTime;
        deathNote++;
    }

    if (deathNote >= 4) {
        stop_sound();
    }
}
