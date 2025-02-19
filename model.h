#ifndef MODEL_H
#define MODEL_H

#define MAX_MISSILES 10
#define MAX_ASTEROIDS 20

/* Enumeration for asteroid sizes. */
typedef enum {
    ASTEROID_SMALL = 1,
    ASTEROID_MEDIUM = 2,
    ASTEROID_LARGE = 3
} AsteroidSize;

/* Structure for a position (x,y) coordinates. */
typedef struct {
    int x;
    int y;
} Position;

/* Structure for the Ship object. */
typedef struct {
    Position pos;    /* Ship's position on screen. */
    int angle;       /* Ship's pointing angle (0-359 degrees). */
} Ship;

/* Structure for a Missile object. */
typedef struct {
    Position pos;    /* Missile's current position. */
    int dx;          /* Horizontal movement per tick. */
    int dy;          /* Vertical movement per tick. */
    int lifetime;    /* Remaining ticks before missile expires. */
    int active;      /* 0 if inactive, 1 if active. */
} Missile;

/* Structure for an Asteroid object. */
typedef struct {
    Position pos;    /* Asteroid's current position. */
    int dx;          /* Horizontal velocity per tick. */
    int dy;          /* Vertical velocity per tick. */
    AsteroidSize size; /* Size/type of asteroid. */
    int active;      /* 0 if inactive, 1 if active. */
} Asteroid;

/* Structure for the Scoreboard. */
typedef struct {
    int score;
    int lives;
} Scoreboard;

/* The complete game model: holds the ship, missiles, asteroids, scoreboard, and a quit flag. */
typedef struct {
    Ship ship;
    Missile missiles[MAX_MISSILES];
    Asteroid asteroids[MAX_ASTEROIDS];
    Scoreboard scoreboard;
    int quit; /* 0 = running, 1 = quit. */
} Model;

/* Initialization function for the model. */
void init_model(Model *model);

/* Ship behaviour functions. */
void move_ship_forward(Ship *ship);
void rotate_ship(Ship *ship, int angle_delta); /* Positive delta rotates one way; negative rotates the other. */

/* Missile behaviour functions. */
void init_missile(Missile *missile, Position pos, int dx, int dy, int lifetime);
void update_missile(Missile *missile);

/* Asteroid behaviour functions. */
void init_asteroid(Asteroid *asteroid, Position pos, int dx, int dy, AsteroidSize size);
void update_asteroid(Asteroid *asteroid);

/* Scoreboard functions. */
void update_score(Scoreboard *scoreboard, int points);
void lose_life(Scoreboard *scoreboard);
void award_bonus_life(Scoreboard *scoreboard);

/* Helper function: wraps a position to the opposite edge if off screen. */
void wrap_position(Position *pos, int screen_width, int screen_height);

#endif /* MODEL_H */
