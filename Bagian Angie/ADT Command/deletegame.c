#include <stdio.h>
#include "deletegame.h"
#include "listgame.h"

void HapusGame(TabGame *T)
/*I.S Tab terdefinisi dan tidak kosong */
/*F.S elemen game ke-i dihapus dari tab game sesuai dengan keinginan user*/
/*Syarat penghapusan game: 
- Game yang dapat dihapus hanyalah game yang dibuat secara custom sendiri oleh user
- Lima Game pertama yang terdapat dlaam file konfigurasi (game default) tidak dapat dihapus 
- Game yang berada dalam queue game (antrian game) tidak dapat dihapus */
{
    printf("Berikut adalah daftar game yang tersedia");
    ListGame(*T);
    printf("Masukkan nomor game yang akan dihapus: ");
    int del;
    scanf("%d", &del);
    if (del < 5)
    {
        printf("Game gagal dihapus\n");
    }
    else
    {
        int j;
        for (j = del; del < GetLastIdx(*T); j++)
        {
            (*T).TG[j] = (*T).TG[j+1];
            (*T).Neff -= 1;
        }
        printf("Game berhasil dihapus\n");
    }
}