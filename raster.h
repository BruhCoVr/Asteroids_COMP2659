#ifndef RASTER_H
#define RASTER_H

#include <stdio.h>
#include "types.h"

/*
 * Function to plot an 8-bit bitmap on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - height: Height of the bitmap.
 */
void plot_bitmap_8 (UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);

/*
 * Function to plot a 16-bit bitmap on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - height: Height of the bitmap.
 */
void plot_bitmap_16 (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

/*
 * Function to plot a 32-bit bitmap on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - height: Height of the bitmap.
 */
void plot_bitmap_32 (UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);

/*
 * Function to plot a single pixel on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate of the pixel.
 * - y: Y-coordinate of the pixel.
 */
void plot_pixel (UINT8 *base, int x, int y);

/*
 * Function to clear the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 */
void clear_sc (UINT32* base);

/*
 * Function to fill the screen with black color.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 */
void black_sc(UINT32* base);

/*
 * Function to draw a vertical line on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate of the line.
 * - y1: Starting Y-coordinate of the line.
 * - y2: Ending Y-coordinate of the line.
 */
void plot_vline(UINT8 *base, int x, int y1, int y2);

/*
 * Function to draw a horizontal line on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - y: Y-coordinate of the line.
 * - x1: Starting X-coordinate of the line.
 * - x2: Ending X-coordinate of the line.
 */
void plot_hline (UINT8 *base, int y, int x1, int x2);

/*
 * Function to plot a bitmap >=32 on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - width: Width of the bitmap.
 * - height: Height of the bitmap.
 */
void plot_bitmap(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int width, unsigned int height);

/*
 * Function to plot stars on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 */
void plot_stars (void *base);

/*
Function responsible for rendering an asteroid on a display or screen buffer. 
The function draws the asteroid at a specific position with a randomly chosen orientation,
depending on the asteroid's size (large, medium, or small).

Parameters: 
 - base: Pointer to the base address of the screen buffer.
 - asteroid: object of the asteroid struct 
*/
/*void render_asteroid(UINT32 *base, const Asteroid *asteroid);*/

#endif
