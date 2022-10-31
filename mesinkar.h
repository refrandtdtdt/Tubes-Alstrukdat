#ifndef __MESIN_KAR__
#define __MESIN_KAR__
#include "boolean.h"
#include <stdio.h>
#define MARK '.'
/* State Mesin */
extern char cc;
extern boolean eop;

char cc;
boolean eop;
static FILE *pita;
static int retval;

void startread(char* filename) {
    pita = fopen(filename,"r");
    adv();
}

void startwrite(char* filename) {
    pita = fopen(filename,"w");
    adv();
}

void adv() {
    retval = fscanf(pita,"%c",&cc);
    eop = (cc == MARK);
    if (eop) {
        fclose(pita);
    }
}

#endif