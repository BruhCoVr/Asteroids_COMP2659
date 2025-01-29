#ifndef BITMAP_S
#define BITMAP_S
#define INVADER_HEIGHT 16
typedef unsigned int UINT16;
typedef unsigned char UINT8;
typedef unsigned long UINT32;

unsigned int invader_bitmap[INVADER_HEIGHT] =
    {
        0x0000,
        0x0810,
        0x0810,
        0x0420,
        0x0240,
        0x1FF8,
        0x2004,
        0x4662,
        0x4002,
        0x43C2,
        0x2424,
        0x1008,
        0x0FF0,
        0x0240,
        0x0E70,
        0x0000};

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);


#endif
