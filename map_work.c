#include "main.h"

int ck_valid_map(char **map)
{
    int i;

    if (!map)
        return (0);
    i = 0;
    if (noonsym(map[i], '1') || noonsym(map[duarrlen(map) - 1], '1'))
        return (1);
    while (map[i])
        if (sne_noonsym(map[i], '1') || str_no_have_syms(map[i], "01SNEW")
            || ft_strlen(map[i++]) != ft_strlen(map[0]))
            return (1);
    
    return (0);
}