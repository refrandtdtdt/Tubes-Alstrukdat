#include <stdio.h>
#include "mesinkar.h"
/* State Mesin */
char cc;
boolean eop;
boolean file;
FILE *pita;
int retval;

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

void STARTF(char* filename) {
    file = true;
    pita = fopen(filename,"r");
    ADV();
}
void CLOSEF() {
   fclose(pita);
}
void STARTW(char* filename) {
   fopen(filename,"w");
   pita = fopen(filename,"w");
}