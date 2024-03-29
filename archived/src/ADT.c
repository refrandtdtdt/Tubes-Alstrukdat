#include "ADT.h"

// HEADER INI BUKAN FINAL, BUAT TESTING AJA

/* ********** KONSTRUKTOR ********** */
void MakeEmpty (TabGame *T)
{
    T->Neff = 0;
   //  for(int i=1;1<=IdxMax;i++)
   //  {
   //    clear(T->TI[i]);
   //  }
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabGame T)
{
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabGame T)
{
    return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabGame T)
{
    return IdxMin;
}

IdxType GetLastIdx (TabGame T)
{
    return T.Neff-1;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabGame T, IdxType i)
{
    return T.TG[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */

void SetTab (TabGame Tin, TabGame *Tout)
{
    Tout->Neff = Tin.Neff;
    for(int i=IdxMin; i<=Tin.Neff; i++)
    {
        Tout->TG[i] = Tin.TG[i];
    }
}

/* Assignment THsl -> Tin */
void SetEl (TabGame *T, IdxType i, ElType v)
{
    T->TG[i] = v;
    T->Neff = T->Neff +1;
}

void SetNeff (TabGame *T, IdxType N)
{
    T->Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabGame T, IdxType i)
{
    return i>=IdxMin && i<=IdxMax;
}

boolean IsIdxEff (TabGame T, IdxType i)
{
    return i>=IdxMin && i<T.Neff;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabGame T)
{
    return T.Neff == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull (TabGame T)
{
    return T.Neff == IdxMax;
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabGame T)
{
    if (T.Neff == 0)
    {
        printf("Tabel kosong\n");
    } 
    else 
    {
        for(int i=IdxMin; i<T.Neff; i++)
        {
            printf("%d:%s\n", i+1, GetElmt(T,i).TabWord);
        }
    }
}

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
         printf("[%d]\n", q.buffer[q.idxHead]);
      }
      else
      {
         printf("[%d", q.buffer[q.idxHead]);
         int i = (q.idxHead+1)%100;
         while (i != q.idxTail)
         {
            printf(",%d", q.buffer[i]);
            i = (i+1)%100;
         }
         printf(",%d]\n", q.buffer[q.idxTail]);
      }
   }
}
