CC = gcc

SRC = main.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
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
