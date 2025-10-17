NAME = push_swap

SRCS = 	srcs/main.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all