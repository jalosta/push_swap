/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:03:12 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/14 16:18:56 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	trisort(t_stack *a)
{
	t_token	*max;

	max = find_min_max(a->top, 0);
	if (a->top->index == max->index)
		ra(a);
	else if (a->top->next->index == max->index)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}

static void	petty_sort(t_stack *a, t_stack *b, bool is_five)
{
	climb(a, b, cheapest_climb(a->top, 0, a->size), 1);
	pb(a, b);
	if (is_five)
	{
		climb(a, b, cheapest_climb(a->top, 1, a->size), 1);
		pb(a, b);
		trisort(a);
		pa(b, a);
	}
	else
		trisort(a);
	pa(b, a);
}

static void	execute_move(t_stack *a, t_stack *b, t_token *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(a, b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
	climb(a, b, cheapest->cost_a, 1);
	climb(a, b, cheapest->cost_b, 0);
}

// static void	skimp_sort(t_stack *a, t_stack *b)
// {
// 	t_token	*min;

// 	pb(a, b);
// 	pb(a, b);
// 	while (a->size > 3)
// 	{
// 		set_targets(a->top, b->top, 1);
// 		cost_analysis(a->top, b->top, a->size, b->size);
// 		execute_move(a, b, cheapest_insert(a->top));
// 		pb(a, b);
// 		if (b->top->index && b->size > 1)
// 			rb(b);
// 	}
// 	trisort(a);
// 	while (b->size > 0)
// 	{
// 		set_targets(b->top, a->top, 0);
// 		climb(a, b, cheapest_climb(a->top, b->top->target->index, a->size), 1);
// 		pa(b, a);
// 	}
// 	min = find_min_max(a->top, 1);
// 	climb(a, NULL, cheapest_climb(a->top, min->index, a->size), 1);
// }

static void	skimp_sort(t_stack *a, t_stack *b)
{
	int		cost_head;
	int		cost_next;
	t_token	*min;

	pb(a, b);
	pb(a, b);
	while (a->size > 3)
	{
		set_targets(a->top, b->top, true);
		cost_analysis(a->top, b->top, a->size, b->size);
		execute_move(a, b, cheapest_insert(a->top));
		pb(a, b);
	}
	trisort(a);
	while (b->size > 0)
	{
		set_targets(b->top, a->top, false);
		cost_head = cheapest_climb(a->top, b->top->target->index, a->size);
		if (b->size > 1)
		{
			cost_next = cheapest_climb(a->top, b->top->next->target->index,
					a->size);
			if (abs(cost_next) + 1 < abs(cost_head))
				sb(b);
		}
		climb(a, b, cheapest_climb(a->top, b->top->target->index, a->size),
			true);
		pa(b, a);
	}
	min = find_min_max(a->top, true);
	climb(a, NULL, cheapest_climb(a->top, min->index, a->size), true);
}

void	push_swap(t_stack *a)
{
	t_stack	b;

	b.top = NULL;
	b.bot = NULL;
	b.size = 0;
	if (a->size == 2)
		write(1, "sa\n", 3);
	else if (a->size == 3)
		trisort(a);
	else if (a->size == 4)
		petty_sort(a, &b, 0);
	else if (a->size == 5)
		petty_sort(a, &b, 0);
	else
		skimp_sort(a, &b);
}
