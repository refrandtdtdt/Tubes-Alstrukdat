#include "story2_node.h"
#include "janken.h"

void node2(int *score, char* player, Address *p)
{
    boolean validinput;
    char dummy;
    int input;
    Sentence word_input;
    printf("Aku cukup bersabar.");START();system("cls");
    printf("voting pun berjalan...");START();system("cls");
    printf("ternyata suaraku menang jauh.");START();system("cls");
    printf("ya jelas lah, bagaimana ceritanya orang aneh macam dia bisa dapat suara dari temen-temen.");START();system("cls");
    printf("lalu dia menangis kencang");START();system("cls");
    printf("Refrendt: \"kenapa gue bisa kalah?!\"");START();system("cls");
    printf("Refrendt: \"Impossible njir!\"");START();system("cls");
    printf("dia pun keluar dari kelas. gurunya heran, apalagi aku.");START();system("cls");
    printf("kemudian kami melanjutkan kelas seperti biasa. sorenya kami pulang. Aku dan Megumi pulang bersama-sama dari sekolah.");START();system("cls");
    printf("Megumi: \"Oh ya, %s. kamu akhir pekan sibuk ga?\"", player);START();system("cls");
    printf("%s: \"Enggak sih, emangnya kenapa?\"", player);START();system("cls");
    printf("\"Mau makan bareng gak? wkwkwk\"");START();system("cls");
    printf("Aku pun mengangguk. yah, tidak ada salahnya juga sih.");START();system("cls");
    printf("%s: \"Enaknya makan di mana?\"", player);START();system("cls");
    printf("Megumi: \"Kalau kamu gimana?\"");START();system("cls");
    printf("%s: \"Nah ini aku bingung atuh eta makanya tanya ke maneh\"", player);START();system("cls");
    printf("Megumi: \"lah, aku juga bingung makanya tanya ke kamu, hahahaha\"");START();system("cls");
    printf("%s: \"Kamu aja\"",player);START();system("cls");
    printf("Megumi: \"Kamu!!\"");START();system("cls");
    printf("%s: \"Mending Kamu aja\"", player);START();system("cls");
    printf("Megumi: \"Duh, dibilangin kamu aja deh!\"");START();system("cls");
    printf("%s: \"Harus kamu!!\"", player);START();system("cls");
    printf("Megumi: \"Kaammmmmuuuuuuuuu!!!!\"");START();system("cls");
    printf("kamu ribut terus dengan Megumi");START();system("cls");
    validinput = false;
    while (!validinput)
    {
        printf("Opsi Dialog: \n1. pergi meninggalkan Megumi, dan meninggalkannya karena keributan ini\n2. Menentukan dengan gunting batu kertas\n\n");
        //scanf("%d", &input);
        START();
        convertToArrayOfKata(&word_input, 1);
        printf("%d\n", word_input.buffer[0].Length);
        input = StrToInt(word_input.buffer[0].TabWord);
        system("cls");
        printf("%d\n", input);
        if ((input == 1) || (input == 2)) {
            validinput = true;
        } 
        else    {
            printf("Invalid Input\n");
        }
    }
    if (input == 1) {
        *score -= 500;
        printf("score -500\n\n");
        printf("%s: \"Dahlah aku kesel sama kamu, kita cukupin hari ini. sampai jumpa besok\"", player);START();system("cls");
        printf("Megumi: \"Woi pengecut, jangan gitu lah\"");START();system("cls");
        printf("Megumi: \"Gimana kalo kita tentuin pakai gunting-batu-kertas?? Berani!!??\"");START();system("cls");
        printf("Opsi Dialog:\n1. Hayyuk.\n\n");
        validinput = false;
        while (!validinput) {
            //scanf("%d", &input);
            START();
            convertToArrayOfKata(&word_input, 1);
            input = StrToInt(word_input.buffer[0].TabWord);
            if (input == 1) {
                validinput = true;
            }
            else    {
                printf("Invalid Input\n");
            }
            system("cls");
        }
    }
    else if (input == 2)    {
        printf("%s: \"Gimana kalo gitu main gunting batu kertas aja buat nentuin. yang kalah harus nentuin, titik.\"", player);START();system("cls");
        printf("Megumi: \"...O-oke deh, mari kita suit\"\n");START();system("cls");   
    }
    boolean win;
    janken(score, 500, 100, &win);

    if (win)    {
        *p = LEFT(*p);
    }
    else    {
        *p = RIGHT(*p);
    }
    /*

    */
}