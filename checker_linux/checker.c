#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

static void	print_exec(t_exec *lst)
{
	while (lst)
	{		
		printf ("%s\n", (lst)->ins);
		lst = (lst)->next;
	}
}

t_exec	*check_instruction(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	t_exec	*new;
	t_exec	*lst;

	new = NULL;
	lst = NULL;
	while (get_next_line(0, &line))
	{	
		new = malloc(sizeof(t_exec));
		new->next = NULL;
		new->ins = exe_instruction(stack_a, stack_b, line);
		exe_lstadd_back(&lst, new);
	}
	free(line);
	if (is_sorted(*stack_a))
		printf("OK\n");
	else
		printf("KO\n");
	return (lst);
}
