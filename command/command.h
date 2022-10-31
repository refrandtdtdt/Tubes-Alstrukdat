#ifndef COMMAND_H
#define COMMAND_H

/*Spesifikasi Command*/

# include "boolean.h"
# include <stdio.h>
# include <stdlib.h>

void help();
/* memberikan bantuan untuk tiap-tiap command
I.S. Sembarang
F.S. Mencetak bantuan-bantuan sesuai input
*/

void quit();
/*
perintah untuk mengeluarkan program
I.S. Sembarang
F.S. mengakhiri program ketika input QUIT diberikan
*/

#endif