#ifndef JANKEN
#define JANKEN

#include "randomizer.h"
#include "..\..\boolean.h"
#include "..\..\ADT\mesinkar.h"
#include "..\..\ADT\mesinkata_modif.h"
#include "..\..\ADT\functions.h"

typedef struct  {
    char* name;
} Janken;
/* buat gunting batu kertas*/
void janken(int *score, int win_score, int lose_score, boolean *win_state);

#endif