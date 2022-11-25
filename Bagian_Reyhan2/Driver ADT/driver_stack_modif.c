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
    int intJumlahPiringan = 3;
    int i, j;
    Word piringN;

    // Mengisi stack 1 dan stack 2
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

    // Stack 3 auto aja (tiang doang untuk nguji isNoPiring)
    for (i = 0; i < (intJumlahPiringan); i++) {
        for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
            if (j == (intJumlahPiringan - 1)) {
                piringN.TabWord[j] = '|';
            } else {
                piringN.TabWord[j] = ' ';
            }
        }
        Push(&S3, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }
    printf("\n");

    // Print isi ketiga stack
    printf("Isi ketiga stacknya gan:\n");
    Display3Stack(S1, S2, S3, intJumlahPiringan);
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

    // Print isi S3
    printf("Isi stack S3:\n");
    DisplayStack(S3);

    // Melihat apakah stack S3 tinggal tiang aja atau ada piringannya
    if (isNoPiring(S3, intJumlahPiringan)) {
        printf("S3 ga ada piringannya gan\n");
    } else {
        printf("S3 ada piringannya gan\n");
    }
    return 0;
}