#include "main.h"

int main(int argc, char *argv[])
{
	t_gen	gen;
	
	if (argc != 2)
		error_call("Error:\nno map specified.\n", 1);
	gen = malloc(sizeof(t_gen));
	gen.src_file = open(argv[1], O_RDONLY);
	if (gen.src_file == -1)
		error_call()
	return (0);
}
