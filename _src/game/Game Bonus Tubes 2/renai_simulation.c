# include <stdio.h>
# include "story_tree.h"
# include "..\..\ADT\mesinkar.h"
# include "execute.h"

StoryTree story;

int main() {
    char* nama;
    Sentence word_nama;
    int skor;
    skor = 0;
    printf("Masukkan Namamu: ");START();convertToArrayOfKata(&word_nama, 1);system("cls");
    nama = word_nama.buffer[0].TabWord;
    StoryTree story;
    int idx = 0;
    char* pita;
    pita = "(1(2(3(5()())(6(7()())(8(0()())(0()()))))(4(9()())(0()())))(0()()))";
    buildTreeString(&story, pita, &idx);
    Address p = story;
    while (!IsTreeEmpty(p))   {
        ExecuteNode(INFO(p), nama, &skor, &p);
    }
    printf("Permainan selesai! Skor yang kamu dapat: %d\n\n", skor);
    CHARMACHINE("credit.txt");
}