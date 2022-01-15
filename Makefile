NAME	= cube3D
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
SRC		= 	main.c\
			reusable_fncs/duarrcalloc.c\
			reusable_fncs/duarrfree.c\
			reusable_fncs/duarrlen.c\
			reusable_fncs/fstsym.c\
			reusable_fncs/getsympos.c\
			reusable_fncs/nohavesym.c\
			reusable_fncs/noonsym.c\
			reusable_fncs/onsymofstr.c\
			reusable_fncs/sne_noonsym.c\
			reusable_fncs/stradd.c\
			reusable_fncs/get_first_found_symbol.c\
			reusable_fncs/duarrotate.c\
			reusable_fncs/freenret.c\
			reusable_fncs/wrongcloser.c\
			reusable_fncs/str_no_have_syms.c\
			reusable_fncs/libft_fncs/ft_atoi.c\
			reusable_fncs/libft_fncs/ft_isalnum.c\
			reusable_fncs/libft_fncs/ft_isalpha.c\
			reusable_fncs/libft_fncs/ft_memset.c\
			reusable_fncs/libft_fncs/ft_strnstr.c\
			reusable_fncs/libft_fncs/ft_substr.c\
			reusable_fncs/libft_fncs/ft_strncmp.c\
			reusable_fncs/get_next_line/get_next_line.c\
			reusable_fncs/get_next_line/get_next_line_utils.c\
			world/cub_cardinal.c	world/cub_collide.c\
			world/cub_map.c			world/cub_player.c\
			utils/cub_cleaner.c		utils/cub_rot.c\
			utils/cub_keybinds.c	utils/cub_utils.c\
			utils/cub_utils2.c\
			utils/cub_utils4.c		utils/cub_vec.c\
			render/cub_floor.c		render/cub_hud.c\
			render/cub_raycast.c	render/cub_raycast2.c\
			render/cub_raycast3.c	render/update_world.c\
			pars_not_reus_fncs/error_call.c\
			pars_not_reus_fncs/serv_fncs_I.c\
			pars_not_reus_fncs/valid_fncs.c\
			pars_not_reus_fncs/init_data.c\



OBJ		= $(SRC:%.c=%.o)

OS := $(shell uname)
ifeq ($(OS),Linux)
	MINILIBX = -Lmlx_Linux -lmlx_Linux -Lminilibx-linux -Imlx_Linux -lXext -lX11 -lm -lz -g
	FLAGS += -Iminilibx-linux -Imlx_Linux -O3
else
	SO_LONG_IS_MACOS = 1
	MINILIBX = -Lmlx -lmlx -framework OpenGL -framework AppKit
	FLAGS += -Imlx
endif


.o: .c
	$(CC) $(FLAGS) $< -o $@

all: mlx-linux $(NAME)

$(NAME): $(OBJ) main.h
	$(CC) $(FLAGS) $(OBJ) $(MINILIBX) -o $@

mlx:
	make -C mlx/

mlx-linux:
	make -C minilibx-linux/

clean:
	make -C mlx/ clean
	make -C minilibx-linux/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f mlx/libmlx.a
	rm -f minilibx/libmlx_Linux.a
	rm -f $(NAME)

re: fclean all
.PHONY: all re clean fclean mlx
