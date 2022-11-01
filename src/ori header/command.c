#include "command.h"

boolean Eqstr(char* s1, char* s2)
{
    int i = 0;
    while (s1[i]!='\0')
    {
        i++;
    }
    int len1 = i;
    while (s2[i]!='\0')
    {
        i++;
    }
    int len2 = i;
    if (len1 != len2)
    {
        return false;
    }
    i = 0;
    while (s1[i]!='\0' && s2[i]!='\0')
    {
        if(s1[i]!=s2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

void quit() {
    printf("keluar dari Game\n");
    printf("Jangan lupa tidur cukup dan makan makanan yang bergizi\n");
    printf("Sayounara\n");
    exit(0);
}

void help() {
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