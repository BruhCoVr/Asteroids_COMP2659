#include <osbind.h>
#include <stdlib.h>
#include "game.h"
#include "model.h"
#include "renderer.h"
#include "input.h"
#include "raster.h"
#include "events.h"

void InitializegGame(Model *model) {
    
    /* Spawn some asteroids */
    Position asteroid_pos1 = {100, 100};
    Position asteroid_pos2 = {500, 300};

    /* Initialize the model with default values */
    initModel(model); 
   
    initAsteroid(&model->asteroids[0], asteroid_pos1, 1, 1, ASTEROID_LARGE);
    initAsteroid(&model->asteroids[1], asteroid_pos2, -1, 1, ASTEROID_MEDIUM);
}

UINT32 GetTime() {
    long old_ssp;
    UINT32 timeNow;

    /* Enter privileged mode */
    old_ssp = Super(0);

    /* Read the timer value */
    timeNow = *(UINT32 *)0x462;

    /* Exit privileged mode */
    Super(old_ssp);

    return timeNow;
}

/* Main game loop */
void RunGame() {
    Model model;
    UINT32 *frameBuffer = (UINT32 *)Physbase();
    UINT32 timeThen, timeNow, timeElapsed;

    /* Initialize the game */
    InitializegGame(&model);
    timeThen = GetTime();

    /* Render the first frame */
    render(&model, frameBuffer);

    /* Main game loop */
    while (!model.quit) {
        timeNow = GetTime();
        timeElapsed = timeNow - timeThen;

        /* Process asynchronous events (user input) */
        if (InputPending()) {
            char input = ReadInput();
            switch (input) {
                case 'w': handleMoveForward(&model); break;
                case 'a': handleIncreaseAngle(&model); break;
                case 'd': handleDecreaseAngle(&model); break;
                case 's': handleShootMissile(&model); break;
                case 'q': handleQuit(&model); break;
                default: break; /* Ignore invalid input */
            }
        }

        /* Process synchronous events (clock ticks) */
        if (timeElapsed > 0) {
            updateAsteroids(&model);
            updateMissiles(&model);

            /* Render the next frame */
            render(&model, frameBuffer);
            timeThen = timeNow;
        }
    }
}

/* Entry point for the game */
void main() {

    printf("\033E\033F\n");
    RunGame();
}