#include "libft/libft.h"
#include <stdio.h>

void	push_stack(t_list **from, t_list **to)
{
	t_list *tmp;
	int size;

	size = ft_lstsize(*from);
	if (size < 1)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	//printf("to = %d\n", (*to)->content);
}
