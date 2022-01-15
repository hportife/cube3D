/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:48:36 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 16:48:37 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) < ft_strlen(s))
		res = (char *)malloc(sizeof(*s) * len + 1);
	else
		res = (char *)malloc(sizeof(*s) * ft_strlen(s) - start + 1);
	if (res == NULL || s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			res[j++] = s[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}
