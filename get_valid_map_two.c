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

int get_sym_pos(char **map, char *symbols)
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
            have = 1;
        i++;
    }
    return (0);
}

int valid_sym_orientation(const char **map, const int x, const int y)
{
    if (map[y][x] == ' ' || map[y][x] == '1')
        return (0);
    if (map[y][x] == '0' || !nohavesm("SNEW", map[y][x]))
    return (0);
}

int get_valid_wall_qt(char **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    if (get_ssssssssssssssssssssssss)
    while(map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (valid_sym_orientation(map, x, y))
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}

int get_valid_map(char **map)
{
    if (!map || !*map)
        return (1);
    if (get_valid_map_size(map) || get_valid_wall_qt(map))
        return (1);
    return (0); //maybe not endet
}