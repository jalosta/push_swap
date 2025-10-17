/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:46:51 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/17 18:37:48 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			error();
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result <= INT_MIN || result >= INT_MAX)
		error();
	return (sign * (int)result);
}

void stack_token(int token, t_token **a)
{
    t_token *new_token;

    new_token->value = token;
}

void stack(t_token **a, char **argv, int argc)
{
	int token;

	while (argv[--argc])
	{
		token = ft_atoi(*argv);
        if (find_duplicate(token, *a))
            error();
        stack_token(token, a);
        argv++;
	}
}