#include "main.h"

int	noonsym(char *str, char sym)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] != sym)
			return (1);
	return (0);
}