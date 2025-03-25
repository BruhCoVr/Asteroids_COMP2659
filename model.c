#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/* Initializes the model to its starting state. */
void initModel(Model *model) {

    int i = 0; 

    /* Place ship in the center with an initial angle of 90 degrees. */
    model->ship.pos.x = SCREEN_WIDTH / 2;
    model->ship.pos.y = SCREEN_HEIGHT / 2;
    model->ship.angle = 90;

    /* Mark all missiles as inactive. */
    for (i = 0; i < MAX_MISSILES; i++) {
        model->missiles[i].active = 0;
        model->missiles[i].lifetime = 0;
    }

    /* Mark all asteroids as inactive. */
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        model->asteroids[i].active = 0;
    }
    
    /* Initialize the scoreboard with 0 points and 3 lives. */
    model->scoreboard.score = 0;
    model->scoreboard.lives = 3;
    
    /* Ensure the game is set to running. */
    model->quit = 0;
}

/* Moves the ship forward by one unit in the direction of its current angle. */
void moveShipForward(Ship *ship) {
    double rad = ship->angle * 3.14159265 / 180.0;
    int dx = (int)(1 * cos(rad));
    int dy = (int)(1 * sin(rad));
    ship->pos.x += dx;
    ship->pos.y -= dy;
    
    wrapPosition(&ship->pos, SCREEN_WIDTH, SCREEN_HEIGHT);
}

/* Rotates the ship by the given angle delta. */
void rotateShip(Ship *ship, int angle_delta) {
    ship->angle += angle_delta;
    if (ship->angle < 0)
        ship->angle += 360;
    else if (ship->angle >= 360)
        ship->angle -= 360;
}

/* Initializes a missile with the provided starting position, velocity and lifetime. */
void initMissile(Missile *missile, Position pos, int dx, int dy, int lifetime) {
    missile->pos = pos;
    missile->dx = dx;
    missile->dy = dy;
    missile->lifetime = lifetime;
    missile->active = 1;
}

/* Updates the missile's position and decreases its lifetime; deactivates if lifetime expires. */
void updateMissile(Missile *missile) {
    if (!missile->active)
        return;

    /* Update bullet position */
    missile->pos.x += missile->dx;
    missile->pos.y += missile->dy;

    /* Deactivate the missile when it has fully left the screen.
       The bullet is 8x8, so we allow a margin of 8 pixels. */
    if (missile->pos.x < -8 || missile->pos.x > SCREEN_WIDTH ||
        missile->pos.y < -8 || missile->pos.y > SCREEN_HEIGHT)
    {
        missile->active = 0;
    }
}



/* Initializes an asteroid with the provided parameters. */
void initAsteroid(Asteroid *asteroid, Position pos, int dx, int dy, AsteroidSize size) {
    asteroid->pos = pos;
    asteroid->dx = dx;
    asteroid->dy = dy;
    asteroid->size = size;
    asteroid->active = 1;
}

/* Updates the asteroid's position and deactivates it if it leaves the screen. */
void updateAsteroid(Asteroid *asteroid) {
    if (!asteroid->active)
        return;
    
    asteroid->pos.x += asteroid->dx;
    asteroid->pos.y += asteroid->dy;
    
    /* As per spec, asteroids disappear when they leave screen bounds. */
    if (asteroid->pos.x < 0 || asteroid->pos.x > SCREEN_WIDTH ||
        asteroid->pos.y < 0 || asteroid->pos.y > SCREEN_HEIGHT)
        asteroid->active = 0;
}

/* Adds the given points to the scoreboard. */
void updateScore(Scoreboard *scoreboard, int points) {
    scoreboard->score += points;
}

/* Decrements the life count by one. */
void loseLife(Scoreboard *scoreboard) {
    if (scoreboard->lives > 0)
        scoreboard->lives--;
}

/* Awards a bonus life if the current number of lives is below 5. */
void awardBonusLife(Scoreboard *scoreboard) {
    if (scoreboard->lives < 5)
        scoreboard->lives++;
}

/* Wraps a position so that objects leaving one edge reappear on the opposite edge. */
void wrapPosition(Position *pos, int screen_width, int screen_height) {
    if (pos->x < 0) pos->x = screen_width - 1;
    if (pos->x >= screen_width) pos->x = 0;
    if (pos->y < 0) pos->y = screen_height - 1;
    if (pos->y >= screen_height) pos->y = 0;
}
