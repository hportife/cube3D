#ifndef MAIN_H
#define MAIN_H

typedef struct s_map
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *SA;
    char    **map;
}   t_map;

typedef struct s_gen
{
    int     src_file;
    t_map   *map_srcs;
}   t_gen;

void    error_call(char *message, int exit_code, t_gen *gen);
int     is_valid_name(char *name);
int     noonsym(char *str, char sym);//проверка наличия в строне не единственного символа во всей строке
int     duarrlen(char **array);//поиск длинны двумерного массива
int 	sne_noonsym(char *str, char sym);//проверка наличия единственного символа в начале и конце строки
int     str_no_have_syms(char *str, char *syms);//проверка наличия в строке только символов имеющихся в syms
int     nohavesm(char *str, char sym);//проверка наличия в строке символа

#endif