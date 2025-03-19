NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = libft/ft_atoi.c libft/ft_split.c libft/ft_strdup.c \
	   libft/ft_strjoin.c error.c functions.c push_swap.c \
       push.c rev_rotate.c rotate.c swap.c free.c index.c \
	   move.c main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
