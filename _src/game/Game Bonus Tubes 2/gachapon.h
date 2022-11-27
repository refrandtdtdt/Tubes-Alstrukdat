#ifndef GACHAPON
#define GACHAPON

#include "boolean.h" 
typedef struct item {
    int rarity;
    char* name;
    int score;
} Item;

typedef Item gacha[100];

/* Game utama */
void gachapon(int *score);

/* Konstruktor gacha*/
void create_gacha(gacha *list_item);

/* shuffle */
void shuffle(gacha *list_item);

/* randomizer*/
int randomizer(int lower, int upper);
#endif