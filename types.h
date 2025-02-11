#ifndef TYPES_H
#define TYPES_H

/* Define an unsigned 8-bit integer type */
typedef unsigned char UINT8;

/* Define an unsigned 16-bit integer type */
typedef unsigned int UINT16;

/* Define an unsigned 32-bit integer type */
typedef unsigned long UINT32;

/* Enumeration for numbers 0 through 9 */
typedef enum {
    num_0 = 0,  /* Represents the number 0 */
    num_1,      /* Represents the number 1 */
    num_2,      /* Represents the number 2 */
    num_3,      /* Represents the number 3 */
    num_4,      /* Represents the number 4 */
    num_5,      /* Represents the number 5 */
    num_6,      /* Represents the number 6 */
    num_7,      /* Represents the number 7 */
    num_8,      /* Represents the number 8 */
    num_9,      /* Represents the number 9 */
    TotalNumbers /* Total count of numbers in the enumeration */
} NumberEnum;

#endif /* TYPES_H */