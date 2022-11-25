/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef STACKMODIF_H
#define STACKMODIF_H

#include <stdio.h>
#include "../boolean.h"
#include "functions.h"
#include "mesinkata_modif.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Word infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


// Mulai dari prosedur ini bakal spesifik digunakan di game Tower of Hanoi
void Display3Stack(Stack S1, Stack S2, Stack S3, int intJumlahPiringan);
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

void DisplayStack(Stack S);
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

boolean isEqStack(Stack S1, Stack S2);
/* Membandingkan apakah dua buah stack sama ataau tidak */
/* I.S. S1 dan S2 terdefinisi */
/* F.S. Mengeluarkan true jika kedua stack sama, false jika beda */
/* Dua stack sama jika jumlah piringan sama dan isi tiap tumpukan di stack sama */

boolean isNoPiring(Stack S, int intJumlahPiringan);
/* Mengecek ada atau ngga piring di tiang */
/* I.S. S terdefinisi */
/* F.S. Mengeluarkan true jika tidak ada piring di tiang, false jika ada */

boolean isPiringAsalBigger(Stack Sasal, Stack Stujuan);
/* Mengecek apakah piringan tiang asal lebih besar dari piringan di tiang tujuan */
/* I.S. S terdefinisi */
/* F.S. Mengeluarkan true jika piringan tiang asal lebih besar dari piringan di tiang tujuan, false jika tidak */

#endif