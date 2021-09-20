#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

/*
 *	In this file we will check the arguments given for doubles, letters 
 *	and int limits.
 *	With the help of ft_strtol i can check for letters and limits.
 *	Is_sorted let me check if the stack is sorted.
 *	And in check_doubles() i'll look for arguments that appears two 
 *	or more times.
*/

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_double(t_list *stack)
{
	t_list	*head;
	t_list	*cursor;
	int		tmp;

	head = stack;
	while (stack)
	{
		cursor = head;
		tmp = stack->content;
		while (cursor)
		{
			if (cursor->content == tmp && stack != cursor)
				return (0);
			cursor = cursor->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	check_arg(char *arg)
{
	long	nbr;
	char	*end;

	nbr = ft_strtol(arg, &end, 10);
	if (end[0] != 0)
		return (0);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}
