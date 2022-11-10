#include <stdio.h>
#include "creategame.h"
#include "../ADT DEFAULT/boolean.h"

void buatgame (TabGame *T)
/*
prosedur ini akan membaca masukkan nama game yang ingin ditambahkan ke dalam Binomo
I.S Sembarang
F.S Game berhasil ditambahkan ke dalam array game yang tersedia 
Apabila game yg ditambahkan sudah ada di dalam array game sebelumnya maka game tidak ditambahkan kembali
*/
{
    char *game;
    printf("Masukkan nama game yang akan ditambahkan: ");
    scanf("%s",&game);
    boolean isMember = false;
    int i;
    for (i = 0; i <= GetLastIdx(*T); i++)
    {
        if (Eqstr((*T).TG[i], game)==true)
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
        int i = (*T).Neff;
        (*T).TG[i] = game;
        printf("Game berhasil ditambahkan");
    }
    else 
    {
        printf("Game sudah terdaftar");
    }
}