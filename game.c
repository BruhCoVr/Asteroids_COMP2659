#include <osbind.h>
#include <stdlib.h>
#include "game.h"
#include "model.h"
#include "renderer.h"
#include "input.h"
#include "raster.h"
#include "events.h"

void initialize_game(Model *model) {

    /* Initialize the model with default values */
    initModel(model);

    /* Spawn some asteroids */
    Position asteroid_pos = {100, 100};
    initAsteroid(&model->asteroids[0], asteroid_pos, 1, 1, ASTEROID_LARGE);
    asteroid_pos->x = 500; 
    asteroid_pos->y = 300;
    initAsteroid(&model->asteroids[1], asteroid_pos, -1, 1, ASTEROID_MEDIUM);
}

/* Main game loop */
void run_game() {
    Model model;
    UINT32 *frameBuffer = (UINT32 *)Physbase();
    UINT32 timeThen, timeNow, timeElapsed;

    /* Initialize the game */
    initialize_game(&model);
    timeThen = get_time();

    /* Render the first frame */
    render(&model, frameBuffer);

    /* Main game loop */
    while (!model.quit) {
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        /* Process asynchronous events (user input) */
        if (input_pending()) {
            char input = read_input();
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
    run_game();
}