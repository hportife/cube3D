/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:51:58 by ttranche          #+#    #+#             */
/*   Updated: 2021/02/01 23:08:41 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fill_img(t_img img, int c, int start, int stop)
{
	int *bytes;
	int *end;

	end = (void *)img.addr + stop * img.line_length;
	bytes = (int *)((void*)img.addr + start * img.line_length);
	while (bytes < end)
		*bytes++ = c;
}
