#include "unistd.h"

void rush_generic(int x, int y, char *chars);

void rush(int x, int y)
{
    char symb[10] = "oooo--|| ";
    return rush_generic(x, y, symb);
}