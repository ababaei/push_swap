CC = gcc

SRC = main.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
NAME = push_swap

all:LIBFT PUSH_SWAP

LIBFT:
	make -C libft/ bonus

PUSH_SWAP:$(OBJ)
	$(CC) $(OBJ) $(FLAGS) -Llibft/ -lft -o $(NAME)

clean:
	rm -f *.o 

fclean: clean
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re LIBFT
