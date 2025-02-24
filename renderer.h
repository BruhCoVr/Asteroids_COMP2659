#ifndef RENDERER_H
#define RENDERER_H

#include "model.h"
#include "types.h"
#include "bitmaps.h"

/* 
 * Renders a complete frame based on the current game model.
 * 'model' is a snapshot of the game state.
 * 'base' is a pointer to the frame buffer into which plotting is done.
 */
void render(const Model *model, UINT32 *base);

/* Renders the ship using the appropriate bitmap for its angle. */
void render_ship(const Ship *ship, UINT32 *base);

/* Renders an active missile using the bullet bitmap. */
void render_missile(const Missile *missile, UINT32 *base);

/* Renders an active asteroid based on its size. */
void render_asteroid(const Asteroid *asteroid, UINT32 *base);

/* Renders the scoreboard (score and lives) in a fixed location. */
void render_scoreboard(const Scoreboard *scoreboard, UINT32 *base);

#endif /* RENDERER_H */
