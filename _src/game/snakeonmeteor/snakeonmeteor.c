#include "snek.h"
// #include "../../ADT/mesinkar.h"
// #include "../../ADT/mesinkata_modif.h"
// #include "../../ADT/functions.h"
#include "mesinkata_modif.h"
#include "functions.h"

int main()
{
    ListSnake Snek; CreateEmptySnake(&Snek);
    Point Food; Point Meteor = MakePoint(-99,-99); Point x, neck;
    address check;
    boolean dead=false; boolean valid, meteor; boolean moved = true;
    char* arah;
    int turn=1; int skor;
    printf("Selamat datang di snake on meteor!\nMengenerate peta, snake dan makanan . . .\n");
    Initialize(&Snek, &Food, &neck);
    printf("Berhasil digenerate!\n\n");
    while (!dead)
    {
        valid=true;
        if(moved){
            printf("TURN %d\n", turn);
            PrintPeta(Snek, Meteor, Food);
        }
        moved=false;
        printf("Silahkan masukkan command anda: ");
        START();
        file = true;
        CopyWord();
        arah = kataToString(currentWord);
        if(Eqstr(arah,"w")){x = PlusDelta(Info(First(Snek)),0,-1);}
        else if(Eqstr(arah,"s")){x = PlusDelta(Info(First(Snek)),0,1);}
        else if(Eqstr(arah,"a")){x = PlusDelta(Info(First(Snek)),-1,0);}
        else if(Eqstr(arah,"d")){x = PlusDelta(Info(First(Snek)),1,0);}
        else {printf("Input invalid. Masukkan w, a, s, atau d.\n\n");valid=false;}
        if(valid)
        {
            if(NEQ(x,Meteor) && NEQ(x,neck))
            {
                check = SearchSnake(Snek,x);
                if(check != Nil && check != Last(Snek))
                {
                    dead = true;
                    printf("TURN %d\n", turn+1);
                    PrintPeta(Snek, Meteor, Food);
                    printf("Kepala snake menabrak diri sendiri!\n");
                    meteor = false;
                }
                else
                {
                    MoveSnake(&Snek,x);
                    moved = true;
                }
            }
            else
            {
                moved = false;
                if(EQ(x,Meteor))
                {
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n\n");
                } else {
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n\n");
                }
            }
            if(moved)
            {
                if(EQ(x,Food))
                {
                    FoodEaten(&Snek, &Food, Meteor);
                }
                Meteor = RandomMapPoint(Snek,Meteor,Food,true);
                check = SearchSnake(Snek,Meteor);
                if (EQ(x,Meteor))
                {
                    dead = true;
                    printf("TURN %d\n", turn+1);
                    PrintPeta(Snek, Meteor, Food);
                    printf("Kepala snake terkena meteor!\n");
                    meteor = true;
                }
                else if (check!=Nil)
                {
                    MeteorHit(&Snek,Meteor);
                }
                neck = Info(Next(First(Snek)));
                turn++;
            }
        }
    }
    if(meteor)
    {
        skor = (NbElmtSnake(Snek) - 1) * 2;
    } else {
        skor = (NbElmtSnake(Snek)) * 2;
    }
    printf("Game berakhir. Skor: %d\n\n", skor);
}