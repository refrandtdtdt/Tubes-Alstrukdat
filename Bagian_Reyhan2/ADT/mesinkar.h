#ifndef __MESIN_KAR__
#define __MESIN_KAR__
#include "../boolean.h"
#include <stdio.h>
/* State Mesin */
extern char cc;
extern boolean eop;
extern boolean file;

#define MARKCHAR '~'
/* State Mesin */

void STARTCHAR(char* filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADVCHAR();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCCCHAR();
/* Mengirimkan currentChar */

boolean IsEOPCHAR();
/* Mengirimkan true jika currentChar = MARK */

void CHARMACHINE(char* filename);

char cc;
boolean eop;
boolean file;
FILE *pita;
int retval;

void ADV();
void START();

boolean STARTF(char* filename);
void CLOSEF();
void STARTW(char* filename);

#endif