#include "libft/libft.h"
#include <stdio.h>

void print_stack(t_list stack_a, t_list stack_b)
{
	int a_len;
	int b_len;

	a_len = ft_lstsize(stack_a);
	b_len = ft_lstsize(stack_b);
	while (a_len == 0 && b_len = 0)
	{
		if (a_len > b_len)
		{
			printf("%d\n", stack_a.content);
			stack_a = stack_a->next;
		}
		else if (b_len > a_len)
		{
			printf("%d\n", stack_b.content);
			stack_b = stack_b->next;
		}
		else
		{
			printf("%8d%d\n", stack_a.content, stack_b.content);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
	}
}
