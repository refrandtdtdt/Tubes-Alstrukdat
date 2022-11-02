#include <stdio.h>
#include "queueGame.h"

void tambahAntrianGame (Set * daftar_game, Queue * antrian_game) {
    // Mengeluarkan output game-game yang sedang dalam antrian
    printf("Berikut adalah daftar antrian game-mu\n");
    for (int i = 0; i < length(*antrian_game); i++) {
        printf("%d. %s\n", i+1, (*antrian_game).buffer[i]);
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    // Mengeluarkan output game-game yang terdapat dalam list
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int j = 0; j < (*daftar_game).Count; j++) {
        printf("%d. %s\n", j+1, (*daftar_game).Elements[j]);
    }

    // Input dan proses
    int nomorGame;
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    scanf("%d\n", &nomorGame);
    while (nomorGame > (*daftar_game).Count) {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        printf("Nomor Game yang mau ditambahkan ke antrian: ");
        scanf("%d\n", &nomorGame);
    }
    enqueue(antrian_game, (*daftar_game).Elements[nomorGame-1]);
    printf("Game berhasil ditambahkan ke dalam daftar antrian.");
}
/*
Prosedur ini akan membaca masukan game yang akan ditambahkan user ke dalam antrian game
I.S. Sudah tersedia daftar game dan antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila masukan masih di dalam rentang nomor game di dalam daftar game, maka game dengan nomor game sesuai
                masukan akan masuk ke antrian game
     Kondisi 2) Apabila masukan di luar rentang, akan mengeluarkan pesan kesalahan dan user akan diminta untuk input
                masukan lagi sampai masukan valid
*/