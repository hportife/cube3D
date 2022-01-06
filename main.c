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
	init_fnc(&gen);
	if (valid_src_file(argv[1], &gen->src_file))
		error_call("Error:\nwrong map name.\n", 1, &gen);
	if (!get_map(&gen->map_srcs, gen->src_file))
		error_call("Error:\nincorrect content of the source file.\n", 1, &gen);
	if (!data_transform(&gen))
		error_call("Error:\nincorrect work with the received data.\n", 1, &gen);
//	while (1);
	error_call("", 0, &gen);//утекает использование ГНЛа, нужно будет создать временную переменную для его использования и перед каждым новым использованием её фришить
}

void	init_images(t_gen **gen)
{
	(*gen)->data->no = mlx_xpm_file_to_image((*gen)->data->mlx, (*gen)->map_srcs->no,
						(*gen)->data->width, (*gen)->data->height);
	free((*gen)->map_srcs->no);
	(*gen)->map_srcs->no = NULL;
	(*gen)->data->so = mlx_xpm_file_to_image((*gen)->data->mlx, (*gen)->map_srcs->so,
											 (*gen)->data->width, (*gen)->data->height);
	free((*gen)->map_srcs->so);
	(*gen)->map_srcs->so = NULL;
	(*gen)->data->we = mlx_xpm_file_to_image((*gen)->data->mlx, (*gen)->map_srcs->we,
											 (*gen)->data->width, (*gen)->data->height);
	free((*gen)->map_srcs->we);
	(*gen)->map_srcs->we = NULL;
	(*gen)->data->ea = mlx_xpm_file_to_image((*gen)->data->mlx, (*gen)->map_srcs->ea,
											 (*gen)->data->width, (*gen)->data->height);
	free((*gen)->map_srcs->ea);
	(*gen)->map_srcs->ea = NULL;
}

int	data_transform(t_gen **gen)
{
	(*gen)->data->mlx = mlx_init();
	init_images(gen);
	if (!valid_map(gen))
		return (0);
	return (1);
}

void	init_fnc(t_gen **gen)
{
	(*gen) = (t_gen *)malloc(sizeof(t_gen));
	(*gen)->data = (t_data *) malloc(sizeof (t_data));
	(*gen)->data->mlx = NULL;
	(*gen)->data->win = NULL;
	(*gen)->map_srcs = (t_map *)malloc(sizeof (t_map));
	(*gen)->map_srcs->no = NULL;
	(*gen)->map_srcs->ea = NULL;
	(*gen)->map_srcs->so = NULL;
	(*gen)->map_srcs->we = NULL;
	(*gen)->map_srcs->map = NULL;
	(*gen)->map_srcs->cc = NULL;
	(*gen)->map_srcs->fc = NULL;
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

//char	*get_data(char *src)
//{
//
//}

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
	while (!ft_isalpha(src[i]))
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
		if (src[i] == ' ')
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
		return (get_color(ft_strnstr(line, "F", ft_strlen(line)), &(*dst)->fc));
	if (ft_strnstr(line, "C", ft_strlen(line)))
		return (get_color(ft_strnstr(line, "C", ft_strlen(line)), &(*dst)->cc));
	return (0);
}



int	get_map(t_map **mpsrc, int map_file)
{
	char	*tmp;
	int		read_ident;

	read_ident = get_next_line(map_file, &tmp);
	while (1) // пока наш файл не закончился
	{
		if (read_ident == -1) // если с файлом беда
			return (0);
		if (fstsym(tmp) == '1' || fstsym(tmp) == '0')
			(*mpsrc)->map = stradd(tmp, (*mpsrc)->map);
		else if (add_content_to_map_srcs(tmp, mpsrc)) //если какая-то из строк нас не устраивает при чтении, ретёрнаем завершение программы
			return (0);
		if (read_ident > 0)
		{
			if (tmp)
				free(tmp);
			read_ident = get_next_line(map_file, &tmp);
		} // продолжаем считывание с файла
		else
			break ;
	}
	for (int i = 0; (*mpsrc)->map[i]; i++)
		printf("%s\n", (*mpsrc)->map[i]);
	return (valid_map_data(mpsrc));
	//сюда нужно добавить проверки корректности всех полученных из файла данных
}
