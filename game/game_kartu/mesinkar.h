#ifndef __MESIN_KAR__
#define __MESIN_KAR__
#include "boolean.h"
#include <stdio.h>
/* State Mesin */
extern char cc;
extern boolean eop;
extern boolean file;

char cc;
boolean eop;
boolean file;
static FILE *pita;
static int retval;

void ADV();
void START();

void STARTF(char* filename);

void STARTW(char* filename);

#endif