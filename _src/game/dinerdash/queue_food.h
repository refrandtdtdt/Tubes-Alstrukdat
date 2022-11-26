/* File : queue_food.h */
/* Definisi ADT QueueFood dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUEFood_H
#define QUEUEFood_H

#include "boolean.h"
#include "adt_makanan.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef Makanan FoodType;
typedef struct {
	FoodType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} QueueFood;




/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueFood, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueueFood(QueueFood *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyfood(QueueFood q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullfood(QueueFood q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthfood(QueueFood q);
/* Mengirimkan banyaknya elemen queueFQueueFood. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueuefood(QueueFood *q, FoodType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeuefood(QueueFood *q, FoodType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display QueueFood *** */
void displayQueueFood(QueueFood q);
/* Proses : Menuliskan isi QueueFood dengan traversal, QueueFood ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika QueueFood kosong : menulis [] */

void sort_enqueuefood(QueueFood *q, FoodType val);

void Search_queuefood(QueueFood Q, int X, int* index);
/*
menghapus yang ketahanannya sudah 0
*/

#endif