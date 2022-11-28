# include <stdio.h>
# include "story_tree.h"
# include "..\..\ADT\mesinkar.h"
# include "execute.h"

StoryTree story;

int main() {
    char* nama;
    int skor;
    skor = 0;
    printf("Masukkan Namamu: ");scanf("%s", nama);
    StoryTree story;
    int idx = 0;
    char* pita;
    pita = "(1(2(3(5(7()())(8()()))(6()()))(4(9()())(0()())))(0()()))";
    buildTreeString(&story, pita, &idx);
    Address p = story;
    while (!IsTreeEmpty(p))   {
        ExecuteNode(INFO(p), nama, &skor, &p);
    }
    printf("Permainan selesai! Skor yang kamu dapat: %d\n\n", skor);
    //CHARMACHINE("credit.txt");
}