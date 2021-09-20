#include "libft/libft.h"
#include <stdio.h>

/*
 * This file will be the crossroad of where the programs is going to go to 
 * sort the list depending on the size of the stack at start.
 */

static void	print_exec(t_exec *lst)
{
	while (lst)
	{		
		printf ("%s\n", (lst)->ins);
		lst = (lst)->next;
	}
}

int	sort_manager(t_list **stack_a, t_list **stack_b, t_exec **lst)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_2(stack_a, stack_b, lst);
	else if (size == 3)
		sort_3(stack_a, stack_b, lst);
	else if (size <= 5)
		sort_5(stack_a, stack_b, lst);
	else
		radix_sort(stack_a, stack_b, lst);
	print_exec(*lst);
	return (1);
}
