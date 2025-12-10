/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:19:56 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/10 20:30:24 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_token
{
	int				value;
	int				index;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_stack
{
	int				size;
	t_token			*top;
	t_token			*bot;
}					t_stack;

void				error(t_stack *a, t_stack *b);
void				parser(char *s, t_stack *a);
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
void				swap(t_stack *s);
void				push(t_stack *src, t_stack *dst);
void				rotate(t_stack *s);
void				rev_rotate(t_stack *s);
void				push_swap(t_stack *a);
bool				sorted(t_token *t);

#endif