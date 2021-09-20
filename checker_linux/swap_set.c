#include "libft/libft.h"
#include <stdio.h>

/*
 * That file will contain 2 functions that will swap the first and 
 * second element of a stack. 
 * Either A or B or both at the same time.
 * If the stack concerned have 1 element or is empty, nothing is to be done.
 */

void	swap_stack(t_list **stack)
{
	t_list	*prev;
	int		size;

	size = ft_lstsize(*stack);
	if (size <= 1)
		return ;
	prev = *stack;
	*stack = (*stack)->next;
	prev->next = (*stack)->next;
	(*stack)->next = prev;
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}
