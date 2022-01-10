#include <stdlib.h>
#include "main.h"


int	freenret(char **str, int ret)
{
	if (str[0])
		free(str[0]);
	return (ret);
}