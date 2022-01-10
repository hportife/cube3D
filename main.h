/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hportife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:36:57 by hportife          #+#    #+#             */
/*   Updated: 2022/01/04 11:36:58 by hportife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_map
{
	char	*no;
	char	*so;
    char	*we;
    char	*ea;
	int		*fc;
	int		*cc;
    char	**map;
}   t_map;

typedef struct s_data
{
	//mlx data
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		f_color;
	int		c_color;
	int		width;
	int		height;
}	t_data;

typedef struct s_gen
{
    int     src_file;
    t_map   *map_srcs;
	t_data	*data;
    int     unit_x_pos;
    int     unit_y_pos;
    char    unit_type;
}   t_gen;

int		noonsym(char *str, char sym);
int		duarrlen(char **array);
char	**duarrfree(char **arr);
char	**duarrcalloc(int size);
char	**duarrotate(char **duarr);
char	**stradd(char *str, char **dst);

int 	sne_noonsym(char *str, char sym);
int 	nohavesm(char *str, char sym);
int 	str_no_have_syms(char *str, char *syms);
int 	onsymofstr(char *str, const char *symbols);
int 	getsympos(char *str, const char *symbols);
char	get_first_found_symbol(char const *str, char const *symbols);
char	fstsym(char *str);
int		freenret(char **str, int ret);

char	*ft_strnstr(const char *str1, const char *str2, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
void    *ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		get_next_line(int fd, char **line);

void	error_call(char *message, int exit_code, t_gen **gen);
int		is_valid_name(char *name);
int		get_map(t_map **mpsrc, int map_file);
int		get_color(char *src, int **color_dst);
int		valid_src_file(char *file_name, int *file_fd);
int		wrongcloser(int tmpfd);
int		valid_map_data(t_map **map_source);
void	init_fnc(t_gen **gen);
int		get_color_ret(int const *color_dst);
int		wrong_pos(char **map, int y);
int		valid_map(t_gen **gen);
int		add_content_to_map_srcs(char *line, t_map **dst);
int		get_path(char *src, char **dst);

int		data_transform(t_gen **gen);
void	init_images(t_gen **gen);
int		create_trgb(int t, int r, int g, int b);

#endif