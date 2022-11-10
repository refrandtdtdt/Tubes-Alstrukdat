#include "boolean.h"
#include <stdio.h>
#include "mesinkar.h"
/* State Mesin */
char cc;
boolean eop;
boolean file;
static FILE *pita;
static int retval;

void ADV()
{
   retval = fscanf(pita,"%c",&cc);
   eop = cc == '\n';
   if (eop && !file)
   {
      rewind(pita);
   }
   else if (eop && file)
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

void STARTF(char* filename) {
    file = true;
    pita = fopen(filename,"r");
    ADV();
}

void STARTW(char* filename) {
    pita = fopen(filename,"w");
    ADV();
}