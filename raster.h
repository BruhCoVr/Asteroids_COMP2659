#ifndef RASTER_H
#define RASTER_H

#include <stdio.h>
#include <osbind.h>

typedef unsigned char UINT8;
typedef unsigned int UINT16;
typedef unsigned long UINT32;

/*Making an enumerated type that will hold 
all of the bitmaps for the numbers 0-9 */
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

/*Function to plot an 8-bit bitmap on a screen or buffer.
It takes a pointer to the base address, x and y coordinates, a pointer to the bitmap data, and the height of the bitmap.
It calculates the offset based on the x and y coordinates, and sets the bits in the target memory area accordingly.*/
void plot_bitmap_8 (UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);

/*Function to plot a 16-bit bitmap on a screen or buffer.
Similar to the previous function, but operates on 16-bit values. The offset calculation and memory access are adjusted for 16-bit data.*/
void plot_bitmap_16 (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

/*Function to plot a 32-bit bitmap on a screen or buffer.
Like the previous functions, but for 32-bit values. The offset and memory access are calculated accordingly for 32-bit data.*/
void plot_bitmap_32 (UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);

/*
This function plots a single pixel at coordinates (x, y) on a monochrome (1-bit per pixel) display.
Ensures the pixel is within the valid screen boundaries (SCREEN_WIDTH and SCREEN_HEIGHT) 
and calculates the appropriate byte in the base memory where the pixel belongs and sets the corresponding bit.
*/
void plot_pixel (UINT8 *base, int x, int y);

/*Function that will clear the screen when called*/
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
