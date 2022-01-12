/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	setup_render(t_gen *gen)
{
	gen->fov = (double)gen->resy / (double)gen->resx;
	gen->img = make_image(gen->data->mlx, gen->resx, gen->resy);
}

void	update_world(t_gen *gen)
{
	update_keybinds(gen);
	update_motion(&(gen->player), gen);
}

int	render_next_frame(t_gen *gen)
{
	update_world(gen);
	draw_floor(gen);
	draw_skybox(gen);
	ray(gen, &(gen->img));
	mlx_put_image_to_window(gen->data->mlx, gen->data->win, gen->img.img, 0, 0);
	mlx_do_sync(gen->data->mlx);
	return (0);
}
