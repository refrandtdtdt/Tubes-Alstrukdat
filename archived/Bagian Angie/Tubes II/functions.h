#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include <stdio.h>
# include <stdlib.h>
# include "boolean.h"

// Fungsi tambahan pembantu
int len(char* str);
boolean Eqstr(char* s1, char* s2);
void getcommParameter(char* s1, char* s2, char* str);
void clear(char* str);
int StrToInt(char* str);

/*memberi delay*/
void delay(unsigned int milisecond);

# endif