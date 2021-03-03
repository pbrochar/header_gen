#include "header_gen.h"

int check_ext(const char *file_name, const char *ext)
{
	int		i;
	size_t	file_name_len;
	size_t	ext_len;
	char	*file_ext;

	file_name_len = ft_strlen(file_name);
	ext_len = ft_strlen(ext);
	file_ext = ft_strnstr(file_name, ext, file_name_len);
	if (file_ext != NULL)
		if (ft_strnstr(file_ext, ext, ext_len))
		    return (1);
	return (0); 
}

int check_args(int argc, char **argv)
{
    int i;

    i = 1;
	if (argc < 3)
	{
		ft_printf("Open a .c file\n");
		return (-1);
	}
    while (i < argc -1)
	{
        if (check_ext(argv[i], ".c") == 0)
	    {
		    ft_printf("%s is not a valid file.\n", argv);
		    return (-1);
	    }
        i++;
    }
    if (check_ext(argv[i], ".h") == 0)
    {
        ft_printf("last arg need to be a .h file's name\n");
        return (-1);
    }
	return (0);
}

int check_access_and_create(int argc, char **argv)
{
    int fd_h;

	if (access(argv[argc - 1], F_OK) != 0)
	{
		fd_h = create_header_file(argv[argc -1]);
		if (fd_h == -1)
			return (-1);
		print_header_base(fd_h, argv[argc -1]);
        return (fd_h);
    }
	else
		ft_printf("%s already exit\n", argv[argc -1]);
    return (-1);
}

int check_access_c(char *argv)
{
	if (access(argv, F_OK) != 0)
	{
		ft_printf("Can't access to %s\n", argv);
		return (-1);
	}
	return (0);
}