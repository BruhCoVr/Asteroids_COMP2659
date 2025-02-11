#include <stdio.h>
#include "raster.h"
#include <osbind.h>
#include <stdlib.h>

#define SHIP 32

int main(){

    UINT8 *base8 = Physbase();
    UINT16 *base16 = Physbase();
    UINT32 *base32 = Physbase();
    int i;
    srand((unsigned) time(NULL));
    
    black_sc(base32);
    plot_bitmap(base32, 200,100,start_bitmap,128,128);
    plot_bitmap_32(base32, 300, 200, ship_down_bitmap, 32);
    plot_bitmap_8(base8, 312, 250, bullet, 8);
    plot_bitmap_8(base8, 312, 300, bullet, 8);
    plot_bitmap_8(base8, 312, 350, bullet, 8);

    for (i=0; i<1000; i++){
        plot_pixel(base8, rand()%640, rand()%400);
    }
  

    return 0;
}