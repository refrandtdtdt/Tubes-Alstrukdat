#include "story_tree.h"

int main()  {
    StoryTree story;
    int idx = 0;
    char* pita;
    int level = 1;
    pita = "(1(2(3(5()())(6(7()())(8(0()())(0()()))))(4(9(A()())(B()()))(0()())))(0()()))";
    //pita = "(1(2()())(3()()))";
    //story = buildBalancedTree(4);
    buildTreeString(&story, pita, &idx);
    PrintPreOrder(story, level);
}