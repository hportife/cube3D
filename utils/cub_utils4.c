/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fill_img(t_img img, int c, int start, int stop)
{
	int	*bytes;
	int	*end;

	end = (void *)img.addr + stop * img.line_length;
	bytes = (int *)((void *)img.addr + start * img.line_length);
	while (bytes < end)
		*bytes++ = c;
}
