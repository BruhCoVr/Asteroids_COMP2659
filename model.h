#include <stdlib.h>
#include <stdio.h>
//#include <osbind.h>

/* 

Scoreboard and asteroids NOT Complete

Scoreboard: NEEDS 1 more function
        1: (Integrate the Scoreboard with Asteroid Destruction).
            When an asteroid is destroyed by a missile we need to update the scoreboard.
             

Asteroids: NEED 3 more functions (for each, small medium and large):

        1: Collision Detection Function - 
            This function will check if a missile has collided with an asteroid based on the hit radius.

        2: Missile Fired Handler -
            This function will handle the event when a missile is fired and check for collisions with asteroids.

        3: Clock Tick Handler -
            This function will be called on each clock tick to update the positions of all active asteroids.

*/

typedef struct {
    unsigned int x, y; // (x,y) coordinates.
    int x_velocity, y_velocity; // Horizontal & Vertical velocity.
    int size; // Size of the Asteroid
    int active; // 0 :destroyed, 1:active 
    int points; // Points the asteroid contains
    int hit_radius; // if the missile enters this radius the asteroyed is assumed to be destroyed.
} smallAsteroid;

typedef struct {
    unsigned int x, y; // (x,y) coordinates.
    int x_velocity, y_velocity; // Horizontal & Vertical velocity.
    int size; // Size of the Asteroid
    int active; // 0 :destroyed, 1:active 
    int points; // Points the asteroid contains
    int hit_radius; // if the missile enters this radius the asteroyed is assumed to be destroyed.
} mediumAsteroid;

typedef struct {
    unsigned int x, y; // (x,y) coordinates.
    int x_velocity, y_velocity; // Horizontal & Vertical velocity.
    int size; // Size of the Asteroid
    int active; // 0 :destroyed, 1:active 
    int points; // Points the asteroid contains
    int hit_radius; // if the missile enters this radius the asteroyed is assumed to be destroyed.
} largeAsteroid;

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

Parameter: scoreboard = object of scoreboard
           high_score = highest score achieved of all time
*/
void initialize_Scoreboard(Scoreboard *scoreboard, int high_socre);

/*
Purpose: Function used to maintain scoreboard of the current player and check if player's
         score surpasses the high_score. 

Parameter: scoreboard = object of scoreboard
           points = points scored by current player. 
*/
void update_score(Scoreboard *scoreboard, int points);

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

