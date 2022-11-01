#include <stdio.h>


#include "../ADT Default/list.c"

int main () {
    List L;
    int masukan;
    MakeList();
    printf("Masukkan input :\n");
    for (int i = 0; i <= 4; i++) {
        scanf("%d\n", &masukan);
        InsertLast(&L, masukan);
    }
    for (int j = 0; j <= 4; j++) {
        printf("%d\n", Get(L, j));
    }
    return 0;
}