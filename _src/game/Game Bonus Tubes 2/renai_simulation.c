# include <stdio.h>
# include "story_tree.h"

StoryTree story;

int main() {
    char* nama;
    int skor;
    skor = 0;
    printf("Masukkan Namamu: ");scanf(%s, nama);
    story = buildStoryTree();
    Address p = story;
    while (IsTreeEmpty(p))   {
        ExecuteNode(INFO(p), nama, &skor, &p);
    }
    printf("Permainan selesai! Skor yang kamu dapat: %d", skor);
}