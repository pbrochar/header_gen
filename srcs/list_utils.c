#include "header_gen.h"

void print_file_name(char *name, int fd)
{
	ft_putstr_fd("\n/*\n**\tfrom ", fd);
    ft_putstr_fd(name, fd);
    ft_putstr_fd("\n*/\n", fd);
}
/*
** Print all the prototype in the list to the header
*/
void print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h)
{
	char *proto;
	char *file_name;

	file_name = ((t_prot *)(lst->content))->file_name;
	if (args.a_opt == 1)
		print_a_opt(args, opt, fd_h);
	print_file_name(file_name, fd_h);
    while (lst)
	{
		if (ft_strncmp(file_name, ((t_prot *)(lst->content))->file_name, ft_strlen(file_name)) != 0)
			print_file_name(file_name, fd_h);
		proto = ((t_prot *)(lst->content))->prototype;
		print_line_in_header(proto, fd_h);
		if (args.v_opt == 1)
			ft_printf("%s\n", proto);
		if (args.c_opt == 1)
			opt->count++;
		file_name = ((t_prot *)(lst->content))->file_name;
		lst = lst->next;
	}
}

/*
** Open all .c files, and put the prototype in linked list 
*/
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
	    parse_and_print(fd_c, fd_h, lst, args.argvalue[i]);
	    close(fd_c);
	    i++;
    }
    return (0);
}

/*
** Free the list and content
*/
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