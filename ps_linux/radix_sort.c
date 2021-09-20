#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

/*
 * This file contain the radix sort algorithm.
 * The idea is to check unit by unit on a binary scale, 
 * and put on A or B stack in function.
 * Then putting back the block and doing it again until the stack A is sorted.
 */

static void	all_on_a(t_list **stack_a, t_list **stack_b, t_exec **lst)
{
	t_exec	*new;

	while (*stack_b)
	{
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		new->ins = exe_instruction(stack_a, stack_b, "pa");
		exe_lstadd_back(lst, new);
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b, t_exec **lst)
{
	int		size;
	t_exec	*new;

	while (!is_sorted(*stack_a))
	{
		size = ft_lstsize(*stack_a);
		while (size)
		{
			new = malloc(sizeof(t_exec));
			new->next = NULL;
			(*stack_a)->i--;
			if ((*stack_a)->i < 0 || (*stack_a)->b_indice[(*stack_a)->i] == 48)
				new->ins = exe_instruction(stack_a, stack_b, "pb");
			else
				new->ins = exe_instruction(stack_a, stack_b, "ra");
			size--;
			exe_lstadd_back(lst, new);
		}
		all_on_a(stack_a, stack_b, lst);
	}
}
