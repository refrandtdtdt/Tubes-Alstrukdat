#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "boolean.h"

void Start()
{
    printf("Start\n");
}

void Load(char *filename)
{
    printf("Load\n");
}

void Save(char* filename)
{
    printf("Save\n");
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

void Help()
{
    printf("Help\n");
}

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

int main() // PROGRAM UTAMA
{
    printf("---------------Welcome---------------\n");
    char command[] = "ini inisialisasi";
    char game[5]; //hanya untuk membaca command dengan kata "GAME" yang dipisah
    while (!Eqstr(command,"QUIT"))
    {
        printf("ENTER COMMAND: ");
        scanf("%s", command);

        // COMMANDS
        if(Eqstr(command,"START")) // START
        {
            Start();
        }
        else if(Eqstr(command,"LOAD")) // LOAD
        {
            char filename[20];
            scanf("%s", filename);
            Load(filename);
        }
        else if(Eqstr(command,"SAVE")) // SAVE
        {
            char filename[20];
            scanf("%s", filename);
            Save(filename);
        }
        else if(Eqstr(command,"CREATE")) // CREATE GAME
        {
            scanf("%s", game);
            if(Eqstr(game,"GAME"))
            {
                CreateGame();
            }
            else
            {
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(Eqstr(command,"LIST")) // LIST GAME
        {
            scanf("%s", game);
            if(Eqstr(game,"GAME"))
            {
                ListGame();
            }
            else
            {
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(Eqstr(command,"DELETE")) // DELETE GAME
        {
            scanf("%s", game);
            if(Eqstr(game,"GAME"))
            {
                DeleteGame();
            }
            else
            {
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(Eqstr(command,"QUEUE")) // QUEUE GAME
        {
            scanf("%s", game);
            if(Eqstr(game,"GAME"))
            {
                QueueGame();
            }
            else
            {
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(Eqstr(command,"PLAY")) // PLAY GAME
        {
            scanf("%s", game);
            if(Eqstr(game,"GAME"))
            {
                PlayGame();
            }
            else
            {
                printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(Eqstr(command,"SKIPGAME")) // SKIPGAME
        {
            int x;
            scanf("%d",&x);
            SkipGame(x);
        }
        // QUIT diimplementasikan melalui while
        else if(Eqstr(command,"HELP")) // HELP
        {
            Help();
        }
        else // COMMAND LAIN
        {
            printf("\nCommand tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }
    printf("\nAnda keluar dari game BNMO.\nBye bye ...");

    return 0;
}