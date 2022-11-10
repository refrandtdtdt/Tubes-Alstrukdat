#include <stdio.h>
#include "creategame.h"
#include "../ADT DEFAULT/boolean.h"
#include "../../src/ADT.h"

void buatgame (TabGame *T)
/*
prosedur ini akan membaca masukkan nama game yang ingin ditambahkan ke dalam Binomo
I.S Sembarang
F.S Game berhasil ditambahkan ke dalam array game yang tersedia 
Apabila game yg ditambahkan sudah ada di dalam array game sebelumnya maka game tidak ditambahkan kembali
*/
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    START();
    file = true;
    CopyWord();
    boolean isMember = false;
    int i;
    for (i = 0; i <= GetLastIdx(*T); i++)
    {
        if (Eqstr((*T).TG[i].TabWord, kataToString(currentWord)))
        {
            isMember = true;
        }
        else
        {
            isMember = false;
        }
    }
    if (!isMember)
    {
        (*T).Neff++;
        (*T).TG[i] = currentWord;
        printf("Game berhasil ditambahkan\n");
    }
    else 
    {
        printf("Game sudah terdaftar\n");
    }
}