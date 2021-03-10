#include "header_gen.h"

/*
** Check if the file's extension is the good one (.c or .h)
*/
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

/*
** Check if args are the good files with their extensions
*/
int check_args(t_args args)
{
    int i;
	int a;

    i = 0;
	a = 1;
	if (args.a_opt == 1)
		a = 2;
    while (i < (args.argcount - a))
	{
        if (check_ext(args.argvalue[i], ".c") == 0)
	    {
		    ft_printf("%s is not a valid file.\n", args.argvalue[i]);
		    return (-1);
	    }
        i++;
    }
	if (args.a_opt == 1) 
	{
		if ((access(args.argvalue[i], F_OK) || check_ext(args.argvalue[i], ".h") == 0))
		{
			ft_printf("Can't access to %s\n", args.argvalue[i]);
			return (-1);
		}
		i++;
	}
	if (check_ext(args.argvalue[i], ".h") == 0)
	{
		ft_printf("last arg need to be a .h file's name\n");
		return (-1);
	}
	return (0);
}

/*
** Check if header file exist, and if not create with base.
** Base = "#ifndef NAME_H" "# define NAME_H"
*/
int check_access_and_create(t_args args)
{
    int fd_h;

	if (access(args.argvalue[args.argcount - 1], F_OK) != 0)
	{
		fd_h = create_header_file(args.argvalue[args.argcount - 1]);
		if (fd_h == -1)
			return (-1);
		print_header_base(fd_h, args.argvalue[args.argcount - 1]);
        return (fd_h);
    }
	else
		ft_printf("%s already exit\n", args.argvalue[args.argcount - 1]);
    return (-1);
}

/*
** Function who check if prog can access to file
*/
int check_access_c(char *argv)
{
	if (access(argv, F_OK) != 0)
		return (-1);
	return (0);
}

int check_c_files(t_args args)
{
	int i;
	int a;

	i = 0;
	a = 1;
	if (args.a_opt == 1)
        a = 2;
	while (i < (args.argcount - a))
	{
	    if (check_access_c(args.argvalue[i]) == -1)
		{
			ft_printf("Can't access to %s\n", args.argvalue[i]);
			if (i == (args.argcount - a) - 1)
			{
				ft_printf("No access to source files. Abort.\n");
				return (-1);
			}
		}
		i++;
	}
	return (0);
}