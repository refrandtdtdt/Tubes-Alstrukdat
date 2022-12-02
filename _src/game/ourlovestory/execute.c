#include "execute.h"
#include <stdio.h>

void ExecuteNode(char id_command, char* nama, int *score, Address *node)    {
    switch (id_command)
    {
    case '0':
        game_over_node(node);
        break;
    case '1':
        node1(score, nama, node);
        break;
    case '2':
        node2(score, nama, node);
        break;
    case '3':
        node3(score, nama, node);
        break;
    case '4':
        node4(score, nama, node);
        //game_over_node(node);
        break;
    case '5':
        node5(score, nama, node);
        break;
    case '6':
        node6(score, nama, node);
        break;
    case '7':
        node7(score, nama, node);
        break;
    case '8':
        node8(score, nama, node);
        break;
    case '9':
        node9(score, nama, node);
        break;
    case 'A':
        nodeA(score, nama, node);
        break;
    case 'B':
        nodeB(score, nama, node);
        break;
    default:
        break;
    }
}
