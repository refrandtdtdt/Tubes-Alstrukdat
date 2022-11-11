/* File : queuePemain.h */
/* Definisi ADT QueuePemain dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUEPEMAIN_H
#define QUEUEPEMAIN_H

#include "boolean.h"
#include "adt_kartu.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef struct {
	Pemain buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} QueuePemain;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueuePemain, maka akses elemen : */
#define IDX_HEADQ(QueuePemain) (QueuePemain).idxHead
#define IDX_TAILQ(QueuePemain) (QueuePemain).idxTail
#define     HEADQ(QueuePemain) (QueuePemain).buffer[(QueuePemain).idxHead]
#define     TAILQ(QueuePemain) (QueuePemain).buffer[(QueuePemain).idxTail]

/* *** Kreator *** */
void CreateQueuePemain(QueuePemain *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isQueuePemainEmpty(QueuePemain q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isQueuePemainFull(QueuePemain q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthQueuePemain(QueuePemain q);
/* Mengirimkan banyaknya elemen queuePemain. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueuePemain(QueuePemain *q, Pemain val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeuePemain(QueuePemain *q, Pemain *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display QueuePemain *** */
//void displayQueuePemain(QueuePemain q);
/* Proses : Menuliskan isi QueuePemain dengan traversal, QueuePemain ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika QueuePemain kosong : menulis [] */


#endif