/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:15:33 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/16 13:46:05 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *s)
{
	int	temp;

	temp = s->top->n;
	s->top->n = s->top->next->n;
	s->top->next->n = temp;
	temp = s->top->i;
	s->top->i = s->top->next->i;
	s->top->next->i = temp;
}

void	push(t_stack *src, t_stack *dst)
{
	t_token	*to_push;

	to_push = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bot = NULL;
	to_push->prev = NULL;
	to_push->next = dst->top;
	if (dst->top)
		dst->top->prev = to_push;
	else
		dst->bot = to_push;
	dst->top = to_push;
	src->len--;
	dst->len++;
}

void	rotate(t_stack *s)
{
	t_token	*first;
	t_token	*last;

	first = s->top;
	last = s->bot;
	s->top = first->next;
	s->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	s->bot = first;
}

void	rev_rotate(t_stack *s)
{
	t_token	*first;
	t_token	*last;

	last = s->bot;
	first = s->top;
	s->bot = last->prev;
	s->bot->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	s->top = last;
}
