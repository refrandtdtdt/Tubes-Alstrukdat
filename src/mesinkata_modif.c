#include <stdio.h>
#include "mesinkata_modif.h"
#include "mesinkar.h"
#include "functions.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : cc sembarang
       F.S. : cc ≠ BLANK atau cc = MARK */
    if (file)
    {
        if (cc == '\n'){
            ADV();
        }
    }
    else
    {
        while (cc == BLANK)
        {
            ADV();
        }
    }
}

void STARTWORD()
{
    /* I.S. : cc sembarang
       F.S. : endWord = true, dan cc = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              cc karakter pertama sesudah karakter terakhir kata */
    IgnoreBlanks();
    if (cc == '\n' && !file)
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
    /* I.S. : cc adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              cc adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika cc = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (cc == '\n' && !file)
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
    clear(currentWord.TabWord);
    currentWord.Length = 0;
    int i = 0;
    while (((cc != BLANK && !file) || file) && cc != '\n')
    {
        if (i < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[i] = cc;
            ADV();
            i++;
        }
        else
        {
            break;
        }
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
    for (int i = 0; i < NMax; i++)
    {
        for(int j = 0; j < NMax; j++)
        {
            sentence->buffer[i].TabWord[j] = '\0';
        }
    }
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