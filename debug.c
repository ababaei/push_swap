#include "libft/libft.h"
#include <stdio.h>

void print_stack(t_list *stack_a, t_list *stack_b)
{
	printf("A |");
	while (stack_a)
	{
		printf(" %d |",stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\nB |");
	while (stack_b)
	{
		printf(" %d |",stack_b->content);
		stack_b = stack_b->next;
	}
	printf("\n__________________\n");
}
