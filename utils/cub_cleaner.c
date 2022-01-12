/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:05:13 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:33 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	destroy_img(t_gen *gen, t_img *img)
{
	if (img->img)
	{
		mlx_destroy_image(gen->data->mlx, img->img);
		img->img = NULL;
	}
}

void	clean_images(t_gen *gen)
{
	destroy_img(gen, &(gen->data->no));
	destroy_img(gen, &(gen->data->so));
	destroy_img(gen, &(gen->data->we));
	destroy_img(gen, &(gen->data->ea));
	destroy_img(gen, &(gen->img));
}

void	clean_and_exit(int code, t_gen *gen)
{
	free_general(&gen);
	gen = NULL;
	exit(code);
}

int	clean_and_exit_z(t_gen *gen)
{
	clean_and_exit(0, gen);
	return (0);
}
