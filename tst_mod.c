#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "events.h"

/* Prints the current state of the game model. */
void print_model_state(Model *model) {
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
void spawn_test_asteroid(Model *model, AsteroidSize size) {
    int i = 0;
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        if (!model->asteroids[i].active) {
            Position pos = {0, 0}; /* spawn at top-left */
            int dx = 1;
            int dy = 1;
            init_asteroid(&model->asteroids[i], pos, dx, dy, size);
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

    init_model(&model);
  
    while (!model.quit) {
        print_model_state(&model);
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
                handle_move_forward(&model);
                break;
            case 'a':
                handle_increase_angle(&model);
                break;
            case 'd':
                handle_decrease_angle(&model);
                break;
            case 's':
                handle_shoot_missile(&model);
                break;
            case 't':
                update_missiles(&model);
                update_asteroids(&model);
                break;
            case 'r':
                respawn_ship(&model);
                break;
            case 'x':
                spawn_test_asteroid(&model, ASTEROID_LARGE);
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
                    handle_missile_collision(&model, missileIndex, asteroidIndex);
                else
                    printf("No active missile or asteroid for collision.\n");
                break;
            }
            case 'k':
                handle_ship_destroyed(&model);
                break;
            case 'q':
                handle_quit(&model);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
    
    printf("Exiting test driver.\n");
    return 0;
}
