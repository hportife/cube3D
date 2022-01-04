#include "main.h"

char	**stradd(char *str, char **dst)
{
	int		i;
	char	**tmp;

	if (!str)
		return (0);
	i = 0;
	tmp = (char **)malloc(sizeof (char *) * duarrlen(dst) + 2);
	if (!tmp)
		return (NULL);
	if (dst)
	{
		while (dst[i])
		{
			tmp[i] = ft_strdup(dst[i]);
			i++;
		}

	}
	tmp[duarrlen(dst)] = ft_strdup(str);
	tmp[duarrlen(dst) + 1] = NULL;
	if (dst)//в какой-то момент заскакивает сюда и пытается зафришить то что не было замаллочено
		dst = duarrfree(dst);
	return (tmp);
}