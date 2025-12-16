/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:03:12 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/16 17:10:52 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	trisort(t_stack *a)
{
	t_token	*max;

	max = find_min_max(a->top, 0);
	if (a->top->i == max->i)
		ra(a);
	else if (a->top->next->i == max->i)
		rra(a);
	if (a->top->i > a->top->next->i)
		sa(a);
}

static void	petty_sort(t_stack *a, t_stack *b, bool is_five)
{
	climb(a, b, cheapest_climb(a->top, 0, a->len), 1);
	pb(a, b);
	if (is_five)
	{
		climb(a, b, cheapest_climb(a->top, 1, a->len), 1);
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
	while (cheapest->c_a > 0 && cheapest->c_b > 0)
	{
		rr(a, b);
		cheapest->c_a--;
		cheapest->c_b--;
	}
	while (cheapest->c_a < 0 && cheapest->c_b < 0)
	{
		rrr(a, b);
		cheapest->c_a++;
		cheapest->c_b++;
	}
	climb(a, b, cheapest->c_a, 1);
	climb(a, b, cheapest->c_b, 0);
}

static void	skimp_sort(t_stack *a, t_stack *b)
{
	t_token	*min;

	pb(a, b);
	pb(a, b);
	if (b->top->i < b->bot->i)
		sb(b);
	while (a->len > 3)
	{
		set_targets(a->top, b->top, 1);
		set_costs(a, b);
		execute_move(a, b, cheapest_insert(a->top));
		pb(a, b);
	}
	trisort(a);
	while (b->len > 0)
	{
		set_targets(b->top, a->top, 0);
		climb(a, b, cheapest_climb(a->top, b->top->target->i, a->len), 1);
		pa(b, a);
	}
	min = find_min_max(a->top, 1);
	climb(a, NULL, cheapest_climb(a->top, min->i, a->len), 1);
}

void	push_swap(t_stack *a)
{
	t_stack	b;

	b.top = NULL;
	b.bot = NULL;
	b.len = 0;
	if (a->len == 2)
		write(1, "sa\n", 3);
	else if (a->len == 3)
		trisort(a);
	else if (a->len == 4)
		petty_sort(a, &b, 0);
	else if (a->len == 5)
		petty_sort(a, &b, 1);
	else
		skimp_sort(a, &b);
}
