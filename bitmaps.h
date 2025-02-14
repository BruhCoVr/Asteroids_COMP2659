#ifndef BITMAPS_H
#define BITMAPS_H

#include "types.h"

/* Bitmap for the ship facing up */
extern const UINT32 ship_up_bitmap[];

/* Bitmap for the ship facing down */
extern const UINT32 ship_down_bitmap[32];

/* Bitmap for the ship facing left */
extern const UINT32 ship_left_bitmap[32];

/* Bitmap for the ship facing right */
extern const UINT32 ship_right_bitmap[32];

/* Bitmap for the ship facing diagonally down-left */
extern const UINT32 ship_diag_down_left_bitmap[32];

/* Bitmap for the ship facing diagonally down-right */
extern const UINT32 ship_diag_down_right_bitmap[32];

/* Bitmap for the ship facing diagonally up-left */
extern const UINT32 ship_diag_up_left_bitmap[32];

/* Bitmap for the ship facing diagonally up-right */
extern const UINT32 ship_diag_up_right_bitmap[32];

/* Bitmaps for the large asteroid in 4 different orientations */
extern const UINT32 largeAsteroid_bitmap[4][32];

/* Bitmaps for the medium asteroid in 4 different orientations */
extern const UINT32 mediumAsteroid_bitmap[4][32];

/* Bitmaps for the small asteroid in 4 different orientations */
extern const UINT32 smallAsteroid_bitmap[4][32];

/* Bitmap for the bullet */
extern const UINT8 bullet[8];

/* Bitmap for the start screen */
extern const UINT32 start_bitmap[16][32];

/* Bitmaps for the number sprites, indexed by TotalNumbers */
extern const UINT16 NumberSprites[TotalNumbers][16];

#endif