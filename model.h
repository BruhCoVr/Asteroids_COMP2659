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
Purpose: Function determines whether a missile has collided with a small asteroid in a 2D space.
            It does this by calculating the squared distance between the missile and the asteroid,
            comparing it to the asteroid's hit radius. 

Parameter: asteroid = object smallAsteroid.
           missile_x = represents the horizontal position of the missile.
           missile_y = represents the vertical position of the missile. 
*/
int check_collision_smallAsteroid(smallAsteroid *asteroid, int missile_x, int missile_y);

/*
Purpose: Function determines whether a missile has collided with a medium asteroid in a 2D space.
            It does this by calculating the squared distance between the missile and the asteroid,
            comparing it to the asteroid's hit radius. 

Parameter: asteroid = object mediumAsteroid.
           missile_x = represents the horizontal position of the missile.
           missile_y = represents the vertical position of the missile. 
*/
int check_collision_mediumAsteroid(mediumAsteroid *asteroid, int missile_x, int missile_y);

/*
Purpose: Function determines whether a missile has collided with a large asteroid in a 2D space.
            It does this by calculating the squared distance between the missile and the asteroid,
            comparing it to the asteroid's hit radius. 

Parameter: asteroid = object largeAsteroid.
           missile_x = represents the horizontal position of the missile.
           missile_y = represents the vertical position of the missile. 
*/
int check_collision_largeAsteroid(largeAsteroid *asteroid, int missile_x, int missile_y);



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

