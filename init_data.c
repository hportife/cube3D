/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:36:52 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 11:36:54 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_images(t_gen **gen)
{
	(*gen)->data->no = load_image((*gen)->data->mlx, (*gen)->map_srcs->no);
	free((*gen)->map_srcs->no);
	(*gen)->map_srcs->no = NULL;
	(*gen)->data->so = load_image((*gen)->data->mlx, (*gen)->map_srcs->so);
	free((*gen)->map_srcs->so);
	(*gen)->map_srcs->so = NULL;
	(*gen)->data->we = load_image((*gen)->data->mlx, (*gen)->map_srcs->we);
	free((*gen)->map_srcs->we);
	(*gen)->map_srcs->we = NULL;
	(*gen)->data->ea = load_image((*gen)->data->mlx, (*gen)->map_srcs->ea);
	free((*gen)->map_srcs->ea);
	(*gen)->map_srcs->ea = NULL;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	data_transform(t_gen **gen)
{
	t_vec	p;

	(*gen)->data->mlx = mlx_init();
	init_images(gen);
	(*gen)->data->f_color = create_trgb(
			0, (*gen)->map_srcs->fc[0],
			(*gen)->map_srcs->fc[1], (*gen)->map_srcs->fc[2]);
	(*gen)->data->c_color = create_trgb(0, (*gen)->map_srcs->cc[0],
			(*gen)->map_srcs->cc[1], (*gen)->map_srcs->cc[2]);
	free((*gen)->map_srcs->fc);
	free((*gen)->map_srcs->cc);
	if (!valid_map(gen))
		return (0);
	p.x = (*gen)->unit_x_pos;
	p.y = (*gen)->unit_y_pos;
	set_player(*gen, (*gen)->unit_type, p);
	return (1);
}

void	init_fnc(t_gen **gen)
{
	(*gen) = (t_gen *)malloc(sizeof(t_gen));
	(*gen)->resx = 800;
	(*gen)->resy = 400;
	(*gen)->src_file = 0;
	(*gen)->map_srcs = (t_map *)malloc(sizeof (t_map));
	(*gen)->map_srcs->no = NULL;
	(*gen)->map_srcs->ea = NULL;
	(*gen)->map_srcs->so = NULL;
	(*gen)->map_srcs->we = NULL;
	(*gen)->map_srcs->map = NULL;
	(*gen)->map_srcs->cc = NULL;
	(*gen)->map_srcs->fc = NULL;
	(*gen)->data = (t_data *) malloc(sizeof (t_data));
	(*gen)->data->mlx = NULL;
	(*gen)->data->win = NULL;
	(*gen)->data->no.img = NULL;
	(*gen)->data->so.img = NULL;
	(*gen)->data->we.img = NULL;
	(*gen)->data->ea.img = NULL;
	(*gen)->data->f_color = 0;
	(*gen)->data->c_color = 0;
	(*gen)->unit_x_pos = 0;
	(*gen)->unit_y_pos = 0;
	(*gen)->unit_type = 0;
}

void	parse_data(t_gen **gen, char *file)
{
	init_fnc(gen);
	if (valid_src_file(file, &(*gen)->src_file))
		error_call("Error:\nwrong map name.\n", 1, gen);
	if (!get_map(&(*gen)->map_srcs, (*gen)->src_file))
		error_call("Error:\nincorrect content of the source file.\n", 1, gen);
	(*gen)->map_srcs->size.x = (int)ft_strlen((*gen)->map_srcs->map[0]);
	(*gen)->map_srcs->size.y = (int)duarrlen((*gen)->map_srcs->map);
	if (!data_transform(gen))
		error_call("Error:\nincorrect work with the received data.\n", 1, gen);
}
