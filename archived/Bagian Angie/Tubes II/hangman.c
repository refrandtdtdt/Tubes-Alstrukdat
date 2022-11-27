#include "hangman.h"
#include "mesinkata_modif.h"
#include "listword.h"
#include <stdlib.h>

void hangman ()
{
    printf("##::::'##::::'###::::'##::: ##::'######:::'##::::'##::::'###::::'##::: ##:\n");
    printf("##:::: ##:::'## ##::: ###:: ##:'##... ##:: ###::'###:::'## ##::: ###:: ##:\n");
    pritnf("##:::: ##::'##:. ##:: ####: ##: ##:::..::: ####'####::'##:. ##:: ####: ##:\n");
    printf("#########:'##:::. ##: ## ## ##: ##::'####: ## ### ##:'##:::. ##: ## ## ##:\n");
    printf("##.... ##: #########: ##. ####: ##::: ##:: ##. #: ##: #########: ##. ####:\n");
    printf("##:::: ##: ##.... ##: ##:. ###: ##::: ##:: ##:.:: ##: ##.... ##: ##:. ###:\n");
    printf("##:::: ##: ##:::: ##: ##::. ##:. ######::: ##:::: ##: ##:::: ##: ##::. ##:\n");
    printf("..:::::..::..:::::..::..::::..:::......::::..:::::..::..:::::..::..::::..::\n");
    printf("\n");
    printf("                      |***********************|\n");
    printf("                      |       MAIN  MENU      |\n");
    printf("                      |***********************|\n");
    printf("                      |          PLAY         |\n");
    printf("                      |         ADD WORD      |\n");
    printf("                      |***********************|\n");
    printf("\n");
    char *input;
    TabKata listKata; MakeEmpty(&listKata);
    printf("Choose Menu: ");
    START();
    if (Eqstr(input,"PLAY"))
    {
        Load("kata.txt",&listKata);
        int i; 
        char kata [100], tempkata[100];
        char hasil [100];
        int kesempatan = 10;
        int length;
        length = strlen(kata);
        while (kesempatan != 0) // kesempatan tidak habis
        {
            printf("Tebakan sebelumnya: \n");
            printf("Kata: ");
            srand(0);
            printf("%s", listKata.TK[rand()%10].TabWord);
            for (i =0 ; i < length; i++)
            {
                printf("Kesempatan: ", kesempatan);
                kesempatan -= 1;
                printf("Masukan tebakan: ");
                char *tebakan; 
                boolean found = true;
                START(); // membaca tebakan dari penggunakan
                if (!Eqstr(tebakan, T.TK[i].TabWord))
                {
                    found = false;
                    if (!found)
                }
            }
        }

    }
    else if (Eqstr(input, "ADD WORD"))
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
