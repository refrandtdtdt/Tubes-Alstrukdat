#include <stdio.h>
#include "../ADT/stack_modif.c"
#include "../ADT/mesinkata_modif.c"
#include "../ADT/mesinkar.c"
#include "../ADT/functions.c"

int main () {
    // Membuat stack kosong
    Stack S1; CreateEmpty(&S1);
    Stack S2; CreateEmpty(&S2);
    Stack S3; CreateEmpty(&S3);

    // Mengisi stack
    printf("Isi stack 1 dulu gan:\n");
    for (int i = 0; i < 3; i++) {
        START();
        CopyWord();
        Push(&S1, currentWord);
    }
    printf("\n");

    printf("Isi stack 2 dulu gan:\n");
    for (int i = 0; i < 3; i++) {
        START();
        CopyWord();
        Push(&S2, currentWord);
    }
    printf("\n");

    printf("Isi stack 3 dulu gan:\n");
    for (int i = 0; i < 3; i++) {
        START();
        CopyWord();
        Push(&S3, currentWord);
    }
    printf("\n");

    // Print isi ketiga stack
    printf("Isi ketiga stacknya gan:\n");
    Display3Stack(S1, S2, S3);
    printf("\n");

    // Print isi 1 stack
    printf("Isi stack pertama gan:\n");
    DisplayStack(S1);
    printf("\n");

    // Membandingkan 2 stack
    if (isEqStack(S1, S2)) {
        printf("Kedua stack sama gan\n");
    } else {
        printf("Kedua stack beda gan\n");
    }
    printf("\n");

    // Melihat apakah stack tinggal tiang atau ada piringannya
    if (isNoPiring(S1)) {
        printf("Ga ada piringannya gan\n");
    } else {
        printf("Ada piringannya gan\n");
    }
    return 0;
}