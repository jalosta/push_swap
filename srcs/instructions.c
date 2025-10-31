/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:08:01 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/31 12:00:58 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_context *c)
{
	swap(&c->a);
	write(1, "sa\n", 3);
	c->price++;
}

void	sb(t_context *c)
{
	swap(&c->b);
	write(1, "sb\n", 3);
	c->price++;
}

void	ss(t_context *c)
{
	swap(&c->a);
	swap(&c->b);
	write(1, "ss\n", 3);
	c->price++;
}

void	ra(t_context *c)
{
	rot(&c->a);
	write(1, "ra\n", 3);
	c->price++;
}

void	rb(t_context *c)
{
	rot(&c->b);
	write(1, "rb\n", 3);
	c->price++;
}

void	rr(t_context *c)
{
	rot(&c->a);
	rot(&c->b);
	write(1, "rr\n", 3);
	c->price++;
}

void	rra(t_context *c)
{
	rev_rot(&c->a);
	write(1, "rra\n", 4);
	c->price++;
}

void	rrb(t_context *c)
{
	rev_rot(&c->b);
	write(1, "rrb\n", 4);
	c->price++;
}

void	rrr(t_context *c)
{
	rev_rot(&c->a);
	rev_rot(&c->b);
	write(1, "rrr\n", 4);
	c->price++;
}

void	pa(t_context *c)
{
	push(&c->b, &c->a);
	write(1, "pa\n", 3);
	c->price++;
}

void	pb(t_context *c)
{
	push(&c->a, &c->b);
	write(1, "pb\n", 3);
	c->price++;
}
