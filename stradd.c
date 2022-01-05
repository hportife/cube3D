#include "main.h"

char	**stradd(char *str, char **dst)
{
	int		i;
	char	**tmp;

	if (!str)
		return (0);
	i = 0;
	tmp = (char **)malloc(sizeof (char *) * (duarrlen(dst) + 2));
	if (!tmp)
		return (dst);
	while (dst && i < duarrlen(dst))
	{
		tmp[i] = ft_strdup(dst[i]);
		i++;
	}
	tmp[i++] = ft_strdup(str);
	tmp[i] = NULL;
	duarrfree(dst);
	return (tmp);
}