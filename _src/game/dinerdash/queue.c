# include "queue_food.h"
# include <stdio.h>

void CreateQueueFood(QueueFood *q)  {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyfood(QueueFood q)    {
    return ((IDX_HEAD(q) == IDX_UNDEF) || (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFullfood(QueueFood q) {
    return (lengthfood(q) == CAPACITY);
}

int lengthfood(QueueFood q) {
    // case 1, IDX_HEAD <= IDX_TAIL
    if ((IDX_HEAD(q) <= IDX_TAIL(q)) && (!isEmptyfood(q))) {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    // case 2, IDX_HEAD >= IDX_TAIL
    else if ((IDX_HEAD(q) > IDX_TAIL(q)) && (!isEmptyfood(q)))   {
        return (CAPACITY + IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    // case 3, queueFood kosong
    else if (isEmptyfood(q))  {
        return 0;
    }
}

void enqueuefood(QueueFood *q, FoodType val)
{
   if (isEmptyfood(*q))
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

void dequeuefood(QueueFood *q, FoodType *val) {
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

void sort_enqueuefood(QueueFood *q, FoodType val)    {
    int i, j, k;
    //kasus ketika belum penuh
    if ((q->idxTail < CAPACITY) && (q->idxTail != IDX_UNDEF))   {
        i = q->idxHead;
        while (q->buffer[i].durasi < val.durasi && i < q->idxTail+1)   {
            i++;
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

void Search_queuefood(QueueFood Q, int X, int* index){
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen dengan ID sesuai dengan ID X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	boolean found = 0;
	int i = IDX_HEAD(Q);
	while((i <= IDX_TAIL(Q)) && !found){
		if(Q.buffer[i].ID == X){
			found = true;
		}
		else{
			i++;
		}
	}
	if (found)	{
		*index = i;
	}
	else	{
		*index = IDX_UNDEF;
	}
}