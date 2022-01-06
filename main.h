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
	int		*width;
	int		*height;
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

void	error_call(char *message, int exit_code, t_gen **gen);
int		is_valid_name(char *name);
int		noonsym(char *str, char sym);//проверка наличия в строне не единственного символа во всей строке
int		duarrlen(char **array);//поиск длинны двумерного массива
int 	sne_noonsym(char *str, char sym);//проверка наличия единственного символа в начале и конце строки
int 	str_no_have_syms(char *str, char *syms);//проверка наличия в строке только символов имеющихся в syms
int 	nohavesm(char *str, char sym);//проверка наличия в строке символа
int 	onsymofstr(char *str, const char *symbols);//возвращает количество появлений символов из строки symbols в строке str
int 	getsympos(char *str, const char *symbols);//возвращает положение первого имеющегося из символов symbols в строке str
char	get_first_found_symbol(char const *str, char const *symbols);//поиск первого совпадающего символа из symbols в строке str
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		get_map(t_map **mpsrc, int map_file);
int		valid_src_file(char *file_name, int *file_fd);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
void	init_fnc(t_gen **gen);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);//тупо атои
char	fstsym(char *str);//поиск первого не табуляционного символа в строке
char	**duarrfree(char **arr);//отчистка двумерного массива
char	**stradd(char *str, char **dst);//добавление строки в двумерный массив
void    *ft_calloc(size_t count, size_t size);
char	**duarrcalloc(int size);//"calloc" для двумерного массива
void	*ft_memset(void *b, int c, size_t len);
int		get_color_ret(int const *color_dst);
int		data_transform(t_gen **gen);
void	init_images(t_gen **gen);


#endif
