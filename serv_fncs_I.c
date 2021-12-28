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
        if (name[i] == '.' && !ft_strnstr("cub", *name[i + 1], 3))
            return (1);
        else 
        {
            i += 3;
            if (i != '\0')
            return (1);
        }
        if (name[i])
            i++;
    }
    return (0);
}