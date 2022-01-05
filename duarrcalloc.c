/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duarrcalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**duarrcalloc(int size)
{
	int		i;
	char	**tmp;

	tmp = (char **)malloc(sizeof (char *) * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp[i] = NULL;
		i++;
	}
	tmp[size] = NULL;
	return (tmp);
}
