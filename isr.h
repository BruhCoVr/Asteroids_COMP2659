/*
 * isr.h
 * Header for custom ISR C handlers and shared definitions.
 *
 */

 #ifndef ISR_H
 #define ISR_H
 
 /* Global flag set by the VBL ISR to request a render in the main loop */
 extern volatile int render_request;
 
 /* C handlers for custom ISRs */
 void vbl_handler(void);
 void ikbd_handler(void);
 int ikbd_get_byte(void);
 
 #endif /* ISR_H */
 