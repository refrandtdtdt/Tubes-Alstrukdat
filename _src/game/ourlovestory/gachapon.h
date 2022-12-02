#ifndef GACHAPON
#define GACHAPON

#include "..\..\boolean.h"
#include "randomizer.h"

typedef struct item {
    int rarity;
    char* name;
    int score;
} Item;

typedef Item gacha[100];

typedef char* string;

/* Game utama */
void gachapon(int *score);

/* Konstruktor gacha*/
void create_gacha(gacha *list_item);

/* shuffle */
void shuffle(gacha *list_item, size_t n);

char* CopyStr(char s[]);

void printstring(char* str);

void clearstr(char* str);
#endif