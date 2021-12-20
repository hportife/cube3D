#include "main.h"

int main(int argc, char *argv[])
{
	t_gen	gen;
	
	if (argc != 2)
		error_call("Error:\nno map specified.\n", 1, &gen);
	gen = malloc(sizeof(t_gen));
	if (valid_src_file(argv[1], gen.src_file))
		error_call("Error:\nwrong map name.\n", 1, &gen);
	return (0);
}
