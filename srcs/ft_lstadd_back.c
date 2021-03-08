#include "header_gen.h"

void	header_lstadd_back(t_header_list **alst, t_header_list *new)
{
	t_header_list *plst;

	if (alst && *alst)
	{
		plst = *alst;
		while (plst->next)
			plst = plst->next;
		plst->next = new;
	}
	else if (alst)
		*alst = new;
}
