/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:55:24 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 09:55:42 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	check_textures(t_gen *gen)
{
	if (!gen->data->no.img)
		handle_error(gen, "Missing north wall texture.", NULL);
	if (!gen->data->so.img)
		handle_error(gen, "Missing south wall texture.", NULL);
	if (!gen->data->we.img)
		handle_error(gen, "Missing west wall texture.", NULL);
	if (!gen->data->ea.img)
		handle_error(gen, "Missing east wall texture.", NULL);
}

void	check_define(t_gen *gen)
{
	if (gen->resx <= 0 || gen->resy <= 0)
		handle_error(gen, "Resolution not properly set.", NULL);
	if (gen->resx > 5218 || gen->resy > 5218)
		handle_error(gen, "Resolution too big for mlx...", NULL);
	if ((unsigned int)(gen->data->c_color) == 0xDB000000)
		handle_error(gen, "Ceeling color not set.", NULL);
	if ((unsigned int)(gen->data->f_color) == 0xDB000000)
		handle_error(gen, "Bottom color not set.", NULL);
	check_textures(gen);
}
