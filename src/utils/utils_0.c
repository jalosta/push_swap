/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:08:38 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/14 14:55:48 by jalosta-         ###   ########.fr       */
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
			if ((smaller && cur->index < src->index && (!best
						|| cur->index > best->index)) || (!smaller
					&& cur->index > src->index && (!best
						|| cur->index < best->index)))
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

int	cheapest_climb(t_token *t, int i, int size)
{
	int	dis;

	dis = 0;
	while (t && t->index != i)
	{
		dis++;
		t = t->next;
	}
	if (dis <= size / 2)
		return (dis);
	else
		return (dis - size);
}

void	cost_analysis(t_token *a, t_token *b, int a_len, int b_len)
{
	t_token	*cur_a;

	cur_a = a;
	while (cur_a)
	{
		cur_a->cost_a = cheapest_climb(a, cur_a->index, a_len);
		if (cur_a->target)
			cur_a->cost_b = cheapest_climb(b, cur_a->target->index, b_len);
		cur_a = cur_a->next;
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
		if ((t->cost_a > 0 && t->cost_b > 0) || (t->cost_a < 0
				&& t->cost_b < 0))
		{
			if (abs(t->cost_a) > abs(t->cost_b))
				price = abs(t->cost_a);
			else
				price = abs(t->cost_b);
		}
		else
			price = abs(t->cost_a) + abs(t->cost_b);
		if (price < best_price)
		{
			best_price = price;
			cheapest = t;
		}
		t = t->next;
	}
	return (cheapest);
}
