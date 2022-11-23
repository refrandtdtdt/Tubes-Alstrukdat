#include <stdio.h>
#include "../ADT/stack_modif.c"
#include "../ADT/array_modif.c"
#include "../ADT/queue_modif.c"
#include "../ADT/mesinkar.c"
#include "../ADT/mesinkata_modif.c"
#include "../ADT/functions.c"

void TowerOfHanoi() {
    // Deklarasi variabel
    Sentence jumlahPiringan, tiangAsal, tiangTujuan;
    int intJumlahPiringan, i, j, a, k, l, m;
    Stack tiangA; CreateEmpty(&tiangA);
    Stack tiangB; CreateEmpty(&tiangB);
    Stack tiangC; CreateEmpty(&tiangC);
    Stack tiangAcuan; CreateEmpty(&tiangAcuan);
    Word piringN;
    boolean end, valid;

    // Menampilkan UI dari Tower of Hanoi
    system("cls");
    CHARMACHINE("GameToH_UI.txt");

    // Meminta input jumlah piringan yang ingin dimainkan
    printf("Selamat datang di game Tower of Hanoi!\n");
    printf("Masukkan jumlah piringan yang ingin dimainkan : ");
    START();
    convertToArrayOfKata(&jumlahPiringan, 1);
    intJumlahPiringan = StrToInt(kataToString(jumlahPiringan.buffer[0]));
    while ((intJumlahPiringan == 0) || (intJumlahPiringan == -999)) {
        printf("===============================================================\n");
        printf("Tolong masukin dalam format angka dan lebih besar dari 0 ya gan\n");
        printf("Masukkan jumlah piringan yang ingin dimainkan : ");
        START();
        convertToArrayOfKata(&jumlahPiringan, 1);
        intJumlahPiringan = StrToInt(kataToString(jumlahPiringan.buffer[0]));
    }

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
    printf("\n");

    // Memasukkan kondisi awal stack ke masing-masing stack
    for (i = 0; i < intJumlahPiringan; i++) {
        for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
            if ((j >= (intJumlahPiringan - 1) - (intJumlahPiringan - 1 - i)) && (j <= (intJumlahPiringan - 1) + (intJumlahPiringan - 1 - i))) {
                piringN.TabWord[j] = '*';
            } else {
                piringN.TabWord[j] = ' ';
            }
        }
        Push(&tiangA, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }
    for (i = 0; i < intJumlahPiringan; i++) {
        for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
            if (j == (intJumlahPiringan - 1)) {
                piringN.TabWord[j] = '|';
            } else {
                piringN.TabWord[j] = ' ';
            }
        }
        Push(&tiangB, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }
    for (i = 0; i < intJumlahPiringan; i++) {
        for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
            if (j == (intJumlahPiringan - 1)) {
                piringN.TabWord[j] = '|';
            } else {
                piringN.TabWord[j] = ' ';
            }
        }
        Push(&tiangC, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }

    // Copy tiangA ke tiangAcuan sebagai acuan nanti di tiangC udah selesai atau belum
    for (i = 0; i < intJumlahPiringan; i++) {
        Push(&tiangAcuan, tiangA.T[i]);
    }

    // Looping Tower of Hanoi sampai tiangC sama dengan tiangAcuan
    end = false;
    while (!end) {
        if (isEqStack(tiangAcuan, tiangC)) {
            end = true;
        }
        // Tampilan stack
        system("cls");
        Display3Stack(tiangA, tiangB, tiangC);
        for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
            printf("=");
        }
        printf("\n");
        for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
            if (m == ((2 * intJumlahPiringan) / 2)) {
                printf("A");
            } else if (m == (((2 * intJumlahPiringan) / 2) + (2 * intJumlahPiringan - 1))) {
                printf("B");
            } else if (m == (((2 * intJumlahPiringan) / 2) + (2 * (2 * intJumlahPiringan - 1)))) {
                printf("C");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
            printf("=");
        }
        valid = false;
        while (!valid) {
            // Input tiang asal
            printf("\n");
            printf("Masukkan pilihan anda!\n");
            printf("Tiang asal : ");
            START();
            convertToArrayOfKata(&tiangAsal, 1);
            if ((tiangAsal.Length == 1) && (tiangAsal.buffer[0].Length == 1) && (tiangAsal.buffer[0].TabWord[0] == 65 || tiangAsal.buffer[0].TabWord[0] == 97 || tiangAsal.buffer[0].TabWord[0] == 66 || tiangAsal.buffer[0].TabWord[0] == 98 || tiangAsal.buffer[0].TabWord[0] == 67 || tiangAsal.buffer[0].TabWord[0] == 99)) {
                valid = true;
            } else {
                // Tampilan stack kalo salah input
                system("cls");
                Display3Stack(tiangA, tiangB, tiangC);
                for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
                    printf("=");
                }
                printf("\n");
                for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
                    if (m == ((2 * intJumlahPiringan) / 2)) {
                        printf("A");
                    } else if (m == (((2 * intJumlahPiringan) / 2) + (2 * intJumlahPiringan - 1))) {
                        printf("B");
                    } else if (m == (((2 * intJumlahPiringan) / 2) + (2 * (2 * intJumlahPiringan - 1)))) {
                        printf("C");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
                for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
                    printf("=");
                }
                printf("\n");
                printf("Masukan tidak valid!");
            }
        }
        // Memasukkan input tiang tujuan
        valid = false;
        while (!valid) {
            // Input tiang tujuan
            printf("Tiang tujuan : ");
            START();
            convertToArrayOfKata(&tiangTujuan, 1);
            if ((tiangTujuan.Length == 1) && (tiangTujuan.buffer[0].Length == 1) && (tiangTujuan.buffer[0].TabWord[0] == 65 || tiangTujuan.buffer[0].TabWord[0] == 97 || tiangTujuan.buffer[0].TabWord[0] == 66 || tiangTujuan.buffer[0].TabWord[0] == 98 || tiangTujuan.buffer[0].TabWord[0] == 67 || tiangTujuan.buffer[0].TabWord[0] == 99)) {
                valid = true;
            } else {
                // Tampilan stack
                system("cls");
                Display3Stack(tiangA, tiangB, tiangC);
                for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
                    printf("=");
                }
                printf("\n");
                for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
                    if (m == ((2 * intJumlahPiringan) / 2)) {
                        printf("A");
                    } else if (m == (((2 * intJumlahPiringan) / 2) + (2 * intJumlahPiringan - 1))) {
                        printf("B");
                    } else if (m == (((2 * intJumlahPiringan) / 2) + (2 * (2 * intJumlahPiringan - 1)))) {
                        printf("C");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
                for (m = 1; m <= (2 * intJumlahPiringan - 1) * 3; m++) {
                    printf("=");
                }
                // Input tiang tujuan kalo salah
                printf("\n");
                printf("Masukan tidak valid!\n");
                printf("Masukkan pilihan anda!\n");
                printf("Tiang asal : %c\n", tiangAsal.buffer[0].TabWord[0]);
            }
        }
    }
}

int main() {
    TowerOfHanoi();
    return 0;
}