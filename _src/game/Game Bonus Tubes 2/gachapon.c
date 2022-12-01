#include "gachapon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_gacha(gacha *list_item) {
    Item three_star;
    Item four_star;
    Item five_star;
    string three_star_name[] = {"Pororo", "Yadu", "Michael Main", "Elan Waker", "Ferdiman", "Lis Thoriq"};
    string four_star_name[] = {"Faith-oni", "Victoria", "Reyhan Padang Asik", "Inspektur Riza", "Algani Takol"};
    string five_star_name[] = {"Hatsune Miku", "Diluc", "Hi Duarr"};
    //printf("sukses1\n");
    int i;
    int offset = 0;
    int random;
    char* currname; 
    for (i = 0; i < 100; i++)   {
        //printf("%d\n", offset);
        if (i < 5)  {
            //printf("yes");
            random = randomizer(0,2,&offset);
            (*list_item)[i].name = CopyStr(five_star_name[random]);
            (*list_item)[i].rarity = 5;
            (*list_item)[i].score = 1000;
            /*
            (*list_item + i*sizeof(Item))->name = CopyStr(five_star_name[random]);
            (*list_item + i*sizeof(Item))->rarity = 5;
            (*list_item + i*sizeof(Item))->score = 1000;
            */
            //printstring((*list_item)[i].name);printf("\n");
        }
        else if ((i >= 5) && (i < 30))  {
            //printf("yes");
            random = randomizer(0,4,&offset);
            (*list_item)[i].name = CopyStr(four_star_name[random]);
            (*list_item)[i].rarity = 4;
            (*list_item)[i].score = 50;
            /*
            (*list_item + i*sizeof(Item))->name = CopyStr(four_star_name[random]);
            (*list_item + i*sizeof(Item))->rarity = 4;
            (*list_item + i*sizeof(Item))->score = 50;
            */
            //printstring((*list_item)[i].name);printf("\n");
        }
        else if ((i >= 30) && (i < 100))    {
            //printf("yes");
            random = randomizer(0,5,&offset);
            (*list_item)[i].name = CopyStr(three_star_name[random]);
            (*list_item)[i].rarity = 3;
            (*list_item)[i].score = 5;
            /*
            (*list_item + i*sizeof(Item))->name = CopyStr(three_star_name[random]);
            (*list_item + i*sizeof(Item))->rarity = 3;
            (*list_item + i*sizeof(Item))->score = 5;
            */
            //printstring((*list_item)[i].name);printf("\n");
        }
        //printf("sukses %d\n", i);
    }
    //printf("sukses2\n");
}

void shuffle(gacha *list_item, size_t n)  {
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          srand(time(NULL));
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          Item t = (*list_item)[j];
          (*list_item)[j] = (*list_item)[i];
          (*list_item)[i] = t;
        }
    }
}

void gachapon(int *score)   {
    int coin = 5;
    char dummy;
    int offset;
    int gacha_score = 0;
    Item prize;
    gacha list;
    //list = (Item*) malloc (200*sizeof(Item));
    srand(time(NULL));
    offset = rand();
    create_gacha(&list);
    printf("Selamat datang di game gachapon, uji keberuntunganmu untuk mendapatkan hadiah figurine 5 stars!!\n");
    while (coin != 0)   {
        printf("jumlah koin saat ini: %d\n", coin);
        printf("Tekan Enter untuk mulai menarik gacha");scanf("%c", &dummy);
        shuffle(&list, 10);
        printf("berhasil\n");
        prize = list[randomizer(0,99, &offset)];
        printf("Selamat! kamu mendapatkan \"%d* - %s\"\n", prize.rarity, prize.name);
        *score += prize.score;
        gacha_score += prize.score;
        printf("Tekan Enter untuk lanjut.");scanf("%c", &dummy);
        coin--;       
    }
    printf("Koinmu habis, permainan berakhir. Skor yang didapat = %d \n", gacha_score);
}

char* CopyStr(char s[])   {
    int i;
    char* s2;
    s2 = (char*)malloc(30*sizeof(char));
    clearstr(s2);
    for (i = 0; s[i] != '\0'; i++)
    {
        s2[i] = s[i];
    }
    return s2;
}


void printstring(char* str) {
    int i =0;
    while (str[i] != '\0')  {
        printf("%c", str[i]);
        i++;
    }
}

void clearstr(char* str)    {
    for (int i = 0; i < 30; i++)    {
        str[i] = '\0';
    }
}