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

}

void position_mediumAsteroid(mediumAsteroid *asteroid) {
    /* Update the asteroid's position based on its velocity */
    asteroid->x += asteroid->x_velocity;
    asteroid->y += asteroid->y_velocity;
}

void position_largeAsteroid(largeAsteroid *asteroid) {
    /* Update the asteroid's position based on its velocity */
    asteroid->x += asteroid->x_velocity;
    asteroid->y += asteroid->y_velocity;
}

int check_collision_smallAsteroid(smallAsteroid *asteroid, int missile_x, int missile_y) {
    // Calculate distance between missile and asteroid, using Euclidean distance formula.
    int dx = missile_x - asteroid->x;
    int dy = missile_y - asteroid->y;
    int distance_squared = dx * dx + dy * dy;

    // Check if distance is within hit radius
    if (distance_squared <= asteroid->hit_radius * asteroid->hit_radius) {
        return 0; // Collision detected
    }
    return 1; // No collision
}

int check_collision_mediumAsteroid(mediumAsteroid *asteroid, int missile_x, int missile_y) {
    // Calculate distance between missile and asteroid, using Euclidean distance formula.
    int dx = missile_x - asteroid->x;
    int dy = missile_y - asteroid->y;
    int distance_squared = dx * dx + dy * dy;

    // Check if distance is within hit radius
    if (distance_squared <= asteroid->hit_radius * asteroid->hit_radius) {
        return 0; // Collision detected
    }
    return 1; // No collision
}

int check_collision_largeAsteroid(largeAsteroid *asteroid, int missile_x, int missile_y) {
    // Calculate distance between missile and asteroid, using Euclidean distance formula.
    int dx = missile_x - asteroid->x;
    int dy = missile_y - asteroid->y;
    int distance_squared = dx * dx + dy * dy;

    // Check if distance is within hit radius
    if (distance_squared <= asteroid->hit_radius * asteroid->hit_radius) {
        return 0; // Collision detected
    }
    return 1; // No collision
}

void initialize_Scoreboard(Scoreboard *scoreboard, int high_score) {
    scoreboard->score = 0;
    scoreboard->high_score = high_score; // HOW DO WE KEEP TRACK OF THIS?
}

void update_score(Scoreboard *scoreboard, int points) {
    scoreboard->score += points;

    // Update high score if the current score exceeds it
    if (scoreboard->score > scoreboard->high_score) {
        scoreboard->high_score = scoreboard->score;
    }
}


