/*
 * isr.c
 * Contains C functions invoked by the custom ISRs.
 * Implements the VBL handler that updates music, processes synchronous events,
 * and sets the render_request flag; and the IKBD handler that reads an incoming
 * byte and enqueues it into a circular buffer.
 *
 */

 #include "isr.h"
 #include "psg.h"
 #include "game.h"
 
 /* Global flag set by VBL ISR to request rendering */
 volatile int render_request = 0;
 
 /*
  * update_music_ISR - Stub function to update the music.
  * In a full implementation, this routine updates PSG registers to step to the next note.
  */
 void update_music_ISR(void) {
     /* Example: update PSG tone registers here using write_psg.
        This function must execute quickly since it is called from the ISR.
     */
 }
 
 /*
  * vbl_handler - Called by the VBL ISR.
  * Updates the music and any synchronous events, then sets the render_request flag.
  */
 void vbl_handler(void) {
     /* Update music from within the ISR */
     update_music_ISR();
 
     /* Process any other synchronous events here if needed */
 
     /* Set the global render_request flag so the main loop renders the next frame */
     render_request = 1;
 }
 
 /*
  * Circular buffer definitions for IKBD input data.
  */
 #define IKBD_BUFFER_SIZE 64
 
 volatile unsigned char ikbd_buffer[IKBD_BUFFER_SIZE];
 volatile int ikbd_head = 0;
 volatile int ikbd_tail = 0;
 
 /*
  * ikbd_enqueue - Enqueues an incoming IKBD byte into a circular buffer.
  * Parameters:
  *   byte - The incoming byte from the IKBD 6850.
  */
 void ikbd_enqueue(unsigned char byte) {
     ikbd_buffer[ikbd_head] = byte;
     ikbd_head = (ikbd_head + 1) % IKBD_BUFFER_SIZE;
     /* If the buffer is full, advance the tail to discard the oldest data */
     if (ikbd_head == ikbd_tail) {
         ikbd_tail = (ikbd_tail + 1) % IKBD_BUFFER_SIZE;
     }
 }
 
 /*
  * ikbd_handler - Called by the IKBD ISR.
  * Reads a byte from the IKBD 6850 data register and enqueues it.
  */
 void ikbd_handler(void) {
     /* For simulation purposes, assume the IKBD 6850 data register is located at address IKBD_DATA_REG.
        In a real system, define IKBD_DATA_REG with the correct value.
     */
     #define IKBD_DATA_REG ((volatile unsigned char *)0xFFFA03)
     unsigned char byte = *IKBD_DATA_REG;
     ikbd_enqueue(byte);
 }
 
 /*
  * ikbd_get_byte - Retrieves the next byte from the IKBD circular buffer.
  * Returns:
  *   The next byte as an int, or -1 if the buffer is empty.
  */
 int ikbd_get_byte(void) {
     if (ikbd_head == ikbd_tail) {
         return -1;  /* Buffer is empty */
     }
     unsigned char byte = ikbd_buffer[ikbd_tail];
     ikbd_tail = (ikbd_tail + 1) % IKBD_BUFFER_SIZE;
     return (int)byte;
 }
 