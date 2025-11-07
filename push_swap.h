/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:09:47 by jalosta-          #+#    #+#             */
/*   Updated: 2025/11/07 06:33:03 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_move
{
	int				target;
	int				cheapest;
	int				sum;
	int				cost_a;
	int				cost_b;
}					t_move;

typedef struct s_token
{
	int				value;
	int				index;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_stack
{
	t_token			*top;
	t_token			*bot;
	int				size;
}					t_stack;

typedef struct s_context
{
	t_stack			a;
	t_stack			b;
	int				price;
}					t_context;

void				swap(t_stack *stack);
void				rot(t_stack *stack);
void				rev_rot(t_stack *stack);
void				push(t_stack *src, t_stack *dst);
void				error(char *msg, t_context *c);
void				demolish(t_stack *s);
void				sa(t_context *c);
void				sb(t_context *c);
void				ss(t_context *c);
void				ra(t_context *c);
void				rb(t_context *c);
void				rr(t_context *c);
void				rra(t_context *c);
void				rrb(t_context *c);
void				rrr(t_context *c);
void				pa(t_context *c);
void				pb(t_context *c);
void				push_swap(t_context *c, t_stack *a, t_stack *b, int size);
void				stack(t_stack *a, int token_value, t_context *c);
void				parse(char *arg, t_context *c);
int					tokenize(char *arg, t_context *c);
bool				sorted(t_token *t);

#endif
