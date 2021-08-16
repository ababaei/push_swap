#include "libft/libft.h"

t_exec *sort_3(t_list **stack_a, t_list **stack_b)
{
	int size;
	t_exec *ret;

	(void)stack_b;
	size = ft_lstsize(*stack_a);
	ret = malloc(sizeof(ret));
	ret->next = NULL;
	if (size == 2)
		ret->content = ft_strdup("sa");
	else if (size == 3)
	{
		while (!is_sorted(*stack_a))
		{
			if ((*stack_a)->content == 2 && (*stack_a)->next->content == 1)
					
		}
	}
		ret->content = ft_strdup("toto");		
	return (ret);
}
