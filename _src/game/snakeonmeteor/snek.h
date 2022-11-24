#ifndef snek_H
#define snek_H
#include "linkedlist.h"
#include "arrPoint.h"

void PrintPeta(ListPoint L, ListPoint O, Point Meteor, Point Food);

Point RandomMapPoint(ListPoint L, ListPoint O, Point Meteor, Point Food, boolean meteor);

void MeteorHit(ListPoint *L, Point Meteor);

void FoodEaten(ListPoint *L, ListPoint O, Point *Food, Point Meteor);

void Initialize(ListPoint *L, ListPoint *O, Point *Food, Point *neck, int diff);

void IncreaseLength(ListPoint *L, ListPoint O, Point Meteor);

void MoveSnake(ListPoint *L, Point NewPos);

void ResetIdx(ListPoint *L);

#endif