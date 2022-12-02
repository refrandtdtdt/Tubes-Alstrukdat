#include <stdio.h>
#include "../ADT/point.h"
#include "../ADT/linkedlist.h"
#include "../ADT/mesinkata_modif.h"
#include "../ADT/mesinkar.h"
#include "../ADT/functions.h"

int main () {
    ListPoint tes; CreateEmptyListPoint(&tes);
    Point titik = MakePoint(1,1);
    InsVFirst(&tes,titik);
    Point titik2 = MakePoint(1,2);
    InsVLast(&tes,titik2);
    PrintInfo(tes);

    return 0;
}