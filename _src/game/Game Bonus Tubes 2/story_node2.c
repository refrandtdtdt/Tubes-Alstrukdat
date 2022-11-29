#include "story2_node.h"
#include "janken.h"

void node2(int *score, char* player, Address *p)
{
    boolean validinput;
    char dummy;
    int input;
    Sentence word_input;
    printf("Aku cukup bersabar.");scanf("%c", &dummy);system("cls");
    printf("voting pun berjalan...");scanf("%c", &dummy);system("cls");
    printf("ternyata suaraku menang jauh.");scanf("%c", &dummy);system("cls");
    printf("ya jelas lah, bagaimana ceritanya orang aneh macam dia bisa dapat suara dari temen-temen.");scanf("%c", &dummy);system("cls");
    printf("lalu dia menangis kencang");scanf("%c", &dummy);system("cls");
    printf("Refrendt: \"kenapa gue bisa kalah?!\"");scanf("%c", &dummy);system("cls");
    printf("Refrendt: \"Impossible njir!\"");scanf("%c", &dummy);system("cls");
    printf("dia pun keluar dari kelas. gurunya heran, apalagi aku.");scanf("%c", &dummy);system("cls");
    printf("kemudian kami melanjutkan kelas seperti biasa. sorenya kami pulang. Aku dan Miya pulang bersama-sama dari sekolah.");scanf("%c", &dummy);system("cls");
    printf("Miya: \"Oh ya, %s. kamu akhir pekan sibuk ga?\"", player);scanf("%c", &dummy);system("cls");
    printf("%s: \"Enggak sih, emangnya kenapa?\"", player);scanf("%c", &dummy);system("cls");
    printf("\"Mau makan bareng gak? wkwkwk\"");scanf("%c", &dummy);system("cls");
    printf("Aku pun mengangguk. yah, tidak ada salahnya juga sih.");scanf("%c", &dummy);system("cls");
    printf("%s: \"Enaknya makan di mana?\"", player);scanf("%c", &dummy);system("cls");
    printf("Miya: \"Kalau kamu gimana?\"");scanf("%c", &dummy);system("cls");
    printf("%s: \"Nah ini aku bingung atuh eta makanya tanya ke maneh\"", player);scanf("%c", &dummy);system("cls");
    printf("Miya: \"lah, aku juga bingung makanya tanya ke kamu, hahahaha\"");scanf("%c", &dummy);system("cls");
    printf("%s: \"Kamu aja\"",player);scanf("%c", &dummy);system("cls");
    printf("Miya: \"Kamu!!\"");scanf("%c", &dummy);system("cls");
    printf("%s: \"Mending Kamu aja\"", player);scanf("%c", &dummy);system("cls");
    printf("Miya: \"Duh, dibilangin kamu aja deh!\"");scanf("%c", &dummy);system("cls");
    printf("%s: \"Harus kamu!!\"", player);scanf("%c", &dummy);system("cls");
    printf("Miya: \"Kaammmmmuuuuuuuuu!!!!\"");scanf("%c", &dummy);system("cls");
    printf("kamu ribut terus dengan Miya");scanf("%c", &dummy);system("cls");
    validinput = false;
    while (!validinput)
    {
        printf("Opsi Dialog: \n1. pergi meninggalkan Miya, dan meninggalkannya karena keributan ini\n2. Menentukan dengan gunting batu kertas\n\n");
        //scanf("%d", &input);
        START();
        convertToArrayOfKata(&word_input, 1);
        input = StrToInt(word_input.buffer[0].TabWord);
        system("cls");
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
        printf("%s: \"Dahlah aku kesel sama kamu, kita cukupin hari ini. sampai jumpa besok\"", player);scanf("%c", &dummy);system("cls");
        printf("Miya: \"Woi pengecut, jangan gitu lah\"");scanf("%c", &dummy);system("cls");
        printf("Miya: \"Gimana kalo kita tentuin pakai gunting-batu-kertas?? Berani!!??\"");scanf("%c", &dummy);system("cls");
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
        printf("%s: \"Gimana kalo gitu main gunting batu kertas aja buat nentuin. yang kalah harus nentuin, titik.\"", player);scanf("%c", &dummy);system("cls");
        printf("Miya: \"...O-oke deh, mari kita suit\"\n");scanf("%c", &dummy);system("cls");   
    }
    boolean win;
    janken(score, 750, 100, &win);

    if (win)    {
        *p = LEFT(*p);
    }
    else    {
        *p = RIGHT(*p);
    }
    /*

    */
}