# include <stdio.h>
# include "story_tree.h"
# include "..\..\ADT\mesinkar.h"
# include "execute.h"

StoryTree story;

int main() {
    char* nama;
    Sentence word_nama;
    Sentence word_input;
    int input;
    boolean valid = false;
    int skor;
    skor = 0;
    printf("Welcome to Our Love Story\n\n");
    while (!valid)  {
        printf("Select menu\n1. START THE GAME\n2. CHARACTER PROFILE\n");
        START();convertToArrayOfKata(&word_input, 1);system("cls");
        input = StrToInt(word_input.buffer[0].TabWord);
        if (input == 1) {
            valid = true;
            system("cls");
        }
        else if (input == 2) {
            system("cls");
            PRINTMACHINE("megumi_main.txt");
            printf("\n\n");
            CHARMACHINE("character_profile.txt");
            printf("Tekan enter untuk menutup");START();system("cls");
        }
        else    {
            printf("input salah\n");
        }
    }
    
    printf("Masukkan Namamu: ");START();convertToArrayOfKata(&word_nama, 1);system("cls");
    nama = kataToString(word_nama.buffer[0]);
    StoryTree story;
    int idx = 0;
    char* pita;
    pita = "(1(2(3(5()())(6(7()())(8(0()())(0()()))))(4(9(A()())(B()()))(0()())))(0()()))";
    buildTreeString(&story, pita, &idx);
    Address p = story;
    while (!IsTreeEmpty(p))   {
        ExecuteNode(INFO(p), nama, &skor, &p);
    }
    printf("Permainan selesai! Skor yang kamu dapat: %d\n\n", skor);
    CHARMACHINE("credit.txt");
    return 0;
}