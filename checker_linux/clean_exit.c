#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

/*
 * This file contains functions to clean exit the programs without any leaks
 * We dont have to free the instruction in exec list because all of them are
 * on the stack. But we do have to free b_indice on number stacks 
 * because there are on the heap.
 */

static void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack->b_indice);
		free(stack);
		stack = tmp;
	}
}

static void	free_exec(t_exec *lst)
{
	t_exec	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->ins);
		free(lst);
		lst = tmp;
	}
}

void	clean_exit(t_list *stack_a, t_list *stack_b, t_exec *lst)
{
	free_exec(lst);
	free_stack(stack_a);
	free_stack(stack_b);
}
