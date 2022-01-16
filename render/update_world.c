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

void	update_world(t_gen *gen)
{
	update_keybinds(gen);
	update_motion(&(gen->player), gen);
}

int	render_next_frame(t_gen *gen)
{
	update_world(gen);
	fill_img(gen->img, gen->data->f_color, gen->img.height);
	fill_img(gen->img, gen->data->c_color, fmax(0, gen->img.height / 2 + 1));
	ray(gen, &(gen->img));
	mlx_put_image_to_window(gen->data->mlx, gen->data->win, gen->img.img, 0, 0);
	mlx_do_sync(gen->data->mlx);
	return (0);
}
