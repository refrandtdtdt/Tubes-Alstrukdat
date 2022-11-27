#include <stdio.h>
#include "GameToH.h"

void TowerOfHanoi() {
    // Deklarasi variabel
    Sentence jumlahPiringan, tiangAsal, tiangTujuan, nama;
    int intJumlahPiringan, i, j, a, k, l, m, z, langkah, score, scoreMax, langkahAcuan;
    Stackt tiangA; 
    CreateEmptyStackt(&tiangA);
    Stackt tiangB; 
    CreateEmptyStackt(&tiangB);
    Stackt tiangC; 
    CreateEmptyStackt(&tiangC);
    Stackt tiangAcuan; 
    CreateEmptyStackt(&tiangAcuan);
    Word piringN, tiangDummy, dummyTiangAsal, dummyTiang;
    boolean end, valid, scoreAkhir;

    // Menampilkan UI dari Tower of Hanoi
    system("cls");
    CHARMACHINE("_src/game/GameToH/GameToH_UI.txt");

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
        PushStack(&tiangA, piringN);
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
        PushStack(&tiangB, piringN);
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
        PushStack(&tiangC, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }

    // Copy tiangA ke tiangAcuan sebagai acuan nanti di tiangC udah selesai atau belum
    for (i = 0; i < intJumlahPiringan; i++) {
        PushStack(&tiangAcuan, tiangA.T[i]);
    }

    // Membuat tiangDummy untuk tampilan tiang jika tidak ada piringan
    for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
        if (j == (intJumlahPiringan - 1)) {
            tiangDummy.TabWord[j] = '|';
        } else {
            tiangDummy.TabWord[j] = ' ';
        }
    }
    // Looping Tower of Hanoi sampai tiangC sama dengan tiangAcuan
    langkah = 0;
    score = 0;
    end = false;
    while (!end) {
        if (isEqStack(tiangAcuan, tiangC)) {
            end = true;
        } else {
            // Tampilan stack
            system("cls");
            Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);

            // Tiang asal
            valid = false;
            while (!valid) {
                // Input tiang asal
                printf("\n");
                printf("Masukkan pilihan anda!\n");
                printf("Tiang asal : ");
                START();
                convertToArrayOfKata(&tiangAsal, 1);
                if ((tiangAsal.Length == 1) && (tiangAsal.buffer[0].Length == 1) && (tiangAsal.buffer[0].TabWord[0] == 65 || tiangAsal.buffer[0].TabWord[0] == 97 || tiangAsal.buffer[0].TabWord[0] == 66 || tiangAsal.buffer[0].TabWord[0] == 98 || tiangAsal.buffer[0].TabWord[0] == 67 || tiangAsal.buffer[0].TabWord[0] == 99)) {
                    if (tiangAsal.buffer[0].TabWord[0] == 'A' || tiangAsal.buffer[0].TabWord[0] == 'a') {
                        if (isNoPiring(tiangA, intJumlahPiringan)) {
                            // Tampilan stack kalo tiang A kosong
                            system("cls");
                            Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                            printf("\n");
                            printf("Tiang A tidak ada piringan!");
                        } else {
                            // Input tiang tujuan
                            printf("Tiang tujuan : ");
                            START();
                            convertToArrayOfKata(&tiangTujuan, 1);
                            if ((tiangTujuan.Length == 1) && (tiangTujuan.buffer[0].Length == 1) && (tiangTujuan.buffer[0].TabWord[0] == 65 || tiangTujuan.buffer[0].TabWord[0] == 97 || tiangTujuan.buffer[0].TabWord[0] == 66 || tiangTujuan.buffer[0].TabWord[0] == 98 || tiangTujuan.buffer[0].TabWord[0] == 67 || tiangTujuan.buffer[0].TabWord[0] == 99)) {
                                if ((tiangAsal.buffer[0].TabWord[0] == 'A' || tiangAsal.buffer[0].TabWord[0] == 'a') && (tiangTujuan.buffer[0].TabWord[0] == 'B' || tiangTujuan.buffer[0].TabWord[0] == 'b')) {
                                    if (isPiringAsalBigger(tiangA, tiangB, intJumlahPiringan)) {
                                        // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                        system("cls");
                                        Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                        printf("\n");
                                        printf("Piringan di tiang A lebih besar dari piringan di tiang B!");
                                    } else {
                                        valid = true;
                                    }
                                } else if ((tiangAsal.buffer[0].TabWord[0] == 'A' || tiangAsal.buffer[0].TabWord[0] == 'a') && (tiangTujuan.buffer[0].TabWord[0] == 'C' || tiangTujuan.buffer[0].TabWord[0] == 'c')) {
                                    if (isPiringAsalBigger(tiangA, tiangC, intJumlahPiringan)) {
                                        // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                        system("cls");
                                        Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                        printf("\n");
                                        printf("Piringan di tiang A lebih besar dari piringan di tiang C!");
                                    } else {
                                        valid = true;
                                    }
                                } else if ((tiangAsal.buffer[0].TabWord[0] == 'A' || tiangAsal.buffer[0].TabWord[0] == 'a') && (tiangTujuan.buffer[0].TabWord[0] == 'A' || tiangTujuan.buffer[0].TabWord[0] == 'a')) {
                                    // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                    system("cls");
                                    Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                    printf("\n");
                                    printf("Pilih tiang tujuan yang berbeda dengan tiang asal!");
                                } 
                            } else {
                                // Tampilan stack kalo salah input
                                system("cls");
                                Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                printf("\n");
                                printf("Masukan tiang tujuan tidak valid!");
                            }
                        }
                    } else if (tiangAsal.buffer[0].TabWord[0] == 'B' || tiangAsal.buffer[0].TabWord[0] == 'b') {
                        if (isNoPiring(tiangB, intJumlahPiringan)) {
                            // Tampilan stack kalo tiang B kosong
                            system("cls");
                            Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                            printf("\n");
                            printf("Tiang B tidak ada piringan!");
                        } else {
                            // Input tiang tujuan
                            printf("Tiang tujuan : ");
                            START();
                            convertToArrayOfKata(&tiangTujuan, 1);
                            if ((tiangTujuan.Length == 1) && (tiangTujuan.buffer[0].Length == 1) && (tiangTujuan.buffer[0].TabWord[0] == 65 || tiangTujuan.buffer[0].TabWord[0] == 97 || tiangTujuan.buffer[0].TabWord[0] == 66 || tiangTujuan.buffer[0].TabWord[0] == 98 || tiangTujuan.buffer[0].TabWord[0] == 67 || tiangTujuan.buffer[0].TabWord[0] == 99)) {
                                if ((tiangAsal.buffer[0].TabWord[0] == 'B' || tiangAsal.buffer[0].TabWord[0] == 'b') && (tiangTujuan.buffer[0].TabWord[0] == 'A' || tiangTujuan.buffer[0].TabWord[0] == 'a')) {
                                    if (isPiringAsalBigger(tiangB, tiangA, intJumlahPiringan)) {
                                        // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                        system("cls");
                                        Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                        printf("\n");
                                        printf("Piringan di tiang B lebih besar dari piringan di tiang A!");
                                    } else {
                                        valid = true;
                                    }
                                } else if ((tiangAsal.buffer[0].TabWord[0] == 'B' || tiangAsal.buffer[0].TabWord[0] == 'b') && (tiangTujuan.buffer[0].TabWord[0] == 'C' || tiangTujuan.buffer[0].TabWord[0] == 'c')) {
                                    if (isPiringAsalBigger(tiangB, tiangC, intJumlahPiringan)) {
                                        // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                        system("cls");
                                        Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                        printf("\n");
                                        printf("Piringan di tiang B lebih besar dari piringan di tiang C!");
                                    } else {
                                        valid = true;
                                    }
                                } else if ((tiangAsal.buffer[0].TabWord[0] == 'B' || tiangAsal.buffer[0].TabWord[0] == 'b') && (tiangTujuan.buffer[0].TabWord[0] == 'B' || tiangTujuan.buffer[0].TabWord[0] == 'b')) {
                                    // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                    system("cls");
                                    Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                    printf("\n");
                                    printf("Pilih tiang tujuan yang berbeda dengan tiang asal!");
                                }
                            } else {
                                // Tampilan stack kalo salah input
                                system("cls");
                                Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                printf("\n");
                                printf("Masukan tiang tujuan tidak valid!");
                            }
                            //valid = true;
                        }
                    } else if (tiangAsal.buffer[0].TabWord[0] == 'C' || tiangAsal.buffer[0].TabWord[0] == 'c') {
                        if (isNoPiring(tiangC, intJumlahPiringan)) {
                            // Tampilan stack kalo tiang C kosong
                            system("cls");
                            Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                            printf("\n");
                            printf("Tiang C tidak ada piringan!");
                        } else {
                            // Input tiang tujuan
                            printf("Tiang tujuan : ");
                            START();
                            convertToArrayOfKata(&tiangTujuan, 1);
                            if ((tiangTujuan.Length == 1) && (tiangTujuan.buffer[0].Length == 1) && (tiangTujuan.buffer[0].TabWord[0] == 65 || tiangTujuan.buffer[0].TabWord[0] == 97 || tiangTujuan.buffer[0].TabWord[0] == 66 || tiangTujuan.buffer[0].TabWord[0] == 98 || tiangTujuan.buffer[0].TabWord[0] == 67 || tiangTujuan.buffer[0].TabWord[0] == 99)) {
                                if ((tiangAsal.buffer[0].TabWord[0] == 'C' || tiangAsal.buffer[0].TabWord[0] == 'c') && (tiangTujuan.buffer[0].TabWord[0] == 'A' || tiangTujuan.buffer[0].TabWord[0] == 'a')) {
                                    if (isPiringAsalBigger(tiangC, tiangA, intJumlahPiringan)) {
                                        // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                        system("cls");
                                        Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                        printf("\n");
                                        printf("Piringan di tiang C lebih besar dari piringan di tiang A!");
                                    } else {
                                        valid = true;
                                    }
                                } else if ((tiangAsal.buffer[0].TabWord[0] == 'C' || tiangAsal.buffer[0].TabWord[0] == 'c') && (tiangTujuan.buffer[0].TabWord[0] == 'B' || tiangTujuan.buffer[0].TabWord[0] == 'b')) {
                                    if (isPiringAsalBigger(tiangC, tiangB, intJumlahPiringan)) {
                                        // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                        system("cls");
                                        Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                        printf("\n");
                                        printf("Piringan di tiang C lebih besar dari piringan di tiang B!");
                                    } else {
                                        valid = true;
                                    }
                                } else if ((tiangAsal.buffer[0].TabWord[0] == 'C' || tiangAsal.buffer[0].TabWord[0] == 'c') && (tiangTujuan.buffer[0].TabWord[0] == 'C' || tiangTujuan.buffer[0].TabWord[0] == 'c')) {
                                    // Tampilan stack kalo piringan di tiang asal > piringan di tiang tujuan
                                    system("cls");
                                    Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                    printf("\n");
                                    printf("Pilih tiang tujuan yang berbeda dengan tiang asal!");
                                }
                            } else {
                                // Tampilan stack kalo salah input
                                system("cls");
                                Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                                printf("\n");
                                printf("Masukan tiang tujuan tidak valid!");
                            }
                            //valid = true;
                        }
                    }
                } else {
                    // Tampilan stack kalo salah input
                    system("cls");
                    Display3Stack(tiangA, tiangB, tiangC, intJumlahPiringan);
                    printf("\n");
                    printf("Masukan tiang asal tidak valid!");
                }
            }
            
            // PopStack piringan teratas dari tiangAsal
            if (tiangAsal.buffer[0].TabWord[0] == 'A' || tiangAsal.buffer[0].TabWord[0] == 'a') {
                i = TopS(tiangA);
                while ((tiangA.T[i].TabWord[intJumlahPiringan-1] == '|') && (i >= 0)) {
                    PopStack(&tiangA, &dummyTiang);
                    i--;
                }
                if (i >= 0) {
                    PopStack(&tiangA, &dummyTiangAsal);
                }
            } else if (tiangAsal.buffer[0].TabWord[0] == 'B' || tiangAsal.buffer[0].TabWord[0] == 'b') {
                i = TopS(tiangB);
                while ((tiangB.T[i].TabWord[intJumlahPiringan-1] == '|') && (i >= 0)) {
                    PopStack(&tiangB, &dummyTiang);
                    i--;
                }
                if (i >= 0) {
                    PopStack(&tiangB, &dummyTiangAsal);
                }
            } else if (tiangAsal.buffer[0].TabWord[0] == 'C' || tiangAsal.buffer[0].TabWord[0] == 'c') {
                i = TopS(tiangC);
                while ((tiangC.T[i].TabWord[intJumlahPiringan-1] == '|') && (i >= 0)) {
                    PopStack(&tiangC, &dummyTiang);
                    i--;
                }
                if (i >= 0) {
                    PopStack(&tiangC, &dummyTiangAsal);
                }
            }

            // Isi kekosongan stack yang telah diPopStack dengan tiang
            if (tiangAsal.buffer[0].TabWord[0] == 'A' || tiangAsal.buffer[0].TabWord[0] == 'a') {
                j = intJumlahPiringan - (TopS(tiangA) + 1);
                for (i = 0; i < j; i++) {
                    PushStack(&tiangA, tiangDummy);
                }
            } else if (tiangAsal.buffer[0].TabWord[0] == 'B' || tiangAsal.buffer[0].TabWord[0] == 'b') {
                j = intJumlahPiringan - (TopS(tiangB) + 1);
                for (i = 0; i < j; i++) {
                    PushStack(&tiangB, tiangDummy);
                }
            } else if (tiangAsal.buffer[0].TabWord[0] == 'C' || tiangAsal.buffer[0].TabWord[0] == 'c') {
                j = intJumlahPiringan - (TopS(tiangC) + 1);
                for (i = 0; i < j; i++) {
                    PushStack(&tiangC, tiangDummy);
                }
            }

            // PopStack piringan teratas dari tiangTujuan dan masukkan dummyTiangAsal
            if (tiangTujuan.buffer[0].TabWord[0] == 'A' || tiangTujuan.buffer[0].TabWord[0] == 'a') {
                i = TopS(tiangA);
                while ((tiangA.T[i].TabWord[intJumlahPiringan-1] == '|') && (i >= 0)) {
                    PopStack(&tiangA, &dummyTiang);
                    i--;
                }
                PushStack(&tiangA, dummyTiangAsal);
            } else if (tiangTujuan.buffer[0].TabWord[0] == 'B' || tiangTujuan.buffer[0].TabWord[0] == 'b') {
                i = TopS(tiangB);
                while ((tiangB.T[i].TabWord[intJumlahPiringan-1] == '|') && (i >= 0)) {
                    PopStack(&tiangB, &dummyTiang);
                    i--;
                }
                PushStack(&tiangB, dummyTiangAsal);
            } else if (tiangTujuan.buffer[0].TabWord[0] == 'C' || tiangTujuan.buffer[0].TabWord[0] == 'c') {
                i = TopS(tiangC);
                while ((tiangC.T[i].TabWord[intJumlahPiringan-1] == '|') && (i >= 0)) {
                    PopStack(&tiangC, &dummyTiang);
                    i--;
                }
                PushStack(&tiangC, dummyTiangAsal);
            }

            // Isi kekosongan stack yang telah diPopStack dengan tiang
            if (tiangTujuan.buffer[0].TabWord[0] == 'A' || tiangTujuan.buffer[0].TabWord[0] == 'a') {
                j = intJumlahPiringan - (TopS(tiangA) + 1);
                for (i = 0; i < j; i++) {
                    PushStack(&tiangA, tiangDummy);
                }
            } else if (tiangTujuan.buffer[0].TabWord[0] == 'B' || tiangTujuan.buffer[0].TabWord[0] == 'b') {
                j = intJumlahPiringan - (TopS(tiangB) + 1);
                for (i = 0; i < j; i++) {
                    PushStack(&tiangB, tiangDummy);
                }
            } else if (tiangTujuan.buffer[0].TabWord[0] == 'C' || tiangTujuan.buffer[0].TabWord[0] == 'c') {
                j = intJumlahPiringan - (TopS(tiangC) + 1);
                for (i = 0; i < j; i++) {
                    PushStack(&tiangC, tiangDummy);
                }
            }

            // Mengosongkan dummyTiang
            for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
                dummyTiang.TabWord[j] = '\0';
            }

            // Langkah bertambah 1
            langkah++;
        }
    }
    // Penghitungan score
    scoreMax = 2 * intJumlahPiringan;
    score = scoreMax;
    langkahAcuan = (pangkat(2, intJumlahPiringan) - 1);
    scoreAkhir = false;
    z = 0;
    while ((z < scoreMax) && !scoreAkhir) {
        if (langkah <= langkahAcuan) {
            scoreAkhir = true;
        } else {
            score--;
            langkahAcuan += (intJumlahPiringan);
            z++;
        }
    }

    // Game ToH telah selesai, menampilkan langkah, score, dan meminta inputan nama
    system("cls");
    printf("=====================\n");
    printf("Kamu berhasil! Horee!\n");
    printf("=====================\n");
    printf("Jumlah langkah kamu : %d\n", langkah);
    printf("Score kamu          : %d\n", score);
    printf("Nama                : ");
    START();
    convertToArrayOfKata(&nama, 1);
}
/* Game Tower of Hanoi */