#include "main.h"

void	free_general(t_gen **gen)
{
	int	i;

	if ((*gen)->src_file > 0)
		close((*gen)->src_file);
	if ((*gen)->map_srcs)
	{
		if ((*gen)->map_srcs->no)
			free((*gen)->map_srcs->no);
		if ((*gen)->map_srcs->so)
			free((*gen)->map_srcs->so);
		if ((*gen)->map_srcs->we)
			free((*gen)->map_srcs->we);
		if ((*gen)->map_srcs->ea)
			free((*gen)->map_srcs->ea);
		if ((*gen)->map_srcs->map)
		{
			i = 0;
			while ((*gen)->map_srcs->map[i])
				free((*gen)->map_srcs->map[i++]);
			free((*gen)->map_srcs->map);
		}
		free((*gen)->map_srcs);
	}
	free((*gen));
}

void    error_call(char *message, int exit_code, t_gen **gen)
{
    if (gen)
        free_general(gen);
    printf("%s\n", message);
    exit (exit_code);
}