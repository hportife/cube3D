/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onsymofstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:51:52 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 16:51:53 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	onsymofstr(char *str, const char *symbols)
{
	int	i;
	int	j;
	int	qt;

	if (!str || !symbols)
		return (0);
	i = 0;
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
