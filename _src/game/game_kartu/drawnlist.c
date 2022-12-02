
/* MODUL DrawnList INTEGER */
/* Berisi definisi dan semua primitif pemrosesan DrawnList integer */
/* Penempatan elemen selalu rapat kiri */
#include <stdio.h>
#include <stdlib.h>
#include "..\..\boolean.h"
#include "drawnlist.h"


/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah DrawnList, cara deklarasi dan akses: */
/* Deklarasi: L : DrawnList */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen DrawnList
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create DrawnList kosong */
DrawnList MakeDrawnList()
{
    DrawnList L;
    for(int i=0;i<MaxEl;i++)
    {
        L.round[i].card.Suits = Tanda;
        L.round[i].id_player = -1;
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk DrawnList L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test DrawnList kosong *** */
boolean IsDrawnListEmpty(DrawnList L)
{
    return L.round[0].card.Suits == Tanda;
}
/* Mengirimkan true jika DrawnList L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
Kartu GetDrawn(DrawnList L, IdxType i)
{
    return L.round[i].card;
}
/* Prekondisi : DrawnList tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen DrawnList yang ke-i */

/* *** Selektor SET : Mengubah nilai DrawnList dan elemen DrawnList *** */
void SetDrawn(DrawnList *L, IdxType i, DrawnCard v)
{
    L->round[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthDrawn(DrawnList L)
{
    int i=0;
    while ((i < MaxEl) && (L.round[i].card.Suits != Tanda))
    {
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif DrawnList */
/* Mengirimkan nol jika DrawnList kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdxDrawn(DrawnList L)
{
    return 0;
}
/* Prekondisi : DrawnList L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdxDrawn(DrawnList L)
{
    return LengthDrawn(L)-1;
}
/* Prekondisi : DrawnList L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidDrawn (DrawnList L, IdxType i)
{
    return i >= FirstIdxDrawn(L) && i < MaxEl;
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran DrawnList */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEffDrawn (DrawnList L, IdxType i)
{
    return i >= FirstIdxDrawn(L) && i <= LastIdxDrawn(L);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk DrawnList */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean SearchDrawn(DrawnList L, Kartu X)
{
    int i=0;
    while(i < LastIdxDrawn(L))
    {
        if((L.round[i].card.Ranks == X.Ranks) && (L.round[i].card.Suits == X.Suits))
        {
            return true;
        }
        i++;
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam DrawnList */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirstDrawn(DrawnList *L, DrawnCard X)
{
    if(!IsDrawnListEmpty(*L))
    {
        for(int i=LengthDrawn(*L);i>0;i--)
        {
            L->round[i] = L->round[i-1];
        }  
    }
    L->round[0] = X;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtDrawn (DrawnList *L, DrawnCard X, IdxType i)
{
    if(!IsDrawnListEmpty(*L))
    {
        for(int j=LengthDrawn(*L);j>i;j--)
        {
            L->round[j] = L->round[j-1];
        }   
    }
    L->round[i] = X;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastDrawn(DrawnList *L, DrawnCard X)
{
    L->round[LengthDrawn(*L)] = X;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstDrawn(DrawnList *L)
{
    for(int i=0;i<=LengthDrawn(*L);i++)
    {
        L->round[i] = L->round[i+1];
    }
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtDrawn(DrawnList *L, IdxType i)
{
    for(int j=i;j<=LengthDrawn(*L);j++)
    {
        L->round[j] = L->round[j+1];
    }
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLastDrawn(DrawnList *L)
{
    L->round[LengthDrawn(*L)-1].card.Suits = Tanda;
    L->round[LengthDrawn(*L)-1].id_player = -1;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

DrawnList ConcatDrawn(DrawnList L1, DrawnList L2)
{
    DrawnList L = MakeDrawnList();
    for(int i=0;i<=LastIdxDrawn(L1);i++)
    {
        L.round[i] = L1.round[i];
    }
    int idx=LastIdxDrawn(L1)+1;
    for(int i=0;i<=LastIdxDrawn(L2);i++)
    {
        L.round[idx] = L2.round[i];
        idx++;
    }
    return L;
}
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah DrawnList yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
