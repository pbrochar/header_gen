#include "header_gen.h"

/*
** Print all the prototype in the list to the header
*/
void print_list_in_header(t_args args, t_hgen *opt, t_list *lst, int fd_h)
{
	char *proto;
	char *file_name;

    if (args.f_opt == 1)
    {
        file_name = ((t_prot *)(lst->content))->file_name;
        print_file_name(file_name, fd_h);
    }
    while (lst)
	{
		if (args.f_opt == 1 && ft_strncmp(file_name, ((t_prot *)(lst->content))->file_name, ft_strlen(file_name)) != 0)
		{
			file_name = ((t_prot *)(lst->content))->file_name;
			print_file_name(file_name, fd_h);		
		}
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
int add_line_in_list(t_args args, int fd_h, t_list **lst)
{
    int fd_c;
    int i;
    int a;

    i = 0;
    a = 1;
    if (args.a_opt == 1)
        a = 2;
    while (i < (args.argcount - a))
	{
	    if (check_access_c(args.argvalue[i]) == -1)
		    i++;
	    if((fd_c = open(args.argvalue[i], O_RDONLY)) == -1)
		    return (1);
	    parse_and_put_list(fd_c, fd_h, lst, args.argvalue[i]);
	    close(fd_c);
	    i++;
    }
    return (0);
}
