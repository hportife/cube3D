cmake_minimum_required(VERSION 3.20)
project(cube C)

set(CMAKE_C_STANDARD 99)

file(GLOB cub_SRC
        "*.h"
        "*.c"
        "get_next_line/*.h"
        "get_next_line/*.c"
        "libft_fncs/*.c"
        "libft_fncs/*.h"
#        "mlx/*.c"
#        "mlx/*.h"
        )

add_executable(cube ${cub_SRC} duarrotate.c)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/mlx)
#
#target_link_libraries (cube ${EXTRA_LIBS} ${CMAKE_CURRENT_SOURCE_DIR}/mlx/libmlx.a)