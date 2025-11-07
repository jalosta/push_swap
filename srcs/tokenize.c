/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:10:38 by jalosta-          #+#    #+#             */
/*   Updated: 2025/11/07 10:11:10 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	tokenize(char *arg, t_context *c)
{
	long	value;
	int		sign;

	sign = 1;
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	value = 0;
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			error("Invalid Token", c);
		value = value * 10 + (*arg - '0');
		arg++;
	}
	if (value * (long)sign <= INT_MIN || value * (long)sign >= INT_MAX)
		error("Limits", c);
	return (sign * (int)value);
}

static bool	is_duplicate(t_token *t, int target)
{
	while (t)
	{
		if (target == t->value)
			return (true);
		t = t->next;
    }
	return (false);
}

void	stack(t_stack *a, int token_value, t_context *c)
{
	t_token	*new;

	if (is_duplicate(a->top, token_value))
		error("Duplicate", c);
	new = malloc(sizeof(t_token));
	if (!new)
		error(NULL, c);
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

void	parse(char *arg, t_context *c)
{
	char *end;
	char *start;

	if (*arg == ' ')
		error("Leading Space", c);
	end = arg + strlen(arg);
	if (*(end - 1) == ' ')
		error("Trailing Space", c);
	while (arg < end)
	{
		start = end - 1;
		while (arg < start && *(start - 1) != ' ')
			start--;
		*end = '\0';
		stack(&c->a, tokenize(start, c), c);
		*end = ' ';
		end = start;
		if (*(end - 1) == ' ')
			end--;
		if (arg < end && *(end - 1) == ' ')
			error("Syntax", c);
	}
}