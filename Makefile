CC = gcc

PS_SRC = main.c \
	  	init.c \
	  	debug.c \
	  	check_stack.c \
	  	swap_set.c \
	  	rotate_set.c \
	  	push_set.c \
	  	sort_manager.c \
	  	sort_min.c \
	  	exec_list.c \
	  	radix_sort.c \
	  	clean_exit.c \
	  	utils.c
	
CHECKER_SRC = main.c \
	  		init.c \
	  		debug.c \
	  		check_stack.c \
	  		swap_set.c \
	  		rotate_set.c \
	  		push_set.c \
	  		exec_list.c \
	  		clean_exit.c \
			checker.c \
	  		utils.c

PS_OBJ = $(PS_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

PSDIR = ps_linux/
CHECKERDIR = checker_linux/

DIROBJ = objs/
CHECKEROBJ = bonus_objs/

DIROBJS = $(addprefix $(DIROBJ), $(PS_OBJ))
CHECKER_OBJS = $(addprefix $(CHECKEROBJ), $(CHECKER_OBJ))

FLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
CHECKER_NAME = checker

all:LIBFT $(NAME)

LIBFT:
	@echo making libft
	@make -C ps_linux/libft/ 

$(CHECKEROBJ)%.o: $(CHECKERDIR)%.c
	@mkdir -p $(CHECKEROBJ)
	@echo compiling: $<
	@$(CC) $(FLAGS) -c $< -o $@

$(DIROBJ)%.o: $(PSDIR)%.c
	@mkdir -p $(DIROBJ)
	@echo compiling: $<
	@$(CC) $(FLAGS) -c $< -o $@

CHECKER_LIBFT:
	make -C checker_linux/libft/

$(NAME):$(DIROBJS)
	@echo Creating executable $(NAME)
	@$(CC) $(DIROBJ)*.o $(FLAGS) -Lps_linux/libft/ -lft -o $(NAME)

$(CHECKER_NAME):CHECKER_LIBFT $(CHECKER_OBJS)
	@echo Creating executable $(CHECKER_NAME)
	@$(CC) $(CHECKEROBJ)*.o $(FLAGS) -Lchecker_linux/libft/ -lft -o $(CHECKER_NAME)

clean:
	rm -rf $(DIROBJ)
	rm -rf $(CHECKEROBJ)

fclean: clean
	rm -f push_swap

checker_fclean: clean
	rm -f checker

re: fclean all

.PHONY: all clean fclean re LIBFT
