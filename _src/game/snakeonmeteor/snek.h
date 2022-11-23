#ifndef snek_H
#define snek_H
#include "linkedlist.h"

void PrintPeta(ListSnake L, Point Meteor, Point Food);

Point RandomMapPoint(ListSnake L, Point Meteor, Point Food, boolean bomb);

void MeteorHit(ListSnake *L, Point Meteor);

void FoodEaten(ListSnake *L, Point *Food, Point Meteor);

void Initialize(ListSnake *L, Point *Food, Point *neck);

void IncreaseLength(ListSnake *L, Point Meteor);

void MoveSnake(ListSnake *L, Point NewPos);

void ResetIdx(ListSnake *L);

#endif