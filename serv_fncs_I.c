#include "main.h"

int is_valid_name(char *name)
{
    if (!name)
        return (0);
    if (ft_strncmp(".cub", &name[ft_strlen(name) - 4], 4))
		return (1);
    return (0);
}