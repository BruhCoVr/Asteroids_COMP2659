#include "raster.h"
#include <osbind.h>
#include <stdlib.h>
#include <time.h>

#define SOLID 0xFF
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define SHIP_HEIGHT 32
#define BITS_IN_BYTE 8
#define BYTES_PER_ROW (SCREEN_WIDTH / BITS_IN_BYTE)
#define NUM_HEIGHT 16
#define NUM_HEIGHT_2 32

/*
 * Function to plot an 8-bit bitmap on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - height: Height of the bitmap.
 */
void plot_bitmap_8 (UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height)
{
    int i;  
    int offset;
    int image_shift_left = x & 7; /* Calculate the left shift amount */
    int image_shift_right = 8 - image_shift_left; /* Calculate the right shift amount */

    offset = (x >> 3) + (y * 80); /* Calculate the offset in the screen buffer */
    for (i = 0; i < height; i++)
    {
        *(base + offset + (80 * i)) ^= bitmap[i] >> image_shift_left; /* Plot the bitmap with left shift */
        if (image_shift_left > 0)
        {
            *(base + offset + 1 + (80 * i)) ^= bitmap[i] << image_shift_right; /* Plot the bitmap with right shift if needed */
        }
    }
    return;
}

/*
 * Function to plot a 16-bit bitmap on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - height: Height of the bitmap.
 */
void plot_bitmap_16 (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
    int i;  
    int offset;
    int image_shift_left = x & 15; /* Calculate the left shift amount */
    int image_shift_right = 16 - image_shift_left; /* Calculate the right shift amount */

    offset = (x >> 4) + (y * 40); /* Calculate the offset in the screen buffer */
    
    for (i = 0; i < height; i++)
    {
        *(base + offset + (40 * i)) ^= bitmap[i] >> image_shift_left; /* Plot the bitmap with left shift */
        if (image_shift_left > 0)
        {
            *(base + offset + 1 + (40 * i)) ^= bitmap[i] << image_shift_right; /* Plot the bitmap with right shift if needed */
        }
    }
    return;
}

/*
 * Function to plot a 32-bit bitmap on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - height: Height of the bitmap.
 */
void plot_bitmap_32 (UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height)
{
    int i;  
    int offset;
    int image_shift_left = x & 31; /* Calculate the left shift amount */
    int image_shift_right = 32 - image_shift_left; /* Calculate the right shift amount */

    offset = (x >> 5) + (y * 20); /* Calculate the offset in the screen buffer */
    
    for (i = 0; i < height; i++)
    {
        *(base + offset + (20 * i)) ^= bitmap[i] >> image_shift_left; /* Plot the bitmap with left shift */
        if (image_shift_left > 0)
        {
            *(base + offset + 1 + (20 * i)) ^= bitmap[i] << image_shift_right; /* Plot the bitmap with right shift if needed */
        } 
    }
    return;
}

/*
 * Function to clear the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 */
void clear_sc(UINT32* base)
{
    int index;
 
    for(index = 0; index < 8000; index++)
    {
        base[index] = 0x0; /* Set each pixel to 0 (clear the screen) */
    }
}

/*
 * Function to fill the screen with black color.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 */
void black_sc(UINT32* base)
{
    int index;
 
    for(index = 0; index < 8000; index++)
    {
        base[index] = 0xFFFFFFFFL; /* Set each pixel to 1 (fill the screen with black) */
    }
}

/*
 * Function to plot a single pixel on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate of the pixel.
 * - y: Y-coordinate of the pixel.
 */
void plot_pixel(UINT8 *base, int x, int y)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
    {
        *(base + y * 80 + (x >> 3)) ^= 1 << (7 - (x & 7)); /* Plot the pixel by setting the corresponding bit */
    }
}

/*
 * Function to draw a vertical line on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate of the line.
 * - y1: Starting Y-coordinate of the line.
 * - y2: Ending Y-coordinate of the line.
 */
void plot_vline(UINT8 *base, int x, int y1, int y2)
{
    int temp;
    if (x >= 0 && x < 640)
    {
        if (y1 > y2)
        {
            temp = y1;
            y1 = y2;
            y2 = temp; /* Swap y1 and y2 if y1 is greater than y2 */
        }
        if (y1 < 0) 
        {
            y1 = 0; /* Ensure y1 is within bounds */
        }
        if (y2 > 399) 
        {
            y2 = 399; /* Ensure y2 is within bounds */
        }  
        for ( ; y1 <= y2; y1++)
        {
            plot_pixel(base, x, y1); /* Plot each pixel along the vertical line */
        }
    }
    return;
}

/*
 * Function to draw a horizontal line on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - y: Y-coordinate of the line.
 * - x1: Starting X-coordinate of the line.
 * - x2: Ending X-coordinate of the line.
 */
void plot_hline (UINT8 *base, int y, int x1, int x2)
{
    UINT8 p1, p2;
    int row1, row2, i;
    int shift_F, shift_B;
    UINT8 *place = base + y * 80;

    row1 = x1 / BITS_IN_BYTE; /* Calculate the starting byte */
    row2 = x2 / BITS_IN_BYTE; /* Calculate the ending byte */
    shift_F = x1 % BITS_IN_BYTE; /* Calculate the forward shift amount */
    shift_B = (BITS_IN_BYTE - 1) - (x2 % BITS_IN_BYTE); /* Calculate the backward shift amount */
    if (row1 == row2)
    {
        p1 = SOLID >> shift_F;
        p2 = SOLID << shift_B;
        *(place + row1) = p1 & p2; /* Plot the line within a single byte */
    }
    else
    {
        p1 = SOLID >> shift_F;
        p2 = SOLID << shift_B;
        *(place + row1) = p1; /* Plot the starting byte */
        for (i = row1 + 1; i < row2; i++)
        {
            *(place + i) = SOLID; /* Plot the full bytes in between */
        }
        *(place + row2) = p2; /* Plot the ending byte */
    }
    return;
}

/*
 * Function to plot a bitmap on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 * - x: X-coordinate where the bitmap should be plotted.
 * - y: Y-coordinate where the bitmap should be plotted.
 * - bitmap: Pointer to the bitmap data.
 * - width: Width of the bitmap.
 * - height: Height of the bitmap.
 */
void plot_bitmap(UINT32 * base, int x, int y, const UINT32 *bitmap, unsigned int width, unsigned int height)
{
    int i, j;
    int offset;
    int word_offset = x >> 5; /* Calculate the word offset */
    int bit_offset = x & 31;  /* Calculate the bit offset */
    int counter = 0;
    for (i = 0; i < height; i++)
    {
        offset = word_offset + (y + i) * 20; /* Calculate the offset in the screen buffer */
        for (j = 0; j < (width + 31) / 32; j++) 
        {
            UINT32 shifted_bitmap = bitmap[counter] >> bit_offset;
            *(base + offset + j) ^= shifted_bitmap; /* Plot the bitmap with left shift */

            if (bit_offset > 0) /* && j + 1 < (width % 32)*/
            {
                UINT32 overflow_bits = bitmap[counter] << (32 - bit_offset);
                *(base + offset + j + 1) ^= overflow_bits; /* Plot the bitmap with right shift if needed */
            }
            counter++;
        }
    }
    return;
}

/*
 * Function to plot random stars on the screen.
 * Parameters:
 * - base: Pointer to the base address of the screen buffer.
 */
void plot_stars (void *base){
    int i;
    srand((unsigned) time(NULL)); /* Seed the random number generator with the current time */
    for (i=0; i<1000; i++){
        plot_pixel(base, rand()%640, rand()%400); /* Plot a pixel at a random (x, y) coordinate */
    }
}

