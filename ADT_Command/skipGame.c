#include <stdio.h>
#include "skipGame.h"

void lewatiGame (Queue * antrian_game, ElType jumlah_skip) {
    printf("Berikut adalah daftar game dalam antrianmu\n");
    int i;
    for (i = 0; i < length((*antrian_game)); i++) {
        printf("%d. %d\n", i+1, (*antrian_game).buffer[(i + IDX_HEAD((*antrian_game))) % CAPACITY]);
    }

    if (isEmpty(*antrian_game)) {
        printf("Belum ada game dalam antrianmu.\n");
        printf("Silakan masukkan command QUEUE GAME untuk menambahkan game dalam antrianmu.\n");
    } else {

    }

    if (jumlah_skip < length(*antrian_game)) {
        int j;
        int dummySkip;
        for (j = 0; j < jumlah_skip; j++) {
            dequeue((antrian_game), &dummySkip);
        }
        int dummy;
        dequeue(antrian_game, &dummy);

        if (dummy == 1) { // 1 asumsinya RNG
            printf("Loading RNG ...\n");
            // Panggil fungsi game RNG
        } else if (dummy == 2) { // 2 asumsinya Diner DASH
            printf("Loading  Diner DASH ...\n");
            // Panggil fungsi game Diner DASH
        } else if ((dummy == 3) || (dummy == 4) || (dummy == 5)) { // asumsinya 3 = DINOSAUR IN EARTH, 4 = RISEWOMAN, 5 = EIFFEL TOWER
            if (dummy == 3) {
                printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            } else if (dummy == 4) {
                printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            } else if (dummy == 5) {
                printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            }
        } else {
            // panggil fungsi game tambahan (angka random)
        }
    } else {
        int j;
        int dummy;
        for (j = 0; j < length((*antrian_game)); j++) {
            dequeue((antrian_game), &dummy);
        }
        printf("Tidak ada permainan lagi dalam antrian game-mu\n");
    }
}
/*
Prosedur ini akan melewati sebanyak <jumlah_skip> game, game yang dilewati akan dikeluarkan dari antrian game,
lalu langsung memainkan game yang terletak pada antrian pertama pada antrian game setelah game-game tadi dilewati
I.S. Sudah tersedia antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila <jumlah_skip> tidak melebihi jumlah antrian game dan game dalam antrian pertama setelah
                skip bisa dimainkan, maka akan mengeluarkan output sedang loading game, lalu memainkan game.
                Game yang dimainkan akan dikeluarkan dari antrian game
     Kondisi 2) Apabila <jumlah_skip> tidak melebihi jumlah antrian game dan game dalam antrian pertama setelah
                skip tidak bisa dimainkan (dalam maintenance), maka akan mengeluarkan output bahwa tidak bisa
                memainkan game. Game yang tidak bisa dimainkan tersebut dikeluarkan dari antrian game
     Kondisi 3) Apabila <jumlah_skip> sama atau melebihi jumlah antrian game, maka semua game dalam antrian akan
                dikeluarkan dari antrian game, lalu menampilkan pesan bahwa tidak ada permainan lagi dalam antrian
                game  
Asumsi : <jumlah_skip> sudah pasti valid setelah memanggil prosedur ini (<jumlah_skip> >= 0) 
Note : apabila antrian game kosong, akan mengeluarkan output bahwa belum ada game dalam antrian dan cara memasukkan
       game ke dalam antrian
*/