/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:17:25 by hportife          #+#    #+#             */
/*   Updated: 2022/01/15 11:17:27 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	clean_mlx(t_gen **gen)
{
	clean_images(*gen);
	if ((*gen)->data->win)
		mlx_destroy_window((*gen)->data->mlx, (*gen)->data->win);
//	mlx_destroy_display((*gen)->data->mlx);
	if ((*gen)->data->mlx)
		free((*gen)->data->mlx);
}

void	free_general(t_gen **gen)
{
	int	i;

	if ((*gen)->src_file > 0)
		close((*gen)->src_file);
	if ((*gen)->map_srcs)
	{
		if ((*gen)->map_srcs->no)
			free((*gen)->map_srcs->no);
		if ((*gen)->map_srcs->so)
			free((*gen)->map_srcs->so);
		if ((*gen)->map_srcs->we)
			free((*gen)->map_srcs->we);
		if ((*gen)->map_srcs->ea)
			free((*gen)->map_srcs->ea);
		if ((*gen)->map_srcs->map)
		{
			i = 0;
			while ((*gen)->map_srcs->map[i])
				free((*gen)->map_srcs->map[i++]);
			free((*gen)->map_srcs->map);
		}
		free((*gen)->map_srcs);
	}
	clean_mlx(gen);
	free((*gen));
}

void	error_call(char *message, int exit_code, t_gen **gen)
{
	if (gen)
	{
		free_general(gen);
		if ((*gen)->src_file > 0)
			close((*gen)->src_file);
	}
	printf("%s\n", message);
	exit (exit_code);
}
