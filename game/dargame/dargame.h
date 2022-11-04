#ifndef DARGAME_H
#define DARGAME_H

# include "queue_buff"
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "stack_buff_debuff.h"
# include "list_character.h"

void dargame();
/*
Game dargame!!
Sebuah next generation turn based.
Memilih 10 Karakter pilihan dengan skill unggulan mereka

Sistem Game:
Yang kalah: yang HPnya sudah 0
setiap pemain akan menyerang secara bergiliran
buff-buff random didapat setiap round

*/

void viewCharacter(List Character);

#endif