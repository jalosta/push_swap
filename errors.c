/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:53:02 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/14 14:52:27 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	demolish(t_token **stack)
{
	t_token	*tmp;
	t_token	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_matrix(char **argv, int i)
{
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	err_demolish(t_token **a, char **argv, bool free_argv)
{
	demolish(a);
	if (free_argv)
		free_matrix(argv, -1);
	write(2, "Error\n", 6);
	exit(1);
}

bool	bad_syntax(char *s)
{
	if (!(ft_isdigit(*s) || *s == '+' || *s == '-'))
		return (true);
	if ((*s == '+' || *s == '-') && !ft_isdigit(s[1]))
		return (true);
	while (*++s)
	{
		if (!ft_isdigit(*s))
			return (true);
	}
	return (false);
}

bool	err_dup(t_token *a, int nbr)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->value == nbr)
			return (true);
		a = a->next;
	}
	return (false);
}