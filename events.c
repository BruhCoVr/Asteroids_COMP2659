#include "events.h"
#include "model.h"
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/* --- Asynchronous (Input) Event Handlers --- */

/* Moves the ship forward. */
void handle_move_forward(Model *model) {
    move_ship_forward(&model->ship);
    printf("Ship moved to (%d, %d)\n", model->ship.pos.x, model->ship.pos.y);
}

/* Rotates the ship by increasing its angle. */
void handle_increase_angle(Model *model) {
    rotate_ship(&model->ship, 1);
    printf("Ship angle increased to %d\n", model->ship.angle);
}

/* Rotates the ship by decreasing its angle. */
void handle_decrease_angle(Model *model) {
    rotate_ship(&model->ship, -1);
    printf("Ship angle decreased to %d\n", model->ship.angle);
}

/* Shoots a missile from the ship’s current position. */
void handle_shoot_missile(Model *model) {
    int i = 0;
    for (i = 0; i < MAX_MISSILES; i++) {
        if (!model->missiles[i].active) {
            double rad = model->ship.angle * 3.14159265 / 180.0;
            int dx = (int)(2 * cos(rad));
            int dy = (int)(2 * sin(rad));
            init_missile(&model->missiles[i], model->ship.pos, dx, dy, 50);
            printf("Missile shot from (%d, %d) with velocity (%d, %d)\n",
                   model->ship.pos.x, model->ship.pos.y, dx, dy);
            break;
        }
    }
}

/* Sets the quit flag to exit the game. */
void handle_quit(Model *model) {
    model->quit = 1;
    printf("Quit event triggered. Exiting game.\n");
}

/* --- Synchronous (Timed) Event Handlers --- */

/* Updates all active asteroids. */
void update_asteroids(Model *model) {
    int i = 0;
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        if (model->asteroids[i].active)
            update_asteroid(&model->asteroids[i]);
    }
    printf("Asteroids updated.\n");
}

/* Updates all active missiles. */
void update_missiles(Model *model) {
    int i = 0;
    for (i = 0; i < MAX_MISSILES; i++) {
        if (model->missiles[i].active)
            update_missile(&model->missiles[i]);
    }
    printf("Missiles updated.\n");
}

/* Respawns the ship at the center of the screen with default settings. */
void respawn_ship(Model *model) {
    model->ship.pos.x = SCREEN_WIDTH / 2;
    model->ship.pos.y = SCREEN_HEIGHT / 2;
    model->ship.angle = 90;
    printf("Ship respawned at (%d, %d) with angle %d\n",
           model->ship.pos.x, model->ship.pos.y, model->ship.angle);
}

/* --- Condition-Based (Cascaded) Event Handlers --- */

/* Handles splitting an asteroid when hit. Large or medium asteroids split into a smaller one. */
void handle_asteroid_split(Model *model, int asteroid_index) {
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
                init_asteroid(&model->asteroids[i], asteroid->pos, asteroid->dx, asteroid->dy, newSize);
                printf("Asteroid %d split: New asteroid %d created with size %d\n",
                       asteroid_index, i, newSize);
                break;
            }
        }
    } else {
        asteroid->active = 0;
        update_score(&model->scoreboard, 100);
        printf("Small asteroid %d destroyed. Score: %d\n",
               asteroid_index, model->scoreboard.score);
    }
}

/* Handles the destruction of an asteroid and updates the score accordingly. */
void handle_asteroid_destroyed(Model *model, int asteroid_index) {
    int points = 0;

    Asteroid *asteroid = &model->asteroids[asteroid_index];
    if (!asteroid->active)
        return;
    
    if (asteroid->size == ASTEROID_LARGE)
        points = 20;
    else if (asteroid->size == ASTEROID_MEDIUM)
        points = 50;
    else if (asteroid->size == ASTEROID_SMALL)
        points = 100;
    
    update_score(&model->scoreboard, points);
    asteroid->active = 0;
    printf("Asteroid %d destroyed. Awarded %d points. Total score: %d\n",
           asteroid_index, points, model->scoreboard.score);
    
    if (model->scoreboard.score % 5000 == 0 && model->scoreboard.lives < 5 && model->scoreboard.score < 30000)
        handle_bonus_life_awarded(model);
    
    if (model->scoreboard.score % 10000 == 0)
        handle_difficulty_ramp_up(model);
}

/* Handles the ship being hit by an asteroid. */
void handle_ship_destroyed(Model *model) {
    lose_life(&model->scoreboard);
    printf("Ship destroyed! Lives remaining: %d\n", model->scoreboard.lives);
    if (model->scoreboard.lives > 0)
        respawn_ship(model);
    else
        handle_game_over(model);
}

/* Logs when an object wraps around the screen. */
void handle_object_wraparound(Model *model, int object_type, int index) {
    if (object_type == 0)
        printf("Ship wrapped around screen.\n");
    else if (object_type == 1)
        printf("Missile %d wrapped around screen.\n", index);
    else if (object_type == 2)
        printf("Asteroid %d wrapped around screen.\n", index);
}

/* Handles the game over event. */
void handle_game_over(Model *model) {
    printf("Game Over! Final score: %d\n", model->scoreboard.score);
    model->quit = 1;
}

/* Handles the collision between a missile and an asteroid. */
void handle_missile_collision(Model *model, int missile_index, int asteroid_index) {
    model->missiles[missile_index].active = 0;
    printf("Missile %d collided with asteroid %d\n", missile_index, asteroid_index);
    if (model->asteroids[asteroid_index].size > ASTEROID_SMALL)
        handle_asteroid_split(model, asteroid_index);
    else
        handle_asteroid_destroyed(model, asteroid_index);
}

/* Awards a bonus life. */
void handle_bonus_life_awarded(Model *model) {
    award_bonus_life(&model->scoreboard);
    printf("Bonus life awarded! Lives: %d\n", model->scoreboard.lives);
}

/* Increases game difficulty (for example, by increasing asteroid speed). */
void handle_difficulty_ramp_up(Model *model) {
    printf("Difficulty ramp up! Increasing asteroid speed/spawn rate.\n");
}
