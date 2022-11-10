/*File: deletegame.h*/

#ifndef DELETEGAME_H
#define DElETEGAME_H
#include "../ADT DEFAULT/array.h"

void HapusGame(TabGame *T);
/*I.S Tab terdefinisi dan tidak kosong */
/*F.S elemen game ke-i dihapus dari tab game sesuai dengan keinginan user*/
/*Syarat penghapusan game: 
- Game yang dapat dihapus hanyalah game yang dibuat secara custom sendiri oleh user
- Lima Game pertama yang terdapat dlaam file konfigurasi (game default) tidak dapat dihapus 
- Game yang berada dalam queue game (antrian game) tidak dapat dihapus */
#endif