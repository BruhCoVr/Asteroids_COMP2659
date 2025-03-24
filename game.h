#ifndef GAME_H
#define GAME_H

#include <osbind.h>
#include <stdlib.h>
#include "model.h"
#include "renderer.h"
#include "input.h"
#include "raster.h"

/* Screen dimensions */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/* Frame rate (70 Hz for TOS) */
#define FRAME_RATE 70

/* Function to initialize the game */
void InitializegGame(Model *model);

UINT32 GetTime();

/* Main game loop */
void RunGame();

/* Function to swap buffers */
void swapBuffers(void **active, void **inactive);

#endif /* GAME_H */