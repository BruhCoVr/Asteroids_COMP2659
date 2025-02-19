#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/* --- Asynchronous (Input) Event Handlers ---
   These functions are intended to be called when a key is pressed. */
void handle_move_forward(Model *model);
void handle_increase_angle(Model *model);
void handle_decrease_angle(Model *model);
void handle_shoot_missile(Model *model);
void handle_quit(Model *model);

/* --- Synchronous (Timed) Event Handlers ---
   These functions simulate clock ticks (e.g. for moving asteroids or missiles). */
void update_asteroids(Model *model);
void update_missiles(Model *model);
void respawn_ship(Model *model);

/* --- Condition-Based (Cascaded) Event Handlers ---
   These functions handle collisions, splits and game over conditions. */
void handle_asteroid_split(Model *model, int asteroid_index);
void handle_asteroid_destroyed(Model *model, int asteroid_index);
void handle_ship_destroyed(Model *model);
void handle_object_wraparound(Model *model, int object_type, int index); /* object_type: 0=ship, 1=missile, 2=asteroid */
void handle_game_over(Model *model);
void handle_missile_collision(Model *model, int missile_index, int asteroid_index);
void handle_bonus_life_awarded(Model *model);
void handle_difficulty_ramp_up(Model *model);

#endif /* EVENTS_H */
