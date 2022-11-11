# include "queue_card.h"
# include <stdio.h>

void CreateQueue(Queue *q)  {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isQueueEmpty(Queue q)    {
    return ((IDX_HEAD(q) == IDX_UNDEF) || (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isQueueFull(Queue q) {
    return (length(q) == CAPACITY);
}

int lengthCard(Queue q) {
    // case 1, IDX_HEAD <= IDX_TAIL
    if ((IDX_HEAD(q) <= IDX_TAIL(q)) && (!isQueueEmpty(q))) {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    // case 2, IDX_HEAD >= IDX_TAIL
    else if ((IDX_HEAD(q) > IDX_TAIL(q)) && (!isQueueEmpty(q)))   {
        return (CAPACITY + IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    // case 3, queue kosong
    else if (isQueueEmpty(q))  {
        return 0;
    }
}

void enqueueCard(Queue *q, Pemain val)
{
   if (isQueueEmpty(*q))
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

void dequeueCard(Queue *q, Pemain *val) {
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