#include <stdio.h>
#include "../ADT_Command/queueGame.h"

int main () {
    Set daftar_game; CreateEmpty(&daftar_game);
    Queue antrian_game; CreateQueue(&antrian_game);

    printf("Masukkan gan :\n");
    char masukan[20];
    for (int i = 0; i < 5; i++) {
        scanf("%d\n", &masukan);
        Insert(&daftar_game, masukan);
    }

    return 0;
}