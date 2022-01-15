/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:48:24 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 16:48:26 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (i + j < len && str1[i])
	{
		if (str1[i + j] == str2[j])
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)str1 + i);
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (0);
}
