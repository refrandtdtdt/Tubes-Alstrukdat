/* File : playGame.h */

#ifndef PLAYGAME_H
#define PLAYGAME_H

#include "../ADT_Default/queue.h"

void mainkanGame (Queue * antrian_game);
/*
Prosedur ini akan langsung memainkan game yang terletak pada antrian pertama pada antrian game
I.S. Sudah tersedia antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila game dalam antrian pertama bisa dimainkan, maka akan mengeluarkan output sedang loading 
                game, lalu memainkan game. Game yang dimainkan akan dikeluarkan dari antrian game
     Kondisi 2) Apabila game dalam antrian pertama tidak bisa dimainkan (dalam maintenance), maka akan mengeluarkan
                output bahwa tidak bisa memainkan game. Game yang tidak bisa dimainkan tersebut dikeluarkan dari
                antrian game
*/

#endif