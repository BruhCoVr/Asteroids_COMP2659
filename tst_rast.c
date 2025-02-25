#include <stdio.h>
#include <osbind.h>

#include "raster.h"
#include "bitmaps.h"
#include "types.h"

#define yield while(!Cconis()){} Cnecin(); /* Yield until a key is pressed */

/* Function prototypes for various test functions */
void test_start(void * base);
void test_plotBitmap8 (void * base);
void test_plotBitmap16 (void * base);
void test_plotBitmap32(void * base);    
void test_plotPixel (void * base);
void test_clearSc (void * base);
void test_blackSc (void * base);
void test_plotHline (void * base);
void test_plotVline (void * base);
void test_plotBitmap (void * base);
void test_plotStars(void * base);

int main(){
    void * base = Physbase(); /* Get the physical base address of the screen */
    
    printf("\033E\033f\n"); /* Clear the screen */
    test_start(base); /* Test start bitmap */
    yield /* Wait for key press */
    test_blackSc(base); /* Test black screen */
    yield /* Wait for key press */
    test_plotStars(base); /* Test plotting stars */
    yield /* Wait for key press */
    test_plotBitmap8(base); /* Test plotting 8-bit bitmap */
    yield /* Wait for key press */
    test_plotBitmap16(base); /* Test plotting 16-bit bitmap */
    yield /* Wait for key press */
    test_plotBitmap_32(base); /* Test plotting 32-bit bitmap */
    yield /* Wait for key press */
    test_plotPixel(base); /* Test plotting a single pixel */
    yield /* Wait for key press */
    test_plotBitmap(base); /* Test plotting various bitmaps */
    yield /* Wait for key press */
    test_clearSc(base); /* Test clearing the screen */
    yield /* Wait for key press */
    test_plotHline(base); /* Test plotting a horizontal line */
    yield /* Wait for key press */
    test_plotVline(base); /* Test plotting a vertical line */
    
    return 0; /* Exit the program */
}

/* Test function to plot an 8-bit bitmap */
void test_plotBitmap8 (void * base){
    plotBitmap8 (base, 200, 200, bullet, 8);
}

/* Test function to plot 16-bit bitmaps */
void test_plotBitmap16 (void * base){
    plotBitmap16 (base, 300, 0, numberSprites[0], 16);
    plotBitmap16 (base, 623, 0, numberSprites[1], 16);
    plotBitmap16 (base, 607, 0, numberSprites[2], 16);
    plotBitmap16 (base, 591, 0, numberSprites[3], 16);
    plotBitmap16 (base, 574, 0, numberSprites[4], 16);
    plotBitmap16 (base, 558, 0, numberSprites[5], 16);
    plotBitmap16 (base, 542, 0, numberSprites[6], 16);
    plotBitmap16 (base, 526, 0, numberSprites[7], 16);
    plotBitmap16 (base, 511, 0, numberSprites[8], 16);
    plotBitmap16 (base, 497, 0, numberSprites[9], 16);
}

/* Test function to plot 32-bit bitmaps */
void test_plotBitmap32(void * base){
    plotBitmap32(base, 200, 320, shipUpBitmap, 32);
    plotBitmap32(base, 234, 320, shipDownBitmap, 32);
    plotBitmap32(base, 266, 320, shipLeftBitmap, 32);
    plotBitmap32(base, 310, 320, shipRightBitmap, 32);
    plotBitmap32(base, 355, 320, shipDiagDownLeftBitmap, 32);
    plotBitmap32(base, 400, 320, shipDiagDownRightBitmap, 32);
    plotBitmap32(base, 440, 320, shipDiagUpLeftBitmap, 32);
    plotBitmap32(base, 480, 320, shipDiagUpRightBitmap, 32);
}

/* Test function to plot the start bitmap */
void test_start (void * base){
    plotBitmap (base, 250, 130, startBitmap[0], 128, 128);
}

/* Test function to plot various bitmaps */
void test_plotBitmap (void * base){
    plotBitmap (base, 400, 128, largeAsteroidBitmap[0], 64, 64);
    plotBitmap (base, 450, 192, mediumAsteroidBitmap[0], 64, 64);
    plotBitmap (base, 500, 256, smallAsteroidBitmap[0], 64, 64);
}

/* Test function to plot a single pixel */
void test_plotPixel (void * base){
    plotPixel (base, 130, 200);
}

/* Test function to clear the screen */
void test_clearSc (void * base){
    clearSc (base);
}

/* Test function to black out the screen */
void test_blackSc (void * base){
    blackSc (base);
}

/* Test function to plot a horizontal line */
void test_plotHline (void * base){
    plotHline (base, 40, 50, 150);
}

/* Test function to plot a vertical line */
void test_plotVline (void * base){
    plotVline (base, 200, 0, 300);
}

/* Test function to plot stars */
void test_plotStars (void * base){
    plotStars (base);
}


