/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:10:38 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/31 06:29:35 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	tokenize(char *arg, t_context *c)
{
	long	value;
	int		sign;

	sign = 1;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	value = 0;
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			error(2, c);
		value = value * 10 + (*arg - '0');
		arg++;
	}
	if (value * sign <= INT_MIN || value * sign >= INT_MAX)
		error(3, c);
	return ((int)value * sign);
}

void	stack(int token_value, t_context *c)
{
	t_token	*new_token;
	t_token	*top;

	top = c->a.top;
	while (top)
	{
		if (top->value == token_value)
			error(4, c);
		top = top->next;
	}
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		error(0, c);
	new_token->value = token_value;
	new_token->prev = NULL;
	top = c->a.top;
	new_token->next = top;
	if (!top)
		c->a.bot = new_token;
	else
		top->prev = new_token;
	c->a.top = new_token;
	c->a.size++;
}

void	parse(char *arg, t_context *c)
{
	char	*end;
	char	*start;
	char	temp;

	if (*arg == ' ')
		error(5, c);
	end = arg + ft_strlen(arg);
	if (*(end - 1) == ' ')
		error(5, c);
	while (end > arg)
	{
		if (*(end - 1) == ' ' && (--end > arg && *(end - 1) == ' '))
			error(5, c);
		if (end == arg)
			return ;
		start = end - 1;
		while (start > arg && *(start - 1) != ' ')
			start--;
		temp = *end;
		*end = '\0';
		stack(tokenize(start, c), c);
		*end = temp;
		end = start;
	}
}
