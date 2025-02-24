#include <stdio.h>
#include <osbind.h>
#include "model.h"
#include "renderer.h"
#include "types.h"

#define FRAME_BUFFER_SIZE 8000  /* Not used now since we use physical screen memory */

int main(void) {
    Model model;
    UINT32 *frameBuffer;

    /* Initialize the model with default values. */
    init_model(&model);
    
    /* Set up a test ship at (100, 100) with an angle of 45 degrees. */
    model.ship.pos.x = 100;
    model.ship.pos.y = 100;
    model.ship.angle = 45;
    
    /* Activate one missile for testing. */
    model.missiles[0].active = 1;
    model.missiles[0].pos.x = 150;
    model.missiles[0].pos.y = 150;
    model.missiles[0].dx = 2;
    model.missiles[0].dy = 0;
    model.missiles[0].lifetime = 10;
    
    /* Activate one asteroid (a small asteroid in this case). */
    model.asteroids[0].active = 1;
    model.asteroids[0].pos.x = 300;
    model.asteroids[0].pos.y = 200;
    model.asteroids[0].dx = -1;
    model.asteroids[0].dy = 1;
    model.asteroids[0].size = ASTEROID_LARGE;
    
    /* Set the scoreboard with a test score and number of lives. */
    model.scoreboard.score = 12345;
    model.scoreboard.lives = 3;
    
    /* Get the physical base address of the screen using Physbase() */
    frameBuffer = (UINT32 *)Physbase();
    
    /* Render the static frame directly to the screen. */
    render(&model, frameBuffer);

    return 0;
}
