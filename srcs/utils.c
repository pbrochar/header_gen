#include "header_gen.h"

/* 
** Check if char is space
*/
int ft_isspace(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    return (0);
}

int	ft_compare(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/*
** Print the file's name.
** Use for f opt.
*/
void print_file_name(char *name, int fd)
{
	ft_putstr_fd("\n/*\n** from ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("\n*/\n", fd);
}

/*
** Check if string is a function
*/
int str_is_fct(char *line)
{
	int i;

	i = 0;
	if (ft_isspace(line[0]) || line[0] == '{' || !ft_isalpha(line[0]))
		return (1);
	while (line[i] != '(' && line[i])
		i++;
	if (!line[i])
		return (1);
	while (line[i] != ')' && line[i])
		i++;
	if (!line[i])
		return (1);
	if (ft_strncmp(line, "static", 6) == 0 || ft_strncmp(line, "typedef", 7) == 0)
		return (1);
	return (0);
}