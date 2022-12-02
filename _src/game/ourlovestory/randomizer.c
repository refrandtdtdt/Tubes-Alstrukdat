#include "randomizer.h"
#include <math.h>

int randomizer(int lower, int upper, int *offset)    {
    srand(time(NULL));
    int seed = rand() + *offset;
    seed = abs((seed << 1) ^ seed + 1);
    *offset = seed;
    return (seed % (upper - lower + 1)) + lower;
}