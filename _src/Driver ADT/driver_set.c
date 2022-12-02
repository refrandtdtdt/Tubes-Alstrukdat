#include <stdio.h>
#include "../ADT/set.h"
#include "../ADT/mesinkata_modif.h"
#include "../ADT/mesinkar.h"
#include "../ADT/functions.h"

int main () {
    // Deklarasi variabel dan membuat set kosong
    Set S; CreateEmptySet(&S);
    int i, j;
    char * strInput;

    // Menginput elemen ke set
    printf("Masukkan isi set dulu gan:\n");
    for (i = 0; i < 5; i++) {
        START();
        CopyWord();
        strInput = kataToString(currentWord);
        InsertSet(&S, strInput);
    }
    printf("\n");

    // Print isi set
    printf("Isi set: ");
    for (j = 0; j < S.Count; j++) {
        printf("%s", S.Elements[j]);
        if (j < 4) {
            printf(", ");
        }
    }
    printf("\n\n");

    // Cek 'aku' member dari set atau ga
    printf("String 'aku' bagian dari set ga?\n");
    if (IsMemberSet(S, "aku")) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");

    // Cek set full atau ga
    printf("Set full ga?\n");
    if (IsFull(S)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");

    // Cek set kosong atau ga
    printf("Set kosong ga?\n");
    if (IsEmptySet(S)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }

    return 0;
}