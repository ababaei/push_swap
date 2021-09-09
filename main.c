/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:47:16 by ababaei           #+#    #+#             */
/*   Updated: 2021/07/02 03:25:33 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define DEBUG false

/*
 * keep track of the chainlist head's adress
 *
 * Main.c will manage everything:
 *		-first we need to check the input is OK (letters, INTMAX/MIN, doubles) -> done in init_stacks() 
 *		-If it's ok we can init the stacks and fill stack A -> init_stacks()
 *		-Then we need to choose the sorting algo <10 or >10 numbers (radix sort)
 *		-There is also some functions to debug (print_stack) 
 */

static void print_exec(t_exec *lst)
{
	while (lst)
	{		
		printf ("%s\n", (lst)->ins);
		lst = (lst)->next;
	}
}

int main(int argc, char **argv)
{
	t_list	*t_stack_a;
	t_list	*t_stack_b;
	t_exec	*exec_list;
	int		errflag;

	errflag = 0;
	if (argc == 1)
		return (EXIT_FAILURE);
	t_stack_a = init_stacks(argc, argv, &errflag);
	t_stack_b = NULL;
	exec_list = NULL;
	if (t_stack_a && is_sorted(t_stack_a))
	{
		clean_exit(t_stack_a, t_stack_b, exec_list);
		return(EXIT_SUCCESS);
	}
	if (t_stack_a == NULL || errflag)
	{	
		write(2, "Error\n", 6);
		clean_exit(t_stack_a, t_stack_b, exec_list);
		return (EXIT_FAILURE);
	}
	sort_manager(&t_stack_a, &t_stack_b, &exec_list);	
	print_exec(exec_list);
	clean_exit(t_stack_a, t_stack_b, exec_list);
	return (EXIT_SUCCESS);
}
