/* File : stack_modif.h */
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
typedef int alamat;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  alamat TOP;  /* alamat TOP: elemen puncak */
} Stackt;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopS(S) (S).TOP
#define InfoTopS(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackt(Stackt *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackt(Stackt S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackt(Stackt S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stackt * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stackt * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


// Mulai dari prosedur ini bakal spesifik digunakan di game Tower of Hanoi
void Display3Stack(Stackt S1, Stackt S2, Stackt S3, int intJumlahPiringan);
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

void DisplayStack(Stackt S);
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

boolean isEqStack(Stackt S1, Stackt S2);
/* Membandingkan apakah dua buah stack sama ataau tidak */
/* I.S. S1 dan S2 terdefinisi */
/* F.S. Mengeluarkan true jika kedua stack sama, false jika beda */
/* Dua stack sama jika jumlah piringan sama dan isi tiap tumpukan di stack sama */

boolean isNoPiring(Stackt S, int intJumlahPiringan);
/* Mengecek ada atau ngga piring di tiang */
/* I.S. S terdefinisi */
/* F.S. Mengeluarkan true jika tidak ada piring di tiang, false jika ada */

boolean isPiringAsalBigger(Stackt Sasal, Stackt Stujuan, int intJumlahPiringan);
/* Mengecek apakah piringan tiang asal lebih besar dari piringan di tiang tujuan */
/* I.S. S terdefinisi */
/* F.S. Mengeluarkan true jika piringan tiang asal lebih besar dari piringan di tiang tujuan, false jika tidak */

int lenBintang(char* str);
/* Meengembalikan panjang bintang di piringan */
/* I.S. S terdefinisi */
/* F.S. Mengembalikan panjang bintang di piringan */

int pangkat(int angka, int pangkatBerapa);
/* Meengembalikan hasil pangkat */
/* I.S. S terdefinisi */
/* F.S. Mengembalikan hasil pangkat */

#endif