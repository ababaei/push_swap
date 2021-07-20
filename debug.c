#include "libft/libft.h"
#include <stdio.h>

void print_stack(t_list *list)
{
	while (list)
	{
		printf("content = %d\n", list->content);
		list = list->next;	
	}
}
