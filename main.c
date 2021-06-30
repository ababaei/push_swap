#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list *t_stack_a;
	t_list *t_stack_b;
	int *test;
	int a;

	printf("toto\n");
	
	a = ft_atoi(argv[1]);
	if (argc == 1)
		return(EXIT_FAILURE);
	t_stack_a = ft_lstnew(&a);
	t_stack_b = ft_lstnew(&a);

	printf("content = %d\n", *(int*)t_stack_a->content);
	return(EXIT_SUCCESS);
}
