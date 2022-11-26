#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"
#include "functions.h"

/* State Mesin */
char cc;
boolean eop;
boolean file;
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

void ADV()
{
   retval = fscanf(pita,"%c",&cc);
   eop = cc == '\n';
   if (eop && !file)
   {
      rewind(pita);
   }
   else if (retval == EOF && file)
   {
      fclose(pita);
   }
}

void START()
{
   file = false;
   pita = stdin;
   ADV();
}

boolean STARTF(char* filename) {
    file = true;
    pita = fopen(filename,"r");
    if (pita == NULL)
    {
      return false;
    }
    else
    {
      ADV();
      return true;
    }
}
void CLOSEF() {
   fclose(pita);
}
void STARTW(char* filename) {
   fopen(filename,"w");
   pita = fopen(filename,"w");
}