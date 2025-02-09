#include <stdio.h>
#include "raster.h"
#include <osbind.h>

void print_ship_up (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
    int i;  
    int offset;

    offset = (x>>5) + (y*20); 
    
    for (i = 0; i < height; i++)
    {
        *(base + offset + (20*i)) |= bitmap[i];
    }
    return;
}

void print_ship_right (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
    int i;  
    int offset;

    offset = (x>>5) + (y*20); 

    for (i = 0; i < height; i++)
    {
        *(base + offset + (20*i)) |= bitmap[i];
    }
    return;
}

void print_ship_down (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
    int i;  
    int offset;

    offset = (x>>5) + (y*20); 

    for (i = 0; i < height; i++)
    {
        *(base + offset + (20*i)) |= bitmap[i];
    }
    return;
}

void print_ship_left (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
{
    int i;  
    int offset;

    offset = (x>>5) + (y*20); 

    for (i = 0; i < height; i++)
    {
        *(base + offset + (20*i)) |= bitmap[i];
    }
    return;
}



