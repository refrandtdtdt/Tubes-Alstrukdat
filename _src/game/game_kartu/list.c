
/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list.h"
#include "../../ADT/functions.h"


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
    for(int i=0;i<MaxCard;i++)
    {
        L.A[i].Suits = Tanda;
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxCard */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmpty(List L)
{
    return LengthList(L) == 0;
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
Kartu GetElList(List L, IdxType i)
{
    return L.A[i];
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void SetElList(List *L, IdxType i, Kartu v)
{
    L->A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthList(List L)
{
    int i=0;
    while ((i < MaxCard) && (L.A[i].Suits != Tanda))
    {
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdxList(List L)
{
    return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdxList(List L)
{
    return LengthList(L)-1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidList (List L, IdxType i)
{
    return i >= FirstIdxList(L) && i < MaxCard;
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEffList (List L, IdxType i)
{
    return i >= FirstIdxList(L) && i <= LastIdxList(L);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean SearchList(List L, Kartu X)
{
    int i=0;
    while(i < LastIdxList(L))
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

void InsertFirstList(List *L, Kartu X)
{
    if(!IsListEmpty(*L))
    {
        for(int i=LengthList(*L);i>0;i--)
        {
            L->A[i] = L->A[i-1];
        }  
    }
    L->A[0] = X;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtList(List *L, Kartu X, IdxType i)
{
    if(!IsListEmpty(*L))
    {
        for(int j=LengthList(*L);j>i;j--)
        {
            L->A[j] = L->A[j-1];
        }   
    }
    L->A[i] = X;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastList(List *L, Kartu X)
{
    if (IsListEmpty(*L)) {
        InsertFirstList(L, X);
    } else {
        (*L).A[LastIdxList(*L) + 1] = X;
    }
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstList(List *L)
{
	int i = FirstIdxList(*L);
	while (i < LastIdxList(*L)) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
    (*L).A[i].Suits = Tanda;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtList(List *L, IdxType i)
{
	int j = LastIdxList(*L);
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

void DeleteLastList(List *L)
{
    L->A[LengthList(*L)-1].Suits = Tanda;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List ConcatList(List L1, List L2)
{
    List L = MakeList();
    for(int i=0;i<=LastIdxList(L1);i++)
    {
        L.A[i] = L1.A[i];
    }
    int idx=LastIdxList(L1)+1;
    for(int i=0;i<=LastIdxList(L2);i++)
    {
        L.A[idx] = L2.A[i];
        idx++;
    }
    return L;
}
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
          delay(9666);
        }
    }
}
