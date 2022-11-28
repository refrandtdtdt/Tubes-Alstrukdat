#ifndef STORY_TREE_H
#define STORY_TREE_H

//#include "..\..\boolean.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Selektor*/
#define ROOT(p)  (p)->info
#define INFO(p)  (p)->info
#define LEFT(p)  (p)->left
#define RIGHT(p) (p)->right

typedef struct StoryTreeNode* Address;
/* Definisi Pohon Biner */
/* pohon biner kosong p = NULL*/
typedef struct StoryTreeNode   {
    char info;
    Address left;
    Address right;
} StoryNode;

typedef Address StoryTree;

/*Konstruktor*/

/* Membuat Story baru*/
StoryTree NewStoryTree(char akar, StoryTree l, StoryTree r);

/* I.S Sembarang*/
/* F.S Menghasilkan sebuah pohon p*/
/* Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi berhasil*/
/* Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal*/
void CreateStoryTree(char akar, StoryTree l, StoryTree r, StoryTree* p);

/* Mengirimkan address hasil alokasi sebuah elemen bernilai x*/
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya menghasilkan p,
maka INFO(p) = x, LEFT(p) = NULL, RIGHT(p) = NULL*/
/* Jika Alokasi gagal, mengirimkan NULL*/
Address newStoryNode(char x);

/* Men-dealokasi-kan Story*/
void DeallocStory(Address p);

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

StoryTree buildBalancedTree(int n);

/*print sesuai pre order dari kiri sampai kanan*/
void PrintPreOrder(StoryTree p);

/* Membuat pohon cerita yang sesuai */
StoryTree buildStoryTree();

/* Membuat Tree dari format string */
/* input dari string st */
/* I.S. st[*idx]=='(' */
/* F.S T terdefinisi */
/* Proses: membaca string st dan membangun pohon secara rekursif*/
void buildTreeString(StoryTree *T, char* st, int *idx);

/* Mengeksekusi Story pada node input */

#endif