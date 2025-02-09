#ifndef RASTER_H
#include <stdio.h>
#include <osbind.h>

#define RASTER_H
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define SHIP_HEIGHT 32
#define SOLID 0xFF
#define BITS_IN_BYTE 8
#define BYTES_PER_ROW (SCREEN_WIDTH / BITS_IN_BYTE) // 80 bytes per row
typedef unsigned int UINT16;

int ship_bitmap[SHIP_HEIGHT] = {
    0xFFFE7FFF,
    0xFFFC3FFF,
    0xFFF81FFF,
    0xFFF81FFF,
    0xFFF00FFF,
    0xFFF00FFF,
    0xFFE007FF,
    0xFFE007FF,
    0xFFC003FF,
    0xFFC183FF,
    0xFF8181FF,
    0xFF83C1FF,
    0xFF03C0FF,
    0xFF07E0FF,
    0xFE07E07F,
    0xFE07E07F,
    0xFC0FF03F,
    0xFC0FF03F,
    0xFC1FF83F,
    0xF81FF81F,
    0xF83FFC1F,
    0xF03FFC0F,
    0xF07FFE0F,
    0xE07FFE07,
    0xE0FFFF07,
    0xC0FFFF03,
    0xC1FFFF83,
    0x81FFFF81,
    0x80000001,
    0x00000000,
    0x00000000,
    0x00000000
};
void print_bitmap(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);

#endif 