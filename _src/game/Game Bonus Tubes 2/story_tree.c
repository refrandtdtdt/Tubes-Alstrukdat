#include "story_tree.h"

StoryTree NewStoryTree(char akar, StoryTree l, StoryTree r)
{
    StoryTree new = (StoryTree) malloc (sizeof(StoryNode));
    if (new != NULL)    {
        ROOT(new) = akar;
        LEFT(new) = l;
        RIGHT(new) = r;
    }
    return new;
}

void CreateStoryTree(char akar, StoryTree l, StoryTree r, StoryTree *p)
{
    *p = NewStoryTree(akar, l, r);
}

Address newStoryNode(char x)
{
    Address new = (Address) malloc (sizeof(StoryNode));
    if (new != NULL){
        INFO(new) = x;
        LEFT(new) = NULL;
        RIGHT(new) = NULL;
    }
    return new;
}

void DeallocStory(Address p){
    free(p);
}

boolean IsTreeEmpty (StoryTree p){
    return p == NULL;
}

boolean IsOneElement(StoryTree p){
    return !IsTreeEmpty(p) && (LEFT(p) == NULL) && (RIGHT(p) == NULL);
}

boolean IsUnerLeft(StoryTree p){
    return !IsTreeEmpty(p) && (LEFT(p) != NULL) && (RIGHT(p) == NULL);
}

boolean IsUnerRight(StoryTree p){
    return !IsTreeEmpty(p) && (LEFT(p) == NULL) && (RIGHT(p) != NULL);
}

boolean IsBiner(StoryTree p){
    return !IsTreeEmpty(p) && (LEFT(p) != NULL) && (RIGHT(p) != NULL);
}

StoryTree buildBalancedTree(int n)  {
    int x, nl, nr;
    StoryTree l, r;
    Address p;
    if (n == 0) {
        return NULL;
    }
    else    {
        scanf("%d", &x);
        p = newStoryNode(x);
        if (p != NULL)  {
            nl = n/2; nr = n - nl - 1;
            l = buildBalancedTree(nl);
            r = buildBalancedTree(nr);
            LEFT(p) = l; RIGHT(p) = r;
        }
        return p;
    }
}

void PrintPreOrder(StoryTree p, int level) {
    if (!IsTreeEmpty(p)) {
        PrintSpace(level);
        printf("%c\n", INFO(p));
        PrintPreOrder(LEFT(p), level + 1);
        PrintPreOrder(RIGHT(p), level + 1);
    }
}

StoryTree buildStoryTree()  {
    StoryTree l, r;
    int x, param;
    Address p;
    printf("Select Parameter yang mau diisi (0 for stop, 1 for left, 2 for right, 3 for binary: ");
    scanf("%d", &param);
    if (param == 0) {
        return NULL;
    }
    else if (param == 1) {
        printf("Masukkan info akar: ");
        scanf("%d", &x);
        p = newStoryNode(x);
        if (p != NULL)  {
            l = buildStoryTree();
            LEFT(p) = l;
        }
        return p;
    }
    else if (param == 2)    {
        printf("Masukkan info akar: ");
        scanf("%d", &x);
        p = newStoryNode(x);
        if (p != NULL)  {
            r = buildStoryTree();
            RIGHT(p) = r;
        }
        return p;
    }
    else if (param == 3)    {
        printf("Masukkan info akar: ");
        scanf("%d", &x);
        p = newStoryNode(x);
        if (p != NULL)  {
            l = buildStoryTree();
            r = buildStoryTree();
            LEFT(p) = l;RIGHT(p) = r;
        }
        return p;       
    }
    else    {
        return NULL;
    }
}

void buildTreeString(StoryTree *T, char* st, int *idx)  {
    Address t;
    (*idx)++;
    if (st[*idx]==')')  {
        (*T)=NULL;
    }
    else
    {
        t = newStoryNode(st[*idx]);
        *T = t;
        (*idx)++;
        buildTreeString(&LEFT(*T), st, idx);
        buildTreeString(&RIGHT(*T), st, idx);
    }
    (*idx)++;
}

void PrintSpace(int n)  {
    int i;
    for (i = 1; i < n; i++) {
        printf("  ");
    }
}

void score_change(int *score, int value)    {
    *score += value;
    if (value >= 0) {
        printf("Score +%d\n\n", value);
    }
    else    {
        printf("Score %d\n\n", value);
    }
}