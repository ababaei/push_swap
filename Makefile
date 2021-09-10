CC = gcc

PS_SRC = ps_linux/main.c \
	  	ps_linux/init.c \
	  	ps_linux/debug.c \
	  	ps_linux/check_stack.c \
	  	ps_linux/swap_set.c \
	  	ps_linux/rotate_set.c \
	  	ps_linux/push_set.c \
	  	ps_linux/sort_manager.c \
	  	ps_linux/sort_min.c \
	  	ps_linux/exec_list.c \
	  	ps_linux/radix_sort.c \
	  	ps_linux/clean_exit.c \
	  	ps_linux/utils.c
	
CHECKER_SRC = checker_linux/main.c \
	  		checker_linux/init.c \
	  		checker_linux/debug.c \
	  		checker_linux/check_stack.c \
	  		checker_linux/swap_set.c \
	  		checker_linux/rotate_set.c \
	  		checker_linux/push_set.c \
	  		checker_linux/exec_list.c \
	  		checker_linux/clean_exit.c \
			checker_linux/checker.c \
	  		checker_linux/utils.c

PS_OBJ = $(PS_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
CHECKER_NAME = checker

all:LIBFT $(NAME)

LIBFT:
	make -C ps_linux/libft/ 

CHECKER_LIBFT:
	make -C checker_linux/libft/

$(NAME):$(PS_OBJ)
	$(CC) $(PS_SRC) $(FLAGS) -Lps_linux/libft/ -lft -o $(NAME)
	make clean

$(CHECKER_NAME):CHECKER_LIBFT $(CHECKER_OBJ)
	$(CC) $(CHECKER_SRC) -Lchecker_linux/libft/ -lft -o $(CHECKER_NAME)
	make clean

clean:
	rm -f *.o 

fclean: clean
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re LIBFT
