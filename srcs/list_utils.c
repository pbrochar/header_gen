#include "header_gen.h"

static void print_a_opt(t_args args, t_hgen *opt, int fd_h)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(opt->fd_header, &line);
	while (ft_strncmp(line, "# define", 8) != 0 && ret == 1)
	{
		free(line);
		ret = get_next_line(opt->fd_header, &line);
	}
	free(line);
	ret = get_next_line(opt->fd_header, &line);
	while (ft_strncmp(line, "#endif", 6) != 0 && ret == 1)
	{
		ft_putstr_fd(line, fd_h);
		if (line[0] != '\n')
			ft_putchar_fd('\n', fd_h);
		free(line);
		ret = get_next_line(opt->fd_header, &line);
	}
	free(line);
	close(opt->fd_header);
}

void print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h)
{
	if (args.a_opt == 1)
		print_a_opt(args, opt, fd_h);
    while (lst)
	{
		print_line_in_header(lst->content, fd_h);
		if (args.p_opt == 1)
			ft_printf("%s\n", lst->content);
		if (args.c_opt == 1)
			opt->count++;
		lst = lst->next;
	}
}

int add_line_in_list(t_args args, int fd_h, t_list **lst)
{
    int fd_c;
    int i;

    i = 0;
    while (i < (args.argcount - 1))
	{
	    if (check_access_c(args.argvalue[i]) == -1)
		    i++;
	    if((fd_c = open(args.argvalue[i], O_RDONLY)) == -1)
		    return (1);
	    parse_and_print(fd_c, fd_h, lst);
	    close(fd_c);
	    i++;
    }
    return (0);
}

void		rem_lst(t_list **lst)
{
	t_list	*prev;

	while (*lst != NULL)
	{
		prev = *lst;
		*lst = (*lst)->next;
		free(prev->content);
		free(prev);
	}
}
