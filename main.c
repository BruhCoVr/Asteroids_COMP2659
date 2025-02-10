#include <stdio.h>
#include "raster.h"
#include <osbind.h>

#define SHIP 32

int main(){

    UINT8 *base8 = Physbase();
    UINT16 *base16 = Physbase();
    UINT32 *base32 = Physbase();

    plot_bitmap_8(base8, 100, 130, bullet,8);
    plot_bitmap_32(base32, 100, 100, ship_up_bitmap,32);
    plot_bitmap_32(base32, 150, 100, ship_down_bitmap,32);
    plot_bitmap_32(base32, 200, 200, ship_left_bitmap,32);
    plot_bitmap_32(base32, 250, 250, ship_right_bitmap,32);
    plot_bitmap_32(base32, 300, 300, ship_diag_down_left_bitmap,32);
    plot_bitmap_32(base32, 400, 350, ship_diag_down_right_bitmap,32);
    plot_bitmap_32(base32, 350, 300, ship_diag_up_left_bitmap,32);
    plot_bitmap_32(base32, 450, 350, ship_diag_up_right_bitmap,32);
    plot_bitmap_32(base32, 500, 250, largeAsteroid_bitmap,32);
    plot_bitmap_32(base32, 550, 200, mediumAsteroid_bitmap,32);
    plot_bitmap_32(base32, 600, 300, smallAsteroid_bitmap,32);
    return 0;
}