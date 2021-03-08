#include "header_gen.h"

t_header_list	*header_lstnew(void *content, void *name)
{
	t_header_list	*new;

	new = (t_header_list *)malloc(sizeof(t_header_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->file_name = name;
	new->next = NULL;
	return (new);
}
