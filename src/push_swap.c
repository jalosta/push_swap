/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:03:12 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/12 15:32:05 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	trisort(t_stack *a)
{
	t_token	*max;

	max = find_min_max(a->top, false);
	if (a->top->index == max->index)
		ra(a);
	else if (a->top->next->index == max->index)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}

static void	petty_sort(t_stack *a, t_stack *b, bool is_five)
{
	climb(a, b, cheapest_climb(a->top, 0, a->size), true);
	pb(a, b);
	if (is_five)
	{
		climb(a, b, cheapest_climb(a->top, 1, a->size), true);
		pb(a, b);
		trisort(a);
		pa(b, a);
	}
	else
		trisort(a);
	pa(b, a);
}

void cost_analysis(t_token *src, t_token *dst, int src_len, int dst_len)
{
	while (src)
	{
		src->cost_a = cheapest_climb(src, src->index, src_len);
		if (src->target)
            src->cost_b = cheapest_climb(dst, src->target->index, dst_len);
        src = src->next;
	}
}

static void	skimp_sort(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
	{
		set_targets(a->top, b->top);
		cost_analysis(a->top, b->top, a->size, b->size);
	}
}

void	push_swap(t_stack *a)
{
	t_stack	b;

	b.top = NULL;
	b.bot = NULL;
	b.size = 0;
	if (a->size == 2)
		sa(a);
	if (a->size == 3)
		trisort(a);
	if (a->size == 4)
		petty_sort(a, &b, false);
	if (a->size == 5)
		petty_sort(a, &b, true);
	else
		skimp_sort(a, &b);
}
