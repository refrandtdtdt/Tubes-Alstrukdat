#include "janken.h"
#include <stdio.h>

void janken(int *score, int win_score, int lose_score, boolean *win_state) {
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
    Sentence input_id_me;
    int id_op,id_me;
    int offset = 0;
    while (!over)   {
        next = false;
        while (!next)   {
            printf("Silakan sut:\n1. Batu\n2. Gunting\n3. Kertas\n");
            START();
            convertToArrayOfKata(&input_id_me, 1);
            id_me = StrToInt(input_id_me.buffer[0].TabWord);
            //scanf("%d", &id_me);
            if ((id_me >= 1) && (id_me <= 3))   {
                next = true;
            }
            else    {
                printf("Input salah.\n");
            }           
        }
        id_op = randomizer(0,2, &offset);
        printf("Miya mengeluarkan %s\n", set[id_op].name);
        if ((id_me == 1) && (id_op+1 == 2))   {
            win = true;
            over = true;
        }
        else if ((id_me == 1) && (id_op+1 == 3))  {
            win = false;
            over = true;
        }
        else if ((id_me == 2) && (id_op+1 == 1))  {
            win = false;
            over = true;
        }
        else if ((id_me == 2) && (id_op+1 == 3))  {
            win = true;
            over = true;
        }        
        else if ((id_me == 3) && (id_op+1 == 1))  {
            win = true;
            over = true;
        }
        else if ((id_me == 3) && (id_op+1 == 2))  {
            win = false;
            over = true;
        }
        else    {
            printf("Imbang, ulangi.\n\n");
        }
    }
    if (win)    {
        *score += win_score;
    }
    else    {
        *score -= lose_score;
    }
    *win_state = win;

}