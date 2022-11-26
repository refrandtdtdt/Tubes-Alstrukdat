#ifndef STORY_TREE_H
#define STORY_TREE_H

#include "..\..\boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Selektor*/
#define ROOT(p)  (p)->info
#define INFO(p)  (p)->info
#define LEFT(p)  (p)->left
#define RIGHT(p) (p)->right

typedef struct StoryNode* Address;
/* Definisi Pohon Biner */
/* pohon biner kosong p = NULL*/
typedef struct StoryTreeNode   {
    int info;
    Address left;
    Address right;
} StoryNode;

typedef Address StoryTree;

/*Konstruktor*/

/* I.S Sembarang*/
/* F.S Menghasilkan sebuah pohon p*/
/* Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi berhasil*/
/* Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal*/
void CreateStoryTree(int akar, StoryTree l, StoryTree r, StoryTree* p);

/* Mengirimkan address hasil alokasi sebuah elemen bernilai x*/
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya menghasilkan p,
maka INFO(p) = x, LEFT(p) = NULL, RIGHT(p) = NULL*/
/* Jika Alokasi gagal, mengirimkan NULL*/
Address newStoryNode(int x);

/*Mengirimkan true jika p adalah pohon yang kosong*/
boolean IsTreeEmpty (StoryTree p);

/* Mengirimkan true jika p adalah pohon yang tidak kosong dan terdiri dari 1 elemen saja */ 
boolean IsOneElement(StoryTree p);

/* Mengirimkan true jike p adalah pohon Uner Left (hanya mempunyai subpohon kiri) */
boolean IsUnerLeft(StoryTree p);

/* Mengirimkan true jika p adalah pohon Uner Right (hanya mempunyai subpohon kanan) */
boolean IsUnerRight(StoryTree p);

/* Mengirimkan true jika p adalah pohon biner*/
boolean IsBiner(StoryTree p);
#endif