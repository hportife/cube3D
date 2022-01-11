/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:05:08 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:16:03 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		stringlen(char *string)
{
	int len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

void	truncate_str(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	len--;
	while (len >= 0 && s[len] == ' ')
		s[len--] = 0;
}
