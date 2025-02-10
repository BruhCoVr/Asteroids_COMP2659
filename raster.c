#include "raster.h"
#include <osbind.h>
#include <stdint.h> // For uint8_t (UINT8)

#define SOLID 0xFF
#define BITS_IN_BYTE 8
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define BYTES_PER_ROW (SCREEN_WIDTH / BITS_IN_BYTE) // 80 bytes per row

unsigned long largeAsteroid_bitmap[32] = 
    {
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00400800L,0x00A01400L,0x01106200L,
        0x02088100L,0x04070080L,0x04000100L,0x04000200L,
        0x04000200L,0x04000100L,0x08000080L,0x04000040L,
        0x02000080L,0x01000100L,0x00800200L,0x00400400L,
        0x00230800L,0x00149000L,0x00086000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
    };

unsigned long mediumAsteroid_bitmap[32] = 
    {
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x000F8000L,0x0070F800L,0x00C00C00L,0x01000600L,
        0x01000200L,0x01000200L,0x01000200L,0x01000200L,
        0x01800200L,0x00F80600L,0x00181800L,0x000E3000L,
        0x0003C000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
    };

unsigned long smallAsteroid_bitmap[32] = 
    {
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00100000L,
        0x003C0000L,0x00278000L,0x0042E000L,0x00C03000L,
        0x00801800L,0x00883800L,0x00F4E000L,0x00038000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
        0x00000000L,0x00000000L,0x00000000L,0x00000000L,
    };


/*Enum list that hold all of the number bitmaps
and will be used to easily access the bitmaps*/
const UINT16 NumberSprites[TotalNumbers][16] = {
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

unsigned int bullet[BULLET_HEIGHT] = 
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
/*Function that will ... */
void print_score(const UINT16 *bitmap, int score){
    int OnesPlace;
    int TensPlace;
    int HundrethsPlace;
    const UINT16 * NumBitmap = NumberSprites[];
    int new_score;

    if(new_score < score){
    for(OnesPlace = 0; OnesPlace < 10; OnesPlace++){
         const UINT16 * NumBitmap = NumberSprites[OnesPlace];
          
    }
    }
}

/*
This function draws a horizontal line on a monochrome (1-bit-per-pixel),
display using a byte array (uint8_t *base) as the screen buffer. 
It sets pixels to "on" (1) within a given row (y) from x1 to x2.
*/
void plot_hline(uint8_t *base, int y, int x1, int x2) {
    // Check for invalid input
    if (base == NULL || y < 0 || y >= SCREEN_HEIGHT || x1 < 0 || x2 < 0 || x1 >= SCREEN_WIDTH || x2 >= SCREEN_WIDTH) {
        return; // Exit if base is NULL or coordinates are out of bounds
    }

    // Ensure x1 <= x2
    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }

    // Calculate starting and ending bytes
    int row1 = x1 / BITS_IN_BYTE;
    int row2 = x2 / BITS_IN_BYTE;

    // Calculate bit positions within the bytes
    int shift_F = x1 % BITS_IN_BYTE;
    int shift_B = (BITS_IN_BYTE - 1) - (x2 % BITS_IN_BYTE);

    // Pointer to the start of the row
    uint8_t *place = base + y * BYTES_PER_ROW;

    // Draw the line
    if (row1 == row2) {
        // Line fits within a single byte
        uint8_t mask = (SOLID >> shift_F) & (SOLID << shift_B);
        *(place + row1) |= mask;
    } else {
        // Line spans multiple bytes
        *(place + row1) |= (SOLID >> shift_F); // First byte
        for (int i = row1 + 1; i < row2; i++) {
            *(place + i) = SOLID; // Middle bytes
        }
        *(place + row2) |= (SOLID << shift_B); // Last byte
    }
}

/*
The function draws a vertical line at a specific x coordinate, 
between two y coordinates (y1 and y2),on a screen with a resolution of 640x400 pixels.
The line is drawn by manipulating bits in the screen buffer.
*/
void plot_vline(uint8_t *base, int x, int y1, int y2) {
    // Check if x is within the screen bounds (0 to 639)
    if (x < 0 || x >= 640) {
        return; // Exit if x is out of bounds
    }

    // Swap y1 and y2 if y1 > y2
    if (y1 > y2) {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }

    // Clamp y1 and y2 to the screen bounds (0 to 399)
    if (y1 < 0) y1 = 0;
    if (y2 >= 400) y2 = 399;

    // Calculate the bitmask for the x coordinate
    uint8_t pattern = 1 << (7 - (x & 7));

    // Calculate the starting byte in the screen buffer
    uint8_t *screen_byte = base + y1 * 80 + (x >> 3);

    // Draw the vertical line
    for (; y1 <= y2; y1++) {
        *screen_byte |= pattern; // Set the pixel
        screen_byte += 80; // Move to the next row (640 pixels / 8 bits per byte = 80 bytes per row)
    }

}

