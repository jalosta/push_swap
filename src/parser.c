/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:08:56 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/12 10:59:50 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	tokenizer(char *s, t_stack *a)
{
	long	value;
	int		sign;

	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	value = 0;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			error(a, NULL);
		value = value * 10 + (*s - '0');
		if (value * (long)sign >= INT_MAX || (value * (long)sign) <= INT_MIN)
			error(a, NULL);
		s++;
	}
	return (sign * (int)value);
}

static void	stack_new_token(t_stack *a, int token_value)
{
	t_token	*new;

	if (is_duplicate(*a, token_value))
		error(a, NULL);
	new = malloc(sizeof(t_token));
	if (!new)
		error(a, NULL);
	new->value = token_value;
	new->prev = NULL;
	new->next = a->top;
	if (!new->next)
		a->bot = new;
	else
		a->top->prev = new;
	a->top = new;
	a->size++;
}

void	parser(char *s, t_stack *a)
{
	int		i;
	char	*end;
	char	*start;

	i = 0;
	while (s[i])
		i++;
	end = s + i;
	while (end > s)
	{
		while (end > s && *(end - 1) == ' ')
			end--;
		if (end == s)
			return ;
		start = end;
		while (start > s && *(start - 1) != ' ')
			start--;
		*end = '\0';
		stack_new_token(a, tokenizer(start, a));
		end = start;
	}
}
