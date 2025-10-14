NAME = push_swap.a

SRC = ft_split.c utils.c errors.c instructions.c push_swap.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
all: $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: clean all