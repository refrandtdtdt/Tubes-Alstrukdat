/*
NIM : 18221161
Nama : Reyhan Putra Ananda
Tanggal : 25 September 2022
Topik Praktikum : Pointer dan Array Dinamik
Deskripsi : Implementasi array.h
*/

#include <stdio.h>
#include "array.h"

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T){
    T->Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
    return IdxMax-IdxMin+1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (TabInt T){
    return T.Neff;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i){
    return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout){
    Tout->Neff = Tin.Neff;
    for (int i = 0; i < Tin.Neff; i++){
        Tout->TI[i] = GetElmt(Tin, i);
    }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetEl (TabInt *T, IdxType i, ElType v){
    T->TI[i] = v; 
    if (i > GetLastIdx(*T)){
        T->Neff++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (TabInt *T, IdxType N){
    T->Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return (i >= IdxMin && i <= IdxMax);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    return (T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    return (T.Neff == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T){
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    } else {
        int i=GetFirstIdx(T);
        for (i; i <= GetLastIdx(T); i++){
            printf("%d:%d\n", i, GetElmt(T, i));
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
    TabInt T;
    MakeEmpty(&T);
    if (NbElmt(T1) == NbElmt(T2)){
        int i=1;
        for (i; i <= NbElmt(T1); i++){
            T.TI[i] = T1.TI[i] + T2.TI[i];
        }
        T.Neff = NbElmt(T1);
    }
    return T;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
TabInt MinusTab (TabInt T1, TabInt T2){
    TabInt T;
    MakeEmpty(&T);
    if (NbElmt(T1) == NbElmt(T2)){
        int i=1;
        for (i; i <= NbElmt(T1); i++){
            T.TI[i] = T1.TI[i] - T2.TI[i];
        }
        T.Neff = NbElmt(T1);
    }
    return T;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
    ElType max = T.TI[IdxMin];
    int i=2;
    for (i; i <= T.Neff; i++){
        if (T.TI[i] > max){
            max = T.TI[i];
        }
    }
    return max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabInt T){
    ElType min = T.TI[IdxMin];
    int i=2;
    for (i; i <= T.Neff; i++){
        if (T.TI[i] < min){
            min = T.TI[i];
        }
    }
    return min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
    IdxType max = IdxMin;
    int i=IdxMin+1;
    for (i; i <= T.Neff; i++){
        if (T.TI[i] > T.TI[max]){
            max = i;
        }
    }
    return max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabInt T){
    IdxType min = IdxMin;
    int i=IdxMin+1;
    for (i; i <= T.Neff; i++){
        if (T.TI[i] < T.TI[min]){
            min = i;
        }
    }
    return min;
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */