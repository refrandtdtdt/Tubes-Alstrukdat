#include "array_modif.h"

// HEADER INI BUKAN FINAL, BUAT TESTING AJA

/* ********** KONSTRUKTOR ********** */
void MakeEmpty (TabGame *T)
{
    T->Neff = 0;
   //  for(int i=1;1<=IdxMax;i++)
   //  {
   //    clear(T->TG[i]);
   //  }
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabGame T)
{
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabGame T)
{
    return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabGame T)
{
    return IdxMin;
}

IdxType GetLastIdx (TabGame T)
{
    return T.Neff-1;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabGame T, IdxType i)
{
    return T.TG[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */

void SetTab (TabGame Tin, TabGame *Tout)
{
    Tout->Neff = Tin.Neff;
    for(int i=IdxMin; i<=Tin.Neff; i++)
    {
        Tout->TG[i] = Tin.TG[i];
    }
}

/* Assignment THsl -> Tin */
void SetEl (TabGame *T, IdxType i, ElType v)
{
    T->TG[i] = v;
    T->Neff = T->Neff +1;
}

void SetNeff (TabGame *T, IdxType N)
{
    T->Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabGame T, IdxType i)
{
    return i>=IdxMin && i<=IdxMax;
}

boolean IsIdxEff (TabGame T, IdxType i)
{
    return i>=IdxMin && i<T.Neff;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabGame T)
{
    return T.Neff == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull (TabGame T)
{
    return T.Neff == IdxMax;
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabGame T)
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