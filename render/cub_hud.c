/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:28:51 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/22 13:20:44 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	draw_skybox(t_gen *gen)
{
	fill_img(gen->img, gen->data->c_color, 0, fmax(0, gen->img.height / 2 +
													gen->player.pitch * 2 +
													1));
}
