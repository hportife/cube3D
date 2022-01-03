#include "get_next_line.h"
#include "../main.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*check_rmd(char **remainder, char **line)
{
	char	*pointer_n;

	pointer_n = NULL;
	if (*remainder)
	{
		pointer_n = ft_strchr(*remainder, '\n');
		if (pointer_n)
		{
			*pointer_n = '\0';
			*line = ft_strdup(*remainder);
			ft_strcpy(*remainder, ++pointer_n);
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (pointer_n);
}

void	tmpst(char **line, char *buf)
{
	char		*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
}

char	*mallbuf(char **buf)
{
	*buf = malloc(sizeof(char) * 1 + 1);
	return (*buf);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	int			bread;
	char		*pointer_n;

	if (fd < 0 || !line || 1 <= 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!mallbuf(&buf))
		return (0);
	pointer_n = check_rmd(&remainder, line);
	bread = 1;
	while (!pointer_n && bread)
	{
		bread = read(fd, buf, 1);
		buf[bread] = '\0';
		pointer_n = ft_strchr(buf, '\n');
		if (pointer_n)
		{
			*pointer_n = '\0';
			remainder = ft_strdup(++pointer_n);
		}
		tmpst(line, buf);
	}
	free(buf);
	return (bread && remainder);
}
