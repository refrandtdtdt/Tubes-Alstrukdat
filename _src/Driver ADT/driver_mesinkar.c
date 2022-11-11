# include <stdio.h>
# include "../ADT/mesinkar.h"
# include "../ADT/functions.h"

int main()
{
    /* *** Membaca File *** */
    // START Mesin Karakter
    STARTCHAR("pitakar.txt");

    // Check First Character
    char first = GetCCCHAR();
    printf("Huruf pertama: %c\n", first);

    // Check ADVCHAR() 
    ADVCHAR();
    char second = GetCCCHAR();
    printf("Huruf kedua: %c\n", second);
    
    // Check if EOP
    printf("%d\n", IsEOPCHAR());

    // Print semua character dari awal sampaii EOP
    CHARMACHINE("pitakar.txt");
    printf("\n");
    
    // Check if EOP is true
    printf("%d\n", IsEOPCHAR());  

    // Check First Character
    char firstC = GetCCCHAR();
    printf("%c\n", firstC);

    return 0;

}
