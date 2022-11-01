# include "game_tambahan.h"

void GameTambahan() {
    srand(time(0));
    int random = rand() % 100;
    printf("Permainan Selesai, Skor: %d\n", random);
}

int main()
{
    GameTambahan();
    return 0;
}