/*
 * video.c
 * Implementation of video base access routines.
 * Provides get_video_base and set_video_base functions to manage the frame buffer start address.
 */

 #include "video.h"
 #include <osbind.h>
 #include "types.h"
 
 /* Static variable to simulate the hardware video base register.
    It must be 256-byte aligned. */
 static UINT32 current_video_base = 0xC00000; /* Example starting address */
 
 /*
  * get_video_base - Returns the current frame buffer start address.
  *
  * Returns:
  *   The current frame buffer start address.
  */
 UINT32 get_video_base(void) {
     UINT32 old_ssp = Super(0);
     UINT32 base = current_video_base;
     Super(old_ssp);
     return base;
 }
 
 /*
  * set_video_base - Sets a new frame buffer start address.
  * The new_base value is forced to be 256-byte aligned.
  *
  * Parameters:
  *   new_base - The new frame buffer start address to set.
  *
  * Notes:
  *   In a production version this routine should be implemented in 68000 assembly
  *   using the movep instruction so that both bytes of the register are updated atomically.
  */
 void set_video_base(UINT32 new_base) {
     /* Ensure the address is 256-byte aligned. */
     new_base &= 0xFFFFFF00;
     
     UINT32 old_ssp = Super(0);
     current_video_base = new_base;
     Super(old_ssp);
 }
 