#include "psg.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>

/** 
 * Defines note tuning values for different tones and octaves.
 * The values are specified as hexadecimal.
 */
const UINT16 noteTunings[NUM_TONES][NUM_OCTAVES] = {
    /* 0000cccc ffffffff */
    /*                 3rd        4th        5th */
    /* C */         {{0x03BE}, {0x01DC}, {0x00EF}},
    /* C_SHARP */   {{0x0387}, {0x01C3}, {0x00E1}},
    /* D */         {{0x0354}, {0x01A9}, {0x00D5}},
    /* D_SHARP */   {{0x0324}, {0x0192}, {0x00C8}},
    /* E */         {{0x02F8}, {0x017B}, {0x00BD}},
    /* F */         {{0x02CC}, {0x0164}, {0x00B2}},
    /* F_SHARP */   {{0x02A5}, {0x0150}, {0x00A8}},
    /* G */         {{0x027E}, {0x013E}, {0x009F}},
    /* G_SHARP */   {{0x025A}, {0x012D}, {0x0096}},
    /* A */         {{0x0239}, {0x011B}, {0x008E}},
    /* A_SHARP */   {{0x0219}, {0x010A}, {0x0085}},
    /* B */         {{0x01FA}, {0x00FD}, {0x007E}},
};

/** 
 * Writes values to PSG (Programmable Sound Generator) registers.
 * 
 * @param sel Register selector value.
 * @param wri Value to write into the register.
 */
void write_psg(int sel, int wri) {
    volatile char *PSG_reg_select = 0xFF8800;
    volatile char *PSG_reg_write = 0xFF8802;

    long old_ssp = Super(0); 

    *PSG_reg_select = sel;
    *PSG_reg_write = wri; 

    Super(old_ssp);
}

/** 
 * Enables a specified audio channel with tone and/or noise generation.
 * 
 * @param channel Channel to enable (A, B, or C).
 * @param tone_on Enables tone if > 0.
 * @param noise_on Enables noise if > 0.
 */
void enable_channel(int channel, int tone_on, int noise_on) {
    int regWrite;
    switch (channel) {
        case A_CHANNEL:
            regWrite = tone_on > 0 && noise_on > 0 ? 0x36 :
                       tone_on > 0 ? 0x3E : 0x37;
            break;
        case B_CHANNEL:
            regWrite = tone_on > 0 && noise_on > 0 ? 0x2D :
                       tone_on > 0 ? 0x3D : 0x2F;
            break;
        case C_CHANNEL:
            regWrite = tone_on > 0 && noise_on > 0 ? 0x1B :
                       tone_on > 0 ? 0x3B : 0x1F;
            break;
    }
    write_psg(7, regWrite);
}

/** 
 * Stops sound by setting the volume of all channels to zero.
 */
void stop_sound() {
    int i;
    for (i = 0; i < 3; i++) {
        write_psg(i + 8, 0); 
    }
}

/** 
 * Sets the volume for a specified channel.
 * 
 * @param channel Channel to set volume for (A, B, or C).
 * @param volume Volume level to set.
 */
void set_volume(int channel, int volume) {
    write_psg(channel + 8, volume); 
}

/** 
 * Sets the tone for a specified channel using fine and coarse tuning.
 * 
 * @param channel Channel to set tone for (A, B, or C).
 * @param tuning Tuning value to set.
 */
void set_tone(int channel, int tuning) {
    int regSelect, tuningVal;
    switch (channel) {
        case A_CHANNEL:
            regSelect = channel; 
            tuningVal = tuning & 0xFF;
            write_psg(regSelect, tuningVal);

            regSelect = channel + 1; 
            tuningVal = (tuning >> 8) & 0xFF;
            write_psg(regSelect, tuningVal);
            break;
        case B_CHANNEL:
            regSelect = channel + 1; 
            tuningVal = tuning & 0xFF;
            write_psg(regSelect, tuningVal);

            regSelect = channel + 2; 
            tuningVal = (tuning >> 8) & 0xFF;
            write_psg(regSelect, tuningVal);
            break;
        case C_CHANNEL:
            regSelect = channel + 2;
            tuningVal = tuning & 0xFF;
            write_psg(regSelect, tuningVal);

            regSelect = channel + 3; 
            tuningVal = (tuning >> 8) & 0xFF;
            write_psg(regSelect, tuningVal);
            break;
    }
}

/** 
 * Sets noise tuning for the PSG.
 * 
 * @param tuning Tuning value for the noise generator.
 */
void set_noise(int tuning) {
    write_psg(6, tuning); 
}

/** 
 * Sets the envelope shape and sustain value for the PSG.
 * 
 * @param shape Envelope shape value.
 * @param sustain Sustain duration value.
 */
void set_envelope(int shape, unsigned int sustain) {
    UINT8 fine = (UINT8)(sustain & 0xFF); 
    UINT8 coarse = (UINT8)(sustain >> 8);

    write_psg(11, fine);       
    write_psg(12, coarse);     
    write_psg(13, shape);  
    
}
