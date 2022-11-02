#include <stdio.h>
#include "../ADT_Command/queueGame.h"

int main () {
    TabInt daftar_game; MakeEmpty(&daftar_game);
    Queue antrian_game; CreateQueue(&antrian_game);

    printf("Masukkan gan :\n");
    int masukan;
    for (int i = 0; i < 5; i++) {
        scanf("%d\n", &masukan);
        SetEl(&daftar_game, i, masukan);
    }
    tambahAntrianGame(daftar_game, &antrian_game);
    return 0;
}