#include "header_gen.h"

/* 
** Check if char is space
*/
int ft_isspace(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    return (0);
}

static int	ft_compare(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

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
                ft_lstswap(&temp, &temp2);
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
