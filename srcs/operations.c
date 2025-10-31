/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:11:18 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/31 06:31:44 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
	temp = stack->top->index;
	stack->top->index = stack->top->next->index;
	stack->top->next->index = temp;
}

void	rot(t_stack *stack)
{
	t_token	*first;
	t_token	*last;

	first = stack->top;
	last = stack->bot;
	stack->top = first->next;
	stack->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->bot = first;
}

void	rev_rot(t_stack *stack)
{
	t_token	*last;
	t_token	*first;

	last = stack->bot;
	first = stack->top;
	stack->bot = last->prev;
	stack->bot->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	stack->top = last;
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
