#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

/*
 * In this file i have my init stack function, it will check if everything is ok and then fill the variables.
 * the checking functions are in the check_stack.c file
 * Then I initialize the stack and fill the content variable.
 * After the list is filled, I use an other function to find each nbr indice and its binary equivalent
 */

void	find_indice(t_list **stack)
{
	t_list *head;
	t_list *cursor;

	head = *stack;
	while (*stack)
	{
		(*stack)->indice = 0;
		cursor = head;
		while (cursor)
		{
			if ((*stack)->content > cursor->content)
				(*stack)->indice++;
			cursor = cursor->next;
		}
		(*stack)->b_indice = ft_itoa_base((*stack)->indice, "01");
		*stack = (*stack)->next;
	}
	*stack = head;
}

t_list *init_stacks(int argc, char **argv)
{
	t_list *tmp;
	t_list *new;
	int i;

	i = 2;
	if (check_arg(argv[1]) == 0)
		return (NULL);
	tmp = ft_lstnew(ft_atoi(argv[1]));
	if (tmp == NULL)
		return (NULL);
	while (i < argc)
	{
		if (check_arg(argv[i]) == 0)
			return (NULL);
		new = malloc(sizeof(t_list));
		if (new == NULL)
			return(NULL);
		new->content = ft_atoi(argv[i]);
		ft_lstadd_back(&tmp, new);
		i++;
	}
	find_indice(&tmp);
	if (check_double(tmp) == 0)
		return (NULL);
	return (tmp);
}
