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

    int jumlahEl = NbElmt(daftar_game);
    printf("Panjangnya gan :\n");
    printf("%d\n", jumlahEl);

    printf("hasilnya gan :\n");
    for (int j = 1; j <= jumlahEl; j++) {
        printf("%d\n", GetElmt(daftar_game, j));
    }

    tambahAntrianGame(daftar_game, &antrian_game);
    return 0;
}