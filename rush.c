void rush_generic(int x, int y, char *chars);

void rush(int x, int y)
{
    char symb = "oooo--|| ";
    return rush_generic(x, y, symb);
}