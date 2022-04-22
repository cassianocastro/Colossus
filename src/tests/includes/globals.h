#ifndef GLOBALS_H

#define GLOBALS_H

#include <stdbool.h>

typedef unsigned int uint;
typedef unsigned char byte;

typedef struct
{
    uint value;
    byte sex;
    byte type;
} inputs;

typedef struct
{
    int c;
    int d;
    int u;
} houses;

bool isMulher, isOrdinal, isLastDivision;

#endif