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

/*
This function plots a single pixel at coordinates (x, y) on a monochrome (1-bit per pixel) display.
Ensures the pixel is within the valid screen boundaries (SCREEN_WIDTH and SCREEN_HEIGHT) 
and calculates the appropriate byte in the base memory where the pixel belongs and sets the corresponding bit.
*/
void plot_pixel (UINT8 *base, int x, int y);

void clear_sc (UINT32* base);

/*
This function draws a vertical line from (x, y1) to (x, y2), ensures x-coordinate is within the the range (0-639).
Handles sawpping y1 and y2 (if in the wrong order), also checking the range for the y-coordinates (0-399).
lastly iterates from y1 to y2, calling plot_pixel to set each pixel along the vertical line.
*/
void plot_vline(UINT8 *base, int x, int y1, int y2);

/*
The function draws a vertical line at a specific x coordinate, 
between two y coordinates (y1 and y2),on a screen with a resolution of 640x400 pixels.
The line is drawn by manipulating bits in the screen buffer. 
*/
void plot_hline (UINT8 *base, int y, int x1, int x2);

#endif 
