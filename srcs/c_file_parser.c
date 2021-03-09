#include "header_gen.h"

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

/*
** Function who format the prototype and print in the header
*/
int print_line_in_header(char *line, int fd)
{
	int i;

	i = 0;
    while (ft_isspace(line[i]) != 1)
    {
	    ft_putchar_fd(line[i], fd);
        i++;
    }
    if (ft_isspace(line[i]))
    {
        if (i <= 3)
            ft_putstr_fd("\t\t\t", fd);
        else
            ft_putstr_fd("\t\t", fd);
    }
    while (ft_isspace(line[i]))
        i++;
	ft_putstr_fd(&line[i], fd);
	if (line[ft_strlen(line) - 1] != ';')
		ft_putchar_fd(';', fd);
	ft_putchar_fd('\n', fd);
	return (0);
}

/*
** Check if the protype is "int main(...)"
*/
static int line_is_not_main(char *line)
{
	int i;

	i = 3;
	if (strncmp(line, "int", 3) != 0)
		return (0);
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (strncmp(&line[i], "main(", 5) == 0)
		return (1);
	return (0);
}

/*
** Parse the file and put all prototypes in linked list
*/
void parse_and_print(int fd_c, int fd_h, t_list **lst, char *file_name)
{
	char *line;

	while (get_next_line(fd_c, &line) == 1)
	{
		while (str_is_fct(line) == 1)
		{
			free(line);
			if (get_next_line(fd_c, &line) < 1)
			{
				free(line);
				return ;
			}
		}
		if ((line_is_not_main(line) == 0))
			ft_lstadd_back(lst, ft_lstnew(malloc_struct_proto(line, file_name)));
		free(line);
	}
}

t_prot *malloc_struct_proto(char *prototype, char *file_name)
{
	t_prot *new;

	new = malloc(sizeof(t_prot));
	if (new == NULL)
		return (NULL);
	new->prototype = ft_strdup(prototype);
	new->file_name = ft_strdup(file_name);
	return (new);
}