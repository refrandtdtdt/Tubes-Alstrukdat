#include <stdio.h>
#include "../ADT_Command/skipGame.h"

int main () {
    Queue antrian_game; CreateQueue(&antrian_game);
    int i, masukan;

    printf("Masukkan gan :\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &masukan);
        enqueue(&antrian_game, masukan);
    }

    lewatiGame(&antrian_game, 6);

    int j;
    printf("Antrian game sekarang :\n");
    for (j = 0; j < length((antrian_game)); j++) {
        printf("%d. %d\n", j+1, (antrian_game).buffer[(j + IDX_HEAD((antrian_game))) % CAPACITY]);
    }
    return 0;
}