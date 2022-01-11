/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:45:16 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/19 11:11:37 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
** Draws the whole textured or untextured floor
*/

void	draw_floor(t_gen *gen)
{
	int				mid;

	mid = fmax(0, gen->img.height / 2 + gen->player.pitch * 2);
	fill_img(gen->img, gen->data->f_color, mid, gen->img.height);
}
