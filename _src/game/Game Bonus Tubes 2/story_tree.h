#ifndef STORY_TREE_H
#define STORY_TREE_H

/*Selektor*/
#define ROOT(p)  (p)->info
#define LEFT(p)  (p)->left
#define RIGHT(p) (p)->right

typedef struct StoryNode* Address;
/* Definisi Pohon Biner */
/* pohon biner kosong p = NIL*/
typedef struct StoryTreeNode   {
    int id;
    Address left;
    Address right;
} StoryNode;

typedef Address StoryTree;

/*Konstruktor*/

#endif