#include "..\janken.h"
#include <stdio.h>

int main()  {
    int score = 0;
    boolean win;
    janken(&score, 100, 100, &win);
    printf("score = %d\n", score);
    return 0;
}