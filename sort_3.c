#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

char	*exe_instruction(t_list **stack_a, t_list **stack_b, char *ins)
{
	if (ft_strncmp("sa", ins, ft_strlen(ins)) == 0)
		swap_stack(stack_a);
	else if (ft_strncmp("sb", ins, ft_strlen(ins)) == 0)
		swap_stack(stack_b);
	else if (ft_strncmp("ra", ins, ft_strlen(ins)) == 0)
		rotate_stack(stack_a);
	else if (ft_strncmp("rb", ins, ft_strlen(ins)) == 0)
		rotate_stack(stack_b);
	else if (ft_strncmp("pa", ins, ft_strlen(ins)) == 0)
		push_stack(stack_a, stack_b);
	else if (ft_strncmp("pb", ins, ft_strlen(ins)) == 0)
		push_stack(stack_b, stack_b);
	else if (ft_strncmp("rra", ins, ft_strlen(ins)) == 0)
		rev_rotate_stack(stack_a);
	else if (ft_strncmp("rrb", ins, ft_strlen(ins)) == 0)
		rev_rotate_stack(stack_b);
	return (ins);	
}

t_exec	*sort_3(t_list **stack_a, t_list **stack_b)
{
	t_exec *new;
	t_exec *lst;

	lst = NULL;
	while (!is_sorted(*stack_a))
	{
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		print_stack(*stack_a, *stack_b);
		if (((*stack_a)->indice == 1 && (*stack_a)->next->indice == 0)
			|| ((*stack_a)->indice == 2 && (*stack_a)->next->indice == 1)
			|| ((*stack_a)->indice == 0 && (*stack_a)->next->indice == 2))
			new->ins = exe_instruction(stack_a, stack_b, "sa");
		else if ((*stack_a)->indice == 2 && (*stack_a)->next->indice == 0)
			new->ins = exe_instruction(stack_a, stack_b, "ra");
		else if ((*stack_a)->indice == 1 && (*stack_a)->next->indice == 2)
			new->ins = exe_instruction(stack_a, stack_b, "rra");
		exe_lstadd_back(&lst, new);
	}
	return (lst);
}
