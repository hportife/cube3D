#include "main.h"

int main(int argc, char *argv[])
{
	t_gen	gen;
	
	if (argc != 2)
		error_call("Error:\nno map specified.\n", 1, &gen);
	gen = malloc(sizeof(t_gen));
	if (valid_src_file(argv[1], gen.src_file))
		error_call("Error:\nwrong map name.\n", 1, &gen);
	if (!get_map(gen.map_srcs, map.src_file))
		error_call("Error:\nincorrect content of the source file.\n", 1, &gen);
	return (0);
}

char	*skip_tabulation(char *src)
{
	int	i;

	i = 0;
	while (src[i] == " " || src[i] == "\t")
		i++;
	return (*src[i]);
}

char	*get_data(char *src)
{

}

int	add_content_to_map_srcs(char *line, t_map **dst)
{
	if (!line)
		return (1);
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		dst->NO = ft_strdup(skip_tabulation(ft_strnstr(line, "NO", ft_strlen(line))));
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		dst->NO = ft_strdup(skip_tabulation(ft_strnstr(line, "SO", ft_strlen(line))));
	return (0);
}

int	get_map(t_map **mpsrc, int map_file)
{
	char	*tmp;
	int		read_ident

	read_ident = get_next_line(map_file, tmp);
	while (read_ident != 0) // пока наш файл не закончился
	{
		if (read_ident == -1) // если сфайлом беда
			return (0);
		if (add_content_to_map_srcs()) //если какая-то из строк нас не устраивает при чтении, ретёрнаем завершение программы
			return (0);
		read_ident = get_next_line(map_file, tmp); // продолжаем считывание с файла
	}

	//сюда нужно добавить проверки корректности всех полученных из файла данных
}