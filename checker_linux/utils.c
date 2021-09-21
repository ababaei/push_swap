#include "libft/libft.h"

char	*exe_instruction(t_list **stack_a, t_list **stack_b, char *ins,
		int *errflag)
{
	if (ft_strncmp("sa", ins, ft_strlen(ins)) == 0)
		swap_stack(stack_a);
	else if (ft_strncmp("sb", ins, ft_strlen(ins)) == 0)
		swap_stack(stack_b);
	else if (ft_strncmp("ra", ins, ft_strlen(ins)) == 0)
		rotate_stack(stack_a);
	else if (ft_strncmp("rb", ins, ft_strlen(ins)) == 0)
		rotate_stack(stack_b);
	else if (ft_strncmp("pb", ins, ft_strlen(ins)) == 0)
		push_stack(stack_a, stack_b);
	else if (ft_strncmp("pa", ins, ft_strlen(ins)) == 0)
		push_stack(stack_b, stack_a);
	else if (ft_strncmp("rra", ins, ft_strlen(ins)) == 0)
		rev_rotate_stack(stack_a);
	else if (ft_strncmp("rrb", ins, ft_strlen(ins)) == 0)
		rev_rotate_stack(stack_b);
	else
		*errflag = 1;
	return (ins);
}

int	is_biggest(t_list *stack)
{
	int	nbr;

	nbr = stack->content;
	while (stack)
	{
		if (nbr < stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_little(t_list *stack)
{
	int	nbr;

	nbr = stack->content;
	while (stack)
	{
		if (nbr > stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
