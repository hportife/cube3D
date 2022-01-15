/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_fncs_I.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:21:09 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 16:21:22 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	is_valid_name(char *name)
{
	if (!name)
		return (0);
	if (ft_strncmp(".cub", &name[ft_strlen(name) - 4], 4))
		return (1);
	return (0);
}

int	have_connect(char *str1, char *str2)
{
	size_t	i;
	int		hv_cnct;

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

int	get_color_ret(int const *color_dst)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color_dst[i] > 255 || color_dst[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

int	get_path(char *src, char **dst)
{
	int	i;
	int	j;

	i = 2;
	if (*dst)
	{
		free(*dst);
		*dst = NULL;
	}
	while (!ft_isalpha(src[i]) && src[i] != '.'
		&& src[i] != '_' && src[i] != '/')
		i++;
	j = i;
	while (ft_isalnum(src[i]) || src[i] == '/'
		|| src[i] == '_' || src[i] == '.')
		i++;
	(*dst) = ft_substr(src, j, i - j);
	return (0);
}

int	get_color(char *src, int **color_dst)
{
	size_t	i;
	int		j;
	int		id;
	char	*tmp;

	i = 1;
	j = i;
	id = 0;
	color_dst[0] = (int *) malloc(sizeof (int) * 3);
	while (i <= ft_strlen(src))
	{
		if (src[i] && (src[i] == ' ' && id != 2))
			j = i++;
		if (src[i] && (src[i] >= '0' && src[i] <= '9'))
			i++;
		else
		{
			tmp = ft_substr(src, j, i);
			color_dst[0][id++] = ft_atoi(tmp);
			j = ++i;
			free(tmp);
		}
	}
	return (get_color_ret(color_dst[0]));
}
