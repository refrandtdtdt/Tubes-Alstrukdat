#include <stdio.h>

#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == '\n')
    {
        ADV();
    }
}
void STARTWORD(char savefile[])
{
    START(savefile);
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;
    while ((currentChar != MARK) && (currentChar != '\n'))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }
}

int WordToInt(Word word)
{
    int result = 0;
    int i;
    result += word.TabWord[0] - 48;
    if (word.Length > 1)
    {
        for (i = 1; i < word.Length; i++)
        {
            result *= 10;
            result += word.TabWord[i] - 48;
        }
    }

    return result;
}

void STARTSTDIN()
{
    STARTINPUT();
    if (currentChar == '\0')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}
