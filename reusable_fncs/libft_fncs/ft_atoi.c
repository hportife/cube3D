#include "../../main.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				j;
	long			k;

	i = 0;
	j = 1;
	k = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (k * j);
}
