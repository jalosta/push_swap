/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:27:36 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/16 14:04:01 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	index_tokens(t_token *top)
{
	t_token	*t;
	t_token	*current;
	int		index;

	t = top;
	while (t)
	{
		current = top;
		index = 0;
		while (current)
		{
			if (t->n > current->n)
				index++;
			current = current->next;
		}
		t->i = index;
		t = t->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	a.top = NULL;
	a.bot = NULL;
	a.len = 0;
	while (argc > 1)
		parser(argv[--argc], &a);
	index_tokens(a.top);
	if (!sorted(a.top))
		push_swap(&a);
	demolish(a);
}
