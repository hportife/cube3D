#include "main.h"

char	get_first_found_symbol(char const *str, char const *symbols)
{
	int		i;
	int		j;

	if (!str || !symbols)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (symbols[j])
		{
			if (symbols[j] == str[i])
				return (symbols[j]);
			j++;
		}
		i++;
	}
	return (0);
}
