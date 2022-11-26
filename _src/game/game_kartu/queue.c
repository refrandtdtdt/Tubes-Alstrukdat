# include "queue.h"
# include <stdio.h>

void CreateQueuePemain(QueuePemain *q)  {
    IDX_HEADQ(*q) = IDX_UNDEF;
    IDX_TAILQ(*q) = IDX_UNDEF;
}

boolean isQueuePemainEmpty(QueuePemain q)    {
    return ((IDX_HEADQ(q) == IDX_UNDEF) || (IDX_TAILQ(q) == IDX_UNDEF));
}

boolean isQueuePemainFull(QueuePemain q) {
    return (lengthQueuePemain(q) == CAPACITY);
}

int lengthQueuePemain(QueuePemain q) {
    // case 1, IDX_HEADQ <= IDX_TAILQ
    if ((IDX_HEADQ(q) <= IDX_TAILQ(q)) && (!isQueuePemainEmpty(q))) {
        return (IDX_TAILQ(q) - IDX_HEADQ(q) + 1);
    }
    // case 2, IDX_HEADQ >= IDX_TAILQ
    else if ((IDX_HEADQ(q) > IDX_TAILQ(q)) && (!isQueuePemainEmpty(q)))   {
        return (CAPACITY + IDX_TAILQ(q) - IDX_HEADQ(q) + 1);
    }
    // case 3, queuePemain kosong
    else if (isQueuePemainEmpty(q))  {
        return 0;
    }
}

void enqueuePemain(QueuePemain *q, Pemain val)
{
   if (isQueuePemainEmpty(*q))
   {
      IDX_TAILQ(*q) = 0;
      IDX_HEADQ(*q) = 0;
      TAILQ(*q) = val;
   }
   else
   {
      IDX_TAILQ(*q) = (IDX_TAILQ(*q)+1)%100;
      TAILQ(*q) = val;
   }
}

void dequeuePemain(QueuePemain *q, Pemain *val) {
    // Kasus Pertama: saat idxHead < idxMax
    if ((IDX_HEADQ(*q) >= 0) && (IDX_HEADQ(*q) < CAPACITY-1) && (IDX_HEADQ(*q) != IDX_TAILQ(*q)))   {
        *val = HEADQ(*q);
        IDX_HEADQ(*q)++;
    }
    // Kasus Kedua: saat idxHead = idxMax
    else if ((IDX_HEADQ(*q) == CAPACITY - 1) && (IDX_HEADQ(*q) != IDX_TAILQ(*q)))  {
        *val = HEADQ(*q);
        IDX_HEADQ(*q) = 0;
    }
    // Kasus Ketiga: saat idxHead = idxTail (panjang antrian hanya 1)
    else if (IDX_HEADQ(*q) == IDX_TAILQ(*q))  {
        *val = HEADQ(*q);
        IDX_HEADQ(*q) = IDX_UNDEF;
        IDX_TAILQ(*q) = IDX_UNDEF;
    }
}
/*
void displayQueuePemain(QueuePemain q)  {
    // array untuk kebutuhan
    Pemain temp[CAPACITY];
    // masukan nilai-nilai queuePemain ke array
    // jika IDX_HEADQ <= IDX_TAILQ
    int i, m, k;
    m = 0;
    while (!isEmpty(q)) {
        dequeuePemain(&q, &k);
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
*/