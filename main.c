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
 * bien penser a garder et a suivre l'adresse de la tete de liste
 *
 * Main.c will manage everything:
 *		-first we need to check the input is OK (letters, INTMAX/MIN)
 *		-If it's ok we can init the stacks and fill stack A
 *		-Then we need to choose the sorting algo <10 or >10 numbers (radix sort)
 *		-There is also some functions to debug (print_stack) 
 */

int main(int argc, char **argv)
{
	t_list	*t_stack_a;
	t_list	*t_stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	t_stack_a = init_stacks(argc, argv);
	t_stack_b = ft_lstnew(0);
	if (DEBUG)
		print_stack(t_stack_a);
	if (t_stack_a == NULL || t_stack_b == NULL)
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}
