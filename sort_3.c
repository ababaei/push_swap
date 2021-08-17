#include "libft/libft.h"
#include <stdio.h>

char	*exe_instruction(t_list **stack_a, t_list **stack_b, char *ins)
{
	(void)stack_b;
	if (ft_strncmp("sa", ins, ft_strlen(ins) == 0))
		swap_stack(stack_a);
	return (ins);	
}

void	sort_3(t_list **stack_a, t_list **stack_b, t_list **lst)
{
	t_list *head;
	t_list *new;

	(void)stack_b;
	head = *lst;
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->content == 2 && (*stack_a)->next->content == 1)
			(*lst)->ins = exe_instruction(stack_a, stack_b, "sa");
		else if ((*stack_a)->content == 3 && (*stack_a)->next->content == 1)
			(*lst)->ins = exe_instruction(stack_a, stack_b, "ra");
		else if ((*stack_a)->content == 2 && (*stack_a)->next->content == 3)
			(*lst)->ins = exe_instruction(stack_a, stack_b, "rra");
		if (!is_sorted(*stack_a))
		{
			*lst = (*lst)->next;
			new = malloc(sizeof(t_list));
			ft_lstadd_back(lst, new);
		}
	}
	*lst = head;
}
