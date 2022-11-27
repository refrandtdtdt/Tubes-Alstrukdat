#include "snek.h"

void PrintPeta(ListPoint L, ListPoint O, Point Meteor, Point Food)
{
    Point x;
    address P, OP;
    for(int i=1; i<=11; i++)
    {
        printf("         ");
        if(i%2==0)
        {
            for(int j=1; j<=11; j++)
            {
                if(j%2==0)
                {
                    x = MakePoint((j/2)-1,(i/2)-1);
                    P = SearchPoint(L,x);
                    OP = SearchPoint(O,x);
                    if (EQ(x,Food))
                    {
                        printf(" o ");
                    }
                    else if (EQ(x,Meteor))
                    {
                        printf(" m ");
                    }
                    else if (P!=Nil)
                    {
                        if(Index(P)==0)
                        {
                            printf(" H ");
                        }
                        else
                        {
                            printf(" %d ", Index(P));
                        }
                    }
                    else if (OP!=Nil)
                    {
                        printf("###");
                    }
                    else
                    {
                        printf("   ");
                    }
                } else {
                    if(j==1)
                    {
                        printf("|");
                    } else if (j==11) {
                        printf("|\n");
                    } else {
                        printf("|");
                    }
                }
            }
        } else {
            printf("#####################\n");
        }
    }
}

Point RandomMapPoint(ListPoint L, ListPoint O, Point Meteor, Point Food, boolean meteor)
{
    boolean done = false; boolean member;
    Point x;
    ArrPoint X = MakeArrPoint();
    while (!done)
    {
        x = RandomPoint();
        member = SearchArrPoint(X,x);
        if(!member)
        {
            if(NEQ(x,Meteor) && NEQ(x,Food) && (meteor || SearchPoint(L,x)==Nil) && SearchPoint(O,x)==Nil)
            {
                done = true;
            }
            else
            {
                InsertLastPoint(&X,x);
            }
        }
    }
    return x;
}

void MeteorHit(ListPoint *L, Point Meteor)
{
    DelP(L,Meteor);
    ResetIdx(L);
}

void FoodEaten(ListPoint *L, ListPoint O, Point *Food, Point Meteor)
{
    IncreaseLength(L,O,Meteor);
    *Food = RandomMapPoint(*L,O,Meteor,Meteor,false);
}

void Initialize(ListPoint *L, ListPoint *O, Point *Food, Point *neck, int diff)
{
    Point x;
    Point dummy = MakePoint(-99,-99);
    x = RandomPoint();
    if(diff==2)
    {
        for(int i=0;i<2;i++)
        {
            InsVFirst(O,x);
            x = RandomMapPoint(*L,*O,dummy,dummy,false);
        }
    } 
    else if(diff==3)
    {
        for(int i=0;i<5;i++)
        {
            InsVFirst(O,x);
            x = RandomMapPoint(*L,*O,dummy,dummy,false);
        }
    }
    x = RandomMapPoint(*L,*O,dummy,dummy,false);
    InsVFirst(L,x);
    IncreaseLength(L, *O, dummy);
    IncreaseLength(L, *O, dummy);
    *Food = RandomMapPoint(*L,*O,dummy,dummy,false);
    *neck = Info(Next(First(*L)));
}

void IncreaseLength(ListPoint *L, ListPoint O, Point Meteor)
{
    address P = Last(*L);
    boolean done = false;
    Point x = PlusDelta(Info(P),-1,0);
    if(NEQ(x,Meteor) && SearchPoint(O,x)==Nil && SearchPoint(*L,x)==Nil)
    {
        InsVLast(L,x);
        done = true;
    }
    x = PlusDelta(Info(P),0,-1);
    if(!done && NEQ(x,Meteor) && SearchPoint(O,x)==Nil && SearchPoint(*L,x)==Nil)
    {
        InsVLast(L,x);
        done = true;
    }
    x = PlusDelta(Info(P),0,1);
    if(!done && NEQ(x,Meteor) && SearchPoint(O,x)==Nil && SearchPoint(*L,x)==Nil)
    {
        InsVLast(L,x);
        done = true;
    }
    Index(Last(*L)) = NbElmtListPoint(*L);
    ResetIdx(L);
}

void MoveSnake(ListPoint *L, Point NewPos)
{
    Point dummy;
    InsVFirst(L,NewPos);
    DelVLast(L,&dummy);
    ResetIdx(L);
}

void ResetIdx(ListPoint *L)
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