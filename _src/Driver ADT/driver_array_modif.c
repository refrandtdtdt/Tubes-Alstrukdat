#include <stdio.h>
#include "../ADT/array_modif.h"
#include "../ADT/mesinkata_modif.h"
#include "../ADT/mesinkar.h"
#include "../ADT/functions.h"

int main () {
    // Membuat array kosong
    TabGame array; MakeEmpty(&array);
    TabGame arrayCopy; MakeEmpty(&arrayCopy);

    // Mengisi array
    printf("Isi arraynya dulu gan:\n");
    for (int i = 0; i < 5; i++) {
        START();
        CopyWord();
        SetEl(&array, i, currentWord);
    }
    printf("\n");

    // Print isi array
    printf("Berikut isi arraynya gan:\n");
    TulisIsi(array);
    printf("\n");

    // Melihat jumlah elemen di array
    printf("Jumlah elemen array: %d\n", NbElmt(array));
    printf("\n");

    // Melihat maksimum elemen yang dapat ditampung array
    printf("Maksimum jumlah elemen array: %d\n", MaxNbEl(array));
    printf("\n");

    // Selektor indeks
    printf("Indeks elemen pertama array: %d\n", GetFirstIdx(array));
    printf("Indeks elemen terakhir array: %d\n", GetLastIdx(array));
    printf("\n");

    // Menghasilkan elemen tertentu
    printf("Elemen ke 3 array adalah: %s\n", array.TG[2].TabWord);
    printf("\n");

    // Set isi array ke arrayCopy
    SetTab(array, &arrayCopy);

    // print isi arrayCopy
    printf("Berikut isi arrayCopynya gan:\n");
    TulisIsi(arrayCopy);
    printf("\n");

    // Set elemen efektif
    SetNeff(&arrayCopy, 10);

    // Melihat jumlah elemen dalam arrayCopy setelah set neff baru
    printf("Jumlah elemen arrayCopy setelah jadi 10: %d\n", NbElmt(arrayCopy));
    printf("\n");

    // Uji indeks
    printf("Apakah 99 termasuk indeks valid dalam arrayCopy?\n");
    if (IsIdxValid(arrayCopy, 99)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("Apakah 22 termasuk indeks efektif dalam arrayCopy?\n");
    if (IsIdxEff(arrayCopy, 22)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");

    // Cek is empty
    printf("Apakah array kosong?\n");
    if (IsEmpty(array)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");
    
    // Cek is full
    printf("Apakah array full?\n");
    if (IsFull(array)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");
    return 0;
}