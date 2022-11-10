# include "game_tambahan.h"

void GameTambahan() {
    srand(time(0));
    int random = abs((rand() % 100 + (rand() % 100)*pow(-1, rand()))) % 100 + abs((rand() % 50)*pow(-1, rand()));
    printf("Permainan Selesai, Skor: %d\n", random);
}
int main()
{
    GameTambahan();
    return 0;
}