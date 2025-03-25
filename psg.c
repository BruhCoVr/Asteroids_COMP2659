#include "psg.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>

#define A_CHANNEL 0
#define B_CHANNEL 1
#define C_CHANNEL 2

void write_psg(int sel, int wri){

    volatile char *PSG_reg_select = 0xFF8800;
	volatile char *PSG_reg_write  = 0xFF8802;

    long old_ssp = Super(0);

    *PSG_reg_select = sel;		
	*PSG_reg_write  = wri;

    Super(old_ssp);
}

void enable_channel(int channel, int tone_on, int noise_on){
    int regWrite;
    switch (channel)
    {
    case A_CHANNEL:
        if(tone_on > 0 && noise_on > 0){
            regWrite = 0x36;
        }
        else if(tone_on > 0 && noise_on == 0){
            regWrite = 0x3E;
        }
        else if(tone_on == 0 && noise_on > 0){
            regWrite = 0x37;
        }
        break;

    case B_CHANNEL:
         if(tone_on > 0 && noise_on > 0){
            regWrite = 0x2D;
        }
        else if(tone_on > 0 && noise_on == 0){
            regWrite = 0x3D;
        }
        else if(tone_on == 0 && noise_on > 0){
            regWrite = 0x2F;
        }
        break;

    case C_CHANNEL:
         if(tone_on > 0 && noise_on > 0){
            regWrite = 0x1B;
        }
        else if(tone_on > 0 && noise_on == 0){
            regWrite = 0x3B;
        }
        else if(tone_on == 0 && noise_on > 0){
            regWrite = 0x1F;
        }
        break;
    
    }

    write_psg(7, regWrite);
}

void stop_sound(){
    int i;
    for(i = 0; i < 3; i++){
        int regSelect =  i + 8;		
        int volumeVal = 0;	
        write_psg(regSelect, volumeVal);
    }
}

void set_volume(int channel, int volume){

    int regSelect =  channel + 8;		
    int volumeVal = volume;	
    write_psg(regSelect, volumeVal);

}

void set_tone(int channel, int tuning){
    int regSelect;
    int tuningVal;
    switch (channel)
    {
    case A_CHANNEL:
    /*fine */
        regSelect = channel;		
        tuningVal = tuning & 0xFF;	
        write_psg(regSelect, tuningVal);

    /*course */
        regSelect =  channel + 1;		
        tuningVal = (tuning >> 8) & 0xFF;	
        write_psg(regSelect, tuningVal);
        break;

    case B_CHANNEL:
    /*fine */
        regSelect =  channel + 1;		
        tuningVal = tuning & 0xFF;
        write_psg(regSelect, tuningVal);

    /*course */
        regSelect =  channel + 2;		
        tuningVal = (tuning >> 8) & 0xFF;	
        write_psg(regSelect, tuningVal);   
        break;

    case C_CHANNEL:
    /*fine */
        regSelect =  channel + 2;		
        tuningVal = tuning & 0xFF;
        write_psg(regSelect, tuningVal);

    /*course */
        regSelect =  channel + 3;		
        tuningVal = (tuning >> 8) & 0xFF;	
        write_psg(regSelect, tuningVal);
        break;
    
    }

}

void set_noise(int tuning){
    
    int regSelect =  6;		
    int tuningVal = tuning;	
    write_psg(regSelect, tuningVal);
}


void set_envelope(int shape, unsigned int sustain){
    int regSelectFine =  11;	
    int regSelectCourse = 12;	
    int regSelectShape = 13;
  
    UINT8 fine,coarse;

    fine = (UINT8)(sustain & 0xFF);
    coarse = (UINT8)(sustain >> 8);

    write_psg(regSelectFine, fine);
    write_psg(regSelectCourse, coarse);
    write_psg(regSelectShape, shape);

}
