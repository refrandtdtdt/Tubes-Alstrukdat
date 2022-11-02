#include <stdio.h>
#include "queueGame.h"

void tambahAntrianGame (List * list_game, Queue * queue_game) {
    // Mengeluarkan output game-game yang sedang dalam antrian
    printf("Berikut adalah daftar antrian game-mu\n");
    for (int i = 0; i < length(*queue_game); i++) {
        printf("%d. %s\n", i+1, (*queue_game).buffer[i]);
    }
    printf("\n");
    // Mengeluarkan output game-game yang terdapat dalam list
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int j = 0; j < Length(*list_game); j++) {
        printf("%d. %s\n", j+1, Get((*list_game), j));
    }
}
/*
Prosedur ini akan membaca masukan game yang akan ditambahkan user ke dalam antrian game
I.S. Sudah tersedia list game dan queue game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila masukan masih di dalam rentang nomor game di dalam list game, maka game dengan nomor game sesuai
                masukan akan masuk ke queue game
     Kondisi 2) Apabila masukan di luar rentang, akan mengeluarkan pesan kesalahan dan user akan diminta untuk input
                masukan lagi sampai masukan valid
*/