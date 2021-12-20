#include "main.h"

void    error_call(char *message, int exit_code)
{
    printf("%s\n", message);
    exit (exit_code);
}