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

void adv() {
    retval = fscanf(pita,"%c",&cc);
    eop = (cc == MARK);
    if (eop) {
        fclose(pita);
    }
}
void advline(char* str)
{
    int i=0;
    while (cc != '\n' && cc != '\0')
    {
        str[i] = cc;
        adv();
        i++;
    }
    adv();
}

void startread(char* filename) {
    pita = fopen(filename,"r");
    adv();
}

void startwrite(char* filename) {
    pita = fopen(filename,"w");
    adv();
}

#endif