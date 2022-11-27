#include "story_tree.h"

int main()  {
    StoryTree story;
    //story = buildBalancedTree(4);
    story = buildStoryTree();
    PrintPreOrder(story);
}