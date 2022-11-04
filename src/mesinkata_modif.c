#include <stdio.h>
#include "mesinkata_modif.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
    IgnoreBlanks();
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    currentWord.Length = 0;
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (i < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[i] = currentChar;
            ADV();
            i++;
        }
        else
            break;
    }
    currentWord.Length = i;
}


boolean isEndWord() {
    return endWord;
}

void convertToArrayOfKata(Sentence *sentence, int length)  {
    /*mengubah kalimat ke dalam bentuk array of Kata*/
    int i = 0;
    STARTWORD();
    while ((!endWord) && (i < length))    {
        for (int j = 0; j < currentWord.Length;j++) {
            sentence->buffer[i].TabWord[j] = currentWord.TabWord[j];
            sentence->buffer[i].Length = currentWord.Length;
        }
        ADVWORD();
        i++;
    }
    sentence->Length = length;
}

void CreateSentence(Sentence *sentence) {
    sentence->Length = 0;
}

char* kataToString(Word kata)   {
    char* output;
    output = (char*) malloc (kata.Length*sizeof(char)+2);
    for (int i = 0; i < kata.Length; i++)   {
        output[i] = kata.TabWord[i];
    }
    output[kata.Length] = '\0';
    return output;
}