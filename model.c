#include <stdlib.h>
//#include <osbind.h>
#include "model.h"
#include "raster.c"


void Initialize_smallAsteroid(smallAsteroid *asteroid, int x, int y, int x_velocity, int y_velocity, int size, int hit_radius) {
    asteroid->x = x;
    asteroid->y = y;
    asteroid->x_velocity = x_velocity;
    asteroid->y_velocity = y_velocity;
    asteroid->size = size;
    asteroid->active = 1;
    asteroid->points = 100;
    asteroid->hit_radius = hit_radius; // WAITING FOR ACTUAL VALUE
}

void Initialize_meidumAsteroid(mediumAsteroid *asteroid, int x, int y, int x_velocity, int y_velocity, int size, int hit_radius) {
    asteroid->x = x;
    asteroid->y = y;
    asteroid->x_velocity = x_velocity;
    asteroid->y_velocity = y_velocity;
    asteroid->size = size;
    asteroid->active = 1;
    asteroid->points = 50;
    asteroid->hit_radius = hit_radius; // WAITING FOR ACTUAL VALUE
}

void Initialize_largeAsteroid(largeAsteroid *asteroid, int x, int y, int x_velocity, int y_velocity, int size, int hit_radius) {
    asteroid->x = x;
    asteroid->y = y;
    asteroid->x_velocity = x_velocity;
    asteroid->y_velocity = y_velocity;
    asteroid->size = size;
    asteroid->active = 1;
    asteroid->points = 20;
    asteroid->hit_radius = hit_radius; // WAITING FOR ACTUAL VALUE
}

void deactivate_smallAsteroid(smallAsteroid *asteroid) {
    asteroid->active = 0; // Setting feild to 0 (false), meaning asteroid destroyed.
}

void deactivate_mediumAsteroid(mediumAsteroid *asteroid) {
    asteroid->active = 0; // Setting feild to 0 (false), meaning asteroid destroyed.
}

void deactivate_largeAsteroid(largeAsteroid *asteroid) {
    asteroid->active = 0; // Setting feild to 0 (false), meaning asteroid destroyed.
}


void position_smallAsteroid(smallAsteroid *asteroid) {
    /* Update the asteroid's position based on its velocity */
    asteroid->x += asteroid->x_velocity;
    asteroid->y += asteroid->y_velocity;

    // Wrap around the screen horizontally (width = 640)
    if (asteroid->x >= SCREEN_WIDTH) {
        asteroid->x -= SCREEN_WIDTH; // Wrap to the left side
    } else if (asteroid->x < 0) {
        asteroid->x += SCREEN_WIDTH; // Wrap to the right side
    }

    // Wrap around the screen vertically (height = 400)
    if (asteroid->y >= SCREEN_HEIGHT) {
        asteroid->y -= SCREEN_HEIGHT; // Wrap to the top
    } else if (asteroid->y < 0) {
        asteroid->y += SCREEN_HEIGHT; // Wrap to the bottom
    }
}

void position_mediumAsteroid(mediumAsteroid *asteroid) {
    /* Update the asteroid's position based on its velocity */
    asteroid->x += asteroid->x_velocity;
    asteroid->y += asteroid->y_velocity;

    // Wrap around the screen horizontally (width = 640)
    if (asteroid->x >= SCREEN_WIDTH) {
        asteroid->x -= SCREEN_WIDTH; // Wrap to the left side
    } else if (asteroid->x < 0) {
        asteroid->x += SCREEN_WIDTH; // Wrap to the right side
    }

    // Wrap around the screen vertically (height = 400)
    if (asteroid->y >= SCREEN_HEIGHT) {
        asteroid->y -= SCREEN_HEIGHT; // Wrap to the top
    } else if (asteroid->y < 0) {
        asteroid->y += SCREEN_HEIGHT; // Wrap to the bottom
    }
}

void position_largeAsteroid(largeAsteroid *asteroid) {
    /* Update the asteroid's position based on its velocity */
    asteroid->x += asteroid->x_velocity;
    asteroid->y += asteroid->y_velocity;

    // Wrap around the screen horizontally (width = 640)
    if (asteroid->x >= SCREEN_WIDTH) {
        asteroid->x -= SCREEN_WIDTH; // Wrap to the left side
    } else if (asteroid->x < 0) {
        asteroid->x += SCREEN_WIDTH; // Wrap to the right side
    }

    // Wrap around the screen vertically (height = 400)
    if (asteroid->y >= SCREEN_HEIGHT) {
        asteroid->y -= SCREEN_HEIGHT; // Wrap to the top
    } else if (asteroid->y < 0) {
        asteroid->y += SCREEN_HEIGHT; // Wrap to the bottom
    }
}

void initialize_Scoreboard(Scoreboard *scoreboard, int high_score) {
    scoreboard->score = 0;
    scoreboard->high_score = high_score; // HOW DO WE KEEP TRACK OF THIS?
}

void update_score(Scoreboard *scoreboard, uint points) {
    scoreboard->score += points;

    // Update high score if the current score exceeds it
    if (scoreboard->score > scoreboard->high_score) {
        scoreboard->high_score = scoreboard->score;
    }
}

void initialize_bullet(Bullet *bullet, int x, int y, int player_x, int player_y, int x_velocity, int y_velocity, int active, int size){
    bullet->x = x;
    bullet->y = y;
    bullet->player_x = player_x;
    bullet->player_y = player_y;
    bullet->x_velocity = x_velocity;
    bullet->y_velocity = y_velocity;
    bullet->size = size;
    bullet->active = 1;
}

void deactivate_bullet(Bullet *bullet){
    bullet->bullet = 0; // Setting feild to 0 (false), meaning bullet destroyed.
}

void position_bullet(Bullet *bullet){
    /* Update the bullet's position based on its velocity */
    bullet->x += bullet->x_velocity;
    bullet->y += bullet->y_velocity;
}

bullet_hit(Bullet *bullet, largeAsteroid *largeAsteroid, mediumAsteroid *mediumAsteroid, smallAsteroid *smallAsteroid){
    /*checking bullets x and y postions and comparing it with the asteroids*/
    
    if(bullet->x == largeAsteroid->x && bullet->y == largeAsteroid->y){
        deactivate_bullet(bullet);
        deactivate_largeAsteroid(largeAsteroid);
    }

    else if (bullet->x == mediumAsteroid->x && bullet->y == mediumAsteroid->y)
    {
        deactivate_bullet(bullet);
        deactivate_mediumAsteroid(mediumAsteroid);
    }
    
    else if (bullet->x == smallAsteroid->x && bullet->y == smallAsteroid->y)
    {
        deactivate_bullet(bullet);
        deactivate_smallAsteroid(smallAsteroid);
    }
}