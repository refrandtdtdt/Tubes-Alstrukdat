#include "story_tree.h"

int main()  {
    StoryTree story;
    int idx = 0;
    char* pita;
    pita = "(1(2(3(5(7()())(8()()))(6()()))(4(9()())(0()())))(0()()))";
    //pita = "(1(2()())(3()()))";
    //story = buildBalancedTree(4);
    buildTreeString(&story, pita, &idx);
    PrintPreOrder(story);
}