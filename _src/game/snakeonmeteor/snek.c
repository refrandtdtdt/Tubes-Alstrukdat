#include "linkedlist.h"
#include "snek.h"

void PrintPeta(ListSnake L, Point Meteor, Point Food)
{
    Point x;
    address P;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            x = MakePoint(j,i);
            P = SearchSnake(L,x);
            if (EQ(x,Food))
            {
                printf("o");
            }
            else if (EQ(x,Meteor))
            {
                printf("m");
            }
            else if (P!=Nil)
            {
                printf("%d", Index(P));
            }
            else
            {
                printf(".");
            }
            if(j==4)
            {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
}

Point RandomMapPoint(ListSnake L, Point Meteor, Point Food, boolean bomb)
{
    boolean done = false;
    Point x;
    while (!done)
    {
        x = RandomPoint();
        if(NEQ(x,Meteor) && NEQ(x,Food) && (SearchSnake(L,x)==Nil || bomb))
        {
            done = true;
        }
    }
    return x;
}

void MeteorHit(ListSnake *L, Point Meteor)
{
    DelP(L,Meteor);
    ResetIdx(L);
}

void FoodEaten(ListSnake *L, Point *Food, Point Meteor)
{
    IncreaseLength(L,Meteor);
    *Food = RandomMapPoint(*L,Meteor,Meteor,false);
}

void Initialize(ListSnake *L, Point *Food, Point *neck)
{
    printf("Loading Game...\n");
    CreateEmptySnake(L);
    Point x = RandomPoint();
    InsVFirst(L,x);
    Point dummy = MakePoint(-99,-99);
    IncreaseLength(L, dummy);
    IncreaseLength(L, dummy);
    *Food = RandomMapPoint(*L,dummy,dummy,false);
    *neck = Info(Next(First(*L)));
}

void IncreaseLength(ListSnake *L, Point Meteor)
{
    address P = Last(*L);
    boolean done = false;
    Point x = PlusDelta(Info(P),-1,0);
    if(SearchSnake(*L,x)==Nil && NEQ(x,Meteor))
    {
        InsVLast(L,x);
        done = true;
    }
    x = PlusDelta(Info(P),0,-1);
    if(!done && SearchSnake(*L,x)==Nil && NEQ(x,Meteor))
    {
        InsVLast(L,x);
        done = true;
    }
    x = PlusDelta(Info(P),0,1);
    if(!done && SearchSnake(*L,x)==Nil && NEQ(x,Meteor))
    {
        InsVLast(L,x);
        done = true;
    }
    Index(Last(*L)) = NbElmtSnake(*L);
    ResetIdx(L);
}

void MoveSnake(ListSnake *L, Point NewPos)
{
    Point dummy;
    InsVFirst(L,NewPos);
    DelVLast(L,&dummy);
    ResetIdx(L);
}

void ResetIdx(ListSnake *L)
{
    address P = First(*L);
    int i = 0;
    while (P!=Nil)
    {
        Index(P) = i;
        P = Next(P);
        i++;
    }
}