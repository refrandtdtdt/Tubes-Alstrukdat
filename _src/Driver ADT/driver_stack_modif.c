#include <stdio.h>
#include "../ADT/stack_modif.h"
#include "../ADT/mesinkata_modif.h"
#include "../ADT/mesinkar.h"
#include "../ADT/functions.h"

int main () {
    // Membuat stack kosong
    Stackt S1; CreateEmptyStackt(&S1);
    Stackt S2; CreateEmptyStackt(&S2);
    Stackt S3; CreateEmptyStackt(&S3);
    int intJumlahPiringan = 3;
    int i, j;
    Word piringN;

    // Mengisi stack 1 dan stack 2
    printf("Isi stack 1 dulu gan:\n");
    for (int i = 0; i < 3; i++) {
        START();
        CopyWord();
        PushStack(&S1, currentWord);
    }
    printf("\n");

    // Stack 2 auto aja (tiang doang untuk nguji isNoPiring)
    for (i = 0; i < intJumlahPiringan; i++) {
        for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
            if ((j >= (intJumlahPiringan - 1) - (intJumlahPiringan - 1 - i)) && (j <= (intJumlahPiringan - 1) + (intJumlahPiringan - 1 - i))) {
                piringN.TabWord[j] = '*';
            } else {
                piringN.TabWord[j] = ' ';
            }
        }
        PushStack(&S2, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }
    printf("\n");

    // Stack 3 auto aja (untuk nguji isNoPiring)
    for (i = 0; i < (intJumlahPiringan - 1); i++) {
        for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
            if ((j >= (intJumlahPiringan - 1) - (intJumlahPiringan - 1 - i)) && (j <= (intJumlahPiringan - 1) + (intJumlahPiringan - 1 - i))) {
                piringN.TabWord[j] = '*';
            } else {
                piringN.TabWord[j] = ' ';
            }
        }
        PushStack(&S3, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }
    for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
        if (j == (intJumlahPiringan - 1)) {
            piringN.TabWord[j] = '|';
        } else {
            piringN.TabWord[j] = ' ';
        }
    }
    PushStack(&S3, piringN);
    for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
        piringN.TabWord[j] = '\0';
    }
    // for (i = 0; i < (intJumlahPiringan - 1); i++) {
    //     for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
    //         if (j == (intJumlahPiringan - 1)) {
    //             piringN.TabWord[j] = '|';
    //         } else {
    //             piringN.TabWord[j] = ' ';
    //         }
    //     }
    //     PushStack(&S3, piringN);
    //     for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
    //         piringN.TabWord[j] = '\0';
    //     }
    // }
    // for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
    //     piringN.TabWord[j] = '*';
    // }
    // PushStack(&S3, piringN);
    // for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
    //     piringN.TabWord[j] = '\0';
    // }
    // printf("\n");

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
    printf("S3 ada piringannya ga gan?\n");
    if (isNoPiring(S3, intJumlahPiringan)) {
        printf("Ga ada gan\n");
    } else {
        printf("Ada gan\n");
    }

    // Melihat apakah isPiringAsalBigger jalan (pake S2 dan S3)
    printf("\nPiring S2 gede ga dari piring S3 gan?\n");
    if (isPiringAsalBigger(S2, S3, intJumlahPiringan)) {
        printf("Iya gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\nPiring S3 gede ga dari piring S2 gan?\n");
    if (isPiringAsalBigger(S3, S2, intJumlahPiringan)) {
        printf("Iya gan\n");
    } else {
        printf("Kaga gan\n");
    }

    return 0;
}