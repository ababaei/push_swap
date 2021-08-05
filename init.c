#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

/*
 *	In this file we will check the arguments given for doubles, letters and int limits.
 *	Then I initialize the stack and fill the content variable.
 *	With the help of ft_strtol i can check for letters and limits.
 *	And in check_doubles() i'll look for arguments that appears two or more times.
 */

int	check_double(t_list *stack)
{
	t_list *head;
	t_list *cursor;
	int tmp;

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
	long nbr;
	char *end;

	nbr = ft_strtol(arg, &end, 10);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	if (end[0] != 0)
		return (0);
	return (1);
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
		//new->indice = find_indice()
		ft_lstadd_front(&tmp, new);
		i++;
	}
	if (check_double(tmp) == 0)
		return (NULL);
	return (tmp);
}
