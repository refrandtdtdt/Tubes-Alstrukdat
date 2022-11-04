#include <stdio.h>
#include "../ADT_Command/queueGame.h"

int main () {
    TabInt daftar_game; MakeEmpty(&daftar_game);
    Queue antrian_game; CreateQueue(&antrian_game);

    printf("Masukkan gan :\n");
    int masukan;
    for (int i = 1; i <= 5; i++) {
        scanf("%d", &masukan);
        SetEl(&daftar_game, i, masukan);
    }

    tambahAntrianGame(daftar_game, &antrian_game);

    int j;
    printf("Antrian game sekarang :\n");
    for (j = 0; j < length((antrian_game)); j++) {
        printf("%d. %d\n", j+1, (antrian_game).buffer[(j + IDX_HEAD((antrian_game))) % CAPACITY]);
    }
    return 0;
}