#ifndef BITMAP_S
#define BITMAP_S
#define INVADER_HEIGHT 16
#define NUM_HEIGHT 16
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

unsigned int num_0[NUM_HEIGHT] =
    {
        0x1FF8,
        0x3FFC,
        0x7FFE,
        0x781E,
        0x781E,
        0x781E,
        0x781E,
        0x781E,
        0x781E,
        0x781E,
        0x781E,
        0x781E,
        0x781E,
        0x7FFE,
        0x3FFC,
        0x1FF8};


unsigned int num_1[NUM_HEIGHT] =
    {
        0x03C0,
        0x07C0,
        0x0FC0,
        0x1FC0,
        0x03C0,
        0x03C0,
        0x03C0,
        0x03C0,
        0x03C0,
        0x03C0,
        0x03C0,
        0x03C0,
        0x03C0,
        0x03C0,
        0xFFFC,
        0xFFFC};


unsigned int num_2[NUM_HEIGHT] =
    {
        0x1FF8,
        0x3FFC,
        0x7FFE,
        0x7FFE,
        0x781E,
        0x701E,
        0x003E,
        0x00FC,
        0x01F8,
        0x03F0,
        0x07E0,
        0x07C0,
        0x0F80,
        0x1FF8,
        0x3FFC,
        0x7FFE};


unsigned int num_3[NUM_HEIGHT] =
    {
        0x3FFC,
        0xFFFC,
        0xFFFC,
        0x001E,
        0x001E,
        0x001E,
        0x3FFC,
        0xFFFC,
        0xFFFC,
        0x3FFC,
        0x001E,
        0x001E,
        0x001E,
        0xFFFC,
        0xFFFC,
        0x3FFC};


unsigned int num_4[NUM_HEIGHT] =
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


unsigned int num_5[NUM_HEIGHT] =
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


unsigned int num_6[NUM_HEIGHT] =
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


unsigned int num_7[NUM_HEIGHT] =
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


unsigned int num_9[NUM_HEIGHT] =
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
void print_score(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

#endif
