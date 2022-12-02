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

void Quit(ScoreBoardList *scores) {
    printf("\nExiting BNMO...\n");
    printf("Goodbye\n");
    exit(0);
}
/*
perintah untuk mengeluarkan program
I.S. Sembarang
F.S. mengakhiri program ketika input QUIT diberikan
*/

void Load(char *filename, TabGame *list, ScoreBoardList *scores, StackHistory *history, boolean init)
{
    char* currline;
    printf("Loading %s...\n", filename);
    boolean exists = STARTF(filename);
    if(!exists)
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
        for (int i = 0; i <games; i++)
        {
            list->TG[i] = gameName.buffer[i];
            scores->List[i].game_name = gameName.buffer[i];
        }
        list->Neff = games;
        scores->Neff = games;
        //batas akhir untuk command START
        if(!init)
        {
            //baca history
            //Sentence gameHistory; CreateSentence(&gameHistory);
            int played = 0;
            while (cc != '\n')
            {
                played *= 10;
                played += cc-'0';
                ADV();
            }
            //printf("%d history loaded\n", played);
            ADV();
            // for (int i = 0; i < played; i++)
            // {
            //     clear(gameHistory.buffer[i].TabWord);
            // }
            for (int i = 0; i < played; i++)
            {
                clear(currentWord.TabWord);
                CopyWord();
                //printf("%s",currentWord.TabWord);
                PushHistory(history,currentWord);
                ADV();
            }
            //baca scoreboard
            int j = 0;
            int scorecount;
            Sentence gamescore; CreateSentence(&gamescore);
            Word temp;
            while(j < games)
            {
                //printf("loading game %d scoreboard\n",j+1);
                scorecount = 0;
                while (cc != '\n')
                {
                    //printf("%c",cc);
                    scorecount *= 10;
                    scorecount += cc-'0';
                    ADV();
                }
                //printf("\n");
                ADV();
                //printf("%d scores loaded\n", scorecount);
                if(scorecount>0)
                {
                    convertToArrayOfKata(&gamescore, scorecount);
                    for(int i = 0; i < scorecount; i++)
                    {
                        int k=0;
                        clear(temp.TabWord);
                        while(gamescore.buffer[i].TabWord[k] != ' ')
                        {
                            temp.TabWord[k] = gamescore.buffer[i].TabWord[k];
                            k++;
                            temp.Length++;
                        }
                        k++; int v=0;
                        while(gamescore.buffer[i].TabWord[k] != '\0')
                        {
                            v *= 10;
                            v += gamescore.buffer[i].TabWord[k]-'0';
                            k++;
                        }
                        InsertScore(&scores->List[j].board,kataToString(temp),v);
                    }
                }
                j++;
                CreateSentence(&gamescore);
                //if(j!=games){ADV();}
            }
        }
        printf("\nSavefile loaded successfully\n");
        CLOSEF();
    }
}
/*
Perintah untuk membaca save file yang ingin dibuka oleh user
I.S. Sembarang
F.S. Jika terdapat save file sesuai nama file masukan user, maka akan membaca save file tersebut. Jika tidak,
     maka akan mengeluarkan pesan bahwa tidak dapa tmenemukan save file tersebut
*/

void Save(char* filename, TabGame list, ScoreBoardList scores, StackHistory history)
{
    printf("Saving to %s...\n", filename);
    STARTW(filename);
    fprintf(pita, "%d\n", list.Neff);
    for (int i = 0; i < list.Neff; i++)
    {
        fprintf(pita, "%s\n", list.TG[i].TabWord);
    }
    int x = history.NbElmt;
    fprintf(pita, "%d\n", x);
    Word val; StackHistory temp; CreateStackHistory(&temp);
    for (int i = 0; i < x; i++)
    {
        PopHistory(&history,&val);
        PushHistory(&temp,val);
    }
    for (int i = 0; i < x; i++)
    {
        PopHistory(&temp,&val);
        fprintf(pita, "%s\n", val.TabWord);
    }
    for (int i = 0; i < scores.Neff; i++)
    {
        fprintf(pita, "%d\n", scores.List[i].board.Count);
        for(int j = 0; j < scores.List[i].board.Count; j++)
        {
            fprintf(pita, "%s %d\n", scores.List[i].board.el[j].Key, scores.List[i].board.el[j].Value);
        }
    }
    CLOSEF();
    printf("Saved Successfully\n");
}
/*
Perintah untuk menyimpan state pemain saat ini ke dalam sebuah file
I.S. Sembarang
F.S. 
*/

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
    if (del <= 6 && del > 0)
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

void mainkanGame (Queue * antrian_game, ScoreBoardList *scores, StackHistory *history) {
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
        int i = 0;
        while(!Eqstr(dummy.TabWord,scores->List[i].game_name.TabWord))
        {
            i++;
        }
        if (Eqstr(dummy.TabWord,"RNG")) {
            printf("Loading RNG ...\n");
            RNG(List[i].board);// Panggil fungsi game RNG
        } else if (Eqstr(dummy.TabWord,"Diner DASH")) {
            printf("Loading Diner DASH ...\n");
            DinerDash(List[i].board);// Panggil fungsi game Diner DASH
        } else if (Eqstr(dummy.TabWord,"HANGMAN")) {
            printf("Loading HANGMAN ...\n");
            hangman(List[i].board);// Panggil fungsi game HANGMAN
        } else if (Eqstr(dummy.TabWord,"TOWER OF HANOI")) {
            printf("Loading TOWER OF HANOI ...\n");
            TowerOfHanoi(List[i].board);// Panggil fungsi game TOWER OF HANOI
        } else if (Eqstr(dummy.TabWord,"SNAKE ON METEOR")) {
            printf("Loading SNAKE ON METEOR ...\n");
            SnakeOnMeteor(List[i].board);// Panggil fungsi game SNAKE ON METEOR
        } else if (Eqstr(dummy.TabWord,"Card Game")) {
            printf("Loading Card Game ...\n");
            GameKartu(List[i].board);// Panggil fungsi game Card Game
        } else {
            GameTambahan(List[i].board);
        }
        PushHistory(history,dummy);
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

void lewatiGame (Queue * antrian_game, int jumlah_skip, StackHistory *history) {
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

            int i = 0;
            while(!Eqstr(dummy.TabWord,scores->List[i].game_name.TabWord))
            {
                i++;
            }
            if (Eqstr(dummy.TabWord,"RNG")) {
                printf("Loading RNG ...\n");
                RNG(List[i].board);// Panggil fungsi game RNG
            } else if (Eqstr(dummy.TabWord,"Diner DASH")) {
                printf("Loading Diner DASH ...\n");
                DinerDash(List[i].board);// Panggil fungsi game Diner DASH
            } else if (Eqstr(dummy.TabWord,"HANGMAN")) {
                printf("Loading HANGMAN ...\n");
                hangman(List[i].board);// Panggil fungsi game HANGMAN
            } else if (Eqstr(dummy.TabWord,"TOWER OF HANOI")) {
                printf("Loading TOWER OF HANOI ...\n");
                TowerOfHanoi(List[i].board);// Panggil fungsi game TOWER OF HANOI
            } else if (Eqstr(dummy.TabWord,"SNAKE ON METEOR")) {
                printf("Loading SNAKE ON METEOR ...\n");
                SnakeOnMeteor(List[i].board);// Panggil fungsi game SNAKE ON METEOR
            } else if (Eqstr(dummy.TabWord,"Card Game")) {
                printf("Loading Card Game ...\n");
                GameKartu(List[i].board);// Panggil fungsi game Card Game
            } else {
                GameTambahan(List[i].board);
            }
            PushHistory(history,dummy);
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

void GameTambahan(ScoreBoard * scoreboard) {
    srand(time(0));
    int random = abs((rand() % 100 + (rand() % 100)*pow(-1, rand()))) % 100 + abs((rand() % 50)*pow(-1, rand()));
    printf("Permainan Selesai, Skor: %d\n", random);
    int i = 5;
    Sentence nama;
    char * strNama;
    printf("Nama (cukup 1 kata) : ");
    START();
    convertToArrayOfKata(&nama, 1);
    strNama = kataToString(nama.buffer[0]);
    InsertScore(&(scoreboard->board), strNama, random);
    //while(scoreboard.game_name != )
}
/*
Perintah untuk memainkan game di mana langsung masuk ke tahap game over dengan langsung mengeluarkan skor akhir berupa
integer random
I.S. Sembarang
F.S. Mengeluarkan output angka random
*/

void RNG(ScoreBoard * scoreboard)
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
    Sentence nama;
    char * strNama;
    printf("Nama (cukup 1 kata) : ");
    START();
    convertToArrayOfKata(&nama, 1);
    strNama = kataToString(nama.buffer[0]);
    InsertScore(&(scoreboard->board), strNama, skor);
}
/*
Perintah untuk memainkan game RNG di mana sistem akan menentukan angka acak, lalu pemain akan diberikan kesempatan untuk
menebak angka tersebut. Sistem akan memberitahu apakah angka tebakan lebih besar atau lebih kecil dari angka random sistem
I.S. Sembarang
F.S. Dikeluarkan output tentang tebakan dari pemain danskornya
*/

void showHistory(int parameter, StackHistory stackHistory)
{
    int banyakHistory_int = parameter;
    if (banyakHistory_int > 0)
    {
        printf("Berikut adalah daftar Game yang telah dimainkan\n");
        PrintStackHistory(stackHistory, banyakHistory_int);
    }
    else
    {
        printf("History gagal ditampilkan.\n");
    }
}

void resetHistory(StackHistory *stackHistory)
{
    boolean valid = false;
    while (!valid)
    {
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
        START();
        CopyWord();
        if (Eqstr(currentWord.TabWord, "YA") || Eqstr(currentWord.TabWord, "TIDAK"))
        {
            valid = true;
        }
        else
        {
            printf("\nMasukan tidak valid coba lagi.\n");
        }
    }

    if (Eqstr(currentWord.TabWord, "YA"))
    {
        CreateStackHistory(stackHistory);
        printf("\nHistory berhasil di-reset.\n");
    }
    else
    {
        printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        PrintStackHistory(*stackHistory, Top(*stackHistory) + 1);
    }
}

void ResetAllScores()
{
    printf("resetallscores\n");
}

void showScoreBoard(ScoreBoardList scores, int jumlahGame)
{
    for(int i=0; i<jumlahGame; i++)
    {
        PrintScoreboard(scores.List[i]);
    }
}