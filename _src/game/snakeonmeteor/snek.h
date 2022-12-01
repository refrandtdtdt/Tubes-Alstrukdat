#ifndef snek_H
#define snek_H
#include "../../ADT/linkedlist.h"
#include "../../ADT/arrPoint.h"

void PrintPeta(ListPoint L, ListPoint O, Point Meteor, Point Food);

Point RandomMapPoint(ListPoint L, ListPoint O, Point Meteor, Point Food, boolean meteor);

void MeteorHit(ListPoint *L, Point Meteor);

void FoodEaten(ListPoint *L, ListPoint O, Point *Food, Point Meteor, boolean *gameover);

void Initialize(ListPoint *L, ListPoint *O, Point *Food, Point *neck, int diff);

void IncreaseLength(ListPoint *L, ListPoint O, Point Meteor, boolean *gameover);

void MoveSnake(ListPoint *L, Point NewPos);

void ResetIdx(ListPoint *L);

#endif