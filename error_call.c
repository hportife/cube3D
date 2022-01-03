#include "main.h"

void	free_general(t_gen *gen)
{
	int	i;

	if (gen->src_file > 0)
		close(gen->src_file);
	if (gen->map_srcs)
	{
		if (gen->map_srcs->NO)
			free(gen->map_srcs->NO);
		if (gen->map_srcs->SO)
			free(gen->map_srcs->SO);
		if (gen->map_srcs->WE)
			free(gen->map_srcs->WE);
		if (gen->map_srcs->SA)
			free(gen->map_srcs->SA);
		if (gen->map_srcs->map)
		{
			i = 0;
			while (gen->map_srcs->map[i])
				free(gen->map_srcs->map[i++]);
			free(gen->map_srcs->map);
		}
	}
}

void    error_call(char *message, int exit_code, t_gen *gen)
{
    if (gen)
        free_general(gen);
    printf("%s\n", message);
    exit (exit_code);
}