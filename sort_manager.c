#include "libft/libft.h"

/*
 * This file will be the crossroad of where the programs is going to go to sort the list depending on the size of the stack at start.
 */

int		sort_manager(t_list **stack_a, t_list **stack_b, char ***lst)
{
	int size;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
		**lst = sort_3(stack_a, stack_b);
	else if (size > 3 && size <= 5)
		**lst = sort_5(stack_a, stack_b);
	else
		**lst = radix_sort(stack_a, stack_b);
	return (1);
}
