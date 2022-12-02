#include "_src/ADT/stack_history.h"

void showHistory(Word command, StackHistory stackHistory)
{
    Word banyakHistory;
    CommandWord(&banyakHistory, command, 2);
    if (banyakHistory.Length > 0)
    {
        int banyakHistory_int = WordToInt(banyakHistory);
        if (banyakHistory_int > 0)
        {
            printf("Berikut adalah daftar Game yang telah dimainkan\n");
            PrintStackHistory(stackHistory, banyakHistory_int);
        }
        else
        {
            printf("History gagal ditampilkan.\n");
        }
    }
    else
    {
        printf("History gagal ditampilkan.\n");
    }
}

void resetHistory(StackHistory *stackHistory)
{
    boolean valid = false;
    while (!valid)
    {
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
        startInputWord();
        if (Eqstr(currentWord, "YA") || Eqstr(currentWord, "TIDAK"))
        {
            valid = true;
        }
        else
        {
            printf("\nMasukan tidak valid coba lagi.\n");
        }
    }

    if (Eqstr(currentWord, "YA"))
    {
        CreateStackHistory(stackHistory);
        printf("\nHistory berhasil di-reset.\n");
    }
    else
    {
        printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        PrintStackHistory(*stackHistory, Top(*stackHistory) + 1);
    }
}