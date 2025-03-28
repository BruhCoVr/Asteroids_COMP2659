#ifndef MUS_H
#define MUS_H
#include "types.h"

/** 
 * Initializes and starts playing the main song.
 */
void start_music();

/** 
 * Updates the main song based on the elapsed time.
 */
void update_Mainmusic(UINT32 time_elapsed);

/** 
 * Initializes and starts playing the death song.
 */
void start_Deathmusic();

/** 
 * Updates the death song based on the elapsed time.
 */
void update_Deathmusic(UINT32 time_elapsed);

#endif /* MUS_H */
