#include <osbind.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "model.h"
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

void InitializegGame(Model *model) {
    Position asteroid_pos1 = {100, 100};
    Position asteroid_pos2 = {500, 300};
    Position asteroid_pos3 = {200, 100};
    Position asteroid_pos4 = {100, 200};
    Position asteroid_pos5 = {200, 200};


    initModel(model);
    initAsteroid(&model->asteroids[0], asteroid_pos1, 1, 1, ASTEROID_LARGE);
    initAsteroid(&model->asteroids[1], asteroid_pos2, -1, 1, ASTEROID_MEDIUM);

    initAsteroid(&model->asteroids[2], asteroid_pos3, -1, -1, ASTEROID_MEDIUM);
    initAsteroid(&model->asteroids[3], asteroid_pos4, 1, 1, ASTEROID_SMALL);
    initAsteroid(&model->asteroids[4], asteroid_pos5, 1, -1, ASTEROID_LARGE);
}

/* Main game loop using an offscreen back buffer and blitting the full frame each iteration */
void RunGame() {
    Model model;
    UINT32 timeThen, timeNow, timeElapsed;
    UINT32 *frameBuffer = Physbase();
    /* Allocate an offscreen back buffer for a 640x400 screen (8000 UINT32 words) */
    UINT32 *backBuffer = (UINT32 *)malloc(8000 * sizeof(UINT32));
    if (!backBuffer) {
        exit(1);  /* Allocation failure */
    }
    
    InitializegGame(&model);
    timeThen = GetTime();
    
    while (!model.quit) {
        /* Process asynchronous input every loop iteration */
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
        updateMissile(&model);
        
        /* Render the complete frame into the offscreen back buffer */
        render(&model, backBuffer);
        
        /* Wait for vertical sync to reduce tearing */
        Vsync();
        /* Blit the complete frame to the physical screen */
        memcpy(frameBuffer, backBuffer, 8000 * sizeof(UINT32));
        
        timeThen = timeNow;
    }
    
    free(backBuffer);
}

void main() {
    /* Seed the random number generator once at startup */
    srand((unsigned) time(NULL));
    /* Clear the screen */
    printf("\033E\033F\n");
    RunGame();
}
