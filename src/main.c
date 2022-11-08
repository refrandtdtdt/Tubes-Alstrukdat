#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "command.h"
#include "mesinkata_modif.h"

int main() // PROGRAM UTAMA
{
    printf("---------------Welcome---------------\n");
    char* command;
    char* parameter;
    int run = 0;
    Queue queueGame; CreateQueue(&queueGame);
    Tabstr listGame; MakeEmpty(&listGame);
    Sentence input; CreateSentence(&input);
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
            Load("default.txt",&listGame);
        }
        else if(Eqstr(command, "LOAD")) // LOAD
        {
            int i = len(parameter); //.txt
            if(parameter[i-4]=='.'&&parameter[i-3]=='t'&&parameter[i-2]=='x'&&parameter[i-1]=='t')
            {
                Load(parameter,&listGame);
            }
            else
            {
                printf("\nFormat file invalid\n");
            }
        }
        else if(Eqstr(command, "SAVE")) // SAVE
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
        else if(Eqstr(command,"CREATE") && Eqstr(parameter,"GAME")) // CREATE GAME
        {
            CreateGame();
        }
        else if(Eqstr(command,"LIST") && Eqstr(parameter,"GAME")) // LIST GAME
        {
            ListGame(listGame);
        }
        else if(Eqstr(command,"DELETE") && Eqstr(parameter,"GAME")) // DELETE GAME
        {
            DeleteGame();
        }
        else if(Eqstr(command,"QUEUE") && Eqstr(parameter,"GAME")) // QUEUE GAME
        {
            QueueGame();
        }
        else if(Eqstr(command,"PLAY") && Eqstr(parameter,"GAME")) // PLAY GAME
        {
            PlayGame();
        }
        else if(Eqstr(command, "SKIPGAME")) // SKIPGAME
        {
            getcommParameter(command,"SKIPGAME ",parameter);
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
                SkipGame(x);
            }
            else
            {
                printf("\nParameter invalid\n");
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