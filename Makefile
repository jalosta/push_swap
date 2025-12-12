# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 12:52:32 by jalosta-          #+#    #+#              #
#    Updated: 2025/12/12 12:12:36 by jalosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
SRCS = src/instructions/r_rr.c src/instructions/s_p_r.c src/utils/utils.c src/utils/utils_0.c src/operations.c src/push_swap.c src/parser.c
OBJS = $(SRCS:.c=.o)
MAIN_SRC    = src/main.c
MAIN_OBJ    = $(MAIN_SRC:.c=.o)
BONUS_SRC = checker.c
$(NAME): $(OBJS) $(MAIN_OBJ)
	gcc -o $(NAME) $(OBJS) $(MAIN_OBJ)
all: $(NAME)
bonus: $(NAME) $(OBJS) $(BONUS_SRC)
	gcc -o $(BONUS_NAME) $(OBJS) $(BONUS_SRC)
clean:
	rm -f $(OBJS) $(MAIN_OBJ)
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
re: fclean all