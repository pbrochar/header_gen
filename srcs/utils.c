#include "header_gen.h"

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
static void	ft_lstswap(char **str1, char **str2)
{
	char *c;

	c = *str2;
	*str2 = *str1;
	*str1 = c;
}

void sort_ascii_list(t_list **lst)
{
    t_list *temp;
    t_list *temp2;

    temp = *lst;
    while(temp)
    {  
        temp2 = temp->next;
        while (temp2)
        {
            if (ft_strncmp(temp->content, temp2->content, ft_strlen(temp2->content)) < 0)
                ft_lstswap((char **)&(temp->content), (char **)&(temp2->content));
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
