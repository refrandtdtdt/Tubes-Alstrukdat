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

void displayQueue(Queue q)  {
    // array untuk kebutuhan
    ElType temp[CAPACITY];
    // masukan nilai-nilai queue ke array
    // jika IDX_HEAD <= IDX_TAIL
    int i, m, k;
    m = 0;
    while (!isEmpty(q)) {
        dequeue(&q, &k);
        temp[m] = k;
        m++;
    }
    // print traversal
    printf("[");
    if (m > 0)  {
        for (i = 0; i < m-1; i++) {
            printf("%d,", temp[i]);
        }
        printf("%d", temp[m-1]);
    }
    printf("]\n");
}