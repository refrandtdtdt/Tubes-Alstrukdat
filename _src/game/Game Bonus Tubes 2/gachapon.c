#include "gachapon.h"
#include <stdio.h>
#include <stdlib.h>

void create_gacha(gacha *list_item) {
    Item three_star;
    Item four_star;
    Item five_star;
    char three_star_name[5] = {"Pororo", "Woody Gunawan", "Michael Main", "Alan Waker", "Ferdiman"};
    char four_star_name[4] = {"Faith-oni", "Victoria", "Reyhan Padang Asik", "Inspektur Riza"};
    char five_star_name[3] = {"Hatsune Miku", "Diluc", "Hi Duarrrrrr"};
    int i;
    for (i = 0; i < 100; i++)   {
        if (i < 5)  {
            list_item[i]->name = five_star_name[randomizer(0,2)];
            list_item[i]->rarity = 5;
            list_item[i]->score = 1000;
        }
        else if ((i >= 5) && (i < 30))  {
            list_item[i]->name = four_star_name[randomizer(0,3)];
            list_item[i]->rarity = 4;
            list_item[i]->score = 50;
        }
        else if ((i >= 30) && (i < 100))    {
            list_item[i]->name = three_star_name[randomizer(0,4)];
            list_item[i]->rarity = 5;
            list_item[i]->score = 5;
        }
    }
}

void shuffle(gacha *list_item)  {
    
}

int randomizer(int lower, int upper)    {
    int seed;
    return seed % (upper - lower + 1) + lower;
}

void gachapon(int *score)   {
    int coin = 5;
    char dummy;
    int gacha_score = 0;
    Item prize;
    gacha list;
    create_gacha(&list);
    printf("Selamat datang di game gachapon, uji keberuntunganmu untuk mendapatkan hadiah figurine 5 stars!!\n");
    while (coin != 0)   {
        printf("jumlah koin saat ini: %d\n", coin);
        printf("Tekan Enter untuk mulai menarik gacha");scanf("%c", &dummy);
        shuffle(&list);
        prize = list[randomizer(0,99)];
        printf("Selamat! kamu mendapatkan \"%d* - %s\"\n", prize.rarity, prize.name);
        *score += prize.score;
        gacha_score += prize.score;
        printf("Tekan Enter untuk lanjut.");scanf("%c", &dummy);
        coin--;       
    }
    printf("Koinmu habis, permainan berakhir. Skor yang didapat = %d \n", gacha_score);
}