/*
 * ikbd_isr.s
 * Custom IKBD ISR for handling keyboard and mouse input.
 * This ISR is installed in place of TOS’s IKBD ISR. It performs the following:
 *   - Saves registers,
 *   - Calls a C handler to process an incoming byte from the IKBD 6850,
 *   - Clears bit #6 of the MFP “in service B” register (at address $FFFA11) before returning.
 *
 */

    .section .text
    .global ikbd_isr
ikbd_isr:
    /* Save registers */
    move.w  d0, -(sp)
    move.w  d1, -(sp)
    move.w  a0, -(sp)

    /* Call the C IKBD handler subroutine (label _ikbd_handler) */
    jsr     _ikbd_handler

    /* Clear bit #6 of the MFP “in service B” register at address $FFFA11 */
    move.b  ($FFFA11).l, d0
    andi.b  #$BF, d0   /* 0xBF = 0xFF with bit 6 cleared (0x40 is bit 6) */
    move.b  d0, ($FFFA11).l

    /* Restore registers */
    move.w  (sp)+, a0
    move.w  (sp)+, d1
    move.w  (sp)+, d0

    rte
