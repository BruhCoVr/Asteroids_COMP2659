#ifndef RASTER_H
#define RASTER_H
#define NUM_HEIGHT 16
#define NUM_HEIGHT_2 32
typedef unsigned int UINT16;
typedef unsigned char UINT8;
typedef unsigned long UINT32;

typedef enum {
    num_0 = 0,
    num_1,
    num_2,
    num_3,
    num_4,
    num_5,
    num_6,
    num_7,
    num_8,
    num_9,
    TotalNumbers
} NumberEnum;

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void print_score(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void clear_sc(UINT32* base);

#endif
