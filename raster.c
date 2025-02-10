#include "raster.H"
#include <osbind.h>


/*Enum list that hold all of the number bitmaps
and will be used to easily access the bitmaps*/
const UINT16 NumberSprites[10][16] = {
    /*Number 0*/
    {0x1FF8, 0x3FFC, 0x7FFE, 0x781E,
     0x781E, 0x781E, 0x781E, 0x781E,
     0x781E, 0x781E, 0x781E, 0x781E,
     0x781E, 0x7FFE, 0x3FFC, 0x1FF8},

    /*Number 1*/
    {0x03C0, 0x07C0, 0x0FC0, 0x1FC0,
     0x03C0, 0x03C0, 0x03C0, 0x03C0,
     0x03C0, 0x03C0, 0x03C0, 0x03C0,
     0x03C0, 0x03C0, 0xFFFC, 0xFFFC},

    /*Number 2*/
    {0x1FF8, 0x3FFC, 0x7FFE, 0x7FFE,
     0x781E, 0x701E, 0x003E, 0x00FC,
     0x01F8, 0x03F0, 0x07E0, 0x07C0,
     0x0F80, 0x1FF8, 0x3FFC, 0x7FFE},

    /*Number 3*/
    {0x3FFC, 0xFFFC, 0xFFFC, 0x001E,
     0x001E, 0x001E, 0x3FFC, 0xFFFC,
     0xFFFC, 0x3FFC, 0x001E, 0x001E,
     0x001E, 0xFFFC, 0xFFFC, 0x3FFC},

    /*Number 4*/
    {0x380E, 0x380E, 0x380E, 0x380E,
     0x380E, 0x380E, 0x3FFE, 0x3FFE,
     0x3FFE, 0x1FFE, 0x001E, 0x001E,
     0x001E, 0x001E, 0x001E, 0x001E},

    /*Number 5*/
    {0x0000, 0x1FF8, 0x3FFC, 0x3FFC,
     0x3800, 0x3800, 0x3800, 0x3FF8,
     0x3FFC, 0x1FFC, 0x001C, 0x001C,
     0x001C, 0x1FFC, 0x3FFC, 0x3FF8},

    /*Number 6*/
    {0x0000, 0x1FF8, 0x3FFC, 0x3FF8,
     0x3C00, 0x3C00, 0x3C00, 0x3C00,
     0x3FF8, 0x3FFC, 0x3C1C, 0x3C1C,
     0x3C1C, 0x3C1C, 0x3FFC, 0x1FF8},

    /*Number 7*/
    {0x0000, 0x3FFC, 0x7FFE, 0x3FFE,
     0x001E, 0x001E, 0x001E, 0x001E,
     0x001E, 0x001E, 0x001E, 0x001E,
     0x001E, 0x001E, 0x001E, 0x001E},

    /*Number 8*/
    {0x0FF0, 0x1FF8, 0x381C, 0x381C,
     0x381C, 0x381C, 0x1FF8, 0x0FF0,
     0x1FF8, 0x381C, 0x381C, 0x381C,
     0x381C, 0x381C, 0x1FF8, 0x0FF0},

    /*Number 9*/
    {0x1FF8, 0x3FFC, 0x3C3C, 0x3C3C,
     0x3C3C, 0x3C3C, 0x3FFC, 0x3FFC,
     0x1FFC, 0x003C, 0x003C, 0x003C,
     0x003C, 0x1FFC, 0x3FFC, 0x3FFC}
};

unsigned char bullet[BULLET_HEIGHT] = 
    {
    0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF
    };

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
/*Function that will */
void print_score(UINT16 *base, int x, int y, unsigned int height){
    int OnesPlace;
    int TensPlace;
    int HundrethsPlace;
    const UINT16 * NumBitmap = NumberSprites[];

    for(OnesPlace = 0; OnesPlace < 10; OnesPlace++){
         const UINT16 * NumBitmap = NumberSprites[OnesPlace];
          
    }

}

