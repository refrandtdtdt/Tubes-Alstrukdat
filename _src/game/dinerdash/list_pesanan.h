/* MODUL LISTPESANAN INTEGER */
/* Berisi definisi dan semua primitif pemrosesan listPesanan integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef ADTListPesanan1
#define ADTListPesanan1

#include "boolean.h"
#include "adt_makanan.h"
/* Kamus Umum */
#define MaxEl 100
#define Mark -9999  /* Nilai tak terdefinisi */
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int

typedef struct {
	Makanan A[MaxEl];  /* Memori tempat penyimpanan elemen (container) */
} ListPesanan;

#define ListPesanan(i) L.A(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah ListPesanan, cara deklarasi dan akses: */
/* Deklarasi: L : ListPesanan */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen listPesanan
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create listPesanan kosong */
ListPesanan MakeListPesanan();
/* I.S. sembarang */
/* F.S. Terbentuk listPesanan L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test listPesanan kosong *** */
boolean IsEmptyPesanan(ListPesanan L);
/* Mengirimkan true jika listPesanan L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
Makanan GetPesanan(ListPesanan L, IdxType i);
/* Prekondisi : listPesanan tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen listPesanan yang ke-i */

/* *** Selektor SET : Mengubah nilai listPesanan dan elemen listPesanan *** */
void SetPesanan(ListPesanan *L, IdxType i, Makanan v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthPesanan(ListPesanan L);
/* Mengirimkan banyaknya elemen efektif listPesanan */
/* Mengirimkan nol jika listPesanan kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdxPesanan(ListPesanan L);
/* Prekondisi : listPesanan L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdxPesanan(ListPesanan L);
/* Prekondisi : listPesanan L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidPesanan (ListPesanan L, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran listPesanan */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEffPesanan (ListPesanan L, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk listPesanan */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
void SearchPesanan(ListPesanan L, Makanan X, IdxType* index);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam listPesanan */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirstPesanan(ListPesanan *L, Makanan X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtPesanan(ListPesanan *L, Makanan X, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastPesanan(ListPesanan *L, Makanan X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstPesanan(ListPesanan *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtPesanan(ListPesanan *L, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLastPesanan(ListPesanan *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

ListPesanan ConcatPesanan(ListPesanan L1, ListPesanan L2);
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah ListPesanan yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

void CreateMark(ListPesanan *L, IdxType i);

void delete_zero_durability(ListPesanan *L);

#endif