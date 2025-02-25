#ifndef BITMAPS_H
#define BITMAPS_H

#include "types.h"

/* Bitmap for the ship facing up */
extern const UINT32 shipUpBitmap[];

/* Bitmap for the ship facing down */
extern const UINT32 shipDownBitmap[32];

/* Bitmap for the ship facing left */
extern const UINT32 shipLeftBitmap[32];

/* Bitmap for the ship facing right */
extern const UINT32 shipRightBitmap[32];

/* Bitmap for the ship facing diagonally down-left */
extern const UINT32 shipDiagDownLeftBitmap[32];

/* Bitmap for the ship facing diagonally down-right */
extern const UINT32 shipDiagDownRightBitmap[32];

/* Bitmap for the ship facing diagonally up-left */
extern const UINT32 shipDiagUpLeftBitmap[32];

/* Bitmap for the ship facing diagonally up-right */
extern const UINT32 shipDiagUpRightBitmap[32];

/* Bitmaps for the large asteroid in 4 different orientations */
extern const UINT32 largeAsteroidBitmap[4][32];

/* Bitmaps for the medium asteroid in 4 different orientations */
extern const UINT32 mediumAsteroidBitmap[4][32];

/* Bitmaps for the small asteroid in 4 different orientations */
extern const UINT32 smallAsteroidBitmap[4][32];

/* Bitmap for the bullet */
extern const UINT8 bullet[8];

/* Bitmap for the start screen */
extern const UINT32 startBitmap[16][32];

/* Bitmaps for the number sprites, indexed by totalNumbers */
extern const UINT16 numberSprites[totalNumbers][16];

#endif