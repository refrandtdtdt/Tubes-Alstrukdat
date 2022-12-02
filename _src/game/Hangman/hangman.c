#include "hangman.h"

void LoadKata(char *filename, TabKata *list)
{
    char* currline;
    boolean exists = STARTFlocal(filename);
    Sentence listkata; CreateSentence(&listkata);
    int banyakkata = 0;
    while (cc != '\n')
    {
        banyakkata *= 10;
        banyakkata += cc-'0';
        ADV();        
    }
    ADV();
    for (int i = 0; i < banyakkata; i++)
    {
        clear(listkata.buffer[i].TabWord);
    }
    convertToArrayOfKata(&listkata, banyakkata);
    for (int i = 0; i <banyakkata;i++)
    {
        list->TK[i] = listkata.buffer[i];
    }
    list->Neff = banyakkata;
    CLOSEF();
}

void SaveKata(char* filename, TabKata list)
{
    STARTWlocal(filename);
    fprintf(pita, "%d\n", list.Neff);
    for (int i = 0; i < list.Neff; i++)
    {
        fprintf(pita, "%s\n", list.TK[i].TabWord);
    }
    CLOSEF();
}

void tambahkata (TabKata *T)
{
    printf("Masukkan kata baru yang akan ditambahkan: ");
    START();
    file = true;
    CopyWord();
    boolean isMember = false;
    int i=0;
    while (!isMember && i<=GetLastIdxTab(*T))
    {
        if (Eqstr((*T).TK[i].TabWord, kataToString(currentWord)))
        {
            isMember = true;
        }
        else
        {
            isMember = false;
        }
        i++;
    }
    boolean isvalid = false;
    while (!isvalid)
    {
        int j = 0;
        isvalid = true;
        while (j < currentWord.Length && isvalid)
        {
            if(!(currentWord.TabWord[j] >='A' && (currentWord.TabWord[j] <= 'Z')))
            {
                isvalid = false;
            }
            j++;
        }
        if(!isvalid)
        {
            printf("Kata yang dimasukkan tidak valid!\n");
            printf("Masukkan kata baru yang akan ditambahkan: ");
            START () ;
            file = true;
            CopyWord();
        }
    }
    if (!isMember && isvalid == true) //bukan member 
    {
        (*T).Neff++;
        (*T).TK[i] = currentWord;
        printf("Kata berhasil ditambahkan\n");
    }
    else 
    {
        printf("Kata sudah terdaftar\n");
    }
}

void clearstring (char *s1)
{
    for (int i = 0; i < 30; i++)
    {
        s1[i] = '\0';
    }
}
void hangman (ScoreBoard * scoreboard)
{
    printf("  __   __  _______  __    _  _______  __   __  _______  __    _ \n");
    printf("|  | |  ||   _   ||  |  | ||       ||  |_|  ||   _   ||  |  | |\n");
    printf("|  |_|  ||  |_|  ||   |_| ||    ___||       ||  |_|  ||   |_| |\n");
    printf("|       ||       ||       ||   | __ |       ||       ||       |\n");
    printf("|       ||       ||       ||   | __ |       ||       ||       |\n");
    printf("|       ||       ||  _    ||   ||  ||       ||       ||  _    |\n");
    printf("|   _   ||   _   || | |   ||   |_| || ||_|| ||   _   || | |   |\n");
    printf("|__| |__||__| |__||_|  |__||_______||_|   |_||__| |__||_|  |__|n");
    printf("\n");
    printf("\n");
    printf("                  |***********************|\n");
    printf("                  |       MAIN  MENU      |\n");
    printf("                  |***********************|\n");
    printf("                  |         PLAY          |\n");
    printf("                  |        ADD WORD       |\n");
    printf("                  |***********************|\n");
    printf("\n");
    printf("                ___       _ \n");
    printf(" |_|  _          |  _    |_) |  _.      |_|  _. ._   _  ._ _   _. ._ \n");
    printf(" | | (_) |_|_|   | (_)   |   | (_| |_|  | | (_| | | (_| | | | (_| | | \n");
    printf("                                    _|               _|               \n");
    printf("1. Ketik PLAY untuk memulai permainan HANGMAN. \n");
    printf("2. Ketik ADD WORD apabila anda ingin menambahkan kata ke dalam permainan HANGMAN \n");
    printf("3. Apabila anda telah mengetik PLAY permainan akan langsung dimulai.\n");
    printf("4. Anda akan diberikan 10 kali kesempatan untuk menebak huruf secara acak, setiap anda berhasil menebak kata maka \n ");
    printf(" anda akan mendapatkan poin sejumlah kata yang ditebak.\n");
    printf("5. Permainan akan berakhir apabila kesempatan habis.\n");
    printf("SELAMAT BERMAIN!\n");
    printf("\n");
    Sentence input, tebakan, nama;
    Word semuatebakan;
    CreateSentence(&input);
    CreateSentence(&tebakan);
    TabKata listKata; MakeEmptyTab(&listKata);
    char * strNama;
    printf("Choose Menu: ");
    START();
    convertToArrayOfKata(&input,2);
    int length;
    int i = 0;
    boolean valid = false;
    boolean guessed;
    int skorakhir = 0;
    clear(semuatebakan.TabWord);
    while (!valid) 
    {
        if((Eqstr(input.buffer[0].TabWord,"PLAY"))) 
        {
            valid = true;
        } 
        else if ((Eqstr(input.buffer[0].TabWord, "ADD")) && (Eqstr(input.buffer[1].TabWord, "WORD")))
        {
            valid = true;
        }
        else 
        {
            printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("Choose Menu: ");
            clear(input.buffer[0].TabWord);
            clear(input.buffer[1].TabWord);
            START();
            convertToArrayOfKata(&input,2);
        }
    }
    if (Eqstr(input.buffer[0].TabWord,"PLAY"))
    {
        LoadKata("_src/game/Hangman/kata.txt",&listKata);
        int kesempatan = 10;
        boolean done = true;
        Word soal;
        Word kosong;
        semuatebakan.Length = 0;
        int n = 0; 
        while (kesempatan != 0)
        {
            if (done == true)
            {
                srand(time(NULL));
                clearstring(soal.TabWord);
                clearstring(kosong.TabWord);
                soal = listKata.TK[rand()%20];
                for (i = 0; i < soal.Length; i++)
                {
                    kosong.TabWord[i] = '_';
                }
                kosong.Length = soal.Length;
                for (i = 0; i < kosong.Length; i++)
                {
                    printf("%c ",kosong.TabWord[i]); // menampilkan _ _ _ _
                }
                done = false;
            }
            guessed = false;
            printf("\n");
            printf("Kesempatan: %d\n",kesempatan);
            printf("Masukkan Tebakan: ");
            CreateSentence(&tebakan);
            START();
            convertToArrayOfKata(&tebakan,1); //input satu huruf tebakan
            int i = 0;
            boolean valid = false;
            while (!valid)
            {
                if ((tebakan.buffer[0].Length == 1) && ((tebakan.buffer[0].TabWord[0] >= 65 && tebakan.buffer[0].TabWord[0] <= 90)))
                {
                    valid = true;
                }
                else
                {
                    printf("Kesempatan: %d\n",kesempatan);
                    printf("\n");
                    printf("Tebakan tidak valid!\n");
                    printf("Masukkan Tebakan: ");
                    CreateSentence(&tebakan);
                    START();
                    convertToArrayOfKata(&tebakan,1); //input satu huruf tebakan
                }
            }
            while (i < soal.Length && soal.TabWord[i] != '\0')
            {
                if (tebakan.buffer[0].TabWord[0] == soal.TabWord[i])
                {
                    kosong.TabWord[i] = soal.TabWord[i];
                    guessed = true;
                }
                i++;
            }
            printf("Kata: %s\n",kosong.TabWord);
            if (!guessed)
            {
                kesempatan -= 1;
            }
            semuatebakan.TabWord[n] = tebakan.buffer[0].TabWord[0];
            semuatebakan.Length++;
            printf("Tebakan sebelumnya:");
            int m = 0;
            while (m < semuatebakan.Length) 
            {
                printf("%c", semuatebakan.TabWord[m]);
                m++;
            }
            n++;
            printf("\n");
            //memeriksa apakah hurufnya sudah ketebak atau belum 
            int k = 0;
            boolean win = true;
            while (k < soal.Length && win == true)
            {
                if (kosong.TabWord[k] != soal.TabWord[k])
                {
                    win = false;
                }
                k++;
            }
            if (win == true)
            {
                skorakhir += soal.Length;
                printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin.\n",soal.TabWord,skorakhir);
                done = true;
                printf("\n");
                clearstring(semuatebakan.TabWord);
                semuatebakan.Length = 0;
                n = 0;
            }
        }
        printf("Game Over! Poin yang anda dapatkan adalah %d poin!\n",skorakhir);
        printf("Nama (cukup 1 kata) : ");
        START();
        convertToArrayOfKata(&nama, 1);
        strNama = kataToString(nama.buffer[0]);
        InsertScore(&(scoreboard->board), strNama, skorakhir);
    }
    else if((Eqstr(input.buffer[0].TabWord, "ADD")) && (Eqstr(input.buffer[1].TabWord, "WORD")))
    {
        LoadKata("_src/game/Hangman/kata.txt",&listKata);
        tambahkata(&listKata);
        SaveKata("_src/game/Hangman/kata.txt", listKata);
    }
}
// int main() {
//   hangman();
//   return 0;
// }