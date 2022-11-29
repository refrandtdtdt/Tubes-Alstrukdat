#include "array.h"

// HEADER INI BUKAN FINAL, BUAT TESTING AJA

/* ********** KONSTRUKTOR ********** */
void MakeEmpty (TabKata *T)
{
    T->Neff = 0;
   //  for(int i=1;1<=IdxMax;i++)
   //  {
   //    clear(T->TG[i]);
   //  }
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabKata T)
{
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabKata T)
{
    return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabKata T)
{
    return IdxMin;
}

IdxType GetLastIdx (TabKata T)
{
    return T.Neff-1;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabKata T, IdxType i)
{
    return T.TK[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */

void SetTab (TabKata Tin, TabKata *Tout)
{
    Tout->Neff = Tin.Neff;
    for(int i=IdxMin; i<=Tin.Neff; i++)
    {
        Tout->TK[i] = Tin.TK[i];
    }
}

/* Assignment THsl -> Tin */
void SetEl (TabKata *T, IdxType i, ElType v)
{
    T->TK[i] = v;
    T->Neff = T->Neff +1;
}

void SetNeff (TabKata *T, IdxType N)
{
    T->Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabKata T, IdxType i)
{
    return i>=IdxMin && i<=IdxMax;
}

boolean IsIdxEff (TabKata T, IdxType i)
{
    return i>=IdxMin && i<T.Neff;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabKata T)
{
    return T.Neff == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull (TabKata T)
{
    return T.Neff == IdxMax;
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabKata T)
{
    if (T.Neff == 0)
    {
        printf("Tabel kosong\n");
    } 
    else 
    {
        for(int i=IdxMin; i<T.Neff; i++)
        {
            printf("%d:%s\n", i+1, GetElmt(T,i).TabWord);
        }
    }
}