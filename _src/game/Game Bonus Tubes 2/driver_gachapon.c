#include "gachapon.h"
#include <stdio.h>

int main()  {
    int score = 0;
    int n = 0;
    /*
    while (n < 100) {
        printf("%d",randomizer(0,5,&score));
        n++;
    }
    */
    gachapon(&score);
    return 0;
}