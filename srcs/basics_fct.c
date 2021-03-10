#include "header_gen.h"

/*
** Print all the prototype in the list to the header
*/
void print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h)
{
	char *proto;
	char *file_name;

	if (!lst)
		return ;
    if (args.f_opt == 1)
		file_name = execute_f_opt(lst, fd_h);
    while (lst)
	{
		if (args.f_opt == 1 && f_opt_compare(file_name, lst) == 1)
			file_name = execute_f_opt(lst, fd_h);
		proto = ((t_prot *)(lst->content))->prototype;
		print_line_in_header(proto, fd_h);
		if (args.v_opt == 1)
			ft_printf("%s\n", proto);
		if (args.c_opt == 1)
			opt->count++;
		lst = lst->next;
	}
    ft_putstr_fd("\n#endif", fd_h);
}


/*
** Open all .c files, and put the prototype in linked list 
*/
int add_line_in_list(t_args args, t_list **lst)
{
    int fd_c;
	int empty_file;
    int i;
    int a;

	empty_file = 0;
    i = 0;
    a = 1;
    if (args.a_opt == 1)
        a = 2;
    while (i < (args.argcount - a))
	{
	    while (check_access_c(args.argvalue[i]) == -1)
		    i++;
	    if((fd_c = open(args.argvalue[i], O_RDONLY)) == -1)
		    return (-1);
	    if (parse_and_put_list(fd_c, lst, args.argvalue[i]) == -1)
		{
			empty_file++;
			ft_printf("No prototype found in %s.\n", args.argvalue[i]);
			if (empty_file == (args.argcount - a))
			{
				ft_printf("No file contains prototypes. Abort.\n");
				return (-1);
			}
		}
	    close(fd_c);
	    i++;
    }
    return (0);
}
