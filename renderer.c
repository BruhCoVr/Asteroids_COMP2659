#include "renderer.h"
#include "bitmaps.h"
#include "raster.h"
#include "types.h"
#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Helper: Selects the correct ship bitmap based on its angle.
 * We assume eight directions:
 *   - Right: [337.5,360) U [0,22.5)
 *   - Diag Up-Right: [22.5,67.5)
 *   - Up: [67.5,112.5)
 *   - Diag Up-Left: [112.5,157.5)
 *   - Left: [157.5,202.5)
 *   - Diag Down-Left: [202.5,247.5)
 *   - Down: [247.5,292.5)
 *   - Diag Down-Right: [292.5,337.5)
 */
static const UINT32 *get_ship_bitmap(int angle) {
    /* Normalize angle to [0, 360) */
    if (angle < 0)
        angle = (angle % 360 + 360) % 360;
    if ((angle >= 337.5) || (angle < 22.5))
        return shipRightBitmap;
    else if (angle < 67.5)
        return shipDiagUpRightBitmap;
    else if (angle < 112.5)
        return shipUpBitmap;
    else if (angle < 157.5)
        return shipDiagUpLeftBitmap;
    else if (angle < 202.5)
        return shipLeftBitmap;
    else if (angle < 247.5)
        return shipDiagDownLeftBitmap;
    else if (angle < 292.5)
        return shipDownBitmap;
    else /* angle < 337.5 */
        return shipDiagDownRightBitmap;
}

/* Renders the ship at its current position and orientation. */
void render_ship(const Ship *ship, UINT32 *base) {
    const UINT32 *ship_bitmap = get_ship_bitmap(ship->angle);
    /* Plot a 32-row bitmap at the ship's (x,y) position. */
    plot_bitmap_32(base, ship->pos.x, ship->pos.y, ship_bitmap, 32);
}

/* Renders an active missile using the bullet bitmap.
   The bullet is an 8x8 8-bit bitmap.
*/
void render_missile(const Missile *missile, UINT32 *base) {
    if (!missile->active)
        return;
    plot_bitmap_8((UINT8 *)base, missile->pos.x, missile->pos.y, bullet, 8);
}

/* Renders an active asteroid. 
   Chooses the appropriate bitmap (first orientation is used) based on asteroid size.
*/
void render_asteroid(const Asteroid *asteroid, UINT32 *base) {
    const UINT32 *asteroid_bitmap = NULL;

    if (!asteroid->active)
        return;
    
    switch (asteroid->size) {
        case ASTEROID_LARGE:
            asteroid_bitmap = largeAsteroidBitmap[0];
            break;
        case ASTEROID_MEDIUM:
            asteroid_bitmap = mediumAsteroidBitmap[0];
            break;
        case ASTEROID_SMALL:
            asteroid_bitmap = smallAsteroidBitmap[0];
            break;
        default:
            return;
    }
    plot_bitmap(base, asteroid->pos.x, asteroid->pos.y, asteroid_bitmap, 64, 64);
}

/* 
 * Helper: Renders a single digit (0-9) using the numberSprites bitmap.
 * Each digit bitmap is 16 rows tall.
 */
static void render_digit(int digit, int x, int y, UINT32 *base) {
    if (digit < 0 || digit > 9)
        return;
    plot_bitmap_16((UINT16 *)base, x, y, numberSprites[digit], 16);
}

/* 
 * Renders the scoreboard by drawing the score and number of lives.
 * For simplicity, this implementation renders only the numeric values.
 */
void render_scoreboard(const Scoreboard *scoreboard, UINT32 *base) {
    char score_str[12];
    int len;
    int x;
    int y;
    int i;  /* Declare loop variable at the top */
    char lives_str[12];

    /* Convert score to a string */
    sprintf(score_str, "%d", scoreboard->score);
    len = (int)strlen(score_str);
    x = 10;  /* Starting x-coordinate for score */
    y = 10;  /* y-coordinate for score display */
    for (i = 0; i < len; i++) {
        int d = score_str[i] - '0';
        render_digit(d, x, y, base);
        x += 16;  /* Advance by the digit width */
    }
    
    sprintf(lives_str, "%d", scoreboard->lives);
    len = (int)strlen(lives_str);
    x = 600;  /* Starting x-coordinate for lives (adjust as needed) */
    y = 10;
    for (i = 0; i < len; i++) {
        int d = lives_str[i] - '0';
        render_digit(d, x, y, base);
        x += 16;
    }
}

/* 
 * Master render function.
 * Clears the screen and then renders the ship, missiles, asteroids, and scoreboard.
 */
void render(const Model *model, UINT32 *base) {
    int i = 0;
    /* Clear the screen. */
    clear_sc(base);
    
    /*sets up black screen for stars*/
    black_sc(base);

    /*plots stars*/
    plot_stars((void *)base); 
    
    /* Render game objects: */
    render_ship(&model->ship, base);
    
    for (i = 0; i < MAX_MISSILES; i++) {
        render_missile(&model->missiles[i], base);
    }
    
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        render_asteroid(&model->asteroids[i], base);
    }
    
    /* Render the scoreboard (score and lives). */
    render_scoreboard(&model->scoreboard, base);
}
