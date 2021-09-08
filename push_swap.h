#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_exec
{
	char	*ins;
	struct s_exec	*next;
}					t_exec;

typedef struct		s_list
{
	int				content;
	char			*b_indice;
	int				i;
	int				indice;
	struct s_list	*next;
}					t_list;

t_list	*init_stacks(int argc, char **argv);
void	fill_num_array(int argc, char **argv, t_list *list);
void	print_stack(t_list *stack_a, t_list *stack_b);
void	print_item(t_list *stack);
void	print_all_items(t_list *stack);

int		is_sorted(t_list *list);
int		check_double(t_list *stack);
int		check_arg(char *arg);

void	swap_stack(t_list **stack);
void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);
void	push_stack(t_list **from, t_list **to);

int		sort_manager(t_list	**stack_a, t_list **stack_b);
void	sort_2(t_list **stack_a, t_list **stack_b, t_exec **lst);
void	sort_3(t_list **stack_a, t_list **stack_b, t_exec **lst);
void	sort_5(t_list **stack_a, t_list **stack_b, t_exec **lst);
void	radix_sort(t_list **stack_a, t_list **stack_b, t_exec **lst);

char	*exe_instruction(t_list **stack_a, t_list **stack_b, char *ins);
int 	is_biggest(t_list *stack);
int 	is_little(t_list *stack);

void	exe_lstadd_back(t_exec **alst, t_exec *new);
#endif
