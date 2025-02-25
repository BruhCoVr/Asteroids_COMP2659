#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "events.h"

/* Prints the current state of the game model. */
void printModelState(Model *model) {
    int i = 0;
    printf("\n--- Game State ---\n");
    printf("Ship: Position (%d, %d), Angle %d\n",
           model->ship.pos.x, model->ship.pos.y, model->ship.angle);
    printf("Score: %d, Lives: %d\n",
           model->scoreboard.score, model->scoreboard.lives);
    
    printf("Missiles:\n");
    for (i = 0; i < MAX_MISSILES; i++) {
        if (model->missiles[i].active)
            printf("  Missile %d: Position (%d, %d), Lifetime %d\n",
                   i, model->missiles[i].pos.x, model->missiles[i].pos.y,
                   model->missiles[i].lifetime);
    }
    
    printf("Asteroids:\n");
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        if (model->asteroids[i].active)
            printf("  Asteroid %d: Position (%d, %d), Size %d\n",
                   i, model->asteroids[i].pos.x, model->asteroids[i].pos.y,
                   model->asteroids[i].size);
    }
    printf("-------------------\n");
}

/* Spawns an asteroid (for testing) at a fixed position. */
void spawnTestAsteroid(Model *model, AsteroidSize size) {
    int i = 0;
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        if (!model->asteroids[i].active) {
            Position pos = {0, 0}; /* spawn at top-left */
            int dx = 1;
            int dy = 1;
            initAsteroid(&model->asteroids[i], pos, dx, dy, size);
            printf("Spawned asteroid %d of size %d at (%d, %d)\n",
                   i, size, pos.x, pos.y);
            break;
        }
    }
}

int main() {
    Model model;
    char input;
    int i = 0; 

    initModel(&model);
  
    while (!model.quit) {
        printModelState(&model);
        printf("Enter command:\n");
        printf("  w: Move Forward\n");
        printf("  a: Increase Angle\n");
        printf("  d: Decrease Angle\n");
        printf("  s: Shoot Missile\n");
        printf("  t: Update Timed Events (Asteroids/Missiles)\n");
        printf("  r: Respawn Ship\n");
        printf("  x: Spawn Test Asteroid (Large)\n");
        printf("  c: Simulate Missile Collision (first active missile & asteroid)\n");
        printf("  k: Destroy Ship\n");
        printf("  q: Quit\n");
        input = getchar();
        while(getchar() != '\n');  /* consume extra characters */
        
        switch(input) {
            case 'w':
                handleMoveForward(&model);
                break;
            case 'a':
                handleIncreaseAngle(&model);
                break;
            case 'd':
                handleDecreaseAngle(&model);
                break;
            case 's':
                handleShootMissile(&model);
                break;
            case 't':
                updateMissiles(&model);
                updateAsteroids(&model);
                break;
            case 'r':
                respawnShip(&model);
                break;
            case 'x':
                spawnTestAsteroid(&model, ASTEROID_LARGE);
                break;
            case 'c': {
                int missileIndex = -1, asteroidIndex = -1;
                for (i = 0; i < MAX_MISSILES; i++) {
                    if (model.missiles[i].active) {
                        missileIndex = i;
                        break;
                    }
                }
                for (i = 0; i < MAX_ASTEROIDS; i++) {
                    if (model.asteroids[i].active) {
                        asteroidIndex = i;
                        break;
                    }
                }
                if (missileIndex != -1 && asteroidIndex != -1)
                    handleMissileCollision(&model, missileIndex, asteroidIndex);
                else
                    printf("No active missile or asteroid for collision.\n");
                break;
            }
            case 'k':
                handleShipDestroyed(&model);
                break;
            case 'q':
                handleQuit(&model);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
    
    printf("Exiting test driver.\n");
    return 0;
}
