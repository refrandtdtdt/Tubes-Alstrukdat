#include <stdio.h>
#include "../ADT/arrPoint.h"
#include "../ADT/point.h"
#include "../ADT/mesinkata_modif.h"
#include "../ADT/mesinkar.h"
#include "../ADT/functions.h"

int main () {
    // Deklarasi variabel dan membentuk ArrPoint kosong (semuanya bernilai -99)
    ArrPoint AP;
    AP = MakeArrPoint();
    int i;
    Point P1, P2, P3;

    // Input point dan dimasukkan ke ArrPoint
    printf("Masukkan P1:\n");
    BacaPoint(&P1);
    SetPoint(&AP, 0, P1);

    printf("Masukkan P2:\n");
    BacaPoint(&P2);
    SetPoint(&AP, 1, P2);

    printf("Masukkan P3:\n");
    BacaPoint(&P3);
    SetPoint(&AP, 2, P3);
    printf("\n");

    // Print isi AP
    printf("Isi AP:\n");
    for (i = 0; i < LengthPoint(AP); i++) {
        TulisPoint(AP.A[i]);
    }
    printf("\n");

    // Cek panjang ArrPoint
    printf("Panjang AP: %d\n", LengthPoint(AP));
    printf("\n");

    // Cek idx terakhir ArrPoint
    printf("Idx terakhir AP: %d\n", LastIdxPoint(AP));
    printf("\n");

    // Cek ada atau tidak P3 di AP
    printf("P3 ada ga di AP?\n");
    if (SearchArrPoint(AP, P3)) {
        printf("Ada gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");

    // Insert point P2 jadi elemen terakhir
    InsertLastPoint(&AP, P2);

    // Print isi AP
    printf("Isi AP setelah P2 ditambahkan lagi ke AP:\n");
    for (i = 0; i < LengthPoint(AP); i++) {
        TulisPoint(AP.A[i]);
    }
    return 0;
}