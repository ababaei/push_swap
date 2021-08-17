#include "libft/libft.h"
#include <stdio.h>

char	*exe_instruction(t_list **stack_a, t_list **stack_b, char *ins)
{
	(void)stack_b;
	if (ft_strncmp("sa", ins, ft_strlen(ins) == 0))
		swap_stack(stack_a);
	return (ins);	
}

t_exec	*sort_3(t_list **stack_a, t_list **stack_b)
{
	t_exec *head;
	t_exec *new;
	t_exec *lst;

	//(void)stack_b;
	lst = malloc(sizeof(lst));
	if (lst == NULL)
		return (NULL);
	lst->next = NULL;
	head = lst;
	printf("TOTO\n");
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->content == 2 && (*stack_a)->next->content == 1)
			lst->ins = exe_instruction(stack_a, stack_b, "sa");
		else if ((*stack_a)->content == 3 && (*stack_a)->next->content == 1)
			lst->ins = exe_instruction(stack_a, stack_b, "ra");
		else if ((*stack_a)->content == 2 && (*stack_a)->next->content == 3)
			lst->ins = exe_instruction(stack_a, stack_b, "rra");
		print_stack(*stack_a, *stack_b);
		if (!is_sorted(*stack_a))
		{
			new = malloc(sizeof(t_exec));
			exe_lstadd_back(&lst, new);
			//lst = lst->next;
		}
	}
	lst = head;
	return (lst);
}
