/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:08:38 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/12 15:22:42 by jalosta-         ###   ########.fr       */
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

void	set_targets(t_token *src, t_token *dst)
{
	t_token	*target_node;
	t_token	*best_match;

	while (src)
	{
		best_match = NULL;
		target_node = dst;
		while (target_node)
		{
			if (target_node->index < src->index)
			{
				if (!best_match || target_node->index > best_match->index)
					best_match = target_node;
			}
			target_node = target_node->next;
		}
		if (!best_match)
			src->target = find_min_max(dst, false);
		else
			src->target = best_match;
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
