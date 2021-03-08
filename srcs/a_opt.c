#include "header_gen.h"

/*
** Try to open file.h
** If success, put the file descriptor in opt struct
*/
int open_fd_header_exist(t_args args, t_hgen *opt)
{
    if ((opt->fd_header = open(args.argvalue[args.argcount - 2], O_RDONLY)) == -1)
    {
        ft_printf("Can't open %s\n", args.argvalue[args.argcount - 2]);
        return (-1);
    }
    return (0);
}

void print_a_opt(t_args args, t_hgen *opt, int fd_h)
{
	char	*line;
	int		ret;

	line = NULL;
    get_next_line(opt->fd_header, &line);
    while (ft_strncmp(line, "# define", 8) != 0)
    {
        free(line);
        get_next_line(opt->fd_header, &line);
    }
    free(line);
    get_next_line(opt->fd_header, &line);
	while (ft_strncmp(line, "#endif", 6) != 0)
    {
        if (str_is_fct(line) == 0)
            header_lstadd_back(&(opt->lst_a_opt), header_lstnew(ft_strdup(line), ft_strdup(args.argvalue[args.argcount - 2])));
        else
        {
            ft_putstr_fd(line, fd_h);
            ft_putchar_fd('\n', fd_h);
        }
        free(line);
        get_next_line(opt->fd_header, &line);
    }
    free(line);
	close(opt->fd_header);
    if (args.s_opt == 1)
        sort_ascii_list(&(opt->lst_a_opt));
    ft_putstr_fd("/*\n**\tfrom ", fd_h);
    ft_putstr_fd(args.argvalue[args.argcount - 2], fd_h);
    ft_putstr_fd("\n*/\n", fd_h);
    while(opt->lst_a_opt)
    {
        print_line_in_header(opt->lst_a_opt->content, fd_h);
        opt->lst_a_opt = opt->lst_a_opt->next;
    }
    rem_lst(&(opt->lst_a_opt));
}