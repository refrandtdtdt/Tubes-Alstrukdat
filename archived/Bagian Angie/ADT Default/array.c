#include <stdio.h>
#include "array.h"

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabGame, cara deklarasi dan akses: */
/* Deklarasi : T : TabGame */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TG untuk mengakses seluruh nilai elemen tabel
 * T.TG[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabGame *T){
    (*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabGame T){
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efekTGf tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabGame T){
    return IdxMax-IdxMin+1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabGame T){
    return IdxMin;
}
/* Prekondisi : Tabel T TGdak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (TabGame T){
    return T.Neff;
}
/* Prekondisi : Tabel T TGdak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabGame T, IdxType i){
    return T.TG[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabGame Tin, TabGame *Tout){
    Tout->Neff = Tin.Neff;
    for (int i = 0; i < Tin.Neff; i++){
        Tout->TG[i] = GetElmt(Tin, i);
    }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan TGn */
/* Assignment THsl -> Tin */
void SetEl (TabGame *T, IdxType i, ElType v){
    T->TG[i] = v; 
    if (i > GetLastIdx(*T)){
        T->Neff++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (TabGame *T, IdxType N){
    T->Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabGame T, IdxType i){
    return (i >= IdxMin && i <= IdxMax);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabGame T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabGame T){
    return (T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabGame T){
    return (T.Neff == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabGame T){
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    } else {
        printf("Berikut adalah daftar game yang tersedia");
        int i=GetFirstIdx(T);
        for (i; i <= GetLastIdx(T); i++){
            printf("%d.%d\n", i, GetElmt(T, i));
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