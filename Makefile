CC = gcc

SRC = main.c \
	  init.c \
	  debug.c \
	  check_stack.c \
	  swap_set.c \
	  rotate_set.c \
	  push_set.c
	

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

all:LIBFT $(NAME)

LIBFT:
	make -C libft/ 

$(NAME):$(OBJ)
	$(CC) $(SRC) $(FLAGS) -Llibft/ -lft -o $(NAME)

clean:
	rm -f *.o 

fclean: clean
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re LIBFT
