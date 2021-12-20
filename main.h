#ifndef MAIN_H
#define MAIN_H

typedef struct s_gen
{
    int src_file;
}   t_gen;

void    error_call(char *message, int exit_code, t_gen *gen);
int     is_valid_name(char *name);


#endif