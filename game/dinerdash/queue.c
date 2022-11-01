# include "queue_food.h"
# include <stdio.h>

void CreateQueue(Queue *q)  {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)    {
    return ((IDX_HEAD(q) == IDX_UNDEF) || (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFull(Queue q) {
    return (length(q) == CAPACITY);
}

int length(Queue q) {
    // case 1, IDX_HEAD <= IDX_TAIL
    if ((IDX_HEAD(q) <= IDX_TAIL(q)) && (!isEmpty(q))) {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    // case 2, IDX_HEAD >= IDX_TAIL
    else if ((IDX_HEAD(q) > IDX_TAIL(q)) && (!isEmpty(q)))   {
        return (CAPACITY + IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    // case 3, queue kosong
    else if (isEmpty(q))  {
        return 0;
    }
}

void enqueue(Queue *q, ElType val)
{
   if (isEmpty(*q))
   {
      IDX_TAIL(*q) = 0;
      IDX_HEAD(*q) = 0;
      TAIL(*q) = val;
   }
   else
   {
      IDX_TAIL(*q) = (IDX_TAIL(*q)+1)%100;
      TAIL(*q) = val;
   }
}

void dequeue(Queue *q, ElType *val) {
    // Kasus Pertama: saat idxHead < idxMax
    if ((IDX_HEAD(*q) >= 0) && (IDX_HEAD(*q) < CAPACITY-1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))   {
        *val = HEAD(*q);
        IDX_HEAD(*q)++;
    }
    // Kasus Kedua: saat idxHead = idxMax
    else if ((IDX_HEAD(*q) == CAPACITY - 1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))  {
        *val = HEAD(*q);
        IDX_HEAD(*q) = 0;
    }
    // Kasus Ketiga: saat idxHead = idxTail (panjang antrian hanya 1)
    else if (IDX_HEAD(*q) == IDX_TAIL(*q))  {
        *val = HEAD(*q);
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
}

void sort_enqueue(Queue *q, ElType val)    {
    int i, j, k;
    //kasus ketika belum penuh
    if ((q->idxTail < CAPACITY) && (q->idxTail != IDX_UNDEF))   {
        i = q->idxTail;
        while (q->buffer[i].durasi > val.durasi)   {
            i--;
        }
        //insert ke indeks i
        for (j = q->idxTail; j >= i; j--)   {
            q->buffer[j+1] = q->buffer[j];
        }
        q->buffer[i] = val;
        q->idxTail++;
    }
    // kasus ketika kosong
    else if ((IDX_HEAD(*q) == IDX_UNDEF) && (IDX_TAIL(*q) == IDX_UNDEF))    {
        q->buffer[0] = val;
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
}

void Search_queue(Queue Q, int X, int* index){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen dengan ID sesuai dengan ID X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	boolean found = 0;
	int i = IDX_HEAD(Q);
	while((i <= IDX_TAIL(Q)) && !found){
		if(Q.buffer[i].ID == X){
			found = 1;
		}
		else{
			i++;
		}
	}
	if (found)	{
		*index = i;
	}
	else	{
		*index = -1;
	}
}