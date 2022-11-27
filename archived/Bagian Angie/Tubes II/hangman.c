#include "hangman.h"
#include "mesinkata_modif.h"
#include "listword.h"
#include <stdlib.h>
#include "array.h"
#include "functions.h"

void hangman ()
{
    printf("  __   __  _______  __    _  _______  __   __  _______  __    _ \n");
    printf("|  | |  ||   _   ||  |  | ||       ||  |_|  ||   _   ||  |  | |\n");
    pritnf("|  |_|  ||  |_|  ||   |_| ||    ___||       ||  |_|  ||   |_| |\n");
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
    Sentence input,tebakan;
    TabKata listKata; MakeEmpty(&listKata);
    printf("Choose Menu: ");
    START();
    convertToArrayOfKata(&input,4);
    int length;
    int i = 0;
    if (Eqstr(&input,"PLAY"))
    {
        Load("kata.txt",&listKata);
        int kesempatan = 10;
        Sentence input,tebakan;
        int i;
        int length;
        length = len(&listKata);
        while (kesempatan != 0)
        {
            printf("Tebakan sebelumnya: %s",tebakan); // masukkin input stlahnya cara nampilin - gman ya
            printf("Kesempatan: %d",kesempatan);
            srand(0);
            Word soal;
            CreateWord(&soal);
            for (i = 0; i <= length-1; i++)
            {
                (*soal).TabWord[i] = (&listKata).TabWord[i];
            }
            soal = &listKata[rand()%5].TK;
            for (i; i<length; i++)
                printf("_", soal.TabWord); // menampilkan _ _ _ _
            printf("Masukkan Tebakan: ");
            START();
            convertToArrayOfKata(&tebakan,1);//input satu huruf tebakan
            kesempatan -= 1;
            if (&tebakan == soal.TabWord[i]) // cara akses satu persatu hurufny gmana ya 
            {
                printf("%s",soal.TabWord[i]); // nampilin huruf yang uda ketebak 
                // cek apakah uda sama semua hurufnya
                if (!Eqstr(&tebakan,soal.TabWord[i]))
                {
                    printf("Berhasil menebak kata %s",&soal,"Kamu mendapatkan %d ", length, " poin");
                }
            }
        }
    }
    else if(Eqstr(&input, "ADD WORD"))
    {
        Load("kata.txt",&listKata);
        printf("MAsukkan kata baru yang ingin ditambahkan: ");
        tambahkata(&listKata);
    }
    else
    {
        printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
    }
}
void Load(char *filename, TabKata *list)
{
    char* currline;
    STARTF(filename);
    Sentence bacaKata; CreateSentence(&bacaKata);
    int kata = 0;
    while (cc != '\n')
    {
        kata *= 10;
        kata += cc-'0';
        ADV();
    }
    ADV();
    for (int i = 0; i < kata; i++)
    {
        clear(bacaKata.buffer[i].TabWord);
    }
    convertToArrayOfKata(&bacaKata, kata);
    for (int i = 0; i <kata;i++)
    {
            list->TK[i] = bacaKata.buffer[i];
    }
    list->Neff = kata;
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

int main() {
  hangman();
  return 0;
}