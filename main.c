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

int	main(int argc, char *argv[])
{
	t_gen	*gen;

	if (argc != 2)
		error_call("Error:\nno map specified.\n", 1, NULL);
	parse_data(&gen, argv[1]);
	setup_render(gen);
	gen->data->win = mlx_new_window(gen->data->mlx, gen->resx,
			gen->resy, "Cub3D");
	mlx_hook(gen->data->win, 2, 1L << 0, key_press, gen);
	mlx_hook(gen->data->win, 3, 1L << 1, key_lift, gen);
	mlx_hook(gen->data->win, 33, 1L << 17, clean_and_exit_z, gen);
	mlx_loop_hook(gen->data->mlx, render_next_frame, gen);
	mlx_loop(gen->data->mlx);
	error_call("success execute", 0, &gen);
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
		if (read_ident == -1)
			return (freenret(&tmp, 0));
		if (fstsym(tmp) == '1' || fstsym(tmp) == '0')
			(*mpsrc)->map = stradd(tmp, (*mpsrc)->map);
		else if ((fstsym(tmp) != '1' && fstsym(tmp) != '0') && (*mpsrc)->map)
			return (freenret(&tmp, 0));
		else if (add_content_to_map_srcs(tmp, mpsrc))
			return (freenret(&tmp, 0));
		if (tmp)
			free(tmp);
		if (read_ident > 0)
			read_ident = get_next_line(map_file, &tmp);
		else
			break ;
	}
	return (valid_map_data(mpsrc));
}
