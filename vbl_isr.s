/*
 * vbl_isr.s
 * Custom Vertical Blank ISR for the game.
 * This ISR is installed in place of the TOS VBL ISR. Its responsibilities include:
 *   - Updating music (via a C subroutine),
 *   - Processing any other synchronous events,
 *   - Setting a global render_request flag to request that the next frame be rendered.
 *
 */

    .section .text
    .global vbl_isr
vbl_isr:
    /* Save registers */
    move.w  d0, -(sp)
    move.w  d1, -(sp)
    move.w  a0, -(sp)
    move.w  a1, -(sp)

    /* Call the C VBL handler subroutine (label _vbl_handler) */
    jsr     _vbl_handler

    /* Restore registers */
    move.w  (sp)+, a1
    move.w  (sp)+, a0
    move.w  (sp)+, d1
    move.w  (sp)+, d0

    rte
