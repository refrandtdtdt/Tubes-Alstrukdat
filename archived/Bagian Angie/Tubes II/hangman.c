#include "hangman.h"
#include "mesinkata_modif.h"
#include <stdlib.h>
#include "array.h"
#include "functions.h"
#include "time.h"
void Load(char *filename, TabKata *list)
{
    char* currline;
    boolean exists = STARTF(filename);
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

void Save(char* filename, TabKata list)
{
    STARTW(filename);
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
    int i;
    while (!isMember && i<=GetLastIdx(*T))
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
    if (!isMember) //bukan member 
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

void hangman ()
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
    printf("                      |***********************|\n");
    printf("                      |       MAIN  MENU      |\n");
    printf("                      |***********************|\n");
    printf("                      |          PLAY         |\n");
    printf("                      |         ADD WORD      |\n");
    printf("                      |***********************|\n");
    printf("\n");
    Sentence input, semuatebakan, tebakan;
    CreateSentence(&input);
    CreateSentence(&semuatebakan);
    CreateSentence(&tebakan);
    TabKata listKata; MakeEmpty(&listKata);
    printf("Choose Menu: ");
    START();
    convertToArrayOfKata(&input,2);
    int length;
    int i = 0;
    boolean valid = false;
    boolean guessed;
    printf("%s \n",input.buffer[0].TabWord);
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
        Load("kata.txt",&listKata);
        int kesempatan = 10;
        srand(time(NULL));
        Word soal = listKata.TK[rand()%10];
        while (kesempatan != 0)
        {
            guessed = false;

            printf("\n");
            printf("Kesempatan: %d\n",kesempatan);
            Word kosong;
            for (i = 0; i < soal.Length; i++)
            {
                kosong.TabWord[i] = '_';
            }
            kosong.Length = soal.Length;
            for (i = 0; i < kosong.Length; i++)
            {
                printf("%c ",kosong.TabWord[i]); // menampilkan _ _ _ _
            }
            printf("\n");
            printf("Masukkan Tebakan: ");
            CreateSentence(&tebakan);
            START();
            convertToArrayOfKata(&tebakan,1); //input satu huruf tebakan
            for (i = 0; i < soal.Length;i++)
            {
                if (tebakan.buffer[0].TabWord[0] == soal.TabWord[i])
                {
                    kosong.TabWord[i] = soal.TabWord[i];
                    printf("%c",kosong.TabWord[i]);
                    guessed = true;
                }
                else
                {
                    printf("_");
                }
            }
            printf("\n"); 
            if (!guessed)
            {
                kesempatan -= 1;
            }
            if (Eqstr(kosong.TabWord,soal.TabWord))
            {
                printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin.\n",soal.TabWord,soal.Length);
                soal = listKata.TK[rand()%10];
                CreateSentence(&semuatebakan);
            }
                    // if (&tebakan == soal.TabWord[i]) // cara akses satu persatu hurufny gmana ya 
                    // {
                    //     printf("%c",soal.TabWord[i]); // nampilin huruf yang uda ketebak 
                    //     // cek apakah uda sama semua hurufnya
                    //     if (!Eqstr(&tebakan,soal.TabWord[i]))
                    //     {
                    //         printf("Berhasil menebak kata %s",&soal,"Kamu mendapatkan %d ", length, " poin");
                    //     }
                    // }
        }
    }
    else if((Eqstr(input.buffer[0].TabWord, "ADD")) && (Eqstr(input.buffer[1].TabWord, "WORD")))
    {
        Load("kata.txt",&listKata);
        tambahkata(&listKata);
        Save("kata.txt", listKata);
    }
}
int main() {
  hangman();
  return 0;
}