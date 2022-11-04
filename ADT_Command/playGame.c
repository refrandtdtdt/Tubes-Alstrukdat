#include <stdio.h>
#include "playGame.h"

void mainkanGame (Queue * antrian_game) {
    printf("Berikut adalah daftar game dalam antrianmu\n");
    int i;
    for (i = 0; i < length((*antrian_game)); i++) {
        printf("%d. %d\n", i+1, (*antrian_game).buffer[(i + IDX_HEAD((*antrian_game))) % CAPACITY]);
    }

    if (isEmpty(*antrian_game)) {
        printf("Belum ada game dalam antrianmu.\n");
        printf("Silakan masukkan command QUEUE GAME untuk menambahkan game dalam antrianmu.\n");
    } else {
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
    }
}
/*
Prosedur ini akan langsung memainkan game yang terletak pada antrian pertama pada antrian game
I.S. Sudah tersedia antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila game dalam antrian pertama bisa dimainkan, maka akan mengeluarkan output sedang loading 
                game, lalu memainkan game. Game yang dimainkan akan dikeluarkan dari atrian game
     Kondisi 2) Apabila game dalam antrian pertama tidak bisa dimainkan (dalam maintenance), maka akan mengeluarkan
                output bahwa tidak bisa memainkan game. Game yang tidak bisa dimainkan tersebut dikeluarkan dari
                antrian game
Note : apabila antrian game kosong, akan mengeluarkan output bahwa belum ada game dalam antrian dan cara memasukkan
       game ke dalam antrian
*/