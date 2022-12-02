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

boolean IsEOPPrint()  {
  return (cc == MARKPRINT);
}

void STARTCHAR(char* filename)    {
    pita = fopen(filename, "r");
    ADVCHAR();
}

void STARTPRINT(char* filename) {
    pita = fopen(filename, "r");
    ADVPRINT(); 
}

void ADVCHAR()  {
    retval = fscanf(pita, "%c", &cc);
    eop = IsEOPCHAR();
    if (eop)    {
        fclose(pita);
    }
}

void ADVPRINT() {
    retval = fscanf(pita, "%c", &cc);
    eop = IsEOPPrint();
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

void PRINTMACHINE(char* filename) {
    STARTPRINT(filename);
    while (!IsEOPPrint())  {
        printf("%c", cc);
        ADVPRINT();
    }
}

boolean STARTFlocal(char* filename) {
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

void STARTWlocal(char* filename) {
   pita = fopen(filename,"w");
}