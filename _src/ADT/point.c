#include <stdio.h>
#include <stdlib.h>
#include "point.h"

Point MakePoint (int X, int Y)
{
	Point P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

void BacaPoint (Point * P)
{
	int x, y;
	scanf("%d %d", &x, &y);
	Absis(*P) = x;
	Ordinat(*P) = y;
}

void TulisPoint (Point P)
{
	int x = Absis(P);
	int y = Ordinat(P);
	printf("(%d,%d)", x, y);
}

boolean EQ (Point P1, Point P2)
{
	return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (Point P1, Point P2)
{
	return (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2));
}

Point PlusDelta (Point P, int deltaX, int deltaY)
{
	Point P1;
	int x = (Absis(P) + deltaX);
	if(x<0){x+=5;}
	Absis(P1) = x % 5;
	x = (Ordinat(P) + deltaY);
	if(x<0){x+=5;}
	Ordinat(P1) = x % 5;
	return P1;
}

void Geser (Point *P, int deltaX, int deltaY)
{
	Absis(*P) += deltaX;
	Ordinat(*P) += deltaY;
}

Point RandomPoint()
{
	srand(time(NULL));
    int x = (rand() % 5);
	int y = (rand() % 5);
	Point p = MakePoint(x,y);
	return p;
}