#include "psg.h"
#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include <math.h>

int A_CHANNEL = 0;
int B_CHANNEL = 1;
int C_CHANNEL = 2;

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
        else if(tone_on > 0 && noise_on = 0){
            regWrite = 0x3E;
        }
        else if(tone_on = 0 && noise_on > 0){
            regWrite = 0x37;
        }
        break;

    case B_CHANNEL:
         if(tone_on > 0 && noise_on > 0){
            regWrite = 0x2D;
        }
        else if(tone_on > 0 && noise_on = 0){
            regWrite = 0x3D;
        }
        else if(tone_on = 0 && noise_on > 0){
            regWrite = 0x2F;
        }
        break;

    case C_CHANNEL:
         if(tone_on > 0 && noise_on > 0){
            regWrite = 0x1B;
        }
        else if(tone_on > 0 && noise_on = 0){
            regWrite = 0x3B;
        }
        else if(tone_on = 0 && noise_on > 0){
            regWrite = 0x1F;
        }
        break;
    
    }

    write_psg(7, regWrite);
}

void stop_sound(){

    for(int i = 0; i < 3; i++){
        int channelReg =  i + 8;		
        int volumeVal = 0;	
        write_psg(channelReg, volumeVal);
    }
}

void set_volume(int channel, int volume){

    int channelReg =  channel + 8;		
    int volumeVal = volume;	
    write_psg(channelReg, volumeVal);

}

//add code to add tuning to course and fine 
void set_tone(int channel, int tuning){

    switch (channel)
    {
    case A_CHANNEL:
    //fine
        int channelReg =  channel;		
        int tuningVal = tuning;	
        write_psg(channelReg, tuningVal);

    //course
        int channelReg =  channel + 1;		
        int tuningVal = tuning;	
        write_psg(channelReg, tuningVal);
        break;

    case B_CHANNEL:
    //fine
        int channelReg =  channel + 1;		
        int tuningVal = tuning;	
        write_psg(channelReg, tuningVal);

    //course
        int channelReg =  channel + 2;		
        int tuningVal = tuning;	
        write_psg(channelReg, tuningVal);   
        break;

    case C_CHANNEL:
    //fine
        int channelReg =  channel + 2;		
        int tuningVal = tuning;	
        write_psg(channelReg, tuningVal);

    //course
        int channelReg =  channel + 3;		
        int tuningVal = tuning;	
        write_psg(channelReg, tuningVal);
        break;
    
    }

}

void set_noise(int tuning){
    
    int channelReg =  6;		
    int tuningVal = tuning;	
    write_psg(channelReg, tuningVal);
}

void set_envelope(int shape, unsigned int sustain){

//no clue how to use test later
    int channelRegFine =  11;	
    int channelRegCourse = 12;	
    int shapeVal = shape;	
    write_psg(channelRegFine, tuningVal);


}
