#include "libft/libft.h"
#include <stdio.h>

void	rotate_stack(t_list **stack)
{
	t_list *prev;

	prev = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, prev);
	prev->next = NULL;
}

void	rev_rotate_stack(t_list **stack)
{
	t_list *prev;
	t_list *head;

	prev = ft_lstlast(*stack);
	head = *stack;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = head;
	ft_lstadd_front(stack, prev);
	
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_stack(stack_a);
	rev_rotate_stack(stack_b);
}
