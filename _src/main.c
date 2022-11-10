#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "command.h"
#include "ADT/mesinkata_modif.h"

int main() // PROGRAM UTAMA
{
    printf("---------------Welcome---------------\n");
    char* command;
    char* parameter;
    int run = 0;
    Queue queueGame; CreateQueue(&queueGame);
    Tabstr listGame; MakeEmpty(&listGame);
    Sentence input; CreateSentence(&input);
    boolean loaded = false;
    //Tabstr listGame; MakeEmpty(&listGame);

    while (run != 1)
    {
        printf("ENTER COMMAND: ");
        START();
        convertToArrayOfKata(&input,NMax);
        command = kataToString(input.buffer[0]);
        parameter = kataToString(input.buffer[1]);
        // COMMANDS
        if(Eqstr(command,"START")) // START
        {
            Load("_data/default.txt",&listGame);
            loaded = true;
        }
        else if(Eqstr(command, "LOAD")) // LOAD
        {
            int i = len(parameter); //.txt
            if(parameter[i-4]=='.'&&parameter[i-3]=='t'&&parameter[i-2]=='x'&&parameter[i-1]=='t')
            {
                Load(parameter,&listGame);
                loaded = true;
            }
            else
            {
                printf("\nFormat file invalid\n");
            }
        }
        else if(Eqstr(command, "SAVE")) // SAVE
        {
            if(loaded)
            {
                getcommParameter(command,"SAVE ",parameter);
                int i = len(parameter); //.txt
                if(parameter[i-4]=='.'&&parameter[i-3]=='t'&&parameter[i-2]=='x'&&parameter[i-1]=='t')
                {
                    Save(parameter, listGame);
                }
                else
                {
                    printf("\nFormat file invalid\n");
                }
            }
            else
            {
                printf("\nData kosong. Silakan menggunakan START atau LOAD terlebih dahulu\n");
            }
        }
        else if(Eqstr(command,"CREATE") && Eqstr(parameter,"GAME")) // CREATE GAME
        {
            if(loaded)
            {
                CreateGame();
            }
            else
            {
                printf("\nData kosong. Silakan menggunakan START atau LOAD terlebih dahulu\n");
            }
        }
        else if(Eqstr(command,"LIST") && Eqstr(parameter,"GAME")) // LIST GAME
        {
            if(loaded)
            {
                ListGame(listGame);
            }
            else
            {
                printf("\nData kosong. Silakan menggunakan START atau LOAD terlebih dahulu\n");
            }
        }
        else if(Eqstr(command,"DELETE") && Eqstr(parameter,"GAME")) // DELETE GAME
        {
            if(loaded)
            {
                DeleteGame();
            }
            else
            {
                printf("\nData kosong. Silakan menggunakan START atau LOAD terlebih dahulu\n");
            }
        }
        else if(Eqstr(command,"QUEUE") && Eqstr(parameter,"GAME")) // QUEUE GAME
        {
            if(loaded)
            {
                tambahAntrianGame (listGame, &queueGame);
            }
            else
            {
                printf("\nData kosong. Silakan menggunakan START atau LOAD terlebih dahulu\n");
            }
        }
        else if(Eqstr(command,"PLAY") && Eqstr(parameter,"GAME")) // PLAY GAME
        {
            if(loaded)
            {
                mainkanGame(&queueGame);
            }
            else
            {
                printf("\nData kosong. Silakan menggunakan START atau LOAD terlebih dahulu\n");
            }
        }
        else if(Eqstr(command, "SKIPGAME")) // SKIPGAME
        {
            if(loaded)
            {
                int x = 0;
                int i = 0;
                boolean num = true;
                while(parameter[i]!='\0' && num)
                {
                    if(parameter[i]-'0'<0 || parameter[i]-'0'>9)
                    {
                        num = false;
                    }
                    else
                    {
                        x *= 10;
                        x += parameter[i]-'0';
                    }
                    i++;
                }

                if(num)
                {
                    lewatiGame(&queueGame, x);
                }
                else
                {
                    printf("\nParameter invalid\n");
                }
            }
            else
            {
                printf("\nData kosong. Silakan menggunakan START atau LOAD terlebih dahulu\n");
            }
        }
        else if(Eqstr(command,"HELP")) // HELP
        {
            Help();
        }
        else if(Eqstr(command, "QUIT")) // QUIT
        {
            Quit();
        }
        else // COMMAND LAIN
        {
            printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
        }
        clear(parameter);
        clear(command);
    }
    //printf("\nAnda keluar dari game BNMO.\nBye bye ...");

    return 0;
}