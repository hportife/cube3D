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

int get_valid_unit_pos(int x, int y, char **map)
{
    if ((y <= 0 || y >= duarrlen(map)) || (x <= 0 || x >= ft_strlen(map[0])))
        return (1);
    if ((map[y - 1][x] != '0' && map[y - 1][x] != '1')
        || (map[y + 1][x] != '0' && map[y + 1][x] != '1'))
        return (1);
    if ((map[y][x - 1] != '0' && map[y][x - 1] != '1')
        || (map[y][x + 1] != '0' && map[y][x + 1] != '1'))
        return (1);
    if ((map[y - 1][x - 1] != '0' && map[y - 1][x - 1] != '1')
    || (map[y + 1][x - 1] != '0' && map[y + 1][x - 1] != '1'))
        return (1);
    if ((map[y - 1][x + 1] != '0' && map[y - 1][x + 1] != '1')
    || (map[y + 1][x + 1] != '0' && map[y + 1][x + 1] != '1'))
        return (1);
    return (0);
}

int move(int *x, int *y, char ident, char **map)
{
    if (ident == 'l' && map[*y][*x - 1] != '1')
        (*x)--;
    else if (ident == 'l' && map[*y][*x - 1] == '1')
        return (1);
    if (ident == 'r' && map[*y][*x + 1] != '1')
        (*x)++;
    else if (ident == 'r' && map[*y][*x - 1] == '1')
        return (1);
    if (ident == 'u' && map[*y - 1][*x] != '1')
        (*y)--;
    else if (ident == 'u' && map[*y - 1][*x] == '1')
        return (1);
    if (ident == 'd' && map[*y + 1][*x] != '1')
        (*y)++;
    else if (ident == 'd' && map[*y + 1][*x] == '1')
        return (1);
    return (0);
}

int valid_exec(int *x, int *y, char **map)
{
    int premission_phase;

    premission_phase = 0;
    
    return (0);
}

int start_wall_valid(int unit_x_pos, int unit_y_pos, char **map) //НУЖНА ДОРАБОТКА
{
    int tmp_x;
    int tmp_y;
    int x;
    int y;

    x = unit_x_pos;
    y = unit_y_pos;
    while (map[y][x - 1] != '1')
        x--;
    y--;
    tmp_x = x;
    tmp_y = y;
    while (x != tmp_x && y != tmp_y)
    {
        valid_exec(&x, &y, map);
    }
}

int get_valid_wall_qt(char **map)
{
    int x_pos;
    int y_pos;

    if (!map || !*map)
        return (1);
    if (get_sym_pos(map, &x_pos, &y_pos, "SNEW"))
        return (1);
    if (get_valid_unit_pos(x_pos, y_pos, map))
        return (1);
    if (start_wall_valid(x_pos, y_pos, map) == -1)
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
1000000100
1110011111
  1001    
  10011111
  10000001
  10000S01
  10000001
  10000001
  11111111
*/