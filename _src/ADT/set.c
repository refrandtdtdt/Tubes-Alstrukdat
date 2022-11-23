/*
Nama: Nazhif Haidar Putra Wibowo
NIM: 18221083
Praktikum 8
Deskripsi: Implementasi primitif Set
*/

# include "set.h"
#include <stdio.h>

void CreateEmptySet(Set *S)    {
    S->Count = SetNil;
}

boolean IsEmptySet(Set S)  {
    return S.Count == SetNil;
}

boolean IsFull(Set S)   {
    return S.Count == MaxElSet;
}

void InsertSet(Set *S, infotypeset Elmt)  {
    if (!IsMemberSet(*S, Elmt))  {
        S->Elements[S->Count] = Elmt;
        S->Count++;
    }
    else    {
        printf("Gomen, nama sudah terpakai.\n");
    }
}

void DeleteSet(Set *S, infotypeset Elmt)  {
    //delete dengan digeser
    int i;
    if (IsMemberSet(*S, Elmt)) {
        int idx = 0;
        while (idx < S->Count)  {
            if (S->Elements[idx] == Elmt)   {
                for (i = idx; i < S->Count; i++)    {
                    S->Elements[i] = S->Elements[i+1];
                }
                S->Count--;
            }
            idx++;
        }
    }
}

boolean IsMemberSet(Set S, infotypeset Elmt)  {
    boolean found = false;
    int i = 0;
    while (!found && (i < S.Count))    {
        if (S.Elements[i] == Elmt) {
            found = true;
        }
        i++;
    }
    return found;
}