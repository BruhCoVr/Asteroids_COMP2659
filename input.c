//#include <osbind.h>
#include "input.h"

/* Check if input is pending */
int input_pending() {
    return Cconis();
}

/* Read input */
char read_input() {
    return (char)Cnecin();
}