#include "execute.h"

void ExecuteNode(char id_command, char* nama, int *score, Address *node)    {
    if (id_command == '0')  {
        game_over_node(node);
    }
    else if (id_command == '1') {
        node1(score, nama, node);      
    }
}