#include "listword.h"

void tambahkata (TabKata *T)
/*
prosedur ini akan membaca masukkan nama game yang ingin ditambahkan ke dalam Binomo
I.S Sembarang
F.S Game berhasil ditambahkan ke dalam array game yang tersedia 
Apabila game yg ditambahkan sudah ada di dalam array game sebelumnya maka game tidak ditambahkan kembali
*/
{
    printf("Masukkan kata baru yang akan ditambahkan: ");
    START();
    file = true;
    CopyWord();
    boolean isMember = false;
    int i;
    for (i = 0; i <= GetLastIdx(*T); i++)
    {
        if (Eqstr((*T).TK[i].TabWord, kataToString(currentWord)))
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
        (*T).TK[i] = currentWord;
        printf("Kata berhasil ditambahkan\n");
    }
    else 
    {
        printf("Kata sudah terdaftar\n");
    }
}