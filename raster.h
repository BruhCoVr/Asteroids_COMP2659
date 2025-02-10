#ifndef RASTER_H
#define RASTER_H

#include <stdio.h>
#include <osbind.h>

typedef unsigned char UINT8;
typedef unsigned int UINT16;
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


extern const UINT32 ship_up_bitmap[];
extern const UINT32 ship_down_bitmap[];
extern const UINT32 ship_left_bitmap[];   
extern const UINT32 ship_right_bitmap[];
extern const UINT32 ship_diag_down_left_bitmap[];
extern const UINT32 ship_diag_down_right_bitmap[];
extern const UINT32 ship_diag_up_left_bitmap[];
extern const UINT32 ship_diag_up_right_bitmap[];  
extern const UINT32 largeAsteroid_bitmap[];
extern const UINT32 mediumAsteroid_bitmap[];
extern const UINT32 smallAsteroid_bitmap[];
extern const UINT8 bullet[];

void plot_bitmap_8 (UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
void plot_bitmap_16 (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void plot_bitmap_32 (UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
void plot_pixel (UINT8 *base, int x, int y);
void clear_sc (UINT32* base);
void plot_vline(UINT8 *base, int x, int y1, int y2);
void plot_hline (UINT8 *base, int y, int x1, int x2);
#endif 
