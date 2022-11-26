
/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listcard.h"
#include "../../_src/ADT/functions.h"


/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList()
{
    List L;
    for(int i=0;i<MaxEl;i++)
    {
        L.A[i].Suits = Tanda;
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmpty(List L)
{
    return LengthCard(L) == 0;
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
Kartu GetCard(List L, IdxType i)
{
    return L.A[i];
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void SetCard(List *L, IdxType i, Kartu v)
{
    L->A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthCard(List L)
{
    int i=0;
    while ((i < MaxEl) && (L.A[i].Suits != Tanda))
    {
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdxCard(List L)
{
    return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdxCard(List L)
{
    return Length(L)-1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidCard (List L, IdxType i)
{
    return i >= FirstIdxCard(L) && i < MaxEl;
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEffCard (List L, IdxType i)
{
    return i >= FirstIdxCard(L) && i <= LastIdxCard(L);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean SearchCard(List L, Kartu X)
{
    int i=0;
    while(i < LastIdxCard(L))
    {
        if((L.A[i].Ranks == X.Ranks) && (L.A[i].Suits == X.Suits))
        {
            return true;
        }
        i++;
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirstCard(List *L, Kartu X)
{
    if(!IsListEmpty(*L))
    {
        for(int i=LengthCard(*L);i>0;i--)
        {
            L->A[i] = L->A[i-1];
        }  
    }
    L->A[0] = X;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(List *L, Kartu X, IdxType i)
{
    if(!IsListEmpty(*L))
    {
        for(int j=Length(*L);j>i;j--)
        {
            L->A[j] = L->A[j-1];
        }   
    }
    L->A[i] = X;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastCard(List *L, Kartu X)
{
    if (IsListEmpty(*L)) {
        InsertFirstCard(L, X);
    } else {
        (*L).A[LastIdxCard(*L) + 1] = X;
    }
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstCard(List *L)
{
	int i = FirstIdxCard(*L);
	while (i < LastIdxCard(*L)) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
    (*L).A[i].Suits = Tanda;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtCard(List *L, IdxType i)
{
	int j = LastIdxCard(*L);
	// while (i <= j) {
	// 	(*L).A[j] = (*L).A[j+1];
    //     j--;
	// }
	while (i <= j) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLastCard(List *L)
{
    L->A[LengthCard(*L)-1].Suits = Tanda;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

void shuffle(List* array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          srand(time(NULL));
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          Kartu t = array->A[j];
          array->A[j] = array->A[i];
          array->A[i] = t;
          delay(10666);
        }
    }
}
