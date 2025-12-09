/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:03:12 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/09 19:39:44 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack *a)
{
	if (a->top->index == 0)
		ra(a);
	if (a->top->next->index == 0)
		rra(a);
	if (a->top->index < a->top->next->index)
		sa(a);
}

void	push_swap(t_stack *a)
{
	if (a->size == 2)
		sa(a);
	if (a->size == 3)
		sort_three(a);
}
