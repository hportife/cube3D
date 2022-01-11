/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:13:45 by ttranche          #+#    #+#             */
/*   Updated: 2021/01/29 18:32:33 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		get_pixel(t_img *data, int x, int y)
{
	return (*(int*)(data->addr + (y * data->line_length + x
		* (data->pixel_len))));
}

bool	check_iscub(char *file)
{
	int		len;

	len = stringlen(file);
	if (len < 4)
		return (false);
	return ((file[len - 1] == 'b' || file[len - 1] == 'B')
		&& (file[len - 2] == 'u' || file[len - 2] == 'U')
		&& (file[len - 3] == 'c' || file[len - 3] == 'C')
		&& file[len - 4] == '.');
}
