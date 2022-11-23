#ifndef listSnakelinier_H
#define listSnakelinier_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"
#define Nil NULL

typedef struct tElmtlistSnake *address;
typedef struct tElmtlistSnake { 
	Point info;
    int index;
	address next;
} ElmtListSnake;
typedef struct {
	address First;
    address Last;
} ListSnake;

/* Definisi listSnake : */
/* ListSnake kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir listSnake : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Index(P) (P)->index
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LISTSNAKE KOSONG ******************/
boolean IsEmptySnake (ListSnake L);
/* Mengirim true jika listSnake kosong */

/****************** PEMBUATAN LISTSNAKE KOSONG ******************/
void CreateEmptySnake (ListSnake *L);
/* I.S. sembarang             */
/* F.S. Terbentuk listSnake kosong */

/****************** Manajemen Memori ******************/
address AlokasiSnake (Point X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiSnake (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LISTSNAKE ******************/
address SearchSnake (ListSnake L, Point X);
/* Mencari apakah ada elemen listSnake dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListSnake *L, Point X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListSnake *L, Point X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen listSnake di akhir; elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal; I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListSnake *L, Point *X);
/* I.S. ListSnake L tidak kosong  */
/* F.S. Elemen pertama listSnake dihapus; nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListSnake *L, Point *X);
/* I.S. listSnake tidak kosong */
/* F.S. Elemen terakhir listSnake dihapus; nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (ListSnake *L, address P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
// void InsertAfter (ListSnake *L, address P, address Prec);
// /* I.S. Prec pastilah elemen listSnake dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// void InsertLast (ListSnake *L, address P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void DelFirst (ListSnake *L, address *P);
// /* I.S. ListSnake tidak kosong */
// /* F.S. P adalah alamat elemen pertama listSnake sebelum penghapusan */
// /*      Elemen listSnake berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListSnake *L, Point X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen listSnake beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari listSnake dan di-dealokasi */
/* Jika tidak ada elemen listSnake dengan info(P)=X, maka listSnake tetap */
/* ListSnake mungkin menjadi kosong karena penghapusan */
// void DelLast (ListSnake *L, address *P);
// /* I.S. ListSnake tidak kosong */
// /* F.S. P adalah alamat elemen terakhir listSnake sebelum penghapusan  */
// /*      Elemen listSnake berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen terakhir yg lama, */
// /* jika ada */
// void DelAfter (ListSnake *L, address *Pdel, address Prec);
// /* I.S. ListSnake tidak kosong. Prec adalah anggota listSnake  */
// /* F.S. Menghapus Next(Prec); */
// /*      Pdel adalah alamat elemen listSnake yang dihapus  */

/****************** PROSES SEMUA ELEMEN LISTSNAKE ******************/
void PrintInfo (ListSnake L);
/* I.S. ListSnake mungkin kosong */
/* F.S. Jika listSnake tidak kosong, iai listSnake dicetak ke kanan; [e1,e2,...,en] */
/* Contoh ; jika ada tiga elemen bernilai 1, 20, 30 akan dicetak; [1,20,30] */
/* Jika listSnake kosong ; menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtSnake (ListSnake L);
/* Mengirimkan banyaknya elemen listSnake; mengirimkan 0 jika listSnake kosong */

#endif