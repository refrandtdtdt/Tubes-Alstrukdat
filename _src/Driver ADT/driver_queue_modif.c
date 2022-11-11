#include <stdio.h>
#include "../ADT/queue_modif.h"
#include "../ADT/mesinkata_modif.h"
#include "../ADT/mesinkar.h"
#include "../ADT/functions.h"

int main () {
    // Membuat queue kosong
    Queue tempat; CreateQueue(&tempat);

    // Mengisi array
    printf("Isi queuenya dulu gan:\n");
    for (int i = 0; i < 5; i++) {
        START();
        CopyWord();
        enqueue(&tempat, currentWord);
    }
    printf("\n");

    // Print isi queue
    printf("Isi queuenya gan:\n");
    displayQueue(tempat);
    printf("\n");

    // Panjang queue
    printf("Panjang queuenya gan: %d\n", length(tempat));
    printf("\n");

    // Cek is empty
    printf("Apakah queue kosong?\n");
    if (isEmpty(tempat)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");

    // Cek is full
    printf("Apakah queue full?\n");
    if (isFull(tempat)) {
        printf("Yoi gan\n");
    } else {
        printf("Kaga gan\n");
    }
    printf("\n");

    // Uji dequeue
    ElType val;
    dequeue(&tempat, &val);

    // Print queue setelah dequeue sekali
    printf("Isi queuenya setelah dequeue sekali gan:\n");
    displayQueue(tempat);
    return 0;
}