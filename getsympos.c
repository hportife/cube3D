#include "main.h"

int getsympos(char *str, const char *symbols)
{
    int i;
    int j;

    if (!str || !symbols)
        return (-1);
    i = 0;
    while (symbols[i])
    {
        j = 0;
        while (str[j])
        {
            if (str[j] == symbols[i])
                return (j);
            j++;
        }
        i++;
    }
    return (-1);
}