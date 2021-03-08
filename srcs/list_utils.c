#include "header_gen.h"

void print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h)
{
    while (lst)
	{
		print_line_in_header(lst->content, fd_h);
		if (args.p_opt == 1)
			printf("%s\n", lst->content);
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
