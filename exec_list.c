#include "libft/libft.h"

void	exe_lstadd_back(t_exec **alst, t_exec *new)
{
	t_exec *head;

	head = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	while (*alst)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = head;
}	
