#include <story_tree.h>

StoryTree NewStoryTree(int akar, StoryTree l, StoryTree r)
{
    StoryTree new = (StoryTree) malloc (sizeof(StoryNode));
    if (new != NULL)    {
        ROOT(new) = akar;
        LEFT(new) = l;
        RIGHT(new) = r;
    }
    return new;
}

void CreateStoryTree(int akar, StoryTree l, StoryTree r, StoryTree *p)
{
    *p = NewStoryTree(akar, l, r);
}

Address newStoryNode(int x)
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
    return p = NULL;
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