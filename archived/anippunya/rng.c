#include "rng.h"

void RNG()
{
    srand(time(NULL));
    int x = (rand() % 30);
    int skor = 100;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    STARTSTDIN();
    while (WordToInt(currentWord) != x)
    {
        if (WordToInt(currentWord) > x)
        {
            printf("Lebih kecil\n");
            skor-=10;
        }
        else if (WordToInt(currentWord) < x)
        {
            printf("Lebih besar\n");
            skor-=10;
        }
        printf("Tebakan: ");
        STARTSTDIN();
    }
    printf("\nYa, X adalah %d.\n", x);
    printf("Skor : %d\n", skor);
}

int main()
{
    RNG();
}
