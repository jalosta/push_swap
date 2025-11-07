/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:08:01 by jalosta-          #+#    #+#             */
/*   Updated: 2025/11/07 07:13:16 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_context *c)
{
	swap(&c->a);
	c->price++;
	printf("%d: sa\n", c->price);
	// write(1, "sa\n", 3);
}

void	sb(t_context *c)
{
	swap(&c->b);
	c->price++;
	printf("%d: sb\n", c->price);
	// write(1, "sb\n", 3);
}

void	ss(t_context *c)
{
	swap(&c->a);
	swap(&c->b);
	c->price++;
	printf("%d: ss\n", c->price);
	// write(1, "ss\n", 3);
}

void	ra(t_context *c)
{
	rot(&c->a);
	c->price++;
	printf("%d: ra\n", c->price);
	// write(1, "ra\n", 3);
}

void	rb(t_context *c)
{
	rot(&c->b);
	c->price++;
	printf("%d: rb\n", c->price);
	// write(1, "rb\n", 3);
}

void	rr(t_context *c)
{
	rot(&c->a);
	rot(&c->b);
	c->price++;
	printf("%d: rr\n", c->price);
	// write(1, "rr\n", 3);
}

void	rra(t_context *c)
{
	rev_rot(&c->a);
	c->price++;
	printf("%d: rra\n", c->price);
	// write(1, "rra\n", 4);
}

void	rrb(t_context *c)
{
	rev_rot(&c->b);
	c->price++;
	printf("%d: rrb\n", c->price);
	// write(1, "rrb\n", 4);
}

void	rrr(t_context *c)
{
	rev_rot(&c->a);
	rev_rot(&c->b);
	c->price++;
	printf("%d: rrr\n", c->price);
	// write(1, "rrr\n", 4);
}

void	pa(t_context *c)
{
	push(&c->b, &c->a);
	c->price++;
	printf("%d: pa\n", c->price);
	// write(1, "pa\n", 3);
}

void	pb(t_context *c)
{
	push(&c->a, &c->b);
	c->price++;
	printf("%d: pb\n", c->price);
	// write(1, "pb\n", 3);
}
