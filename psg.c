#include "psg.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_psg(int reg, int val){

    volatile char *PSG_reg_select = 0xFF8800;
	volatile char *PSG_reg_write  = 0xFF8802;

    *PSG_reg_select = reg;		
	*PSG_reg_write  = val;
}

void enable_channel(int channel, int tone_on, int noise_on){
    
    //no clue how to enable channels
	*PSG_reg_select = 7 ;		/* enable channel A on mixer */
	*PSG_reg_write  = 0x3E;

    int channelReg =  channel;		
    int volumeVal = volume;	

    write_psg(channelReg, volumeVal);
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

void set_tone(int channel, int tuning){

    int channelReg =  channel + 1;		
    int tuningVal = tuning;	
    write_psg(channelReg, tuningVal);

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
