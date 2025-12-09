# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 12:52:32 by jalosta-          #+#    #+#              #
#    Updated: 2025/12/09 19:23:06 by jalosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = src/instructions/r_rr.c src/instructions/s_p_r.c src/main.c src/operations_utils.c src/push_swap.c src/parser.c
OBJS = $(SRCS:.c=.o)
$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all