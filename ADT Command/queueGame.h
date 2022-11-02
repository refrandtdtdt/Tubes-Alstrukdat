/* File : queueGame.h */

#ifndef QUEUEGAME_H
#define QUEUEGAME_H

#include "../ADT Default/list.h"
#include "../ADT Default/queue.h"

void tambahAntrianGame (List * list_game, Queue * queue_game);
/*
Prosedur ini akan membaca masukan game yang akan ditambahkan user ke dalam antrian game
I.S. Sudah tersedia list game dan queue game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila masukan masih di dalam rentang nomor game di dalam list game, maka game dengan nomor game sesuai
                masukan akan masuk ke queue game
     Kondisi 2) Apabila masukan di luar rentang, akan mengeluarkan pesan kesalahan dan user akan diminta untuk input
                masukan lagi sampai masukan valid
*/

#endif