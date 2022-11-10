# include "help.h"

void help() {
    char* input;
    input = (char*) malloc (20*sizeof(char));
    printf("help command: \n");
    printf("-START\n-LOAD\n-SAVE\n-CREATE GAME\n-LIST GAME\n-DELETE GAME\n-QUEUE GAME\n-PLAY GAME\n-SKIP GAME\n");
    scanf("%s", &input);
    if (input == "LOAD")   {
        printf("(+) LOAD <filename>: \n");
        printf("Memiliki satu argumen yaitu filename yang merepresentasikan suatu save file yang ingin dibuka. ");
        printf("Membaca save file <filename> yang berisi list game yang dapat dimainkan, histori dan scoreboard game\n");
    }
    else if (input == "START")  {
        printf("(+) START: \n");
        printf("Memulai program dengan me-load konfigurasi default.\n");
    }
    else if (input == "SAVE") {
        printf("(+) SAVE <filename>: \n");
        printf("menyimpan save file dengan nama <filename>.\n");
    }
    else if (input == "CREATE GAME") {
        printf("(+) CREATE GAME: \n");
        printf("Membuat game baru ke dalam Daftar Game.\n");
    }
    else if (input == "LIST GAME")  {
        print("(+) LIST GAME: \n menampilkan daftar game-game yang tersedia.\n");
    }
    else if (input == "DELETE GAME")    {
        printf("(+) DELETE GAME: \n");
        printf("Menghapus Game yang ada di daftar Game, kemudian memasukkan nomor game yang akan dihapus.\n");
    }
    else if (input == "QUEUE GAME") {
        printf("(+) QUEUE GAME: \n");
        printf("mendaftarkan permainan ke dalam antrean.\n");
    }
    else if (input == "PLAY GAME")  {
        printf("(+) PLAY GAME: \n");
        printf("Memainkan sebuah permainan.\n");
    }
    else if (input == "SKIP GAME")  {
        printf("(+) SKIP GAME <n>: \n");
        printf("melewatkan permainan sebanyak n.\n");
    }
    free(input);
}