/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:47:16 by ababaei           #+#    #+#             */
/*   Updated: 2021/07/01 03:53:57 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list *t_stack_a;
	t_list *t_stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	t_stack_a = init_stacks(argc, argv);
	t_stack_b = ft_lstnew(&argc);
	if (t_stack_a == NULL || t_stack_b == NULL)
		return (EXIT_FAILURE);
	//ft_lstiter(t_stack_a, &print_stack);
	return (EXIT_SUCCESS);
}

t_list *init_stacks(int argc, char **argv)
{
	t_list *tmp;
	t_list *new;
	int arg_num;
	int i;

	i = 2;
	arg_num = ft_atoi(argv[1]);
	printf("num = %d\n",arg_num);
	new = ft_lstnew(&arg_num);
	printf("new = %p\n", &new);
	if (tmp == NULL)
		return (NULL);
	while (i < argc)
	{
		arg_num = ft_atoi(argv[i]);
		printf("num = %d\n",arg_num);
		new = ft_lstnew(&arg_num);
		printf("new = %p\n", &new);
		ft_lstadd_front(&tmp, new);
		if (tmp == NULL)
			return (NULL);
		i++;
	}
/*
	while (tmp)
	{
		printf("ptr = %p\n", tmp);
		printf("content = %d\n", *(int*)tmp->content);
		tmp = tmp->next;		
	}*/
	return (tmp);
}

void print_stack(void *content)
{
	printf("content = %d\n", *(int*)content);
}
