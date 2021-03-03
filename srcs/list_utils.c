#include "header_gen.h"

void print_list_in_header(t_list *lst, int fd_h)
{
    while (lst)
	{
		print_line_in_header(lst->content, fd_h);
		lst = lst->next;
	}
}

int add_line_in_list(char **argv, int argc, int fd_h, t_list **lst)
{
    int fd_c;
    int i;

    i = 1;
    while (i < (argc - 1))
	{
	    if (check_access_c(argv[i]) == -1)
		    i++;
	    if((fd_c = open(argv[i], O_RDONLY)) == -1)
		    return (1);
	    parse_and_print(fd_c, fd_h, lst);
	    close(fd_c);
	    i++;
    }
    return (0);
}

void		rem_lst(t_list **lst)
{
	t_list	*temp;
	t_list	*prev;

	temp = *lst;
	prev = NULL;
	while (temp)
	{

		if (prev)
			prev->next = temp->next;
		else
			*lst = temp->next;
		free(temp->content);
		free(temp);
		prev = temp;
		temp = temp->next;
	}
}