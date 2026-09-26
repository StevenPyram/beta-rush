int corner_ind(int line, int col, int x, int y)
{
    int top = (line == 0);
    int bottom = (line == y - 1);
    int left = (col == 0);
    int right = (col == x - 1);

    if (top && left) // coin HG
        return 0;
    if (top && right) // coin HD
        return 1;
    if (bottom && left) // coin BG
        return 2;
    if (bottom && right) // coin BD
        return 3;
    return -1; // pas un coin
}

int border_ind(int line, int col, int x, int y)
{
    int top = (line == 0);
    int bottom = (line == y - 1);
    int left = (col == 0);
    int right = (col == x - 1);

    if (top) // bord HH
        return 4;
    if (bottom) // bord HB
        return 5;
    if (left) // bord VG
        return 6;
    if (right) // bord VD
        return 7;
    return -1; // pas un bord
}

int index(int line, int col, int x, int y)
{
    int index = corner_ind(line, col, x, y); // est ce un coin ?

    if (index == -1)
    { // si ce n'est pas un coin
        index = border_ind(line, col, x, y);
        if (index == -1)
        {             // ce n'est pas un bord (haut bas gauche droite)
            return 8; // index du milieu remplissage par default
        }
        return index; // index du bord
    }
    return index; // index du coin
}

void write_line(int line, int x, int y, const char *chars)
{
    for (int i = 0; i <= x - 1; i++) // parcour toute les colonnes de la ligne
    {
        int ind_char = index(line, i, x, y); // quelle caractere utiliser
        write(1, chars[ind_char], 1);
    }
    write(1, "\n", 1); // reviens a la ligne
}

void rush_generic(int x, int y, char *chars)
{
    if (x <= 0 || y <= 0)
    {
        write(1, "Invalid size\n", 13);
        return 0;
    }
    for (int i = 0; i <= y - 1; i++)
        write_line(i, x, y, chars);
}