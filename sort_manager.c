#include "libft/libft.h"
#include <stdio.h>

/*
 * This file will be the crossroad of where the programs is going to go to sort the list depending on the size of the stack at start.
 */

int		sort_manager(t_list **stack_a, t_list **stack_b)
{
	t_exec *exec_list;

	int size;
	size = ft_lstsize(*stack_a);
	exec_list = NULL;
	//printf("size = %i\n\n", size);
	if (size == 2)
		sort_2(stack_a, stack_b, &exec_list);
	else if (size == 3)
		sort_3(stack_a, stack_b, &exec_list);
	else if (size <= 5)
		sort_5(stack_a, stack_b, &exec_list);
	else
		radix_sort(stack_a, stack_b, &exec_list);
	while (exec_list)
	{		
		printf ("%s\n", exec_list->ins);
		exec_list = exec_list->next;
	}
/*	else if (size > 3 && size <= 5)
		*lst = sort_5(stack_a, stack_b);
	else
		*lst = radix_sort(stack_a, stack_b);
*/	//printf("lst = %d\n", (*lst)->content);
	return (1);
}
