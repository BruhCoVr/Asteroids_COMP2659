#ifndef PSG_H
#define PSG_H

void write_psg(int reg, int val);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

void set_volume(int channel, int volume);

void set_tone(int channel, int tuning);

void set_noise(int tuning);

void set_envelope(int shape, unsigned int sustain);

#endif /* PSG_H */