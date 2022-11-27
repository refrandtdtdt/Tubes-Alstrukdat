#ifndef GAME_OVER
#define GAME_OVER

#include "story_tree.h"
#include "boolean.h"

void game_over_node(boolean *isRunning)   {
    printf("YOU LOSE\n");
    *isRunning = false;
}

#endif