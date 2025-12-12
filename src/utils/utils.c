/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:57:45 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/12 14:51:10 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	demolish(t_stack s)
{
	t_token	*next;

	while (s.size > 0)
	{
		next = s.top->next;
		free(s.top);
		s.top = next;
		s.size--;
	}
}

t_token	*find_min_max(t_token *t, bool min)
{
	t_token	*find;

	find = t;
	while (t)
	{
		if ((min && find->index > t->index) || (!min && find->index < t->index))
			find = t;
		t = t->next;
	}
	return (find);
}

bool	is_duplicate(t_stack a, int v)
{
	while (a.top)
	{
		if (v == a.top->value)
			return (true);
		a.top = a.top->next;
	}
	return (false);
}

void	error(t_stack *a, t_stack *b)
{
	demolish(*a);
	if (b)
		demolish(*b);
	write(2, "Error\n", 6);
	exit(1);
}

bool	sorted(t_token *t)
{
	while (t && t->next)
	{
		if (t->value > t->next->value)
			return (false);
		t = t->next;
	}
	return (true);
}
