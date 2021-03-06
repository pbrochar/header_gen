#include "header_gen.h"

/*
** Print the header's name
** Uppercase letters
** NAME_H
*/
static void print_header_name(int fd, char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		if (name[i] >= 97 && name[i] <= 122)
			ft_putchar_fd(name[i] - 32, fd);
		else if (name[i] == '.')
			ft_putchar_fd('_', fd);
		else
			ft_putchar_fd(name[i], fd);
		i++;
	}
}

/*
** Create header file with O_CREAT, with Read and Write permission (O_RDWR)
** Return the file descriptor of the new file
*/
int create_header_file(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_CREAT | O_RDWR, 0777)) == -1)
	{
		ft_printf("Can't create file\n");
		return (-1);
	}
	return (fd);
}

/*
** Print in header : "#ifndef" and "# define"
*/
int print_header_base(int fd, char *name)
{
	ft_putstr_fd("#ifndef ", fd);
	print_header_name(fd, name);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("# define ", fd);
	print_header_name(fd, name);
	ft_putstr_fd("\n\n", fd);
	return (0);
}
