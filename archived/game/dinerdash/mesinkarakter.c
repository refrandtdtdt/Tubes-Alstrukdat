# include <stdio.h>
# include "mesinkarakter.h"

char cc;
boolean eop;

FILE *pita;
int retval;

boolean IsEOPCHAR()   {
    return (cc == MARKCHAR);
}

void STARTCHAR(char* filename)    {
    pita = fopen(filename, "r");
    ADVCHAR();
}

void ADVCHAR()  {
    retval = fscanf(pita, "%c", &cc);
    eop = IsEOPCHAR();
    if (eop)    {
        fclose(pita);
    }
}

char GetCCCHAR()    {
    return cc;
}

void CHARMACHINE(char* filename)  {
    STARTCHAR(filename);
    while (!IsEOPCHAR())  {
        printf("%c", cc);
        ADVCHAR();
    }
}