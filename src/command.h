#ifndef COMMAND_H
#define COMMAND_H

/*Spesifikasi Command*/

# include "boolean.h"
# include "functions.h"
# include <stdio.h>
# include <stdlib.h>
# include "ADT.h"
# include "mesinkar.h"
# include "mesinkata_modif.h"

void Help() {
    char* input;
    input = (char*) malloc (20*sizeof(char));
    printf("help command: \n");
    printf("-START\n-LOAD\n-SAVE\n-CREATE GAME\n-LIST GAME\n-DELETE GAME\n-QUEUE GAME\n-PLAY GAME\n-SKIP GAME\n");
    scanf("%[^\n]%*c", input);
    if (Eqstr(input,"LOAD"))   {
        printf("(+) LOAD <filename>: \n");
        printf("Memiliki satu argumen yaitu filename yang merepresentasikan suatu save file yang ingin dibuka. ");
        printf("Membaca save file <filename> yang berisi list game yang dapat dimainkan, histori dan scoreboard game\n");
    }
    else if (Eqstr(input,"START"))  {
        printf("(+) START: \n");
        printf("Memulai program dengan me-load konfigurasi default.\n");
    }
    else if (Eqstr(input,"SAVE")) {
        printf("(+) SAVE <filename>: \n");
        printf("menyimpan save file dengan nama <filename>.\n");
    }
    else if (Eqstr(input,"CREATE GAME")) {
        printf("(+) CREATE GAME: \n");
        printf("Membuat game baru ke dalam Daftar Game.\n");
    }
    else if (Eqstr(input,"LIST GAME"))  {
        printf("(+) LIST GAME: \n menampilkan daftar game-game yang tersedia.\n");
    }
    else if (Eqstr(input,"DELETE GAME"))    {
        printf("(+) DELETE GAME: \n");
        printf("Menghapus Game yang ada di daftar Game, kemudian memasukkan nomor game yang akan dihapus.\n");
    }
    else if (Eqstr(input,"QUEUE GAME")) {
        printf("(+) QUEUE GAME: \n");
        printf("mendaftarkan permainan ke dalam antrean.\n");
    }
    else if (Eqstr(input,"PLAY GAME"))  {
        printf("(+) PLAY GAME: \n");
        printf("Memainkan sebuah permainan.\n");
    }
    else if (Eqstr(input,"SKIP GAME"))  {
        printf("(+) SKIP GAME <n>: \n");
        printf("melewatkan permainan sebanyak n.\n");
    }
    free(input);
}
/* memberikan bantuan untuk tiap-tiap command
I.S. Sembarang
F.S. Mencetak bantuan-bantuan sesuai input
*/

void Quit() {
    printf("keluar dari Game\n");
    printf("Jangan lupa tidur cukup dan makan makanan yang bergizi\n");
    printf("Sayounara\n");
    exit(0);
}
/*
perintah untuk mengeluarkan program
I.S. Sembarang
F.S. mengakhiri program ketika input QUIT diberikan
*/
// void Start()
// {
//     Load()
// }

void Load(char *filename, Tabstr *list)
{
    char* currline;
    printf("Loading %s...\n", filename);
    STARTF(filename);
    if(retval == EOF)
    {
        printf("\nSavefile could not be found\n");
    }
    else
    {
        Sentence gameName; CreateSentence(&gameName);
        int games = 0;
        while (cc != '\n')
        {
            games *= 10;
            games += cc-'0';
            ADV();
        }
        printf("%d games loaded\n", games);
        ADV();
        for (int i = 0; i < games; i++)
        {
            clear(gameName.buffer[i].TabWord);
        }
        convertToArrayOfKata(&gameName, games);
        for (int i = 0; i <games;i++)
        {
            list->TI[i] = gameName.buffer[i];
        }
        list->Neff = games;
        printf("\nSavefile loaded successfully\n");
        CLOSEF();
    }
}

void Save(char* filename, Tabstr list)
{
    printf("Saving to %s...\n", filename);
    STARTW(filename);
    fprintf(pita, "%d\n", list.Neff);
    for (int i = 0; i < list.Neff; i++)
    {
        fprintf(pita, "%s\n", list.TI[i].TabWord);
    }
    CLOSEF();
    printf("Saved Successfully\n");
}

void CreateGame()
{
    printf("CreateGame\n");
}

void ListGame(Tabstr T)
{
    TulisIsi(T);
}

void DeleteGame()
{
    printf("DeleteGame\n");
}

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
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    boolean valid = false;
    while (!valid) {
        scanf("%d", &nomorGame);
        if (IsIdxEff(daftar_game, nomorGame)) {
            valid = true;
        } else {
            printf("Nomor permainan tidak valid, silakan masukkan nomor game pada list.\n");
            printf("Nomor Game yang mau ditambahkan ke antrian: ");
        }
    }
    enqueue(antrian_game, GetElmt((daftar_game), (nomorGame)));
    printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
}
/*
Prosedur ini akan membaca masukan game yang akan ditambahkan user ke dalam antrian game
I.S. Sudah tersedia daftar game dan antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila masukan masih di dalam rentang nomor game di dalam daftar game, maka game dengan nomor game sesuai
                masukan akan masuk ke antrian game
     Kondisi 2) Apabila masukan di luar rentang, akan mengeluarkan pesan kesalahan dan user akan diminta untuk input
                masukan lagi sampai masukan valid
*/

void mainkanGame (Queue * antrian_game) {
    printf("Berikut adalah daftar game dalam antrianmu\n");
    int i;
    for (i = 0; i < length((*antrian_game)); i++) {
        printf("%d. %d\n", i+1, (*antrian_game).buffer[(i + IDX_HEAD((*antrian_game))) % CAPACITY]);
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    if (isEmpty(*antrian_game)) {
        printf("Belum ada game dalam antrianmu.\n");
        printf("Silakan masukkan command QUEUE GAME untuk menambahkan game dalam antrianmu.\n");
    } else {
        // Dequeue game yang dimainkan
        int dummy;
        dequeue(antrian_game, &dummy);

        if (dummy == 1) { // 1 asumsinya RNG
            printf("Loading RNG ...\n");
            // Panggil fungsi game RNG
        } else if (dummy == 2) { // 2 asumsinya Diner DASH
            printf("Loading  Diner DASH ...\n");
            // Panggil fungsi game Diner DASH
        } else if ((dummy == 3) || (dummy == 4) || (dummy == 5)) { // asumsinya 3 = DINOSAUR IN EARTH, 4 = RISEWOMAN, 5 = EIFFEL TOWER
            if (dummy == 3) {
                printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            } else if (dummy == 4) {
                printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            } else if (dummy == 5) {
                printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            }
        } else {
            printf("Nanti menjalankan fungsi game tambahan.\n"); // panggil fungsi game tambahan (angka random)
        }
    }
}
/*
Prosedur ini akan langsung memainkan game yang terletak pada antrian pertama pada antrian game
I.S. Sudah tersedia antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila game dalam antrian pertama bisa dimainkan, maka akan mengeluarkan output sedang loading 
                game, lalu memainkan game. Game yang dimainkan akan dikeluarkan dari atrian game
     Kondisi 2) Apabila game dalam antrian pertama tidak bisa dimainkan (dalam maintenance), maka akan mengeluarkan
                output bahwa tidak bisa memainkan game. Game yang tidak bisa dimainkan tersebut dikeluarkan dari
                antrian game
Note : apabila antrian game kosong, akan mengeluarkan output bahwa belum ada game dalam antrian dan cara memasukkan
       game ke dalam antrian
*/

void lewatiGame (Queue * antrian_game, int jumlah_skip) {
    printf("Berikut adalah daftar game dalam antrianmu\n");
    int i;
    for (i = 0; i < length((*antrian_game)); i++) {
        printf("%d. %d\n", i+1, (*antrian_game).buffer[(i + IDX_HEAD((*antrian_game))) % CAPACITY]);
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    if (isEmpty(*antrian_game)) {
        printf("Belum ada game dalam antrianmu.\n");
        printf("Silakan masukkan command QUEUE GAME untuk menambahkan game dalam antrianmu.\n");
    } else {
        if (jumlah_skip < length(*antrian_game)) {
            // Dequeue <jumlah_skip> buah game
            int j;
            int dummySkip;
            for (j = 0; j < jumlah_skip; j++) {
                dequeue((antrian_game), &dummySkip);
            }

            // Dequeue game yang dimainkan
            int dummy;
            dequeue(antrian_game, &dummy);
            
            /* 
            Kalau <jumlah_skip> == length(*antrian_game) - 1, maka akan ngeskip (ngedequeue) <jumlah_skip> buah
            game lalu juga ngedequeue game yang dimainkan, akibatnya IDX_HEAD(*antrian_game) > IDX_TAIL(*antrian_game)
            karena pada dasarnya kalau ngedequeue itu index dari head akan "mundur", maka harus dibuat kondisi khusus
            untuk menjadikan antrian tadi menjadi kosong lagi dengan CreateQueue(antrian_game)
            */
            if (IDX_HEAD(*antrian_game) > IDX_TAIL(*antrian_game)) {
                CreateQueue(antrian_game);
            }

            if (dummy == 1) { // 1 asumsinya RNG
                printf("Loading RNG ...\n");
                // Panggil fungsi game RNG
            } else if (dummy == 2) { // 2 asumsinya Diner DASH
                printf("Loading  Diner DASH ...\n");
                // Panggil fungsi game Diner DASH
            } else if ((dummy == 3) || (dummy == 4) || (dummy == 5)) { // asumsinya 3 = DINOSAUR IN EARTH, 4 = RISEWOMAN, 5 = EIFFEL TOWER
                if (dummy == 3) {
                    printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan.\n");
                    printf("Silahkan pilih game lain.\n");
                } else if (dummy == 4) {
                    printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan.\n");
                    printf("Silahkan pilih game lain.\n");
                } else if (dummy == 5) {
                    printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan.\n");
                    printf("Silahkan pilih game lain.\n");
                }
            } else {
                printf("Nanti menjalankan fungsi game tambahan.\n"); // panggil fungsi game tambahan (angka random)
            }
        } else {
            CreateQueue(antrian_game);
            printf("Tidak ada permainan lagi dalam antrian game-mu\n");
        }
    }
}
/*
Prosedur ini akan melewati sebanyak <jumlah_skip> game, game yang dilewati akan dikeluarkan dari antrian game,
lalu langsung memainkan game yang terletak pada antrian pertama pada antrian game setelah game-game tadi dilewati
I.S. Sudah tersedia antrian game di main program yang sudah terdefinisi
F.S. Kondisi 1) Apabila <jumlah_skip> tidak melebihi jumlah antrian game dan game dalam antrian pertama setelah
                skip bisa dimainkan, maka akan mengeluarkan output sedang loading game, lalu memainkan game.
                Game yang dimainkan akan dikeluarkan dari antrian game
     Kondisi 2) Apabila <jumlah_skip> tidak melebihi jumlah antrian game dan game dalam antrian pertama setelah
                skip tidak bisa dimainkan (dalam maintenance), maka akan mengeluarkan output bahwa tidak bisa
                memainkan game. Game yang tidak bisa dimainkan tersebut dikeluarkan dari antrian game
     Kondisi 3) Apabila <jumlah_skip> sama atau melebihi jumlah antrian game, maka semua game dalam antrian akan
                dikeluarkan dari antrian game, lalu menampilkan pesan bahwa tidak ada permainan lagi dalam antrian
                game  
Asumsi : <jumlah_skip> sudah pasti valid setelah memanggil prosedur ini (<jumlah_skip> >= 0) 
Note : apabila antrian game kosong, akan mengeluarkan output bahwa belum ada game dalam antrian dan cara memasukkan
       game ke dalam antrian
*/

#endif