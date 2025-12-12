/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:47:58 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/12 08:30:26 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_instructions(t_stack *a, t_stack *b, char *ins)
{
	if (!strcmp(ins, "sa"))
		sa(a);
	else if (!strcmp(ins, "sb"))
		sb(b);
	else if (!strcmp(ins, "pa"))
		pa(b, a);
	else if (!strcmp(ins, "pb"))
		pb(a, b);
	else if (!strcmp(ins, "ra"))
		ra(a);
	else if (!strcmp(ins, "rb"))
		rb(b);
	else if (!strcmp(ins, "rr"))
		rr(a, b);
	else if (!strcmp(ins, "rra"))
		rra(a);
	else if (!strcmp(ins, "rrb"))
		rrb(b);
	else if (!strcmp(ins, "rrr"))
		rrr(a, b);
	else
		error(a, b);
}

static void	fetch_parse_instructions(t_stack *a)
{
	char	buffer[1];
	int		i;
	char	ins[5];
	t_stack	b;

	b.top = NULL;
	b.bot = NULL;
	b.size = 0;
	i = 0;
	while (read(STDIN_FILENO, buffer, 1))
	{
		if (*buffer == '\n')
		{
			ins[i] = '\0';
			handle_instructions(a, &b, ins);
			i = 0;
		}
		else
		{
			ins[i++] = *buffer;
			if (i >= 4)
				error(a, &b);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;

	a.top = NULL;
	a.bot = NULL;
	a.size = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	while (argc > 1)
		parser(argv[--argc], &a);
	fetch_parse_instructions(&a);
	if (sorted(a.top))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	demolish(a);
}
