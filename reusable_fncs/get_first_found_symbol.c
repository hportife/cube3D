/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_found_symbol.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:24:26 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 13:24:28 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	get_first_found_symbol(char const *str, char const *symbols)
{
	int		i;
	int		j;

	if (!str || !symbols)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (symbols[j])
		{
			if (symbols[j] == str[i])
				return (symbols[j]);
			j++;
		}
		i++;
	}
	return (0);
}
