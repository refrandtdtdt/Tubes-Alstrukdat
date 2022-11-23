#include <stdio.h>
#include "stack_modif.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S) {
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S) {
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X) {
    if (IsEmptyStack(*S)) {
        Top(*S) = 0;
        InfoTop(*S) = X;
    } else {
        Top(*S)++;
        InfoTop(*S) = X;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X) {
    if (Top(*S) == 0) {
        (*X) = InfoTop(*S);
        Top(*S) = Nil;
    } else {
        (*X) = InfoTop(*S);
        Top(*S)--;
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void Display3Stack(Stack S1, Stack S2, Stack S3) {
    int i, j;
    for (i = Top(S1); i >= 0; i--) {
        printf("%s", S1.T[i].TabWord);
        printf("%s", S2.T[i].TabWord);
        printf("%s", S3.T[i].TabWord);
        printf("\n");
    }
}
/* Menampilkan isi 3 stack yang berjajar ke samping dengan isi tiap stacknya berjajar ke bawah */
/* I.S. S1, S2, S3 terdefinisi */
/* F.S. Tercetak isi stack seperti di bawah ini */
/*
Misal :
   *             *
  * *     *     * *
 * * *   * *   * * * 
* * * * * * * * * * *
*/

void DisplayStack(Stack S) {
    int i, j;
    for (i = Top(S); i >= 0; i--) {
        printf("%s\n", S.T[i].TabWord);
    }
}
/* Menampilkan isi stack secara berjajar ke bawah */
/* I.S. S terdefinisi */
/* F.S. Tercetak isi stack berjajar ke bawah */
/*
Misal :
   *    
  * *    
 * * * 
* * * * 
*/

boolean isEqStack(Stack S1, Stack S2) {
    int i = 0;
    if (Top(S1) == Top(S2)) {
        while (i <= Top(S1)) {
            if (!Eqstr(S1.T[i].TabWord, S2.T[i].TabWord)) {
                return false;
            }
            i++;
        }
        return true;
    } else {
        return false;
    }
}
/* Membandingkan apakah dua buah stack sama ataau tidak */
/* I.S. S1 dan S2 terdefinisi */
/* F.S. Mengeluarkan true jika kedua stack sama, false jika beda */
/* Dua stack sama jika jumlah piringan sama dan isi tiap tumpukan di stack sama */