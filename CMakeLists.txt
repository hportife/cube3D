cmake_minimum_required(VERSION 3.20)
project(cube C)

set(CMAKE_C_STANDARD 99)

add_executable(cube main.c
        duarrlen.c
        error_call.c
        nohavesym.c
        noonsym.c
        onsymofstr.c
        serv_fncs_I.c
        sne_noonsym.c
        str_no_have_syms.c
        valid_fncs.c
        getsympos.c
        libft_fncs/ft_strnstr.c
        libft_fncs/ft_isalnum.c
        get_next_line/get_next_line.c
        get_next_line/get_next_line_utils.c
        libft_fncs/ft_isalpha.c
        libft_fncs/ft_substr.c
        libft_fncs/ft_atoi.c
        stradd.c
        duarrfree.c
        fstsym.c
        duarrcalloc.c
        libft_fncs/ft_memset.c
        get_first_found_symbol.c)
