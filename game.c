#include <osbind.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "music.h"
#include "model.h"
#include "time.h"
#include "psg.h"
#include "types.h"
#include "renderer.h"
#include "input.h"
#include "raster.h"
#include "events.h"

UINT32 GetTime() {
    long old_ssp;
    UINT32 timeNow;
    old_ssp = Super(0);
    timeNow = *(UINT32 *)0x462;
    Super(old_ssp);
    return timeNow;
}

UINT32 start_time, current_time;

void InitializegGame(Model *model) {
    
    
    /* Spawn some asteroids */
    Position asteroid_pos1 = {100, 100};
    Position asteroid_pos2 = {500, 300};
    Position asteroid_pos3 = {200, 100};
    Position asteroid_pos4 = {100, 200};
    Position asteroid_pos5 = {200, 200};


    initModel(model);
    initAsteroid(&model->asteroids[0], asteroid_pos1, 2, 2, ASTEROID_LARGE);
    initAsteroid(&model->asteroids[1], asteroid_pos2, -2, 2, ASTEROID_MEDIUM);
    initAsteroid(&model->asteroids[2], asteroid_pos3, -2, -2, ASTEROID_MEDIUM);
    initAsteroid(&model->asteroids[3], asteroid_pos4, 2, 2, ASTEROID_SMALL);
    initAsteroid(&model->asteroids[4], asteroid_pos5, 2, -2, ASTEROID_LARGE);
}

/* Main game loop using an offscreen back buffer and blitting the full frame each iteration */
void RunGame() {
    Model model;
    UINT32 timeThen, timeNow, timeElapsed;
    UINT32 frameStart = GetTime();
    int numberOfMissiles = 0;
    int numberOfAsteroids = 0;
    UINT32 *frameBuffer = Physbase();
    /* Allocate an offscreen back buffer for a 640x400 screen (8000 UINT32 words) */
    UINT32 *backBuffer = (UINT32 *)malloc(8000 * sizeof(UINT32));
    if (!backBuffer) {
        exit(1);  /* Allocation failure */
    }
    

    start_music();
    start_time = getTime();

    /* Initialize the game */
    InitializegGame(&model);
    timeThen = GetTime();
    
    while (!model.quit) {
        /* Process asynchronous input every loop iteration */

        current_time = getTime();
        update_Mainmusic(current_time - start_time);

        timeNow = GetTime();
        timeElapsed = timeNow - timeThen;

        /* Process asynchronous events (user input) */
        if (InputPending()) {
            char input = ReadInput();
            switch (input) {
                case 'w': 
                case 'W': 
                    handleMoveForward(&model); 
                    break;
                case 'a': 
                case 'A': 
                    handleIncreaseAngle(&model); 
                    break;
                case 'd': 
                case 'D': 
                    handleDecreaseAngle(&model); 
                    break;
                case 's': 
                case 'S': 
                    handleShootMissile(&model); 
                    break;
                case 'q': 
                case 'Q': 
                    handleQuit(&model); 
                    break;
                default: break;
            }
        }
        
        
        /* Update simulation and rendering every iteration for improved responsiveness */
        timeNow = GetTime();
        timeElapsed = timeNow - timeThen;
        /* Optionally, you could use timeElapsed to scale motion for consistent speed,
           but for now we update each loop to make input immediately effective. */
        updateAsteroids(&model);
        updateMissiles(&model);

        /*Check for missile-asteroid collisions */
        for (numberOfMissiles = 0; numberOfMissiles < MAX_MISSILES; numberOfMissiles++) {
            if (model.missiles[numberOfMissiles].active) {
                for (numberOfAsteroids = 0; numberOfAsteroids < MAX_ASTEROIDS; numberOfAsteroids++) {
                    if (model.asteroids[numberOfAsteroids].active && 
                        checkCollision(&model.missiles[numberOfMissiles].pos, &model.asteroids[numberOfAsteroids].pos, model.asteroids[numberOfAsteroids].size)) {
                        handleMissileCollision(&model, numberOfMissiles, numberOfAsteroids);
                    }
                }
            }
        }
        
        /* Render the complete frame into the offscreen back buffer */
        render(&model, backBuffer);
        
        /* Wait for vertical sync to reduce tearing */
        Vsync();
        /* Blit the complete frame to the physical screen */
        memcpy(frameBuffer, backBuffer, 8000 * sizeof(UINT32));
        
        timeThen = timeNow;

        while ((GetTime() - frameStart) < 1) {};
    }
    
    free(backBuffer);

    stop_sound();
}

void main() {
    /* Seed the random number generator once at startup */
    srand((unsigned) time(NULL));
    /* Clear the screen */
    printf("\033E\033F\n");
    RunGame();
}
