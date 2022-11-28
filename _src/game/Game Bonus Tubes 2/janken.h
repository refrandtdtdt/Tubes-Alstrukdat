#ifndef JANKEN
#define JANKEN

#include "randomizer.h"
#include "..\..\boolean.h"

typedef struct  {
    char* name;
} Janken;
/* buat gunting batu kertas*/
void janken(int *score);

#endif