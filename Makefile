NAME = ?

SRC = ?

OBJ = $(SRC:.c=.o)

all:	$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: 	fclean all

.PHONY:	all, clean, fclean, re