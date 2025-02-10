#include "raster.H"
#include <osbind.h>

void print_bitmap(UINT16 *base, int x, int y,
                  const UINT16 *bitmap, unsigned int height)
{
    int i;
    int offset;
    offset = (x >> 4) + (y * 40); /* 2^4 = 16 and 640 / 16 = 40 */
    for (i = 0; i < height; i++)
        *(base + offset + (40 * i)) ^= bitmap[i];
    return;
}

void clear_sc(UINT32* base){

    int index;
 
    for(index = 0; index < 8000; index++){

        base[index] = 0x0;

    }
};

/*Not done yet*/
void print_score(UINT16 *base, int x, int y, unsigned int height){
    int OnesPlace;
    int TensPlace;
    int HundrethsPlace;
    const UINT16 * NumBitmap = NumberSprites[];

    for(OnesPlace = 0; OnesPlace < 10; OnesPlace++){
         const UINT16 * NumBitmap = NumberSprites[OnesPlace];
          
    }

}

int main() {

    void *base = (void*)Physbase();
    const UINT16 * NumBitmap = NumberSprites;
    int i;

    clear_sc(base);
    print_bitmap(base, 54, 54, ship_bitmap, 32);
    for(i = 0; i < 50; i++){
        print_bitmap(base, 200, i, invader_bitmap, INVADER_HEIGHT);
        Vsync();
        print_bitmap(base, 200, i, invader_bitmap, INVADER_HEIGHT);
    }
    
    /*
    while (1) {
        print_bitmap(base, 32, 32, invader_bitmap, INVADER_HEIGHT);
    }*/

    return 0;
}