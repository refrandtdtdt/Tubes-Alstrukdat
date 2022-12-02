/*File hangman.h*/

#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "arraykata.h"
#include "../../ADT/functions.h"
#include <time.h>
#include "../../ADT/map_scoreboard.h"

void hangman (ScoreBoard * scoreboard); 
/* prosedur ini akan membaca sebuah masukkan bertipe char berupa tebakan kata atau gnka dan prgogram akan megnecek
satu per satu apakah tebakan tersebut sesuai atau tidak. 
I.S Sembarang 
F.S Mereturn score berdasarkan panjang kata yang ditebak */
#endif