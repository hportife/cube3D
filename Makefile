NAME	= cube3D
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS)
FRMWK	= -framework OpenGL -framework AppKit
SRC		= 	main.c\
			duarrcalloc.c	duarrfree.c	duarrlen.c\
			error_call.c	fstsym.c	getsympos.c\
			nohavesym.c		noonsym.c	onsymofstr.c\
			serv_fncs_I.c	sne_noonsym.c	stradd.c\
			str_no_have_syms.c	valid_fncs.c\
			get_first_found_symbol.c	duarrotate.c\
			libft_fncs/ft_atoi.c\
			libft_fncs/ft_isalnum.c\
			libft_fncs/ft_isalpha.c\
			libft_fncs/ft_memset.c\
			libft_fncs/ft_strnstr.c\
			libft_fncs/ft_substr.c\
			libft_fncs/ft_strncmp.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\


OBJ		= $(SRC:%.c=%.o)

.o: .c
	$(CC) $(CFLAGS) -Imlx $< -o $@

all: mlx $(NAME)

$(NAME): $(OBJ) main.h
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx $(FRMWK) -o $@

mlx:
	make -C mlx/

clean:
	make -C mlx/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f mlx/libmlx.a
	rm -f $(NAME)

re: fclean all
.PHONY: all re clean fclean mlx
# all :
# 	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 -Lmlx -lmlx -framework OpenGL -framework AppKit main.c mlx/libmlx.a in_game.c servfnc_SL.c so_long.h gnl/get_next_line.h gnl/get_next_line.c gnl/get_next_line_utils.c
