#include <stdio.h>
#include "raster.h"
#include <osbind.h>

int main(){

    UINT16 base = Physbase();
    
    print_bitmap(base, 32, 32, ship_bitmap, SHIP_HEIGHT);
    
    return 0;
}