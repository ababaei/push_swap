#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_list
{
	int				content;
	int				b_indice;
	int				indice;
	struct s_list	*next;
}					t_list;

t_list	*init_stacks(int argc, char **argv);
void	fill_num_array(int argc, char **argv, t_list *list);
void	print_stack(t_list *list);

#endif
