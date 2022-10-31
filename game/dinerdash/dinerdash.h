#ifndef DINERDASH_H
#define DINERDASH_H

# include "queue_food.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>

int rng(int lower, int upper);

void CreateMakanan(Makanan* food, int id);
/*
Membuat sebuah tipe data makanan random
I.S. Sembarang
F.S. membuat food bertipe data Makanan dengan random value
*/

void Table(Queue antrean, Queue cooking, Queue serving);
/* 
Menampilkan Table terkait.
I.S Sembarang
F.S Menampilkan Isi Queue
*/
void DinerDash();
/*
Program untuk Game Diner Dash
*/

#endif