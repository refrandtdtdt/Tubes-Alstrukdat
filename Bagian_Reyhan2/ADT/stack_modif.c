#include <stdio.h>
#include "stack_modif.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S) {
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S) {
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X) {
    if (IsEmptyStack(*S)) {
        Top(*S) = 0;
        InfoTop(*S) = X;
    } else {
        Top(*S)++;
        InfoTop(*S) = X;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X) {
    if (Top(*S) == 0) {
        (*X) = InfoTop(*S);
        Top(*S) = Nil;
    } else {
        (*X) = InfoTop(*S);
        Top(*S)--;
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

// Mulai dari prosedur ini bakal spesifik digunakan di game Tower of Hanoi
void Display3Stack(Stack S1, Stack S2, Stack S3, int intJumlahPiringan) {
    int i, j, m;
    for (i = Top(S1); i >= 0; i--) {
        printf("%s", S1.T[i].TabWord);
        printf("%s", S2.T[i].TabWord);
        printf("%s", S3.T[i].TabWord);
        printf("\n");
    }
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
}
/* Menampilkan isi 3 stack yang berjajar ke samping dengan isi tiap stacknya berjajar ke bawah */
/* I.S. S1, S2, S3 terdefinisi */
/* F.S. Tercetak isi stack seperti di bawah ini */
/*
Misal :
   *             *
  * *     *     * *
 * * *   * *   * * * 
* * * * * * * * * * *
*/

void DisplayStack(Stack S) {
    int i, j;
    for (i = Top(S); i >= 0; i--) {
        printf("%s\n", S.T[i].TabWord);
    }
}
/* Menampilkan isi stack secara berjajar ke bawah */
/* I.S. S terdefinisi */
/* F.S. Tercetak isi stack berjajar ke bawah */
/*
Misal :
   *    
  * *    
 * * * 
* * * * 
*/

boolean isEqStack(Stack S1, Stack S2) {
    int i = 0;
    if (Top(S1) == Top(S2)) {
        while (i <= Top(S1)) {
            if (!Eqstr(S1.T[i].TabWord, S2.T[i].TabWord)) {
                return false;
            }
            i++;
        }
        return true;
    } else {
        return false;
    }
}
/* Membandingkan apakah dua buah stack sama ataau tidak */
/* I.S. S1 dan S2 terdefinisi */
/* F.S. Mengeluarkan true jika kedua stack sama, false jika beda */
/* Dua stack sama jika jumlah piringan sama dan isi tiap tumpukan di stack sama */

boolean isNoPiring(Stack S, int intJumlahPiringan) {
    // Membuat Skosong sebagai acuan stack kosong
    Stack Skosong; CreateEmpty(&Skosong);
    Word piringN;
    int i, j;
    for (i = 0; i < intJumlahPiringan; i++) {
        for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
            if (j == (intJumlahPiringan - 1)) {
                piringN.TabWord[j] = '|';
            } else {
                piringN.TabWord[j] = ' ';
            }
        }
        Push(&Skosong, piringN);
        for (j = 0; j < ((2 * intJumlahPiringan) - (2 * i + 1)); j++) {
            piringN.TabWord[j] = '\0';
        }
    }
    if (isEqStack(S, Skosong)) {
        return true;
    } else {
        return false;
    }
}
/* Mengecek ada atau ngga piring di tiang */
/* I.S. S terdefinisi */
/* F.S. Mengeluarkan true jika tidak ada piring di tiang, false jika ada */

boolean isPiringAsalBigger(Stack Sasal, Stack Stujuan, int intJumlahPiringan) {
    // Membuat tiangDummy agar bisa jadi patokan untuk ambil piringan teratas (biar si tiang ga keitung)
    int k, l, m, n;
    Word tiangDummy;
    int j;
    for (j = 0; j < (2 * intJumlahPiringan - 1); j++) {
        if (j == (intJumlahPiringan - 1)) {
            tiangDummy.TabWord[j] = '|';
        } else {
            tiangDummy.TabWord[j] = ' ';
        }
    }
    int z;
    if (len(tiangDummy.TabWord) > (2 * intJumlahPiringan - 1)) {
        for (z = (2 * intJumlahPiringan - 1); z < len(tiangDummy.TabWord); z++) {
            tiangDummy.TabWord[z] = '\0';
        }
    }

    // Kalau di tiang tujuan kosong (tinggal tiang aja), maka langsung false biar piring bisa pindah
    Word topPiringAsal, topPiringTujuan;
    if (isNoPiring(Stujuan, intJumlahPiringan)) { 
        return false;
    } else {
        // Ngambil piringan teratas Sasal
        boolean nemuPiringAsal = false;
        int i = Top(Sasal);
        int stackAsalKe;
        while ((i >= 0) && (!nemuPiringAsal)) {
            if (!Eqstr(Sasal.T[i].TabWord, tiangDummy.TabWord)) {
                nemuPiringAsal = true;
                stackAsalKe = i;
            } else {
                i--;
            }
        }

        // Ngambil piringan teratas Stujuan
        boolean nemuPiringTujuan = false;
        int k = Top(Stujuan);
        int stackTujuanKe;
        while ((k >= 0) && (!nemuPiringTujuan)) {
            if (!Eqstr(Stujuan.T[k].TabWord, tiangDummy.TabWord)) {
                nemuPiringTujuan = true;
                stackTujuanKe = k;
            } else {
                k--;
            }
        }

        // Membandingkan kedua length kedua piringan (banyak bintangnya)
        if (lenBintang(Sasal.T[i].TabWord) > lenBintang(Stujuan.T[k].TabWord)) {
            return true;
        } else {
            return false;
        }
    }
}
/* Mengecek apakah piringan tiang asal lebih besar dari piringan di tiang tujuan */
/* I.S. S terdefinisi */
/* F.S. Mengeluarkan true jika piringan tiang asal lebih besar dari piringan di tiang tujuan, false jika tidak */

int lenBintang(char* str) {
    int i = 0;
    int length = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] == '*') {
            length++;
        }
        i++;
    }
    return length;
}
/* Meengembalikan panjang bintang di piringan */
/* I.S. S terdefinisi */
/* F.S. Mengembalikan panjang bintang di piringan */

int pangkat(int angka, int pangkatBerapa) {
    int hasil = 1;
    int i;
    for (i = 0; i < pangkatBerapa; i++) {
        hasil *= angka;
    }
    return hasil;
}
/* Meengembalikan hasil pangkat */
/* I.S. S terdefinisi */
/* F.S. Mengembalikan hasil pangkat */