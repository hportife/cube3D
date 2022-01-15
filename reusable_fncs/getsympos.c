/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsympos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:24:52 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 13:24:54 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	getsympos(char *str, const char *symbols)
{
	int	i;
	int	j;

	if (!str || !symbols)
		return (-1);
	i = 0;
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
