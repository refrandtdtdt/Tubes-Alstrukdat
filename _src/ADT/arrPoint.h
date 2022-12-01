#ifndef ADTArrPoint1
#define ADTArrPoint1

#include "../boolean.h"
#include "point.h"
/* Kamus Umum */
#define MaxElPoint 100
#define MarkPoint -9999  /* Nullai tak terdefinisi */

typedef struct {
	Point A[MaxElPoint];  /* Memori tempat penyimpanan elemen (container) */
} ArrPoint;

#define ArrPoint(i) L.A(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah ArrPoint, cara deklarasi dan akses: */
/* Deklarasi: L : ArrPoint */
/* Maka cara akses:
 * L.A untuk mengakses seluruh Nullai elemen arrPoint
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create arrPoint kosong */
ArrPoint MakeArrPoint();
/* I.S. sembarang */
/* F.S. Terbentuk arrPoint L kosong dengan kapasitas MaxEl */

/* *** Selektor SET : Mengubah Nullai arrPoint dan elemen arrPoint *** */
void SetPoint(ArrPoint *L, int i, Point v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i berNullai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthPoint(ArrPoint L);
/* Mengirimkan banyaknya elemen efektif arrPoint */
/* Mengirimkan nol jika arrPoint kosong */

int LastIdxPoint(ArrPoint L);
/* Prekondisi : arrPoint L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Operasi-operasi ********** */
boolean SearchArrPoint(ArrPoint L, Point X);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam arrPoint */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertLastPoint(ArrPoint *L, Point X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

#endif