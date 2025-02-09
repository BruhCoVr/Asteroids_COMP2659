#include <stdio.h>
#include "raster.h"
#include <osbind.h>

#define SHIP 32

int main(){


    UINT16 *base = Physbase();
   
        print_ship_right(base, 32,32, ship_right_bitmap, 32);
        print_ship_left(base, 64,32, ship_left_bitmap, 32);
        print_ship_down(base, 96,32, ship_down_bitmap, 32);
    return 0;
}