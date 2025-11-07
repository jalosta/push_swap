/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:14:11 by jalosta-          #+#    #+#             */
/*   Updated: 2025/11/07 10:21:28 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool sorted(t_token *t)
{
    while (t && t-> next)
    {
        if (t->next->value < t->value)
            return false;
        t = t->next;
    }
	return true;
}

void	error(char *msg, t_context *c)
{
	demolish(&c->a);
	demolish(&c->b);
	if (msg)
		printf("%s ", msg);
	printf("Error\n");
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
			if (target->value < constant->value)
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
	b->top = NULL;
	a->bot = NULL;
	b->bot = NULL;
	a->size = 0;
	b->size = 0;
}

static void print_results(t_context c)
{
	t_token *current = c.a.top;
	printf("\nA: ");
	while (current)
	{
		printf("%i", current->value);
		current = current->next;
		if (current)
			printf(" ");
		else
			printf("\nprice = %d\n", c.price);
	}
}

int	main(int argc, char **argv)
{
	t_context	c;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	initialize(&c.a, &c.b);
	if (argc == 2)
		parse(argv[1], &c);
	else
	{
		while (argc > 1)
			stack(&c.a, tokenize(argv[--argc], &c), &c);
	}
	index_tokens(&c.a);
	c.price = 0;
	if (!sorted(c.a.top))
		push_swap(&c, &c.a, &c.b, c.a.size);
	print_results(c);
	demolish(&c.a);
	demolish(&c.b);
}
