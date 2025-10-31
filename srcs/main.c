/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:14:11 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/31 12:24:28 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	sorted(t_token *tokens)
{
	while (tokens && tokens->next)
	{
		if (tokens->value > tokens->next->value)
			return (false);
		tokens = tokens->next;
	}
	return (true);
}

void	error(int msg, t_context *c)
{
	demolish(&c->a);
	demolish(&c->b);
	write(2, "Error\n", 6);
	if (msg == 1)
		printf("Stack empty\n");
	if (msg == 2)
		printf("Invalid token\n");
	if (msg == 3)
		printf("Limits\n");
	if (msg == 4)
		printf("Duplicate\n");
	if (msg == 5)
		printf("Invalid syntax\n");
	exit(0);
}

static void	index_tokens(t_stack *a)
{
	t_token	*target;
	t_token	*constant;
	int		count;

	target = a->top;
	while (target)
	{
		count = 0;
		constant = a->top;
		while (constant)
		{
			if (target->value > constant->value)
				count++;
			constant = constant->next;
		}
		target->index = count;
		target = target->next;
	}
}

static void	initialize(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bot = NULL;
	a->size = 0;
	b->top = NULL;
	b->bot = NULL;
	b->size = 0;
}

int	main(int argc, char **argv)
{
	t_context	c;
	t_token		*progress;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	initialize(&c.a, &c.b);
	if (argc == 2)
		parse(argv[1], &c);
	else
	{
		while (argc > 1)
			stack(tokenize(argv[--argc], &c), &c);
	}
	if (!c.a.size)
		error(1, &c);
	index_tokens(&c.a);
	c.price = 0;
	if (!sorted(c.a.top))
		push_swap(&c, &c.a, &c.b, c.a.size);
	printf("price = %d\n", c.price);
	progress = c.a.top;
	printf("A: ");
	while (progress)
	{
		printf("%i ", progress->value);
		progress = progress->next;
	}
	printf("\n");
	demolish(&c.a);
	demolish(&c.b);
}
