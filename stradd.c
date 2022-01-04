#include "main.h"

char	**stradd(char *str, char **dst)
{
	int		i;
	char	**tmp;

	if (!str)
		return (0);
	i = 0;
	tmp = (char **)(sizeof (char *) * duarrlen(dst) + 2);
	if (!tmp)
		return (NULL);
	tmp[duarrlen(dst) + 1] = NULL;
	tmp[duarrlen(dst)] = ft_strdup(str);
	while (dst[i])
	{
		tmp[i] = ft_strdup(dst[i]);
		i++;
	}
	dst = duarrfree(dst);
	return (tmp);
}