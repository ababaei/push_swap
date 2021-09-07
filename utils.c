#include "libft/libft.h"

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
		push_stack(stack_b, stack_a);
	else if (ft_strncmp("rra", ins, ft_strlen(ins)) == 0)
		rev_rotate_stack(stack_a);
	else if (ft_strncmp("rrb", ins, ft_strlen(ins)) == 0)
		rev_rotate_stack(stack_b);
	return (ins);	
}

int	is_biggest(t_list *stack)
{
	int ret;

	ret = stack->content;
	while (stack)
	{
		if (stack->content > ret)
			ret = stack->content;
		stack = stack->next;
	}
	return (ret);
}

int	is_little(t_list *stack)
{
	int ret;

	ret = stack->content;
	while (stack)
	{
		if (stack->content < ret)
			ret = stack->content;
		stack = stack->next;
	}
	return (ret);
}
