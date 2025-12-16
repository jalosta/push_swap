/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:57:45 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/16 14:04:16 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	demolish(t_stack s)
{
	t_token	*next;

	while (s.len > 0)
	{
		next = s.top->next;
		free(s.top);
		s.top = next;
		s.len--;
	}
}

t_token	*find_min_max(t_token *t, bool min)
{
	t_token	*find;

	find = t;
	while (t)
	{
		if ((min && find->i > t->i) || (!min && find->i < t->i))
			find = t;
		t = t->next;
	}
	return (find);
}

bool	is_duplicate(t_stack a, int value)
{
	while (a.top)
	{
		if (value == a.top->n)
			return (1);
		a.top = a.top->next;
	}
	return (0);
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
		if (t->n > t->next->n)
			return (0);
		t = t->next;
	}
	return (1);
}
