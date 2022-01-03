#include "main.h"

int str_no_have_syms(char *str, char *syms)
{
    int i;

    if(!str && !syms)
        return (0);
    if (!str || !syms)
        return (1);
    i = 0;
    while (str[i])
    {
        if (nohavesm(syms, str[i]))
            return (1);
        i++;
    }
    return (0);
}