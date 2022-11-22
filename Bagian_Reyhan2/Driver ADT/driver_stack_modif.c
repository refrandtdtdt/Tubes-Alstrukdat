#include <stdio.h>
#include "../ADT/stack_modif.h"
#include "../ADT/mesinkata_modif.h"
#include "../ADT/mesinkar.h"
#include "../ADT/functions.h"

int main () {
    // Membuat stack kosong
    Stack S;
    CreateEmpty(&S);

    // Mengisi stack
    printf("Isi stacknya dulu gan:\n");
    for (int i = 0; i < 5; i++) {
        START();
        CopyWord();
        Push(&S, currentWord);
    }

    // Print isi stack
    printf("Isi stacknya gan:\n");
    DisplayStack(S);
    printf("\n");
    return 0;
}