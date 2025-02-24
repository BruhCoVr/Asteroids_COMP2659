#include <stdio.h>
#include <osbind.h>

#include "raster.h"
#include "bitmaps.h"
#include "types.h"

#define yield while(!Cconis()){} Cnecin(); /* Yield until a key is pressed */

/* Function prototypes for various test functions */
void test_start(void * base);
void test_plot_bitmap_8 (void * base);
void test_plot_bitmap_16 (void * base);
void test_plot_bitmap_32 (void * base);    
void test_plot_pixel (void * base);
void test_clear_sc (void * base);
void test_black_sc (void * base);
void test_plot_hline (void * base);
void test_plot_vline (void * base);
void test_plot_bitmap (void * base);
void test_plot_stars(void * base);

int main(){
    void * base = Physbase(); /* Get the physical base address of the screen */
    
    printf("\033E\033f\n"); /* Clear the screen */
    test_start(base); /* Test start bitmap */
    yield /* Wait for key press */
    test_black_sc(base); /* Test black screen */
    yield /* Wait for key press */
    test_plot_stars(base); /* Test plotting stars */
    yield /* Wait for key press */
    test_plot_bitmap_8(base); /* Test plotting 8-bit bitmap */
    yield /* Wait for key press */
    test_plot_bitmap_16(base); /* Test plotting 16-bit bitmap */
    yield /* Wait for key press */
    test_plot_bitmap_32(base); /* Test plotting 32-bit bitmap */
    yield /* Wait for key press */
    test_plot_pixel(base); /* Test plotting a single pixel */
    yield /* Wait for key press */
    test_plot_bitmap(base); /* Test plotting various bitmaps */
    yield /* Wait for key press */
    test_clear_sc(base); /* Test clearing the screen */
    yield /* Wait for key press */
    test_plot_hline(base); /* Test plotting a horizontal line */
    yield /* Wait for key press */
    test_plot_vline(base); /* Test plotting a vertical line */
    
    return 0; /* Exit the program */
}

/* Test function to plot an 8-bit bitmap */
void test_plot_bitmap_8 (void * base){
    plot_bitmap_8 (base, 200, 200, bullet, 8);
}

/* Test function to plot 16-bit bitmaps */
void test_plot_bitmap_16 (void * base){
    plot_bitmap_16 (base, 300, 0, numberSprites[0], 16);
    plot_bitmap_16 (base, 623, 0, numberSprites[1], 16);
    plot_bitmap_16 (base, 607, 0, numberSprites[2], 16);
    plot_bitmap_16 (base, 591, 0, numberSprites[3], 16);
    plot_bitmap_16 (base, 574, 0, numberSprites[4], 16);
    plot_bitmap_16 (base, 558, 0, numberSprites[5], 16);
    plot_bitmap_16 (base, 542, 0, numberSprites[6], 16);
    plot_bitmap_16 (base, 526, 0, numberSprites[7], 16);
    plot_bitmap_16 (base, 511, 0, numberSprites[8], 16);
    plot_bitmap_16 (base, 497, 0, numberSprites[9], 16);
}

/* Test function to plot 32-bit bitmaps */
void test_plot_bitmap_32 (void * base){
    plot_bitmap_32 (base, 200, 320, shipUpBitmap, 32);
    plot_bitmap_32 (base, 234, 320, shipDownBitmap, 32);
    plot_bitmap_32 (base, 266, 320, shipLeftBitmap, 32);
    plot_bitmap_32 (base, 310, 320, shipRightBitmap, 32);
    plot_bitmap_32 (base, 355, 320, shipDiagDownLeftBitmap, 32);
    plot_bitmap_32 (base, 400, 320, shipDiagDownRightBitmap, 32);
    plot_bitmap_32 (base, 440, 320, shipDiagUpLeftBitmap, 32);
    plot_bitmap_32 (base, 480, 320, shipDiagUpRightBitmap, 32);
}

/* Test function to plot the start bitmap */
void test_start (void * base){
    plot_bitmap (base, 250, 130, startBitmap[0], 128, 128);
}

/* Test function to plot various bitmaps */
void test_plot_bitmap (void * base){
    plot_bitmap (base, 400, 128, largeAsteroidBitmap[0], 64, 64);
    plot_bitmap (base, 450, 192, mediumAsteroidBitmap[0], 64, 64);
    plot_bitmap (base, 500, 256, smallAsteroidBitmap[0], 64, 64);
}

/* Test function to plot a single pixel */
void test_plot_pixel (void * base){
    plot_pixel (base, 130, 200);
}

/* Test function to clear the screen */
void test_clear_sc (void * base){
    clear_sc (base);
}

/* Test function to black out the screen */
void test_black_sc (void * base){
    black_sc (base);
}

/* Test function to plot a horizontal line */
void test_plot_hline (void * base){
    plot_hline (base, 40, 50, 150);
}

/* Test function to plot a vertical line */
void test_plot_vline (void * base){
    plot_vline (base, 200, 0, 300);
}

/* Test function to plot stars */
void test_plot_stars (void * base){
    plot_stars (base);
}


