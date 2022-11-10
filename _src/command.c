# include "command.h"

void Help() {
    char* input;
    printf("Help command: \n");
    printf("-START\n-LOAD\n-SAVE\n-CREATE GAME\n-LIST GAME\n-DELETE GAME\n-QUEUE GAME\n-PLAY GAME\n-SKIP GAME\n:\n");
    START();
    file = true;
    CopyWord();
    input = kataToString(currentWord);
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

void Load(char *filename, TabGame *list)
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
            list->TG[i] = gameName.buffer[i];
        }
        list->Neff = games;
        printf("\nSavefile loaded successfully\n");
        CLOSEF();
    }
}

void Save(char* filename, TabGame list)
{
    printf("Saving to %s...\n", filename);
    STARTW(filename);
    fprintf(pita, "%d\n", list.Neff);
    for (int i = 0; i < list.Neff; i++)
    {
        fprintf(pita, "%s\n", list.TG[i].TabWord);
    }
    CLOSEF();
    printf("Saved Successfully\n");
}

void buatgame (TabGame *T)
/*
prosedur ini akan membaca masukkan nama game yang ingin ditambahkan ke dalam Binomo
I.S Sembarang
F.S Game berhasil ditambahkan ke dalam array game yang tersedia 
Apabila game yg ditambahkan sudah ada di dalam array game sebelumnya maka game tidak ditambahkan kembali
*/
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    START();
    file = true;
    CopyWord();
    boolean isMember = false;
    int i;
    for (i = 0; i <= GetLastIdx(*T); i++)
    {
        if (Eqstr((*T).TG[i].TabWord, kataToString(currentWord)))
        {
            isMember = true;
        }
        else
        {
            isMember = false;
        }
    }
    if (!isMember)
    {
        (*T).Neff++;
        (*T).TG[i] = currentWord;
        printf("Game berhasil ditambahkan\n");
    }
    else 
    {
        printf("Game sudah terdaftar\n");
    }
}

void ListGame(TabGame T)
{
    TulisIsi(T);
}

void HapusGame(TabGame *T)
/*I.S Tab terdefinisi dan tidak kosong */
/*F.S elemen game ke-i dihapus dari tab game sesuai dengan keinginan user*/
/*Syarat penghapusan game: 
- Game yang dapat dihapus hanyalah game yang dibuat secara custom sendiri oleh user
- Lima Game pertama yang terdapat dlaam file konfigurasi (game default) tidak dapat dihapus 
- Game yang berada dalam queue game (antrian game) tidak dapat dihapus */
{
    printf("Berikut adalah daftar game yang tersedia\n");
    ListGame(*T);
    printf("Masukkan nomor game yang akan dihapus: ");
    START();
    CopyWord();
    int del = WordToInt(currentWord);
    if (del <= 5 && del > 0)
    {
        printf("Game gagal dihapus\n");
    }
    else
    {
        if (del <= T->Neff)
        {
            int j;
            for (j = del-1; j < T->Neff; j++)
            {
                (*T).TG[j] = (*T).TG[j+1];
            }
            (*T).Neff--;
            printf("Game berhasil dihapus\n");
        }
        else
        {
            printf("Nomor game tidak ada dalam list\n");
        }
    }
}

void tambahAntrianGame (TabGame daftar_game, Queue * antrian_game) {
    // Mengeluarkan output game-game yang sedang dalam antrian
    printf("Berikut adalah daftar antrian game-mu\n");
    for (int i = 0; i < length(*antrian_game); i++) {
        printf("%d. %s\n", i+1, (*antrian_game).buffer[i].TabWord);
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    // Mengeluarkan output game-game yang terdapat dalam list
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int j = 0; j < NbElmt(daftar_game); j++) {
        printf("%d. %s\n", j+1, GetElmt(daftar_game, j).TabWord);
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    // Input dan proses
    int nomorGame;
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    boolean valid = false;
    while (!valid) {
        //scanf("%d", &nomorGame);
        START();
        CopyWord();
        nomorGame = WordToInt(currentWord);
        if (IsIdxEff(daftar_game, nomorGame-1)) {
            valid = true;
        } else {
            printf("Nomor permainan tidak valid, silakan masukkan nomor game pada list.\n");
            printf("Nomor Game yang mau ditambahkan ke antrian: ");
        }
    }
    enqueue(antrian_game, GetElmt((daftar_game), (nomorGame-1)));
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
        printf("%d. %s\n", i+1, (*antrian_game).buffer[(i + IDX_HEAD((*antrian_game))) % CAPACITY].TabWord);
    }

    // Biar ada jaraknya aja kayak di contoh spesifikasi wkwkwk
    printf("\n");

    if (isEmpty(*antrian_game)) {
        printf("Belum ada game dalam antrianmu.\n");
        printf("Silakan masukkan command QUEUE GAME untuk menambahkan game dalam antrianmu.\n");
    } else {
        // Dequeue game yang dimainkan
        Word dummy;
        dequeue(antrian_game, &dummy);

        if (Eqstr(dummy.TabWord,"RNG")) {
            printf("Loading RNG ...\n");
            RNG();// Panggil fungsi game RNG
        } else if (Eqstr(dummy.TabWord,"Diner DASH")) {
            printf("Loading Diner DASH ...\n");
            // Panggil fungsi game Diner DASH
        } else if (Eqstr(dummy.TabWord,"DINOSAUR IN EARTH")) {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan.\n");
            printf("Silahkan pilih game lain.\n");
        } else if (Eqstr(dummy.TabWord,"RISEWOMAN")) {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan.\n");
            printf("Silahkan pilih game lain.\n");
        } else if (Eqstr(dummy.TabWord,"EIFFEL TOWER")) {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan.\n");
            printf("Silahkan pilih game lain.\n");
        } else if (Eqstr(dummy.TabWord,"Card Game")) {
        printf("Loading Card Game ...\n");
        // Panggil fungsi game Card Game
        } else {
            GameTambahan();
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
        printf("%d. %s\n", i+1, (*antrian_game).buffer[(i + IDX_HEAD((*antrian_game))) % CAPACITY].TabWord);
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
            Word dummySkip;
            for (j = 0; j < jumlah_skip; j++) {
                dequeue((antrian_game), &dummySkip);
            }

            // Dequeue game yang dimainkan
            Word dummy;
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

            if (Eqstr(dummy.TabWord,"RNG")) {
                printf("Loading RNG ...\n");
                RNG();// Panggil fungsi game RNG
            } else if (Eqstr(dummy.TabWord,"Diner DASH")) {
                printf("Loading Diner DASH ...\n");
                // Panggil fungsi game Diner DASH
            } else if (Eqstr(dummy.TabWord,"DINOSAUR IN EARTH")) {
                printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            } else if (Eqstr(dummy.TabWord,"RISEWOMAN")) {
                printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            } else if (Eqstr(dummy.TabWord,"EIFFEL TOWER")) {
                printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan.\n");
                printf("Silahkan pilih game lain.\n");
            } else if (Eqstr(dummy.TabWord,"Card Game")) {
                printf("Loading Card Game ...\n");
            } else {
                GameTambahan();
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

void GameTambahan() {
    srand(time(0));
    int random = abs((rand() % 100 + (rand() % 100)*pow(-1, rand()))) % 100 + abs((rand() % 50)*pow(-1, rand()));
    printf("Permainan Selesai, Skor: %d\n", random);
}

void RNG()
{
    srand(time(NULL));
    int x = (rand() % 30);
    int skor = 100;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    START();
    CopyWord();
    while (WordToInt(currentWord) != x)
    {
        if (WordToInt(currentWord) > x)
        {
            printf("Lebih kecil\n");
            skor-=10;
        }
        else if (WordToInt(currentWord) < x)
        {
            printf("Lebih besar\n");
            skor-=10;
        }
        printf("Tebakan: ");
        START();
        CopyWord();
    }
    printf("\nYa, X adalah %d.\n", x);
    printf("Skor : %d\n", skor);
}