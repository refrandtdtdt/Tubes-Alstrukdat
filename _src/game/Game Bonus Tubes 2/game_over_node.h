#ifndef GAME_OVER
#define GAME_OVER

#include "story_tree.h"
#include "boolean.h"

void game_over_node(Address *p)   {
    printf("YOU LOSE\n");
    *p = LEFT(*p);
}

#endif