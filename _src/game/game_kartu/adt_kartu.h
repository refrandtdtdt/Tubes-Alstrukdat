#ifndef ADT_KARTU
#define ADT_KARTU

# include "boolean.h"
# define MaxCard 52

typedef struct Kartu
{
    char Suits;
    char* Ranks;
} Kartu;

typedef struct List{
	Kartu A[MaxCard];  /* Memori tempat penyimpanan elemen (container) */
} List;

typedef struct player {
    int id_player;
    char nama[20];
    List pegangan;
} Pemain;

typedef struct DrawnCard
{
    Kartu card;
    int id_player;
} DrawnCard;

typedef struct Drawnlist  {
    DrawnCard round[10];
} DrawnList;



#endif