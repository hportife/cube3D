/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stradd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:27:44 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 13:27:46 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**stradd(char *str, char **dst)
{
	int		i;
	char	**tmp;

	if (!str)
		return (0);
	i = 0;
	tmp = (char **)malloc(sizeof (char *) * (duarrlen(dst) + 2));
	if (!tmp)
		return (dst);
	while (dst && i < duarrlen(dst))
	{
		tmp[i] = ft_strdup(dst[i]);
		i++;
	}
	tmp[i++] = ft_strdup(str);
	tmp[i] = NULL;
	duarrfree(dst);
	return (tmp);
}
