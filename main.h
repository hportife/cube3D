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
# include <math.h>
# include <stdbool.h>

# include "reusable_fncs/get_next_line/get_next_line.h"
# include "mlx/mlx.h"

# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define FORWARD_W_Z 13
# define BACK_S_S 1
# define RIGHT_D_D 2
# define LEFT_A_Q 0
# define ESC 53

typedef enum e_cardinal
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_cardinal;

typedef struct s_vec {
	int			x;
	int			y;
}				t_vec;

typedef struct s_vecd {
	double		x;
	double		y;
}				t_vecd;

typedef struct s_keybinds
{
	bool			forwards;
	bool			backwards;
	bool			left;
	bool			right;
	bool			rotate_left;
	bool			rotate_right;
	t_vecd			move;
}					t_keybinds;

typedef struct s_player
{
	t_vecd			pos;
	t_vecd			s_pos;
	t_vecd			render;
	t_vecd			motion;
	t_keybinds		keybinds;
	double			yaw;
	double			pitch;
	double			motion_yaw;
	double			motion_pitch;
}					t_player;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*fc;
	int		*cc;
	char	**map;
	t_vec	size;
}	t_map;

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			pixel_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_shape
{
	int			x;
	int			y;
	int			height;
	t_img		*img;
}				t_shape;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	int		f_color;
	int		c_color;
}	t_data;

typedef struct s_gen
{
	int			src_file;
	t_map		*map_srcs;
	t_data		*data;
	t_img		img;
	t_player	player;
	int			unit_x_pos;
	int			unit_y_pos;
	char		unit_type;
	double		resx;
	double		resy;
	double		fov;
}	t_gen;

typedef struct s_rot
{
	double	angle;
	double	cos;
	double	sin;
}			t_rot;

typedef struct s_ray {
	t_vecd		st_cos;
	t_vecd		st_sin;
	double		ln_cos;
	double		ln_sin;
}				t_ray;

typedef struct s_trace {
	t_ray		ray;
	t_ray		step;
	t_rot		rot;
	t_shape		line;
	t_vec		pos;
	t_vecd		ref;
	t_cardinal	card;
	int			i;
	double		newa;
	double		len;
	double		offset;
}				t_trace;

void		free_general(t_gen **gen);
int			get_pixel(t_img *data, int x, int y);
t_img		make_image(void *mlx, int w, int h);
t_img		load_image(void *mlx, char *path);
void		set_img_strip(t_img *data, t_shape shape, float offset);
void		fill_img(t_img img, int c, int start, int stop);

t_rot		make_rot(double angle);

void		parse_data(t_gen **gen, char *file);

int			noonsym(char *str, char sym);
int			duarrlen(char **array);
char		**duarrfree(char **arr);
char		**duarrcalloc(int size);
char		**duarrotate(char **duarr);
char		**stradd(char *str, char **dst);
int			sne_noonsym(char *str, char sym);
int			nohavesm(char *str, char sym);
int			str_no_have_syms(char *str, char *syms);
int			onsymofstr(char *str, const char *symbols);
int			getsympos(char *str, const char *symbols);
char		get_first_found_symbol(char const *str, char const *symbols);
char		fstsym(char *str);
int			freenret(char **str, int ret);

char		*ft_strnstr(const char *str1, const char *str2, size_t len);

int			ft_isalnum(int c);
int			ft_isalpha(int c);

char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_atoi(const char *str);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		error_call(char *message, int exit_code, t_gen **gen);
int			have_connect(char *str1, char *str2);
int			is_valid_name(char *name);
int			get_map(t_map **mpsrc, int map_file);
int			get_color(char *src, int **color_dst);
int			valid_src_file(char *file_name, int *file_fd);
int			wrongcloser(int tmpfd);
int			valid_map_data(t_map **map_source);
void		init_fnc(t_gen **gen);
int			get_color_ret(int const *color_dst);
int			wrong_pos(char **map, int y);
int			valid_map(t_gen **gen);
int			add_content_to_map_srcs(char *line, t_map **dst);
int			get_path(char *src, char **dst);
int			data_transform(t_gen **gen);
void		init_images(t_gen **gen);
int			create_trgb(int t, int r, int g, int b);
void		ray(t_gen *gen, t_img *img);
t_vec		get_collide_pos(t_trace trace);
int			check_collide(t_gen *gen, t_vec pos);
t_ray		get_init_ray(t_rot *rot, double x, double y);
void		cast_forward(t_ray *ray, t_ray step);
t_img		*get_texture(t_gen *gen, t_cardinal card);
void		destroy_img(t_gen *gen, t_img *img);
void		clean_images(t_gen *gen);
void		clean_and_exit(int code, t_gen *gen);
int			clean_and_exit_z(t_gen *gen);
int			mlx_destroy_display(void *mlx_ptr);
void		set_keystate(t_keybinds *keybinds, int key, bool pressed);
int			key_press(int keycode, t_gen *gen);
int			key_lift(int keycode, t_gen *gen);
void		update_keybinds(t_gen *gen);
t_keybinds	make_keybinds(void);
int			map_get(t_map *map, int x, int y);
void		collidex(t_gen *gen, t_player *player);
void		collidey(t_gen *gen, t_player *player);

t_player	make_player(void);
void		update_motion(t_player *player, t_gen *gen);
void		draw_floor(t_gen *gen);
void		draw_skybox(t_gen *gen);

t_cardinal	get_cardinal(t_trace trace);

void		normalize(t_vecd *vec, double scale);
double		calc_sqrtlen(t_vecd v);
int			set_player(t_gen *gen, char c, t_vec p);
int			render_next_frame(t_gen *gen);
void		setup_render(t_gen *gen);

#endif