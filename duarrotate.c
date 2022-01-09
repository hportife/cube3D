#include "main.h"

char **duarrotate(char **duarr)
{
	char	**tmp;
	int		i;
	int		j;

	if (!duarr || !duarr[0])
		return (0);
	tmp = (char **) malloc(sizeof (char *) * (ft_strlen(duarr[0]) + 1));
	if (!tmp)
		return (0);
	tmp[ft_strlen(duarr[0])] = NULL;
	i = 0;
	while (i < ft_strlen(duarr[0]))
		tmp[i++] = ft_calloc(sizeof (char), duarrlen(duarr));
	i = -1;
	while (duarr[++i])
	{
		j = -1;
		while (duarr[i][++j])
			tmp[j][i] = duarr[i][j];
	}
	return (tmp);
}