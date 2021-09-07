#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

t_exec	*sort_2(t_list **stack_a, t_list **stack_b)
{
	t_exec *new;
	t_exec *lst;

	lst = NULL;
	new = malloc(sizeof(t_exec));
	new->next = NULL;
	new->ins = exe_instruction(stack_a, stack_b, "sa");
	exe_lstadd_back(&lst, new);
	return (lst);
}

t_exec	*sort_3(t_list **stack_a, t_list **stack_b)
{
	t_exec *new;
	t_exec *lst;

	lst = NULL;
	//print_stack(*stack_a, *stack_b);
	while (!is_sorted(*stack_a))
	{
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		//print_stack(*stack_a, *stack_b);
		if (((*stack_a)->content > (*stack_a)->next->content)
			&& ((*stack_a)->next->content < (*stack_a)->next->next->content))
			new->ins = exe_instruction(stack_a, stack_b, "ra");
		else if (((*stack_a)->content < (*stack_a)->next->content)
			&& ((*stack_a)->content > (*stack_a)->next->next->content))
			new->ins = exe_instruction(stack_a, stack_b, "rra");
		else
			new->ins = exe_instruction(stack_a, stack_b, "sa");
		exe_lstadd_back(&lst, new);
	}
	return (lst);
}

//le sort_3 dessous fonctionne pas a cause des indices qui changent apres les push
t_exec	*sort_5(t_list **stack_a, t_list **stack_b)
{
	t_exec *new;
	t_exec *lst;

	lst = NULL;
	while (!is_sorted(*stack_a) || ft_lstsize(*stack_a) != 5)
	{
		print_stack(*stack_a, *stack_b);
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		if (ft_lstsize(*stack_a) != 3 && !is_sorted(*stack_a))
			new->ins = exe_instruction(stack_a, stack_b, "pa");
		else
			lst = sort_3(stack_a, stack_b);
		if (ft_lstsize(*stack_a) != 5 && *stack_a)
		{
			if ((*stack_b)->content < (*stack_a)->content 
					|| is_biggest(*stack_a) == (*stack_a)->content)
				new->ins = exe_instruction(stack_a, stack_b, "pb");
			else
				new->ins = exe_instruction(stack_a, stack_b, "ra");
		}
		else if ((*stack_a)->content != is_little(*stack_a))
			new->ins = exe_instruction(stack_a, stack_b, "ra");
		exe_lstadd_back(&lst, new);
		sleep(1);
	}
	return (lst);	
}
