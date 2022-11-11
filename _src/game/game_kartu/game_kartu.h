#ifndef GAME_KARTU_H
#define GAME_KARTU_H

# include "adt_kartu.h"
# include "queue.h"
# include "stack.h"
# include "list.h"
# include "../../ADT/functions.h"
# include "../../ADT/mesinkar.h"
# include "../../ADT/mesinkata_modif.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include "drawnlist.h"

/*Membuat pemain baru*/
Pemain CreatePlayer(Word nama, int id);

/* Menetapkan Nama-nama Pemain*/
void SetPlayers(QueuePemain* pemain, int jumlah);

/*
Mengembalikan nilai boolean apakah c1 lebih kuat daripada c2. hanya
berlaku pada kartu yang suitsnya sama
*/
boolean Stronger(Kartu c1, Kartu c2);

/*
mengubah nilai ranks jadi int supaya bisa dibandingkan nilainya
*/
int RanksToInt(Kartu c);

/*
mengecek apakah suit kedua kartu sama atau tidak
*/
boolean CheckSuitsEqual(Kartu c1, Kartu c2);

/* bikin kumpulan kartu baru*/
void CreateDeck(List* cards);

/* mengocok kartu (bukan mengocok perut wkwkwkw)*/
void Shuffle(List* cards, Stack* card_stack);

/*
mengambil kartu dari pegangan, lalu membuangnya. output adalah kartu yang dipilih
*/
void Draw(List* cards, Kartu pick, DrawnCard* draw, int id_pemain);

/*
mengambi 1 kartu dari tumpukan kartu
*/
void Take(List *cards, Stack* card_stack);

/*Mencari apakah pada list card terdapat suit pada kartu c*/
boolean SearchSuits(List card, Kartu c);

/*Mencetak kartu dalam bentuk SUITS:RANKS*/
void PrintCard(Kartu card);

/*Mencetak Kartu yang dimiliki pemain*/
void PrintPlayerCards(Pemain pemain);

/*Mencetak List Kartu*/
void PrintCardList(List card);

/* Mencetak List DrawnCard*/
void PrintDrawnCardList(DrawnList drawn);

void PrintStackCard(Stack card_stack);

/*Mengembalikan kartu max dari deck.
Prekondisi: semua suit pada cards harus sama.
 */
DrawnCard Max(DrawnList cards);

#endif