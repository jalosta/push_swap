/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:27:36 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/09 19:40:43 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	demolish(t_stack s)
{
	t_token	*next;

	while (s.size > 0)
	{
		next = s.top->next;
		free(s.top);
		s.top = next;
		s.size--;
	}
}

static bool	sorted(t_token *t)
{
	while (t && t->next)
	{
		if (t->value > t->next->value)
			return (false);
		t = t->next;
	}
	return (true);
}

static void	index_tokens(t_token *top)
{
	t_token	*t;
	t_token	*current;
	int		i;

	t = top;
	while (t)
	{
		current = top;
		i = 0;
		while (current)
		{
			if (t->value < current->value)
				i++;
			current = current->next;
		}
		t->index = i;
		t = t->next;
	}
}

void	error(t_stack *a, t_stack *b)
{
	demolish(*a);
	if (b)
		demolish(*b);
	write(2, "Error\n", 6);
	exit(1);
}

#include <stdio.h>
void print_results(t_token *t)
{
	while (t)
	{
		printf("%i", t->value);
		t = t->next;
		if (t)
			printf(" ");
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	int		c;

	if (argc < 2)
		return (0);
	a.top = NULL;
	a.bot = NULL;
	a.size = 0;
	c = argc - 1;
	while (c)
		parser(argv[c--], &a);
	if (a.size < 2)
		error(&a, NULL);
	index_tokens(a.top);
	if (!sorted(a.top))
		push_swap(&a);
	print_results(a.top);
	demolish(a);
}
