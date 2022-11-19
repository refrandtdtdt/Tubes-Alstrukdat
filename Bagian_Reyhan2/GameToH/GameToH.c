#include <stdio.h>
#include "../ADT/array_modif.c"
#include "../ADT/queue_modif.c"
#include "../ADT/mesinkar.c"
#include "../ADT/mesinkata_modif.c"
#include "../ADT/functions.c"

void TowerOfHanoi() {
    // Deklarasi variabel
    Sentence jumlahPiringan, tiangAsal, tiangTujuan;
    int intJumlahPiringan, intTiangAsal, intTiangTujuan, i, j, a;

    // Menampilkan UI dari Tower of Hanoi
    system("cls");
    CHARMACHINE("GameToH_UI.txt");

    // Meminta input jumlah piringan yang ingin dimainkan
    printf("Selamat datang di game Tower of Hanoi!\n");
    printf("Masukkan jumlah piringan yang ingin dimainkan : ");
    START();
    convertToArrayOfKata(&jumlahPiringan, 1);
    intJumlahPiringan = StrToInt(kataToString(jumlahPiringan.buffer[0]));

    // Animasi loading katanye
    printf("\n");
    printf("===============================================================\n");
    printf("Selamat bermain! Loading dulu yah nyiapin tower ");
    for (i = 0; i <= 14; i++) {
        for (j = 0; j < 100000000; j++) {
            a = j;
        }
        printf(".");
    }

    // Menampilkan tampilan awal posisi piringan


    // Meminta input asal dan tujuan piringan yang akan dipindahkan
    system("cls");
    START();
    convertToArrayOfKata(&tiangAsal, 1);
    intTiangAsal = StrToInt(kataToString(tiangAsal.buffer[0]));
    START();
    convertToArrayOfKata(&tiangTujuan, 1);
    intTiangTujuan = StrToInt(kataToString(tiangTujuan.buffer[0]));
}

int main() {
    TowerOfHanoi();
    return 0;
}