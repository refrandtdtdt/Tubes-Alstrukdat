#ifndef ListPointlinier_H
#define ListPointlinier_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"
#define Nil NULL

typedef struct tElmtListPoint *address;
typedef struct tElmtListPoint { 
	Point info;
    int index;
	address next;
} ElmtListPoint;
typedef struct {
	address First;
    address Last;
} ListPoint;

/* Definisi ListPoint : */
/* ListPoint kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir ListPoint : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Index(P) (P)->index
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST ListPoint KOSONG ******************/
boolean IsEmptyListPoint (ListPoint L);
/* Mengirim true jika ListPoint kosong */

/****************** PEMBUATAN ListPoint KOSONG ******************/
void CreateEmptyListPoint (ListPoint *L);
/* I.S. sembarang             */
/* F.S. Terbentuk ListPoint kosong */

/****************** Manajemen Memori ******************/
address AlokasiPoint (Point X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DeAlokasiPoint (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN ListPoint ******************/
address SearchPoint (ListPoint L, Point X);
/* Mencari apakah ada elemen ListPoint dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListPoint *L, Point X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListPoint *L, Point X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListPoint di akhir; elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal; I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListPoint *L, Point *X);
/* I.S. ListPoint L tidak kosong  */
/* F.S. Elemen pertama ListPoint dihapus; nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListPoint *L, Point *X);
/* I.S. ListPoint tidak kosong */
/* F.S. Elemen terakhir ListPoint dihapus; nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (ListPoint *L, address P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
// void InsertAfter (ListPoint *L, address P, address Prec);
// /* I.S. Prec pastilah elemen ListPoint dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// void InsertLast (ListPoint *L, address P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void DelFirst (ListPoint *L, address *P);
// /* I.S. ListPoint tidak kosong */
// /* F.S. P adalah alamat elemen pertama ListPoint sebelum penghapusan */
// /*      Elemen ListPoint berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListPoint *L, Point X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListPoint beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari ListPoint dan di-dealokasi */
/* Jika tidak ada elemen ListPoint dengan info(P)=X, maka ListPoint tetap */
/* ListPoint mungkin menjadi kosong karena penghapusan */
// void DelLast (ListPoint *L, address *P);
// /* I.S. ListPoint tidak kosong */
// /* F.S. P adalah alamat elemen terakhir ListPoint sebelum penghapusan  */
// /*      Elemen ListPoint berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen terakhir yg lama, */
// /* jika ada */
// void DelAfter (ListPoint *L, address *Pdel, address Prec);
// /* I.S. ListPoint tidak kosong. Prec adalah anggota ListPoint  */
// /* F.S. Menghapus Next(Prec); */
// /*      Pdel adalah alamat elemen ListPoint yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListPoint ******************/
void PrintInfo (ListPoint L);
/* I.S. ListPoint mungkin kosong */
/* F.S. Jika ListPoint tidak kosong, iai ListPoint dicetak ke kanan; [e1,e2,...,en] */
/* Contoh ; jika ada tiga elemen bernilai 1, 20, 30 akan dicetak; [1,20,30] */
/* Jika ListPoint kosong ; menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtListPoint (ListPoint L);
/* Mengirimkan banyaknya elemen ListPoint; mengirimkan 0 jika ListPoint kosong */

#endif