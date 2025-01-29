#include "BITMAP_S.H"
#include <osbind.h>

void print_bitmap(UINT16 *base, int x, int y,
                  const UINT16 *bitmap, unsigned int height)
{
    int i;
    int offset;
    offset = (x >> 4) + (y * 40); /* 2^4 = 16 and 640 / 16 = 40 */
    for (i = 0; i < height; i++)
        *(base + offset + (40 * i)) |= bitmap[i];
    return;
}

int main() {

    char *base = (char*)Physbase();

    while (1) {
        print_bitmap(base, 32, 32, invader_bitmap, INVADER_HEIGHT);
    }

    return 0;
}
