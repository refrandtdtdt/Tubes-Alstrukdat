#include "snek.h"
// #include "../../ADT/mesinkar.h"
// #include "../../ADT/mesinkata_modif.h"
// #include "../../ADT/functions.h"
#include "mesinkata_modif.h"
#include "functions.h"

int main()
{
    ListPoint Snek; CreateEmptyListPoint(&Snek);
    ListPoint Obstacle; CreateEmptyListPoint(&Obstacle);
    Point Food; Point Meteor = MakePoint(-99,-99); Point x, neck;
    address checkSnek, checkObstacle;
    boolean dead=false; boolean valid, meteor; boolean moved = true;
    char* arah, pilihan;
    int turn=1; int skor; int diff=0;
    printf("Selamat datang di snake on meteor!\n");
    printf("List Difficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    while (!(diff>=1 && diff<=3))
    {
        printf("Masukkan pilihan difficulty(1-3): ");
        START();
        file = true;
        CopyWord();
        diff = StrToInt(kataToString(currentWord));
        if (!(diff>=1 && diff<=3))
        {
            printf("Masukan invalid, mohon ulangi\n");
        }
    }
    printf("Mengenerate peta, snake dan makanan . . .\n");
    Initialize(&Snek, &Obstacle, &Food, &neck, diff);
    printf("Berhasil digenerate!\n\n");
    while (!dead)
    {
        valid=true;
        if(moved){
            printf("TURN %d\n", turn);
            PrintPeta(Snek, Obstacle, Meteor, Food);
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
                checkObstacle = SearchPoint(Obstacle,x);
                if(checkObstacle != Nil)
                {
                    dead = true;
                    printf("TURN %d\n", turn+1);
                    PrintPeta(Snek, Obstacle, Meteor, Food);
                    printf("Kepala snake menabrak obstacle!\n");
                    meteor = false;
                }
                else
                {
                    checkSnek = SearchPoint(Snek,x);
                    if(checkSnek != Nil && checkSnek != Last(Snek))
                    {
                        dead = true;
                        printf("TURN %d\n", turn+1);
                        PrintPeta(Snek, Obstacle, Meteor, Food);
                        printf("Kepala snake menabrak diri sendiri!\n");
                        meteor = false;
                    }
                    else
                    {
                        MoveSnake(&Snek,x);
                        moved = true;
                    }
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
                    FoodEaten(&Snek, Obstacle, &Food, Meteor);
                }
                Meteor = RandomMapPoint(Snek,Obstacle,Meteor,Food,true);
                if (EQ(x,Meteor))
                {
                    dead = true;
                    printf("TURN %d\n", turn+1);
                    PrintPeta(Snek, Obstacle, Meteor, Food);
                    printf("Kepala snake terkena meteor!\n");
                    meteor = true;
                }
                else
                {
                    checkSnek = SearchPoint(Snek,Meteor);
                    if (checkSnek!=Nil)
                    {
                        MeteorHit(&Snek,Meteor);
                    }
                }
                neck = Info(Next(First(Snek)));
                turn++;
            }
        }
    }
    if(meteor)
    {
        skor = (NbElmtListPoint(Snek) - 1) * 2;
    } else {
        skor = (NbElmtListPoint(Snek)) * 2;
    }
    printf("Game berakhir. Skor: %d\n\n", skor);
}