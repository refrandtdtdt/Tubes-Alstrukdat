#include "game_over_node.h"

void game_over_node(Address *p)   {
    printf("YOU LOSE\n");
    *p = LEFT(*p);
}