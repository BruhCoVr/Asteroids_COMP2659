#ifndef PSG_H
#define PSG_H
#include "types.h"

/** 
 * Enumeration for the available sound channels (A, B, C).
 */
typedef enum {
    A_CHANNEL = 0,
    B_CHANNEL,
    C_CHANNEL,
} Channel;

/** 
 * Enumeration for musical notes.
 */
typedef enum {
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

/** 
 * Enumeration for octaves.
 */
typedef enum {
    OCTAVE_3 = 0,
    OCTAVE_4,
    OCTAVE_5,
    NUM_OCTAVES
} Octave;

/** 
 * Structure representing a playable note with tone, octave, and hold time.
 */
typedef struct {
    Note note;
    Octave octave;
    unsigned long holdTime;
} PlayableNote;

/** 
 * Externally defined note tuning values.
 */
extern const UINT16 noteTunings[NUM_TONES][NUM_OCTAVES];

/** 
 * Function declarations for PSG operations.
 */
void write_psg(int reg, int val);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_volume(int channel, int volume);
void set_tone(int channel, int tuning);
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);

#endif /* PSG_H */
