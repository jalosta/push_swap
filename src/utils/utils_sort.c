/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:08:38 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/16 17:06:16 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	climb(t_stack *a, t_stack *b, int dis, bool for_a)
{
	while (dis > 0)
	{
		if (for_a)
			ra(a);
		else
			rb(b);
		dis--;
	}
	while (dis < 0)
	{
		if (for_a)
			rra(a);
		else
			rrb(b);
		dis++;
	}
}

void	set_targets(t_token *src, t_token *dst, bool smaller)
{
	t_token	*best;
	t_token	*cur;

	while (src)
	{
		best = NULL;
		cur = dst;
		while (cur)
		{
			if ((smaller && cur->i < src->i && (!best || cur->i > best->i))
				|| (!smaller && cur->i > src->i && (!best || cur->i < best->i)))
				best = cur;
			cur = cur->next;
		}
		if (best)
			src->target = best;
		else
			src->target = find_min_max(dst, !smaller);
		src = src->next;
	}
}

int	cheapest_climb(t_token *t, int index, int size)
{
	int	dis;

	dis = 0;
	while (t && t->i != index)
	{
		dis++;
		t = t->next;
	}
	if (dis <= size / 2)
		return (dis);
	else
		return (dis - size);
}

void	set_costs(t_stack *a, t_stack *b)
{
	t_token	*cur;

	cur = a->top;
	while (cur)
	{
		cur->c_a = cheapest_climb(a->top, cur->i, a->len);
		if (cur->target)
			cur->c_b = cheapest_climb(b->top, cur->target->i, b->len);
		cur = cur->next;
	}
}

t_token	*cheapest_insert(t_token *t)
{
	int		price;
	int		best_price;
	t_token	*cheapest;

	best_price = INT_MAX;
	cheapest = NULL;
	while (t)
	{
		if ((t->c_a > 0 && t->c_b > 0) || (t->c_a < 0 && t->c_b < 0))
		{
			if (abs(t->c_a) > abs(t->c_b))
				price = abs(t->c_a);
			else
				price = abs(t->c_b);
		}
		else
			price = abs(t->c_a) + abs(t->c_b);
		if (price < best_price)
		{
			best_price = price;
			cheapest = t;
		}
		t = t->next;
	}
	return (cheapest);
}
