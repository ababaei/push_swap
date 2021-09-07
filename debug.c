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
	printf(" %p", stack_a);
	printf("\nB |");
	while (stack_b)
	{
		printf(" %d |",stack_b->content);
		stack_b = stack_b->next;
	}
	printf(" %p", stack_a);
	printf("\n__________________\n");
}

void print_item(t_list *stack)
{
	char *sep = "______________________\n";
	int slen;

	slen = (int)ft_strlen(sep) - 3;
	printf("%s", sep);
	printf("| %-*p |\n\
| %-*d |\n\
| indice = %-*d |\n\
| b_indice = %-*s |\n\
| %-*p |\n",
			slen,stack,
			slen, stack->content,
			slen - 9,stack->indice,
			slen - 11,stack->b_indice,
			slen,stack->next);
}

void print_all_items(t_list *stack)
{
	while (stack)
	{
		print_item(stack);	
		stack = stack->next;
	}
}
