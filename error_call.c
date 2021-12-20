#include "main.h"

void    error_call(char *message, int exit_code, t_gen *gen)
{
    if (gen)
        free_general(gen);
    printf("%s\n", message);
    exit (exit_code);
}