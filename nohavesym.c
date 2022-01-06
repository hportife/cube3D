#include "main.h"

int nohavesm(char *str, char sym)
{
    int i;

    if (!str)
        return (1);
    i = 0;
    while (str[i])
    {
        if (str[i] == sym)
            return (0);
        i++;
    }
    return (1);
}