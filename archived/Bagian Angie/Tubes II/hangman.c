#include "hangman.h"
#include "mesinkata_modif.h"

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
    printf("ENTER COMMAND");
    START ();
    if (Eqstr(input, "Play")) // memainkan game hangman untuk mengacak kata pake print rand()
    {
        printf("Tebakan sebelumnya");
    }
    else if ((input, "AddWord")) // menambahkan list kata ke dalam in-game dictionary
    {
        printf()
    }
}