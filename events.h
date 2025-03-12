#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/* --- Asynchronous (Input) Event Handlers ---
   These functions are intended to be called when a key is pressed. */
void handleMoveForward(Model *model);
void handleIncreaseAngle(Model *model);
void handleDecreaseAngle(Model *model);
void handleShootMissile(Model *model);
void handleQuit(Model *model);

/* --- Synchronous (Timed) Event Handlers ---
   These functions simulate clock ticks (e.g. for moving asteroids or missiles). */
void updateAsteroids(Model *model);
void updateMissiles(Model *model);
void respawnShip(Model *model);

/* --- Condition-Based (Cascaded) Event Handlers ---
   These functions handle collisions, splits and game over conditions. */
void handleAsteroidSplit(Model *model, int asteroid_index);
void handleAsteroidDestroyed(Model *model, int asteroid_index);
void handleShipDestroyed(Model *model);
void handleObjectWraparound(Model *model, int object_type, int index); /* object_type: 0=ship, 1=missile, 2=asteroid */
void handleGameOver(Model *model);
void handleMissileCollision(Model *model, int missile_index, int asteroid_index);
void handleBonusLifeAwarded(Model *model);
void handleDifficultyRampUp(Model *model);

#endif /* EVENTS_H */
