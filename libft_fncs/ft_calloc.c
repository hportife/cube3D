/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:48:27 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 11:48:35 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = malloc(count * size);
	if (i == NULL)
		return (NULL);
	ft_memset(i, 0, count * size);
	return (i);
}
