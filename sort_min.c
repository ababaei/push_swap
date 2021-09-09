#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

/*
 * This file contain the algo to sort 2,3 and 5 sized list.
 * The 5 one, just put 2 element on stack B and then use the sort 3 algo before
 * before putting back the 2 on stack A
 */

void	sort_2(t_list **stack_a, t_list **stack_b, t_exec **lst)
{
	t_exec *new;

	new = malloc(sizeof(t_exec));
	new->next = NULL;
	new->ins = exe_instruction(stack_a, stack_b, "sa");
	exe_lstadd_back(lst, new);
}

void	sort_3(t_list **stack_a, t_list **stack_b, t_exec **lst)
{
	t_exec *new;

	while (!is_sorted(*stack_a))
	{
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		if (((*stack_a)->content > (*stack_a)->next->content)
			&& ((*stack_a)->next->content < (*stack_a)->next->next->content)
			&& ((*stack_a)->content > (*stack_a)->next->next->content))
			new->ins = exe_instruction(stack_a, stack_b, "ra");
		else if (((*stack_a)->content < (*stack_a)->next->content)
			&& ((*stack_a)->content > (*stack_a)->next->next->content))
			new->ins = exe_instruction(stack_a, stack_b, "rra");
		else
			new->ins = exe_instruction(stack_a, stack_b, "sa");
		exe_lstadd_back(lst, new);
	}
}

static void put_out(t_list **stack_a, t_list **stack_b, t_exec **lst)
{
	t_exec *new;

	while (ft_lstsize(*stack_a) != 3)
	{
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		new->ins = exe_instruction(stack_a, stack_b, "pb");
		exe_lstadd_back(lst, new);
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b, t_exec **lst)
{
	t_exec *new;
	int stack_size;

	stack_size = ft_lstsize(*stack_a);
	put_out(stack_a, stack_b, lst);
	sort_3(stack_a, stack_b, lst);
	while (!is_sorted(*stack_a) || ft_lstsize(*stack_a) != stack_size)
	{
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		if (*stack_b && (((*stack_b)->content < (*stack_a)->content 
				&& ((*stack_b)->content > ft_lstlast(*stack_a)->content
					|| (is_little(*stack_a))))
				|| (is_little(*stack_a) 
				&& (*stack_b)->content > ft_lstlast(*stack_a)->content)))
			new->ins = exe_instruction(stack_a, stack_b, "pa");
		else
			new->ins = exe_instruction(stack_a, stack_b, "ra");
		exe_lstadd_back(lst, new);
	}
}
