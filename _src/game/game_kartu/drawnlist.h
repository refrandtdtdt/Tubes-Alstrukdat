/* MODUL DrawnList Kartu */
/* Berisi definisi dan semua primitif pemrosesan DrawnList Kartu */
/* Penempatan elemen selalu rapat kiri */

#ifndef ADTDrawnList1
#define ADTDrawnList1

#include "boolean.h"
#include "adt_kartu.h"
/* Kamus Umum */
#define Tanda '?'  /* Nilai tak terdefinisi */
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int

//#define DrawnList(i) L.A(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah DrawnList, cara deklarasi dan akses: */
/* Deklarasi: L : DrawnList */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen DrawnList
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create DrawnList kosong */
DrawnList MakeDrawnList();
/* I.S. sembarang */
/* F.S. Terbentuk DrawnList L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test DrawnList kosong *** */
boolean IsDrawnListEmpty(DrawnList L);
/* Mengirimkan true jika DrawnList L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
Kartu GetDrawn(DrawnList L, IdxType i);
/* Prekondisi : DrawnList tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen DrawnList yang ke-i */

/* *** Selektor SET : Mengubah nilai DrawnList dan elemen DrawnList *** */
void SetDrawn(DrawnList *L, IdxType i, DrawnCard v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthDrawn(DrawnList L);
/* Mengirimkan banyaknya elemen efektif DrawnList */
/* Mengirimkan nol jika DrawnList kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdxDrawn(DrawnList L);
/* Prekondisi : DrawnList L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdxDrawn(DrawnList L);
/* Prekondisi : DrawnList L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidDrawn (DrawnList L, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran DrawnList */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEffDrawn (DrawnList L, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk DrawnList */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean SearchDrawn(DrawnList L, Kartu X);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam DrawnList */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirstDrawn(DrawnList *L, DrawnCard X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtDrawn(DrawnList *L, DrawnCard X, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastDrawn(DrawnList *L, DrawnCard X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstDrawn(DrawnList *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtDrawn(DrawnList *L, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLastDrawn(DrawnList *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

DrawnList ConcatDrawn (DrawnList L1, DrawnList L2);
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah DrawnList yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
void PrintDrawnList(DrawnList L);
#endif