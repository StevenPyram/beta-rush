#include "unistd.h"

int rush_generic(int x, int y, char const *chars);

void rush(int x, int y)
{
    if (x == 1 || y == 1)
    {
        rush_generic(x, y, "BBBBBBBB");
        return;
    }
    rush_generic(x, y, "AACCBBBB ");
    return;
}