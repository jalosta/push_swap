/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:15:50 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/14 17:23:20 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap takes one or more arguments as a list of integers or stack a and
 * provides a set of instructions for sorting it from lowest integer to highest.
 * Arguments may range in number from a single string to the limit for terminal.
 * Stack a may be in form of a single string or several arguments of individual
 * integers.
 */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_token
{
	int				value;
	struct s_token	*next;
}					t_token;

bool				ft_isspace(int c);
bool				bad_syntax(char *s);
bool				err_dup(t_token *a, int nbr);
bool				ft_isdigit(int c);
bool				stack_sorted(t_token *stack);
bool				stack_tidy(t_token *stack);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
t_token				*ft_lstlast(t_token *lst);
char				**ft_split(char *s);
void				error(void);
void				demolish(t_token **stack);
void				free_matrix(char **argv, int i);
void				err_demolish(t_token **a, char **argv, bool free_argv);
void				ft_lstadd_back(t_token **lst, t_token *new);

#endif