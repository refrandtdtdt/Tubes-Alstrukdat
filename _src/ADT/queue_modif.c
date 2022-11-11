#include "queue_modif.h"

void CreateQueue(Queue *q)
{
   q->idxTail = IDX_UNDEF;
   q->idxHead = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
   return q.idxTail == IDX_UNDEF;
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q)
{
   return (q.idxTail+1)%100 == q.idxHead;
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q)
{
   if (q.idxTail == IDX_UNDEF)
   {
      return 0;
   }
   else 
   {
      int i = q.idxHead;
      int count = 1;
      while (i != q.idxTail)
      {
         count++;
         i = (i+1)%100;
      }
      return count;
   }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
   if (isEmpty(*q))
   {
      q->idxTail = 0;
      q->idxHead = 0;
      q->buffer[q->idxTail] = val;
   }
   else
   {
      q->idxTail = (q->idxTail+1)%100;
      q->buffer[q->idxTail] = val;
   }
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val)
{
   if (q->idxTail==q->idxHead)
   {
      *val = q->buffer[q->idxHead];
      q->idxTail = IDX_UNDEF;
      q->idxHead = IDX_UNDEF;
   }
   else
   {
      *val = q->buffer[q->idxHead];
      q->idxHead = (q->idxHead+1)%100;
   }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
   if(isEmpty(q))
   {
      printf("[]\n");
   }
   else
   {
      if(q.idxTail==q.idxHead)
      {
         printf("[%s]\n", q.buffer[q.idxHead].TabWord);
      }
      else
      {
         printf("[%s", q.buffer[q.idxHead].TabWord);
         int i = (q.idxHead+1)%100;
         while (i != q.idxTail)
         {
            printf(",%s", q.buffer[i].TabWord);
            i = (i+1)%100;
         }
         printf(",%s]\n", q.buffer[q.idxTail].TabWord);
      }
   }
}
