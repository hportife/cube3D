#include "../main.h"

int	sne_noonsym(char *str, char sym)
{
    if ((!str) || (str[0] != sym) || (str[ft_strlen(str) - 1] != sym))
        return (1);
    return (0);
}