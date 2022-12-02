#include "arraykata.h"

// HEADER INI BUKAN FINAL, BUAT TESTING AJA

/* ********** KONSTRUKTOR ********** */
void MakeEmptyTab (TabKata *T)
{
    T->Neff = 0;
   //  for(int i=1;1<=IdxMax;i++)
   //  {
   //    clear(T->TG[i]);
   //  }
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtTab (TabKata T)
{
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbElTab (TabKata T)
{
    return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IndexType GetFirstIdxTab (TabKata T)
{
    return IdxMin;
}

IndexType GetLastIdxTab (TabKata T)
{
    return T.Neff-1;
}

/* *** Menghasilkan sebuah elemen *** */
Eletype GetElmtTab (TabKata T, IndexType i)
{
    return T.TK[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */

void SetTabKata (TabKata Tin, TabKata *Tout)
{
    Tout->Neff = Tin.Neff;
    for(int i=IdxMin; i<=Tin.Neff; i++)
    {
        Tout->TK[i] = Tin.TK[i];
    }
}

/* Assignment THsl -> Tin */
void SetElKata (TabKata *T, IndexType i, Eletype v)
{
    T->TK[i] = v;
    T->Neff = T->Neff +1;
}

void SetNeffKata (TabKata *T, IndexType N)
{
    T->Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidTab (TabKata T, IndexType i)
{
    return i>=IdxMin && i<=IdxMax;
}

boolean IsIdxEffTab (TabKata T, IndexType i)
{
    return i>=IdxMin && i<T.Neff;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTab (TabKata T)
{
    return T.Neff == 0;
}

/* *** Test tabel penuh *** */
boolean IsFullTab (TabKata T)
{
    return T.Neff == IdxMax;
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTab (TabKata T)
{
    if (T.Neff == 0)
    {
        printf("Tabel kosong\n");
    } 
    else 
    {
        for(int i=IdxMin; i<T.Neff; i++)
        {
            printf("%d:%s\n", i+1, GetElmtTab(T,i).TabWord);
        }
    }
}