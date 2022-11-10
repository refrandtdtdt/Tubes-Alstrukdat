#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "command.h"
#include "mesinkata_modif.h"

int main() // PROGRAM UTAMA
{
    printf("---------------Welcome to---------------\n");
    printf(" _______  ___   __    _  _______  __   __  _______    __   __    ___   ___ \n"); 
    printf("|  _    ||   | |  |  | ||       ||  |_|  ||       |  |  | |  |  |   | |   | \n");
    printf("| |_|   ||   | |   |_| ||   _   ||       ||   _   |  |  |_|  |  |   | |   | \n");
    printf("|       ||   | |       ||  | |  ||       ||  | |  |  |       |  |   | |   | \n");
    printf("|  _   | |   | |  _    ||  |_|  ||       ||  |_|  |  |       |  |   | |   | \n");
    printf("| |_|   ||   | | | |   ||       || ||_|| ||       |   |     |   |   | |   | \n");
    printf("|_______||___| |_|  |__||_______||_|   |_||_______|    |___|    |___| |___| \n");

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&######BBBBBBBBBBBBBBB#######&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@&#GP5YYYYYYJJJJJJYYYYY55555555PPPPPPPPPPPPPPGGGBB#&&@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@#5YYYYYJJJJJJJJYGBGPPPPP5555555YYYYYYYYYYYYYYYYYY55555PPPPPGG#@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@&PY5555555YYYYYG&5?7!!!!!7777777???????????????????777777!!!!!7Y#@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@#Y55YY555Y555YP@Y!777!JPGPPPPP555555555YYYYY55555555PPPPPPPPJ77!J@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@BY55GPY555555YG&?777!5#?^:::::........................::::^?&5!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@PYYYGPYY5#PY5YB&777!J@7...::......:::........:::::.... .....BB!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@&PYGBYY5555555YB#777!GB:.:::..:?5Y~.................~Y5?:...:BG!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@&5Y55Y5BBYYP#PY#B7777BG.:::...YG~?B!...::.   .::...^BJ~5P...:BB!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@&5YYPP55555555Y#G!777BG.::....:........?P5JJJ5P?....:...:..::BB!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@#5Y5GG5YY5#PYY5&G!777BG.::..............:^~!~^:............::BB!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@#555YY5555555Y5&P!777BG.::.................................::BB!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@#Y5Y555555Y55Y5@5!777BG.::................................:::BB!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@#YY55YYYYY555Y5@Y!777BG.::......:::.......................:::BB!77#@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@#Y5##BGP55YY5YP@Y!777BG.::::::::::::........::::::::.....:::.BB!77&@@@@@@@@@@@@@@@ \n");
    printf("@@&&@@@@@@@@@@@@@@BYG@&&&&&##PYYP@J!77!#G.::::::::::::::...::::::::::::::::::..BG!7?&@@@@@@@@@@@@@@@ \n");
    printf("@#YJ5&@@@@@@@@@@@@BYG@&&#&&&@BYYP@J!77!5&!...................................:?&Y!7?&@@@@@@@@@@@@@@@ \n");
    printf("@&?77B@@@@@@@@@@@@BY5#&#&&&#@BYYG@?77777YGP555555555555555555555555555555Y555GGJ!77?&@@@@@@@@@@@@@@@ \n");
    printf("@@P77J&@@@@@@@@@@@BYP#&#BB##B5YYG&?77777!!7?????????????????????????????JYJ??7!!77!J@@@@@@@@@@@@@@@@ \n");
    printf("@@&Y77Y@@@@@@@@@@@BYG&&&&###B5YYG&?777777PGGGGGGGGGGGGGGGGGGGP77777777!P#B#J!77777!J@@@@@@@@@@@@@@@@ \n");
    printf("@@@&J775&@@@@@@@@@BY5G&&&&&&&5YYG&7777777#&#################&&777777777P#B#J!77777!Y@@@@@@@@@@@@@@@@ \n");
    printf("@@@@&Y77J#@@@@@@@@BYB@&&&#&#PY5YB&7777777?JJJJJJJJJJJJJJJJJJJ?7777777777?J?7777777!Y@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@G?7?5#@@@@@@BYPBB#&##@#Y5YB&77777777!!!!!!!!!!!!!!!!!!!777777!!7777!77777777!5@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@&P?7?5B&@@@BY55PPPPGBPY5YB#77777777777!!J55J!!77777777777777YJ7777777777777!P@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@&PJ77?YGB#B#@&&&&#PY55YB#77777777777JYB55BYY77777777777!?B@#G7!7777777777!G@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@#GY?77?JJYYY5&&&PY5YB#77777777777BGP7!PGB77777777777J#@BYGB?777??77777!G&#&&@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@&#G5YJJ?J5&#@GY5YB#7777777777777GGPB77777777777775PP555PY!JB&GPG?777BB???J5G#@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@B#&&&&&&B5Y5YB#77777777777777??77777777777777!7JYYJ?7!5@&YY&Y!77#@&BGY?7?YG&@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@PY5PGGP5YY55YB#77777777!!!!!!!7!!!!!!!77777775#&#BGGBP75GPPY7777#@@@@@&GJ77JB@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@BYYYYYYY5555YB#77777777Y55555J7J55555J777777?&##55555&Y!!!!!777?&@@@@@@@@G?77P@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@&BP5YYY55555YB#77777777B####&P7B#####G77777775#&BGPGBG777777777?&@@@@@@@@@&Y775@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@&BP5YYYYYYB#777777777????7777?????77777777!?Y55YY?777777777!J@@@@@@@@@@@&5JP&@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@&#BP55YB#77777777777777777777777777777777!!!!!!77777777!!Y@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&B#@57!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777777777777?JP&@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#G555555555PPPPPPPPPGGGGGGGGGBGGGGBB#####&&&&@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@PYYG@@@@@@@@@@@@@@@@@@@@@@P??Y@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J77P@@@@@@@@@@@@@@@@@@@@@@P77J@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J77P@@@@@@@@@@@@@@@@@@@@@@P77J@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J77P@@@@@@@@@@@@@@@@@@@@@@P77J@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J77P@@@@@@@@@@@@@@@@@@@@@@P77J&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y77JG#@@@@@@@@@@@@@@@@@@@@B?77J5B&@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#PJ?77Y&@@@@@@@@@@@@@@@@@@@#GYJ?JB@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#BGB&@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");

    printf("\n");
    printf("                      |***********************|\n");
    printf("                      |       MAIN  MENU      |\n");
    printf("                      |***********************|\n");
    printf("                      |          START        |\n");
    printf("                      |          LOAD         |\n");
    printf("                      |***********************|\n");
    printf("\n");
    printf("Ketik START untuk memulai program, ketik LOAD untuk me-load file game!");
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
            Load("default.txt",&listGame);
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