/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:11:18 by jalosta-          #+#    #+#             */
/*   Updated: 2025/11/06 23:57:30 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *s)
{
	int	temp;

	temp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = temp;
	temp = s->top->index;
	s->top->index = s->top->next->index;
	s->top->next->index = temp;
}

void	rot(t_stack *s)
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

void	rev_rot(t_stack *s)
{
	t_token	*last;
	t_token	*first;

	last = s->bot;
	first = s->top;
	s->bot = last->prev;
	s->bot->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	s->top = last;
}

void	push(t_stack *src, t_stack *dst)
{
	t_token	*load;

	if (!src || !src->top)
		return ;
	load = src->top;
	src->top = load->next;
	src->size--;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bot = NULL;
	load->prev = NULL;
	load->next = dst->top;
	if (dst->top)
		dst->top->prev = load;
	else
		dst->bot = load;
	dst->top = load;
	dst->size++;
}

void	demolish(t_stack *s)
{
	t_token	*current;
	t_token	*next;

	if (s)
	{
		current = s->top;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}
