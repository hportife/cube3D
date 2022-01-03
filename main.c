#include "main.h"

int main(int argc, char *argv[])
{
	t_gen	*gen;
	
	if (argc != 2)
		error_call("Error:\nno map specified.\n", 1, NULL);
	init_fnc(&gen);
	if (valid_src_file(argv[1], &gen->src_file))
		error_call("Error:\nwrong map name.\n", 1, &gen);
	if (!get_map(&gen->map_srcs, gen->src_file))
		error_call("Error:\nincorrect content of the source file.\n", 1, &gen);
//	while (1);
	error_call("", 0, &gen);//утекает использование ГНЛа, нужно будет создать временную переменную для его использования и перед каждым новым использованием её фришить
}

void	init_fnc(t_gen **gen)
{
	(*gen) = (t_gen *)malloc(sizeof(t_gen));
	(*gen)->map_srcs = (t_map *)malloc(sizeof (t_map));
	(*gen)->map_srcs->NO = NULL;
	(*gen)->map_srcs->EA = NULL;
	(*gen)->map_srcs->SO = NULL;
	(*gen)->map_srcs->WE = NULL;
	(*gen)->map_srcs->map = NULL;
}

char	*skip_tabulation(char *src)
{
	int	i;

	i = 0;
	while (src[i] == ' ' || src[i] == '\t')
		i++;
	return (&src[i]);
}

//char	*get_data(char *src)
//{
//
//}

int	get_path(char *src, char **dst)
{
	int	i;
	int	j;

	i = 2;
	if (*dst)
	{
		free(*dst);
		*dst = NULL;
	}
	while (!ft_isalpha(src[i]))
		i++;
	j = i;
	while (ft_isalnum(src[i]) || src[i] == '/' || src[i] == '_' || src[i] == '.')
		i++;
	(*dst) = ft_substr(src, j, i - j);
	return (0);
}

int	valid_map_data()
{

}

int	add_content_to_map_srcs(char *line, t_map **dst)
{
	if (!line)
		return (1);
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		get_path(ft_strnstr(line, "NO", ft_strlen(line)), &(*dst)->NO);
	if (ft_strnstr(line, "SO", ft_strlen(line)))
		get_path(ft_strnstr(line, "SO", ft_strlen(line)), &(*dst)->SO);
	if (ft_strnstr(line, "WE", ft_strlen(line)))
		get_path(ft_strnstr(line, "WE", ft_strlen(line)), &(*dst)->WE);
	if (ft_strnstr(line, "EA", ft_strlen(line)))
		get_path(ft_strnstr(line, "EA", ft_strlen(line)), &(*dst)->EA);
//	if (ft_strnstr(line, "F", ft_strlen(line)) || ft_strnstr(line, "C", ft_strlen(line)))
//		get_color();
	return (vaild_map_data());
}

int	get_map(t_map **mpsrc, int map_file)
{
	char	*tmp;
	int		read_ident;

	read_ident = get_next_line(map_file, &tmp);
	while (read_ident != 0) // пока наш файл не закончился
	{
		if (read_ident == -1) // если сфайлом беда
			return (0);
		if (add_content_to_map_srcs(tmp, mpsrc)) //если какая-то из строк нас не устраивает при чтении, ретёрнаем завершение программы
			return (0);
		read_ident = get_next_line(map_file, &tmp); // продолжаем считывание с файла
	}
	return (1);
	//сюда нужно добавить проверки корректности всех полученных из файла данных
}