/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:51:51 by ttranche          #+#    #+#             */
/*   Updated: 2021/03/24 11:23:44 by ttranche         ###   ########.fr       */
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
//
//void	clean_images(t_gen *gen)
//{
//	destroy_img(gen, &(gen->walls.north));
//	destroy_img(gen, &(gen->walls.south));
//	destroy_img(gen, &(gen->walls.west));
//	destroy_img(gen, &(gen->walls.east));
//	destroy_img(gen, &(gen->img));
//}
//
//void	clean_all(t_gen *gen)
//{
//	clean_images(gen);
//	if (gen->data->win)
//		mlx_destroy_window(gen->data->mlx, gen->data->win);
//	mlx_destroy_display(gen->data->mlx);
//	clear_map(gen->map_srcs);
//	free_file(&gen->file);
//	if (gen->mlx)
//		free(gen->mlx);
//	if (gen->last_path)
//		free(gen->last_path);
//}
//
void	clean_and_exit(int code, t_gen *gen)
{
//	clean_all(gen);
	gen = NULL;
	exit(code);
}
//
//int		clean_and_exit_z(t_gen *gen)
//{
//	clean_and_exit(0, gen);
//	return (0);
//}
