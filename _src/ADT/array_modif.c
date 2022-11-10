#include "array_modif.h"

// HEADER INI BUKAN FINAL, BUAT TESTING AJA

/* ********** KONSTRUKTOR ********** */
void MakeEmpty (Tabstr *T)
{
    T->Neff = 0;
   //  for(int i=1;1<=IdxMax;i++)
   //  {
   //    clear(T->TI[i]);
   //  }
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (Tabstr T)
{
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (Tabstr T)
{
    return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (Tabstr T)
{
    return IdxMin;
}

IdxType GetLastIdx (Tabstr T)
{
    return T.Neff-1;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (Tabstr T, IdxType i)
{
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */

void SetTab (Tabstr Tin, Tabstr *Tout)
{
    Tout->Neff = Tin.Neff;
    for(int i=IdxMin; i<=Tin.Neff; i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
}

/* Assignment THsl -> Tin */
void SetEl (Tabstr *T, IdxType i, ElType v)
{
    T->TI[i] = v;
    T->Neff = T->Neff +1;
}

void SetNeff (Tabstr *T, IdxType N)
{
    T->Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (Tabstr T, IdxType i)
{
    return i>=IdxMin && i<=IdxMax;
}

boolean IsIdxEff (Tabstr T, IdxType i)
{
    return i>=IdxMin && i<=T.Neff;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (Tabstr T)
{
    return T.Neff == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull (Tabstr T)
{
    return T.Neff == IdxMax;
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (Tabstr T)
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