#include <stdio.h>
#include "../ADT_Command/playGame.h"

int main () {
    Queue antrian_game; CreateQueue(&antrian_game);
    int i, masukan;

    printf("Masukkan gan :\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &masukan);
        enqueue(&antrian_game, masukan);
    }

    mainkanGame(&antrian_game);

    int j;
    printf("Antrian game sekarang :\n");
    for (j = 0; j < length(antrian_game); j++) {
        printf("%d. %d\n", j+1, antrian_game.buffer[j]);
    }
    return 0;
}