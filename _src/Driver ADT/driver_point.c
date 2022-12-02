#include <stdio.h>
#include "../ADT/point.c"
#include "../ADT/mesinkata_modif.c"
#include "../ADT/mesinkar.c"
#include "../ADT/functions.c"

int main () {
    // Deklarasi variabel dan membuat point kosong
    Point P1, P2, Psalin, Prandom;
    int x, y;
    
    // Meminta input isi point 1
    printf("Masukkan isi point 1! (formatnya x y): ");
    BacaPoint(&P1);
    printf("\n");

    // Meminta input isi point 2 (make MakePoint)
    printf("Masukkan isi point 2! (formatnya x y): ");
	scanf("%d %d", &x, &y);
    P2 = MakePoint(x, y);
    printf("\n");

    // Print isi point 1 dan 2
    printf("Isi point 1:\n");
    TulisPoint(P1);
    printf("\n\n");

    printf("Isi point 2:\n");
    TulisPoint(P2);
    printf("\n\n");

    // Cek apakah point 1 = point 2
    printf("Point 1 sama ga gan dengan point 2?\n");
    if (EQ(P1, P2)) {
        printf("Yoi gan\n");
    } else if (NEQ(P1, P2)) {
        printf("Kaga gan\n");
    }
    printf("\n");

    // Uji PlusDelta dengan deltaX 2 dan deltaY 2
    printf("Psalin dari P1 yang deltaX ditambah 2 dan deltaY ditambah 2:\n");
    Psalin = PlusDelta(P1, 2, 2);
    TulisPoint(Psalin);
    printf("\n\n");

    // Uji geser
    printf("P2 setelah deltaX ditambah 2 dan deltaY ditambah 2:\n");
    Geser(&P2, 2, 2);
    TulisPoint(P2);
    printf("\n\n");

    // Uji RandomPoint
    printf("Point random:\n");
    Prandom = RandomPoint();
    TulisPoint(Prandom);
    return 0;
}