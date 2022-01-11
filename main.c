/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:36:52 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 11:36:54 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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


int		render_next_frame(t_gen *gen)
{
	update_world(gen);
	draw_floor(gen);
	draw_skybox(gen);
	ray(gen, &(gen->img));
	mlx_put_image_to_window(gen->data->mlx, gen->data->win, gen->img.img, 0, 0);
	mlx_do_sync(gen->data->mlx);
	return (0);
}

int main(int argc, char *argv[])
{
	t_gen	*gen;
	
	if (argc != 2)
		error_call("Error:\nno map specified.\n", 1, NULL);
	parse_data(&gen, argv[1]);
	setup_render(gen);
	gen->data->win = mlx_new_window(gen->data->mlx, gen->resx, gen->resy, "Cub3D");
	mlx_hook(gen->data->win, 2, 1L << 0, key_press, gen);
	mlx_hook(gen->data->win, 3, 1L << 1, key_lift, gen);
//	mlx_hook(gen->data->win, 33, 1L << 17, clean_and_exit_z, gen);
	mlx_loop_hook(gen->data->mlx, render_next_frame, gen);
	mlx_loop(gen->data->mlx);

	error_call("success execute", 0, &gen);//утекает использование ГНЛа, нужно будет создать временную переменную для его использования и перед каждым новым использованием её фришить
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

int		set_player(t_gen *gen, char c, t_vec p)
{
	int val;

	if (c == 'E')
		val = 0;
	else if (c == 'S')
		val = 1;
	else if (c == 'W')
		val = 2;
	else if (c == 'N')
		val = 3;
	else
		return (0);
	gen->player = make_player();
	gen->player.pos.x = p.x + 0.50001;
	gen->player.pos.y = p.y + 0.50001;
	gen->player.s_pos.x = gen->player.pos.x;
	gen->player.s_pos.y = gen->player.pos.y;
	gen->player.yaw = M_PI / 2.0 * val;
	return (1);
}

int	data_transform(t_gen **gen)
{
	t_vec p;

	(*gen)->data->mlx = mlx_init();
	init_images(gen);
	(*gen)->data->f_color = create_trgb(0, (*gen)->map_srcs->fc[0],
						(*gen)->map_srcs->fc[1], (*gen)->map_srcs->fc[2]);
	(*gen)->data->c_color = create_trgb(0, (*gen)->map_srcs->cc[0],
										(*gen)->map_srcs->cc[1], (*gen)->map_srcs->cc[2]);
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
	(*gen)->data->width = 0;
	(*gen)->data->height = 0;
	(*gen)->unit_x_pos = 0;
	(*gen)->unit_y_pos = 0;
	(*gen)->unit_type = 0;
}

char	*skip_tabulation(char *src)
{
	int	i;

	i = 0;
	while (src[i] == ' ' || src[i] == '\t')
		i++;
	return (&src[i]);
}

int	get_path(char *src, char **dst)
{
	int	i;
	int	j;

	i = 2;
	if (*dst)
	{
		free(*dst);
		*dst = NULL;
	}
	while (!ft_isalpha(src[i]) && src[i] != '.' && src[i] != '_' && src[i] != '/')
		i++;
	j = i;
	while (ft_isalnum(src[i]) || src[i] == '/' || src[i] == '_' || src[i] == '.')
		i++;
	(*dst) = ft_substr(src, j, i - j);
	return (0);
}

int	wrongcloser(int tmpfd)
{
	close(tmpfd);
	return (0);
}

int	valid_map_data(t_map **map_source)
{
	int	tmpfd;

	tmpfd = open((*map_source)->ea, O_RDONLY);
	if (tmpfd == -1)
		return (wrongcloser(tmpfd));
	close(tmpfd);
	tmpfd = open((*map_source)->no, O_RDONLY);
	if (tmpfd == -1)
		return (wrongcloser(tmpfd));
	close(tmpfd);
	tmpfd = open((*map_source)->so, O_RDONLY);
	if (tmpfd == -1)
		return (wrongcloser(tmpfd));
	close(tmpfd);
	tmpfd = open((*map_source)->we, O_RDONLY);
	if (tmpfd == -1)
		return (wrongcloser(tmpfd));
	close(tmpfd);
	return (1);
}

int	get_color_ret(int const *color_dst)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (color_dst[i] > 255 || color_dst[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

int	get_color(char *src, int **color_dst)
{
	int i;
	int	j;
	int id;

	i = 1;
	j = i;
	id = 0;
	color_dst[0] = (int *) malloc(sizeof (int) * 3);
	while (src[i])
	{
		if (src[i] == ' ' && id != 2)
			j = i++;
		if (src[i] >= '0' && src[i] <= '9')
			i++;
		else
		{
			color_dst[0][id] = ft_atoi(ft_substr(src, j, i));
			j = ++i;
			id++;
		}
	}
	color_dst[0][id] = ft_atoi(ft_substr(src, j, i));
	return (get_color_ret(color_dst[0]));
}

int	add_content_to_map_srcs(char *line, t_map **dst)
{
	if (!line)
		return (1);
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		get_path(ft_strnstr(line, "NO", ft_strlen(line)), &(*dst)->no);
	if (ft_strnstr(line, "SO", ft_strlen(line)))
		get_path(ft_strnstr(line, "SO", ft_strlen(line)), &(*dst)->so);
	if (ft_strnstr(line, "WE", ft_strlen(line)))
		get_path(ft_strnstr(line, "WE", ft_strlen(line)), &(*dst)->we);
	if (ft_strnstr(line, "EA", ft_strlen(line)))
		get_path(ft_strnstr(line, "EA", ft_strlen(line)), &(*dst)->ea);
	if (ft_strnstr(line, "F", ft_strlen(line)))
		if (get_color(ft_strnstr(line, "F", ft_strlen(line)), &(*dst)->fc))
			return (1);
	if (ft_strnstr(line, "C", ft_strlen(line)))
		if (get_color(ft_strnstr(line, "C", ft_strlen(line)), &(*dst)->cc))
			return (1);
	return (0);
}

int	get_map(t_map **mpsrc, int map_file)
{
	char	*tmp;
	int		read_ident;

	read_ident = get_next_line(map_file, &tmp);
	while (1)
	{
		if (read_ident == -1) // если с файлом беда
			return (freenret(&tmp, 0));
		if (fstsym(tmp) == '1' || fstsym(tmp) == '0')
			(*mpsrc)->map = stradd(tmp, (*mpsrc)->map);
		else if ((fstsym(tmp) != '1' && fstsym(tmp) != '0') && (*mpsrc)->map)
			return (freenret(&tmp, 0));
		else if (add_content_to_map_srcs(tmp, mpsrc)) //если какая-то из строк нас не устраивает при чтении, ретёрнаем завершение программы
			return (freenret(&tmp, 0));
		if (tmp)
			free(tmp);
		if (read_ident > 0) // пока наш файл не закончился
			read_ident = get_next_line(map_file, &tmp); // продолжаем считывание с файла
		else
			break ;
	}
	return (valid_map_data(mpsrc));
}
