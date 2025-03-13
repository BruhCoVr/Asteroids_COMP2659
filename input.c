#include <osbind.h>
#include "input.h"

/* Check if input is pending */
int InputPending() {
    return Cconis();
}

/* Read input */
char ReadInput() {
    return (char)Cnecin();
}