#include "main.h"

int valid_src_file(char *file_name, int *file_fd)
{
    if (!(ft_strchr(file_name, '.')))
        return (1);
    
}