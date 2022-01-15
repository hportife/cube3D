/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_no_have_syms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:53:19 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 16:53:21 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	str_no_have_syms(char *str, char *syms)
{
	int	i;

	if (!str && !syms)
		return (0);
	if (!str || !syms)
		return (1);
	i = 0;
	while (str[i])
	{
		if (nohavesm(syms, str[i]))
			return (1);
		i++;
	}
	return (0);
}
