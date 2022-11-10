# include "functions.h"

int len(char* str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n')
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

void getcommParameter(char* s1, char* s2, char* str)
{
    int i = len(s2);
    int j = len(s1);
    int k = 0;
    while (i+k<=j)
    {
        str[k] = s1[i+k];
        k++;
    }
}
// Fungsi untuk mengambil bagian belakang dari suatu string

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
    int i;
    for (i = 0; i < len(str); i++)    {
        val *= ten;
        dig = str[i] - '0';
        val += dig;
        ten *= 10;
    }
    return val;
}