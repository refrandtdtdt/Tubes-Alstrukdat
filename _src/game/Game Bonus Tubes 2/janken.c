#include "janken.h"
#include <stdio.h>

void janken(int *score, int win_score, int lose_score) {
    Janken set[3];
    int i_set = 0;
    set[i_set].name = "Batu";
    i_set++;
    set[i_set].name = "Gunting";
    i_set++;
    set[i_set].name = "Kertas";

    //main game
    boolean over = false;
    boolean win, next;
    Janken opponent, me;
    int id_op,id_me;
    while (!over)   {
        next = false;
        while (!next)   {
            printf("Silakan sut:\n1. Batu\n2. Gunting\n3. Kertas\n");
            scanf("%d", &id_me);
            if ((id_me >= 1) && (id_me <= 3))   {
                next = true;
            }
            else    {
                printf("Input salah.\n")
            }           
        }
        id_op = randomizer(0,2);
        printf("Miya mengeluarkan %s\n", set[id_op].name);
        if ((id_me == 1) && (id_op == 2))   {
            win = true;
            over = true;
        }
        else if ((id_me == 1) && (id_op == 3))  {
            win = false;
            over = true;
        }
        else if ((id_me == 2) && (id_op == 1))  {
            win = false;
            over = true;
        }
        else if ((id_me == 2) && (id_op == 3))  {
            win = true;
            over = true;
        }        
        else if ((id_me == 3) && (id_op == 1))  {
            win = true;
            over = true;
        }
        else if ((id_me == 3) && (id_op == 2))  {
            win = false;
            over = true;
        }
        else if (id_me == id_op)    {
            printf("Imbang, ulangi.\n\n");
        }
    }
    if (win)    {
        *score += win_score;
    }
    else    {
        *score -= lose_score;
    }

}