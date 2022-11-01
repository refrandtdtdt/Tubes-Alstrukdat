# include <stdio.h>
# include "boolean.h"

// Fungsi tambahan pembantu
int len(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
// Fungsi untuk menghitung panjang string

boolean Eqstr(char* s1, char* s2)
{
    if (len(s1) != len(s2))
    {
        return false;
    }
    int i = 0;
    while (s1[i]!='\0' && s2[i]!='\0')
    {
        if(s1[i]!=s2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
// Fungsi untuk mengecek apakah dua string adalah sama

boolean Eqfront(char* s1, char* s2)
{
    int i = 0;
    while (s2[i]!='\0')
    {
        if(s1[i]!=s2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
// Fungsi khusus untuk mengecek apakah command awal sudah benar

void getcommParameter(char* s1, char* s2, char* str)
{
    // cek apakah command valid
    int i = len(s2)+1;
    int j = len(s1);
    int k = 0;
    while (i+k<j)
    {
        str[k] = s1[i+k];
        k++;
    }
}
// Fungsi khusus untuk mengambil masukan parameter command

void clear(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = '\0';
        i++;
    }
}

int StrToInt(char* str) {
    int val = 0;
    int ten = 1;
    int dig;
    while (*str != '\0')    {
        val *= ten;
        dig = *str - '0';
        val += dig;
        ten *= 10;
        *(str++);
    }
}
// int main()
// {
//     char tes[] = "testing jeger";
//     char tes1[] = "testing";
//     char str[20];
//     getcommParameter(tes,tes1,str);
//     printf("%s",str);
//     return 0;
// }