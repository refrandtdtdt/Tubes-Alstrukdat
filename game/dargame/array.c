# include "array.h"
# include <stdlib.h>
# include <stdio.h>

void MakeEmpty (TabInt *T)  {
    T->Neff = 0;
}

int NbElmt (TabInt T)   {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    return T.Neff;
}

int MaxNbEl (TabInt T)  {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
    return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx (TabInt T)  {
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)   {
    return T.Neff;
}

ElType GetElmt (TabInt T, IdxType i)    {
    return T.TI[i];
}

void SetTab (TabInt Tin, TabInt *Tout)  {
    Tout->Neff = Tin.Neff;
    IdxType i;
    for (i = IdxMin; i <= Tin.Neff; i++)    {
        Tout->TI[i] = Tin.TI[i];
    }
}

void SetEl (TabInt *T, IdxType i, ElType v) {
    T->TI[i] = v;
    if (i > GetLastIdx(*T))
    {
        (*T).Neff++;
    }
}

void SetNeff (TabInt *T, IdxType N) {
    T->Neff = N;
}

boolean IsIdxValid (TabInt T, IdxType i)    {
    return (i >= IdxMin) && (i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i)  {
    return (i >= IdxMin) && (i <= T.Neff);
}

boolean IsEmpty (TabInt T)  {
    return T.Neff == 0;
}

boolean IsFull (TabInt T)   {
    return T.Neff = IdxMax;
}

void TulisIsi (TabInt T)    {
    IdxType i, j;
    if (T.Neff == 0)    {
        printf("Tabel kosong\n");
    }
    else    {
        for (i = IdxMin; i <= T.Neff; i++)  {
            j = i;
            printf("%d:%d\n", j, T.TI[i]);
        }
    }
}

TabInt PlusTab (TabInt T1, TabInt T2)   {
    TabInt T3;
    IdxType i;
    for (i = IdxMin; i <= T1.Neff; i++) {
        SetEl(&T3, i, T1.TI[i] + T2.TI[i]);
    }
    T3.Neff = T1.Neff;
    return T3;
}

TabInt MinusTab (TabInt T1, TabInt T2)  {
    TabInt T3;
    IdxType i;
    for (i = IdxMin; i <= T1.Neff; i++) {
        SetEl(&T3, i, T1.TI[i] - T2.TI[i]);
    }
    T3.Neff = T1.Neff;
    return T3;    
}

ElType ValMax (TabInt T)    {
    ElType max = T.TI[IdxMin];
    IdxType i;
    for (i = IdxMin; i <= T.Neff; i++)  {
        if (T.TI[i] > max)
            max = T.TI[i];
    }
    return max;
}

ElType ValMin (TabInt T)    {
    ElType min = T.TI[IdxMin];
    IdxType i;
    for (i = IdxMin; i <= T.Neff; i++)  {
        if (T.TI[i] < min)
            min = T.TI[i];
    }
    return min;    
}

IdxType IdxMaxTab (TabInt T)    {
    IdxType j = IdxUndef;
    IdxType i;
    for (i = IdxMin; i <= T.Neff; i++)  {
        if (T.TI[i] == ValMax(T))   {
            j = i;
            break;
        }
    }
    return j;
}

IdxType IdxMinTab (TabInt T)    {
    IdxType idx = IdxUndef;
    IdxType i;
    for (i = IdxMin; i <= T.Neff; i++)  {
        if (T.TI[i] == ValMin(T))   {
            idx = i;
            break;
        }
    }
    return idx;
}
/*
    int cap = IdxMax - IdxMin + 1;
    IdxType idx;
    if (T->Neff < cap)  {
        for (idx = i; idx <= T->Neff + 1; idx++)    {
            T->TI[idx] = T->TI[idx + 1];
        }
        T->TI[i] = v;
    }
    T->Neff ++;
*/

