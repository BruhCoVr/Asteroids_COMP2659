#include <stdio.h>
#include <osbind.h>

#include "raster.h"
#include "bitmaps.h"
#include "types.h"

#define yield while(!Cconis()){} Cnecin(); /* Yield until a key is pressed */

/* Function prototypes for various test functions */
void testStart(void * base);
void testPlotBitmap8 (void * base);
void testPlotBitmap16 (void * base);
void testPlotBitmap32(void * base);    
void testPlotPixel (void * base);
void testClearSc (void * base);
void testBlackSc (void * base);
void testPlotHline (void * base);
void testPlotVline (void * base);
void testPlotBitmap (void * base);
void testPlotStars(void * base);

int main(){
    void * base = Physbase(); /* Get the physical base address of the screen */
    
    printf("\033E\033f\n"); /* Clear the screen */
    testStart(base); /* Test start bitmap */
    yield /* Wait for key press */
    testBlackSc(base); /* Test black screen */
    yield /* Wait for key press */
    testPlotStars(base); /* Test plotting stars */
    yield /* Wait for key press */
    testPlotBitmap8(base); /* Test plotting 8-bit bitmap */
    yield /* Wait for key press */
    testPlotBitmap16(base); /* Test plotting 16-bit bitmap */
    yield /* Wait for key press */
    testPlotBitmap32(base); /* Test plotting 32-bit bitmap */
    yield /* Wait for key press */
    testPlotPixel(base); /* Test plotting a single pixel */
    yield /* Wait for key press */
    testPlotBitmap(base); /* Test plotting various bitmaps */
    yield /* Wait for key press */
    testClearSc(base); /* Test clearing the screen */
    yield /* Wait for key press */
    testPlotHline(base); /* Test plotting a horizontal line */
    yield /* Wait for key press */
    testPlotVline(base); /* Test plotting a vertical line */
    
    return 0; /* Exit the program */
}

/* Test function to plot an 8-bit bitmap */
void testPlotBitmap8 (void * base){
    plotBitmap8 (base, 200, 200, bullet, 8);
}

/* Test function to plot 16-bit bitmaps */
void testPlotBitmap16 (void * base){
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
void testPlotBitmap32(void * base){
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
void testStart (void * base){
    plotBitmap (base, 250, 130, startBitmap[0], 128, 128);
}

/* Test function to plot various bitmaps */
void testPlotBitmap (void * base){
    plotBitmap (base, 400, 128, largeAsteroidBitmap[0], 64, 64);
    plotBitmap (base, 450, 192, mediumAsteroidBitmap[0], 64, 64);
    plotBitmap (base, 500, 256, smallAsteroidBitmap[0], 64, 64);
}

/* Test function to plot a single pixel */
void testPlotPixel (void * base){
    plotPixel (base, 130, 200);
}

/* Test function to clear the screen */
void testClearSc (void * base){
    clearSc (base);
}

/* Test function to black out the screen */
void testBlackSc (void * base){
    blackSc (base);
}

/* Test function to plot a horizontal line */
void testPlotHline (void * base){
    plotHline (base, 40, 50, 150);
}

/* Test function to plot a vertical line */
void testPlotVline (void * base){
    plotVline (base, 200, 0, 300);
}

/* Test function to plot stars */
void testPlotStars (void * base){
    plotStars (base);
}


