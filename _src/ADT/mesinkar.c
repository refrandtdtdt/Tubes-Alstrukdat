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
    char path[] = "_data/";
    char filepath[] = ".................................................";
    clear(filepath);// = (char*) malloc ((len(filename)+len(path)-2)*sizeof(char));
    int i = 0;
    while (i < len(path))
    {
      filepath[i] = path[i];
      i++;
    }
    int j = 0;
    while (i-len(path) < len(filename))
    {
      filepath[i] = filename[j];
      i++;
      j++;
    }
    i=0;
    pita = fopen(filepath,"r");
    ADV();
}
void CLOSEF() {
   fclose(pita);
}
void STARTW(char* filename) {
   char path[] = "_data/";
   char filepath[] = ".................................................";
   clear(filepath);// = (char*) malloc ((len(filename)+len(path)-2)*sizeof(char));
   int i = 0;
   while (i < len(path))
   {
      filepath[i] = path[i];
      i++;
   }
   int j = 0;
   while (i-len(path) < len(filename))
   {
      filepath[i] = filename[j];
      i++;
      j++;
   }
   i=0;
   fopen(filepath,"w");
   pita = fopen(filepath,"w");
}