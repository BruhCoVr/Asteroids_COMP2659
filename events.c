#include "events.h"
#include "model.h"
#include "music.h"
#include "types.h"
#include "time.h"
#include "effects.h"
#include "psg.h"
#include <stdio.h>
#include <math.h>
#include <osbind.h>
#include <stdlib.h>

UINT32 start_timeEvent, current_timeEvent;


/* --- Asynchronous (Input) Event Handlers --- */

/* Moves the ship forward. */
void handleMoveForward(Model *model) {
    start_timeEvent = getTime();
    thrusting_effect();
    while ((getTime() - start_timeEvent) < 33) {
    }
    write_psg(9, 0);
    write_psg(10, 0);

    moveShipForward(&model->ship);
    /*printf("Ship moved to (%d, %d)\n", model->ship.pos.x, model->ship.pos.y);*/
}

/* Rotates the ship by increasing its angle. */
void handleIncreaseAngle(Model *model) {
    rotateShip(&model->ship, 45);
    /*printf("Ship angle increased to %d\n", model->ship.angle);*/
}

/* Rotates the ship by decreasing its angle. */
void handleDecreaseAngle(Model *model) {
    rotateShip(&model->ship, -45);
    /*printf("Ship angle decreased to %d\n", model->ship.angle);*/
}

/* Shoots a missile from the ship’s current position. */
void handleShootMissile(Model *model) {
    int i;
    start_timeEvent = getTime();
    shooting_effect();
    while ((getTime() - start_timeEvent) < 33) {
    }
    write_psg(10, 0);

    for (i = 0; i < MAX_MISSILES; i++) {
        if (!model->missiles[i].active) {
            double rad = model->ship.angle * 3.14159265 / 180.0;
            int bullet_dx = (int)(2 * cos(rad));
            int bullet_dy = -(int)(2 * sin(rad));

            /* Compute ship center assuming a 32x32 ship */
            int centerX = model->ship.pos.x + 16;
            int centerY = model->ship.pos.y + 16;

            int offset = 40;
            Position bulletPos;
            bulletPos.x = centerX + (int)(offset * cos(rad));
            bulletPos.y = centerY - (int)(offset * sin(rad));

            initMissile(&model->missiles[i], bulletPos, bullet_dx, bullet_dy, 50);
            break;
        }
    }
}


/* Sets the quit flag to exit the game. */
void handleQuit(Model *model) {
    model->quit = 1;
    /*printf("Quit event triggered. Exiting game.\n");*/
}

/* --- Synchronous (Timed) Event Handlers --- */

/* Updates all active asteroids. */
void updateAsteroids(Model *model) {
    int i = 0;
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        if (model->asteroids[i].active)
            updateAsteroid(&model->asteroids[i]);
    }
    /*printf("Asteroids updated.\n");*/
}

/* Updates all active missiles. */
void updateMissiles(Model *model) {
    int i = 0;
    for (i = 0; i < MAX_MISSILES; i++) {
        if (model->missiles[i].active)
            updateMissile(&model->missiles[i]);
    }
    /*printf("Missiles updated.\n");*/
}

/* Respawns the ship at the center of the screen with default settings. */
void respawnShip(Model *model) {
    model->ship.pos.x = SCREEN_WIDTH / 2;
    model->ship.pos.y = SCREEN_HEIGHT / 2;
    model->ship.angle = 90;
    /*printf("Ship respawned at (%d, %d) with angle %d\n",
           model->ship.pos.x, model->ship.pos.y, model->ship.angle);*/
}

/* --- Condition-Based (Cascaded) Event Handlers --- */

/* Handles splitting an asteroid when hit. Large or medium asteroids split into a smaller one. */
void handleAsteroidSplit(Model *model, int asteroid_index) {
    int i = 0;
    Asteroid *asteroid = &model->asteroids[asteroid_index];
    if (asteroid->size == ASTEROID_LARGE || asteroid->size == ASTEROID_MEDIUM) {
        for (i = 0; i < MAX_ASTEROIDS; i++) {
            if (!model->asteroids[i].active) {
                AsteroidSize newSize;
                if (asteroid->size == ASTEROID_LARGE) {
                    newSize = ASTEROID_MEDIUM;
                } else {
                    newSize = ASTEROID_SMALL;
                }
                initAsteroid(&model->asteroids[i], asteroid->pos, asteroid->dx, asteroid->dy, newSize);
                /*printf("Asteroid %d split: New asteroid %d created with size %d\n",
                       asteroid_index, i, newSize); */
                break;
            }
        }
    } else {
        asteroid->active = 0;
        updateScore(&model->scoreboard, 100);
        /*printf("Small asteroid %d destroyed. Score: %d\n",
               asteroid_index, model->scoreboard.score);*/
    }
}

/* Handles the destruction of an asteroid and updates the score accordingly. */
void handleAsteroidDestroyed(Model *model, int asteroid_index) {
    int points = 0;
    Asteroid *asteroid = &model->asteroids[asteroid_index];
    start_timeEvent = getTime();
    explosion_effect();
    while ((getTime() - start_timeEvent) < 33) {
    }
    write_psg(10, 0);

 
    if (!asteroid->active)
        return;
    
    if (asteroid->size == ASTEROID_LARGE)
        points = 20;
    else if (asteroid->size == ASTEROID_MEDIUM)
        points = 50;
    else if (asteroid->size == ASTEROID_SMALL)
        points = 100;
    
    updateScore(&model->scoreboard, points);
    asteroid->active = 0;
    /*printf("Asteroid %d destroyed. Awarded %d points. Total score: %d\n",
           asteroid_index, points, model->scoreboard.score);*/
    
    if (model->scoreboard.score % 5000 == 0 && model->scoreboard.lives < 5 && model->scoreboard.score < 30000)
        handleBonusLifeAwarded(model);
    
    if (model->scoreboard.score % 10000 == 0)
        handleDifficultyRampUp(model);
}

/* Handles the ship being hit by an asteroid. */
void handleShipDestroyed(Model *model) {
    loseLife(&model->scoreboard);
    /*printf("Ship destroyed! Lives remaining: %d\n", model->scoreboard.lives);*/
    if (model->scoreboard.lives > 0)
        respawnShip(model);
    else
        handleGameOver(model);
}

/* Logs when an object wraps around the screen. */
void handleObjectWraparound(Model *model, int object_type, int index) {
    /*if (object_type == 0)
        printf("Ship wrapped around screen.\n");
    else if (object_type == 1)
        printf("Missile %d wrapped around screen.\n", index);
    else if (object_type == 2)
        printf("Asteroid %d wrapped around screen.\n", index);*/
}


/* Handles the game over event. */
void handleGameOver(Model *model) {
    start_timeEvent = getTime();
    start_Deathmusic();
    while ((getTime() - start_timeEvent) < 500) {
        int current_time = getTime();
        update_Deathmusic(current_time - start_timeEvent);
    }
    write_psg(8, 0);
    
    /*printf("Game Over! Final score: %d\n", model->scoreboard.score);*/
    model->quit = 1;
}

/* Handles the collision between a missile and an asteroid. */
void handleMissileCollision(Model *model, int missile_index, int asteroid_index) {
    model->missiles[missile_index].active = 0;
    /*printf("Missile %d collided with asteroid %d\n", missile_index, asteroid_index);*/
    if (model->asteroids[asteroid_index].size > ASTEROID_SMALL)
        handleAsteroidSplit(model, asteroid_index);
    else
        handleAsteroidDestroyed(model, asteroid_index);
}

/* Awards a bonus life. */
void handleBonusLifeAwarded(Model *model) {
    awardBonusLife(&model->scoreboard);
    /*printf("Bonus life awarded! Lives: %d\n", model->scoreboard.lives);*/
}

/* Increases game difficulty (for example, by increasing asteroid speed). */ 
void handleDifficultyRampUp(Model *model) {
    /*printf("Difficulty ramp up! Increasing asteroid speed/spawn rate.\n");*/
}
