/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:19:56 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/14 13:57:13 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_token
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_token	*target;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_stack
{
	int				size;
	t_token			*top;
	t_token			*bot;
}					t_stack;

void				swap(t_stack *s);
void				push(t_stack *src, t_stack *dst);
void				rotate(t_stack *s);
void				rev_rotate(t_stack *s);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				pa(t_stack *b, t_stack *a);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				parser(char *s, t_stack *a);
bool				is_duplicate(t_stack a, int v);
void				error(t_stack *a, t_stack *b);
bool				sorted(t_token *t);
void				demolish(t_stack s);
t_token				*find_min_max(t_token *t, bool min);
void				set_targets(t_token *src, t_token *dst, bool smaller);
int					cheapest_climb(t_token *t, int i, int size);
void				climb(t_stack *a, t_stack *b, int dis, bool for_a);
void				push_swap(t_stack *a);
void				cost_analysis(t_token *a, t_token *b, int a_len, int b_len);
t_token				*cheapest_insert(t_token *t);

#endif