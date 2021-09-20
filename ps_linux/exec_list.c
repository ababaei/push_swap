#include "libft/libft.h"
#include <stdio.h>

void	exe_lstadd_back(t_exec **alst, t_exec *new)
{
	t_exec	*head;

	head = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = head;
}

int	exe_lstsize(t_exec *lst)
{
	int	tmp;

	tmp = 0;
	while (lst)
	{
		tmp++;
		lst = lst->next;
	}
	return (tmp);
}
