# include <stdio.h>
# include "../ADT/mesinkata_modif.h"
# include "../ADT/mesinkar.h"
# include "../ADT/functions.h"

int main () {
    /* *** Membaca baris *** */
    // START Mesin Kata (pitakar2.txt)
    STARTCHAR("pitakar.txt");
    STARTWORD();

    // Check First Line (Total Game) 
    Word firstLine = currentWord;
    printf("First Word: ");
    printf("%s", firstLine.TabWord); 
    printf("\n");

    // Check Second Line (Game 1)
    ADVWORD();
    Word secondLine = currentWord;
    printf("Second Word: ");
    printf("%s", secondLine.TabWord); 
    printf("\n");

    // Check Third Line (Game 2)
    ADVWORD();
    Word thirdLine = currentWord;
    printf("Third Word: ");
    printf("%s", thirdLine.TabWord); 
    printf("\n");
    
    // Tes kataToString
    printf("String dari third word:\n");
    printf("%s\n", kataToString(currentWord));

    // Tes wordToInt
    printf("Int dari third word:\n");
    printf("%d\n", WordToInt(currentWord));

    // Cek isEndWord
    ADVWORD();
    printf("Udah akhir blom gan?\n");
    if (isEndWord()) {
        printf("Yoi gan");
    } else {
        printf("Belom gan");
    }

    return 0;
}