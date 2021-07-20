#include "libft/libft.h"
/*
int	check_stack(t_list *list)
{
	
}
*/

t_list *init_stacks(int argc, char **argv)
{
	t_list *tmp;
	t_list *new;
	int i;

	i = 1;
	tmp = ft_lstnew(ft_atoi(argv[i]));
	if (tmp == NULL)
		return (NULL);
	while (i < argc - 1)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return(NULL);
		new->content = ft_atoi(argv[i + 1]);
		//new->indice = find_indice()
		ft_lstadd_front(&tmp, new);
		i++;
	}
	return (tmp);
}
