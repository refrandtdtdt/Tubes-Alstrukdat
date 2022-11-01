#include <stdio.h>
#include "queueGame.h"

/*
Prosedur ini akan membaca nomor game yang akan dimasukkan ke dalam antrian, lalu dicek apakah nomor game
tersebut masih dalam rentang nomor game yang ada pada daftar game.
Asumsi : Queue game maksimal hanya menampung 100 antrian game
I.S. Terdapat queue untuk menampung antrian.
F.S. Apabila nomor game valid, game dengan nomor game tersebut dimasukkan ke dalam queue tempat penampungan,
apabila tidak, akan mengeluarkan output bahwa nomor game tidak valid dan akan mengulang proses input nomor game
yang akan dimasukkan ke queue tempat penampungan.
*/
void tambahQueueGame () {
    // Deklarasi
    Queue tempatPenampungan;
    CreateQueue(&tempatPenampungan);
    boolean found;
    found = false;

    // Input dan Proses
    while (!found) {

    }

}