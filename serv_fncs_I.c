#include "main.h"


int is_valid_name(char *name)
{
    int i;

    if (!name)
        return (0);
    i = 0;
    while (name[i])
    {
        if (!ft_isalnum(name[i]) && name[i] != '_' && name[i] != '.')
            return (1);
        i++;
    }
    return (0);
}