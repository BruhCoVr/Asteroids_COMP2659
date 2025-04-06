;-----------------------------------------------------------------------------
; UINT32 get_video_base(void)
; Returns current video base address (24-bit address in 32-bit return value)
;-----------------------------------------------------------------------------
_get_video_base:
    move.l  #0xFFFF8201, a0    ; Point to video base high byte register
    clr.l   d0                 ; Clear all 32 bits of return register
    
    move.b  (a0), d0           ; Read high byte (bits 16-23)
    lsl.l   #8, d0             ; Shift left 8 bits
    move.b  2(a0), d0          ; Read middle byte (bits 8-15 from 0xFFFF8203)
    lsl.l   #8, d0             ; Shift left 8 more bits (bits 0-7 = 0)
    
    rts                        ; Returns 24-bit address in d0 (upper 8 bits 0)
    
    
;-----------------------------------------------------------------------------
; void set_video_base(UINT32 new_base)
; Sets new video base address (must be 256-byte aligned)
;-----------------------------------------------------------------------------
_set_video_base:
    move.l  4(sp), d0          ; Get 32-bit parameter from stack
    lsr.l   #8, d0             ; Shift right 8 bits to align high/middle bytes
    
    move.l  #0xFFFF8201, a0    ; Point to video base register pair
    movep.w d0, (a0)           ; ATOMIC write to both 8201 (high) and 8203 (middle)
    
    rts