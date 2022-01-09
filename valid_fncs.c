/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:37:06 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 11:37:08 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	valid_src_file(char *file_name, int *file_fd)
{
	if (!(ft_strchr(file_name, '.')))
		return (1);
	if (is_valid_name(file_name))
		return (1);
	*file_fd = open(file_name, O_RDONLY);
	if (*file_fd == -1)
		return (1);
	return (0);
}

int	wrong_pos(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == '0' && (y > 0 || !nohavesm("01SNEW", map[y - 1][x]))
				&& (y < duarrlen(map) - 1 || !nohavesm("01SNEW", map[y + 1][x]))
				&& (x > 0 || !nohavesm("01SNEW", map[y][x - 1]))
				&& (x < (int)ft_strlen(map[y]) - 1
				|| !nohavesm("01SNEW", map[y][x + 1])))
			x++;
		else if (!nohavesm("SNEW", map[y][x]) && (y > 0 && y < duarrlen(map) - 1
				&& x > 0 && x < (int)ft_strlen(map[y]) - 1)
				&& (!nohavesm("01", map[y - 1][x]))
				&& (!nohavesm("01", map[y + 1][x]))
				&& (!nohavesm("01", map[y][x - 1]))
				&& (!nohavesm("01", map[y][x + 1])))
			x++;
		else if (map[y][x] == '1' || map[y][x] == ' ')
			x++;
		else
			break ;
	}
	if (!map[y][x])
		return (0);
	return (1);
}

int	get_stnnd(char *str, int *start, int *end, char	border)
{
	int	i;

	*start = getsympos(str, &border);
	if (*start == -1)
		return (-1);
	i = *start;
	while (str[i] && str[i] != ' ')
	{
		if (str[i + 1] != str[*start])
			*end = i;
		i++;
	}
	return (0);
}

//int	digit_period_compr(int opst, int opnd, int spst, int spnd)
//{
//	int i;
//
//	if (spst > opnd || spnd < opst)
//		return (0);
//	while (opst < opnd)
//	{
//		i = spst;
//		while (i < spnd)
//		{
//			if (i == opst)
//				return (1);
//			i++;
//		}
//		opst++;
//	}
//	return (0);
//}
//
//int	gaps_checker(char **map, char border)
//{
//	int	i;
//	int	x;
//	int	y;
//	int	prevst;
//	int	prevnd;
//
//	i = 0;
//	while (map && map[i] && map[i + 1])
//	{
//		get_stnnd(map[i], &prevst, &prevnd, border);
//		get_stnnd(map[i + 1], &x, &y, border);
//		if (prevst == -1 || x == -1)
//			return (1);
//		if (digit_period_compr(prevst, prevnd, x, y))
//			i++;
//		else
//			while (!digit_period_compr(prevst, prevnd, x, y))
//			{
//				i++;
//				get_stnnd(map[i], &prevst, &prevnd, border);
//				get_stnnd(map[i + 1], &x, &y, border);
//				if (prevst == -1 || x == -1 || !map[i])
//					return (1);
//			}
//	}
//	return (0);
//}

int	have_connect(char *str1, char *str2)
{
	int	i;
	int	hv_cnct;

	if (!str1 || !str2)
		return (0);
	i = 0;
	hv_cnct = 0;
	while (i < ft_strlen(str1))
	{
		if (str1[i] != ' ' && str2[i] != ' ')
			hv_cnct++;
		i++;
	}
	return (hv_cnct);
}

int	gaps_checker(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i + 1])
	{
		if (have_connect(map[i], map[i + 1]) < 1)
			return (1);
		i++;
	}
	return (0);
}

int	free_use_gaps_ck(char **map)
{
	int	gapsckret;

	printf("\n");
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	gapsckret = gaps_checker(map);
	duarrfree(map);
	return (gapsckret);
}

int	valid_map(t_gen **gen)
{
	int		y;
	int		unit_qt;

	y = 0;
	unit_qt = 0;
	while ((*gen)->map_srcs->map && (*gen)->map_srcs->map[y])
	{
		unit_qt += onsymofstr((*gen)->map_srcs->map[y], "SNEW");
		if (unit_qt == 1)
		{
			(*gen)->unit_type = get_first_found_symbol((*gen)->map_srcs->map[y],
					"SNEW");
			(*gen)->unit_x_pos = getsympos((*gen)->map_srcs->map[y], "SNEW");
			(*gen)->unit_y_pos = y;
		}
		if (unit_qt > 1 || wrong_pos((*gen)->map_srcs->map, y)
			|| ft_strlen((*gen)->map_srcs->map[y])
			!= ft_strlen((*gen)->map_srcs->map[0])
			|| noonsym((*gen)->map_srcs->map[y], ' '))
			return (0);
		y++;
	}
	return (!gaps_checker((*gen)->map_srcs->map) && !free_use_gaps_ck(duarrotate((*gen)->map_srcs->map)));
}
