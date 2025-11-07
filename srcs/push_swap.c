/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:11:48 by jalosta-          #+#    #+#             */
/*   Updated: 2025/11/07 10:20:33 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack *s, t_context *c)
{
	if (!s->top->index)
		ra(c);
	else if (!s->top->next->index)
		rra(c);
	if (s->top->next->index > s->top->index)
		sa(c);
}

static int	cheapest(t_stack *s, int index)
{
	t_token	*current;
	int		distance;

	current = s->top;
	distance = 0;
	while (current && current->index != index)
	{
		distance++;
		current = current->next;
	}
	if (distance <= s->size / 2)
		return (distance);
	else
		return (distance - s->size);
}

static void	climb(t_context *c, int distance, bool is_a)
{
	if (is_a)
	{
		while (distance-- > 1)
			ra(c);
		while (distance++ < -1)
			rra(c);
	}
	if (!is_a)
	{
		while (distance-- > 1)
			rb(c);
		while (distance++ < -1)
			rrb(c);
	}
}

static void	small_sort(t_stack *a, t_context *c, bool is_five)
{
	climb(c, cheapest(a, 0), true);
	pb(c);
	if (is_five)
	{
		climb(c, cheapest(a, 1), true);
		pb(c);
		sort_three(a, c);
		pa(c);
	}
	else
		sort_three(a, c);
	pa(c);
}

static int	get_index_min(t_stack *a)
{
	t_token	*current;
	int		min;

	current = a->top;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

static int	spot_target(int index, t_stack *dst)
{
	t_token	*current;
	int		target;

	current = dst->top;
	target = INT_MAX;
	while (current)
	{
		if (current->index > index && current->index < target)
			target = current->index;
		current = current->next;
	}
	if (target == INT_MAX)
		target = get_index_min(dst);
	return (target);
}

static void	make_move(t_context *c, t_move *m)
{
	int	ca;
	int	cb;
	int	common;

	ca = m->cost_a;
	cb = m->cost_b;
	if ((ca > 0 && cb > 0) || (ca < 0 && cb < 0))
	{
		common = fmin(abs(ca), abs(cb));
		while (common-- >= 1)
		{
			if (ca > 0)
				rr(c);
			else
				rrr(c);
		}
		if (ca > 0)
			ca -= fmin(abs(m->cost_a), abs(m->cost_b));
		else
			ca += fmin(abs(m->cost_a), abs(m->cost_b));
		if (cb > 0)
			cb -= fmin(abs(m->cost_a), abs(m->cost_b));
		else
			cb += fmin(abs(m->cost_a), abs(m->cost_b));
	}
	while (ca > 0)
	{
		ra(c);
		ca--;
	}
	while (ca < 0)
	{
		rra(c);
		ca++;
	}
	while (cb > 0)
	{
		rb(c);
		cb--;
	}
	while (cb < 0)
	{
		rrb(c);
		cb++;
	}
}

static void	reap_cheapest(t_stack *a, t_stack *b, t_context *c)
{
	t_token	*current;
	t_move	best;
	t_move	m;
	int		ca;
	int		cb;

	current = a->top;
	best.sum = INT_MAX;
	while (current)
	{
		m.target = spot_target(current->index, b);
		ca = cheapest(a, current->index);
		cb = cheapest(b, m.target);
		if ((ca < 0 && cb > 0) || (ca > 0 && cb < 0))
			m.sum = abs(ca) + abs(cb);
		else
			m.sum = abs(ca) + abs(cb) - fmin(abs(ca), abs(cb));
		if (m.sum < best.sum)
		{
			best = m;
			best.cheapest = current->index;
			best.cost_a = ca;
			best.cost_b = cb;
		}
		current = current->next;
	}
	make_move(c, &best);
	pb(c);
}

static void	skimpy_sort(t_stack *a, t_stack *b, t_context *c)
{
	int	target;

	pb(c);
	pb(c);
	while (a->size > 0)
		reap_cheapest(a, b, c);
	printf("\n");
	climb(c, cheapest(b, 0), false);
	while (b->size > 0)
		pa(c);
}

void	push_swap(t_context *c, t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		sa(c);
	else if (size == 3)
		sort_three(a, c);
	else if (size == 4)
		small_sort(a, c, false);
	else if (size == 5)
		small_sort(a, c, true);
	else
		skimpy_sort(a, b, c);
}
