cmake_minimum_required(VERSION 3.20)
project(cube C)

set(CMAKE_C_STANDARD 99)

file(GLOB cub_SRC
        "*.h"
        "*.c"
        "reusable_fncs/get_next_line/*.h"
        "reusable_fncs/get_next_line/*.c"
        "reusable_fncs/libft_fncs/*.c"
        "reusable_fncs/libft_fncs/*.h"
        "reusable_fncs/*.c"
        "reusable_fncs/*.h"
        "pars_not_reus_fncs/*.c"
        "pars_not_reus_fncs/*.h"
        "render/*.c"
        "render/*.h"
        "utils/*.c"
        "utils/*.h"
        "world/*.c"
        "world/*.h"
        )

add_executable(cube ${cub_SRC})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux)

#target_link_libraries (cube ${EXTRA_LIBS} ${CMAKE_CURRENT_SOURCE_DIR}/mlx/libmlx.a)

target_link_libraries (cube ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx_Linux.a X11 Xext m)
