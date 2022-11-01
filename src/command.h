#ifndef COMMAND_H
#define COMMAND_H

/*Spesifikasi Command*/

# include "boolean.h"
# include "functions.h"
# include <stdio.h>
# include <stdlib.h>
# include "mesinkar.h"

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
void Start()
{
    printf("Start\n");
}

void Load(char *filename)
{
    printf("Load %s\n", filename);
    startread(filename);
    char currline[] = "................................................";
    int games = 0;
    while (cc != '\n')
    {
        games *= 10;
        games += cc-'0';
        adv();
    }
    printf("%d\n", games);
    adv();
    for(int i=0; i<games;i++)
    {
        clear(currline);
        advline(currline);
        printf("%s\n", currline);
    }
    printf("\n");
}

void Save(char* filename)
{
    printf("Save %s\n", filename);
}

void CreateGame()
{
    printf("CreateGame\n");
}

void ListGame()
{
    printf("ListGame\n");
}

void DeleteGame()
{
    printf("DeleteGame\n");
}

void QueueGame()
{
    printf("QueueGame\n");
}

void PlayGame()
{
    printf("PlayGame\n");
}

void SkipGame(int x)
{
    printf("SkipGame %d\n", x);
}

#endif