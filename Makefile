NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = error.c ft_atoi.c ft_split.c functions.c push_swap.c push.c rev_rotate.c rotate.c swap.c main.c

OBJ = $(SRC:.c=.o)

COMPILE = $(CC) $(FLAGS)

all: $(NAME)

$(NAME): $(SRC)
        $(COMPILE) $(SRC) -o $(NAME)

clean:
        $(RM) $(OBJ)

fclean: clean
        $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
