#include "main.h"

int get_valid_map_size(char **map)
{
    int i;
    int fst_str_size;
    int tmp_str_size;

    i = 0;
    str_size = ft_strlen(map[i]);
    while(map[i])
    {
        tmp_str_size = ft_strlen(map[i]);
        if (tmp_str_size < fst_str_size || tmp_str_size > fst_str_size)
            return (1);
        i++;
    }
    return (0);
}

int onsymofstr(char *str, const char *symbols)
{
    int i;
    int j;
    int qt;

    if (!str || !symbols)
        return (0);
    i = 0;
    j = 0;
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

int getsympos(char *str, const char *symbols)
{
    int i;
    int j;

    if (!str || !symbols)
        return (-1);
    i = 0;
    j = 0;
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

int get_sym_pos(char **map, int *x_pos, int *y_pos, char *symbols)
{
    int i;
    int have;

    if (!map || !*map)
        return (1);
    i = 0;
    have = 0;
    while (map[i])
    {
        if (onsymofstr(map[i], symbols) > 1 || (onsymofstr(map[i], symbols) >= 1 && have == 1))
            return (1);
        if (onsymofstr(map[i], symbols) == 1)
        {
            *y = i;
            *x = getsympos(map[i], symbols);////////////////////////////
            have = 1;
        }
        i++;
    }
    return (0);
}

int get_valid_wall_qt(char **map)
{
    int x_pos;
    int y_pos;

    if (!map || !*map)
        return (1);
    if (get_sym_pos(map, &x_pos, &y_pos, "SNEW"))
        return (1);
    
}

int get_valid_map(char **map)
{
    if (!map || !*map)
        return (1);
    if (get_valid_map_size(map) || get_valid_wall_qt(map))
        return (1);
    
}

/*
111111    
1000011111    
1000000001
1110011111
  1001    
  10011111
  10000001
  10000S01
  10000001
  10000001
  11111111
*/