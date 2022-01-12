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
	mlx_hook(gen->data->win, 33, 1L << 17, clean_and_exit_z, gen);
	mlx_loop_hook(gen->data->mlx, render_next_frame, gen);
	mlx_loop(gen->data->mlx);

	error_call("success execute", 0, &gen);//утекает использование ГНЛа, нужно будет создать временную переменную для его использования и перед каждым новым использованием её фришить
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
	char *tmp;

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
			tmp = ft_substr(src, j, i);
			color_dst[0][id] = ft_atoi(tmp);
			j = ++i;
			id++;
			free(tmp);
		}
	}
	tmp = ft_substr(src, j, i);
	color_dst[0][id] = ft_atoi(tmp);
	free(tmp);
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
