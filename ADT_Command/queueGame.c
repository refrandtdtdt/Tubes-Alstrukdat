#include <stdio.h>
#include "queueGame.h"

void tambahAntrianGame (TabInt daftar_game, Queue * antrian_game) {
    // Mengeluarkan output game-game yang sedang dalam antrian
    printf("Berikut adalah daftar antrian game-mu\n");
    for (int i = 0; i < length(*antrian_game); i++) {
        printf("%d. %d\n", i+1, (*antrian_game).buffer[i]);
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    // Mengeluarkan output game-game yang terdapat dalam list
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int j = 1; j <= NbElmt(daftar_game); j++) {
        printf("%d. %d\n", j, GetElmt(daftar_game, j));
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    // Input dan proses
    int nomorGame;
    boolean found = false;
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    scanf("%d\n", &nomorGame);
    if (nomorGame >= IdxMin && nomorGame <= NbElmt(daftar_game)) {
        enqueue(antrian_game, GetElmt((daftar_game), (nomorGame)));
        printf("Game berhasil ditambahkan ke dalam daftar antrian.");
    } else {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}
/*
Prosedur ini akan membaca masukan game yang akan ditambahkan user ke dalam antrian game
I.S. Sudah tersedia daftar game dan antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila masukan masih di dalam rentang nomor game di dalam daftar game, maka game dengan nomor game sesuai
                masukan akan masuk ke antrian game
     Kondisi 2) Apabila masukan di luar rentang, akan mengeluarkan pesan kesalahan dan user akan diminta untuk input
                masukan lagi sampai masukan valid
*/