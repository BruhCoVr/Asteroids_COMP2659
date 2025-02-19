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

    int score; // Current score of the player.
    int high_score; // Highest score achieved.
}Scoreboard;

typedef struct{
    int player_x, player_y; // position of the players tip where the bullet gets shot from
    int x, y; // position of the bullet
    int x_velocity, y_velocity; // velocity of the bullet 
    int active; // 0 :hit something, 1:active 
    int size; // size of the bullet
}Bullet;

/*
Purpose: Function is used for the Initialization of an small asteroid.

Parameters: asteroid = Object of smallAsteroid struct.
            (x,y) = Coordinates of the asteroid.
            (x_velocity, y_velocity) = Asteroid's horizontal & vertical velocity.
            size = Size of the Asteroid. 
            hit_radius = if the missile enters this radius the asteroyed is assumed to be destroyed.
*/ 
void Initialize_smallAsteroid(smallAsteroid *asteroid, int x, int y, int x_velocity, int y_velocity, int size, int hit_radius);

/*
Purpose: Function is used for the Initialization of an medium asteroid.

Parameters: asteroid = Object of mediumAsteroid struct.
            (x,y) = Coordinates of the asteroid.
            (x_velocity, y_velocity) = Asteroid's horizontal & vertical velocity.
            size = Size of the Asteroid. 
            hit_radius = if the missile enters this radius the asteroyed is assumed to be destroyed.
*/ 
void Initialize_mediumAsteroid(mediumAsteroid *asteroid, int x, int y, int x_velocity, int y_velocity, int size, int hit_radius);

/*
Purpose: Function is used for the Initialization of an large asteroid.

Parameters: asteroid = Object of largeAsteroid struct.
            (x,y) = Coordinates of the asteroid.
            (x_velocity, y_velocity) = Asteroid's horizontal & vertical velocity.
            size = Size of the Asteroid. 
            hit_radius = if the missile enters this radius the asteroyed is assumed to be destroyed.
*/ 
void Initialize_largeAsteroid(largeAsteroid *asteroid, int x, int y, int x_velocity, int y_velocity, int size, int hit_radius);

/*
Purpose: Fucntion is used for the deactivation of the asteroid setting the active feild to 0 (false).

Parameter: asteroid = object of smallAsteroid. 
*/
void deactivate_smallAsteroid(smallAsteroid *asteroid);

/*
Purpose: Fucntion is used for the deactivation of the asteroid setting the active feild to 0 (false).

Parameter: asteroid = object of mediumAsteroid. 
*/
void deactivate_mediumAsteroid(mediumAsteroid *asteroid);

/*
Purpose: Fucntion is used for the deactivation of the asteroid setting the active feild to 0 (false).

Parameter: asteroid = object of largeAsteroid. 
*/
void deactivate_largeAsteroid(largeAsteroid *asteroid);

/*
Purpose: Function is used to modify the asteroid's position based on its current velocity.
            Also for the asteroid to wrap around the screen if is exceeds the set screen height & width. 

Parameter: asteroid = object samllAsteroid.
*/
void position_smallAsteroid(smallAsteroid *asteroid);

/*
Purpose: Function is used to modify the asteroid's position based on its current velocity.
            Also for the asteroid to wrap around the screen if is exceeds the set screen height & width. 

Parameter: asteroid = object mediumAsteroid.
*/
void position_mediumAsteroid(mediumAsteroid *asteroid);

/*
Purpose: Function is used to modify the asteroid's position based on its current velocity.
            Also for the asteroid to wrap around the screen if is exceeds the set screen height & width. 

Parameter: asteroid = object largeAsteroid.
*/
void position_largeAsteroid(largeAsteroid *asteroid);

/*
Purpose: Function is used to initialize Scoreboard 
=======
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


/*
Purpose: Function is used for the Initialization of an bullet.

Parameters: asteroid = Object of Bullet struct.
            (x,y) = Coordinates of the bullet.
            (player_x, player_y) = Coordinates of the tip of the player.
            (x_velocity, y_velocity) = bullet's horizontal & vertical velocity.
            size = Size of the bullet. 
            active = if the bullet enters this radius the asteroyed is assumed to be destroyed.
*/ 
void initialize_bullet(Bullet *bullet, int player_x, int player_y, int x_velocity, int y_velocity, int active, int size);

/*
Purpose: Fucntion is used for the deactivation of the bullet setting the active feild to 0 (false).

Parameter: bullet = object of Bullet. 
*/
void deactivate_bullet(Bullet *bullet);

/*
Purpose: Function is used to modify the bullets's position based on its current velocity.
           
Parameter: bullet = object Bullet.
*/
void position_bullet(Bullet *bullet);

/*
Purpose: To check if a bullet has hit any type of asteroid

Parameter: bullet = object Bullet.
           largeAsteroid = object largeAsteroid.
           mediumAsteroid = object mediumAsteroid
           smallAsteroid = object smallAsteroid.
*/
void bullet_hit(Bullet *bullet, largeAsteroid *largeAsteroid, mediumAsteroid *mediumAsteroid, smallAsteroid *smallAsteroid);

#endif /* MODEL_H */

