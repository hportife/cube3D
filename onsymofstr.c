#include "main.h"

int onsymofstr(char *str, const char *symbols)
{
    int i;
    int j;
    int qt;

    if (!str || !symbols)
        return (0);
    i = 0;
    qt = 0;
    while (symbols[i])
    {
        j = 0;
        while (str[j])
        {
            if (str[j] == symbols[i])
                qt++;
            j++;
        }
        i++;
    }
    return (qt);
}