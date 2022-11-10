#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include <stdio.h>
# include "boolean.h"

// Fungsi tambahan pembantu
int len(char* str);
boolean Eqstr(char* s1, char* s2);
boolean Eqfront(char* s1, char* s2);
void getcommParameter(char* s1, char* s2, char* str);
void clear(char* str);
int StrToInt(char* str);

/*memberi delay*/
void delay(unsigned int milisecond);

// int main()
// {
//     char tes[] = "testing jeger";
//     char tes1[] = "testing";
//     char str[20];
//     getcommParameter(tes,tes1,str);
//     printf("%s",str);
//     return 0;
// }
# endif