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
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list	*t_stack_a;
	t_list	*t_stack_b;
	int		*num_list;
	int i = 0;

	if (argc == 1)
		return (EXIT_FAILURE);
	num_list = malloc(sizeof(int) * argc - 1);
	fill_num_array(argc, argv, &num_list);
	t_stack_a = init_stacks(argc, argv);
	t_stack_b = ft_lstnew(&argc);
	while (i < argc - 1)
	{
		printf("int = %d\n", num_list[i]);
		i++;
	}
	if (t_stack_a == NULL || t_stack_b == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void fill_num_array(int argc, char **argv, int **num_list)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		(*num_list)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

t_list *init_stacks(int argc, char **argv)
{
	t_list *tmp;
	t_list *new;
	int arg_num;
	int i;

	i = 2;
	arg_num = ft_atoi(argv[1]);
	tmp = ft_lstnew(&arg_num);
	if (tmp == NULL)
		return (NULL);
	while (i < argc)
	{
		arg_num = ft_atoi(argv[i]);
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return(NULL);
		new->content = &arg_num;
		ft_lstadd_front(&tmp, new);
		i++;
	}


	while (tmp)
	{
		printf("ptr = %p\n", tmp);
		printf("content = %d\n", *(int*)tmp->content);
		tmp = tmp->next;		
	}
	return (tmp);
}

void print_stack(void *content)
{
	printf("content = %d\n", *(int*)content);
}
