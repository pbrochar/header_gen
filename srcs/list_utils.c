#include "header_gen.h"


/*
** Swap two t_prot *
** Use for ASCII sort
*/
static void	ft_lstswap(t_list **prot1, t_list **prot2)
{
    void *c;

	c = (*prot1)->content;
    (*prot1)->content = (*prot2)->content;
    (*prot2)->content = c;
}

/*
** Sort linked list's elements in ascii order
*/
void sort_ascii_list(t_list **lst)
{
    t_list *temp;
    t_list *temp2;
    char *proto;
    char *proto2;

    temp = *lst;
    while(temp)
    { 
        temp2 = temp->next;
        while (temp2)
        {
            if (ft_compare(((t_prot *)temp->content)->prototype, ((t_prot *)temp2->content)->prototype) > 0)
            {
                if (ft_compare(((t_prot *)temp->content)->file_name, ((t_prot *)temp2->content)->file_name) == 0)
                    ft_lstswap(&temp, &temp2);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

/*
** Malloc a struct for linked list who contain the prototype and file's name.
*/
t_prot *malloc_struct_proto(char *prototype, char *file_name)
{
	t_prot *new;

	new = malloc(sizeof(t_prot));
	if (new == NULL)
    {
        ft_printf("Problem with dynamic memory allocation. The behavior of the program is unpredictable.\n");
		return (NULL);
    }
	new->prototype = ft_strdup(prototype);
	new->file_name = ft_strdup(file_name);
	return (new);
}

/*
** Free the list and content
*/
void		rem_lst(t_list **lst)
{
	t_list	*prev;

    prev = *lst;
	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		free(((t_prot *)prev->content)->file_name);
		free(((t_prot *)prev->content)->prototype);
		free(prev->content);
		free(prev);
	}
}