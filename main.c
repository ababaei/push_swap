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

#define DEBUG true

/*
 * keep track of the chainlist head's adress
 *
 * Main.c will manage everything:
 *		-first we need to check the input is OK (letters, INTMAX/MIN, doubles) -> done in init_stacks() 
 *		-If it's ok we can init the stacks and fill stack A -> init_stacks()
 *		-Then we need to choose the sorting algo <10 or >10 numbers (radix sort)
 *		-There is also some functions to debug (print_stack) 
 */

int main(int argc, char **argv)
{
	t_list	*t_stack_a;
	t_list	*t_stack_b;
	char 	**exec_list;

	if (argc == 1)
		return (EXIT_FAILURE);
	t_stack_a = init_stacks(argc, argv);
	t_stack_b = malloc(sizeof(t_list));
	if (t_stack_a == NULL || t_stack_b == NULL)
	{	
		printf("ERROR GROS BOUFFON\n");
		return (EXIT_FAILURE);
	}
	if (is_sorted(t_stack_a))
		printf("SORTED\n");
	t_stack_b->next = NULL;
	if (DEBUG)
		print_all_items(t_stack_a);
		//print_stack(t_stack_a, t_stack_b);
	exec_list = malloc(sizeof(char *) * argc)
	exec_list[argc] = NULL;
	sort_manager(t_stack_a, t_stack_b, exec_list);	
	/*
	swap_stack(&t_stack_a);
	print_stack(t_stack_a, t_stack_b);
	rev_rotate_stack(&t_stack_a);
	print_stack(t_stack_a, t_stack_b);
	*/
	return (EXIT_SUCCESS);
}
