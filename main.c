/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:15:53 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/14 15:03:54 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	new->next = NULL;
}

static void	stack_token(t_token **stack, int nbr)
{
    t_token *token;
    
    if (!stack)
        return ;
    token = malloc(sizeof(t_token));
    if (!token)
        return ;
    token->value = nbr;
    token->next = NULL;
    ft_lstadd_back(stack, token);
}

static void	stack(t_token **a, bool free_argv, char **argv)
{
	long	nbr;
	int		i;

	while (argv[i])
	{
		nbr = ft_atoi(argv[1]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			err_demolish(a, argv, free_argv);
		if (err_dup(*a, (int)nbr))
			err_demolish(a, argv, free_argv);
		stack_token(a, (int)nbr);
	}
	if (free_argv)
		free_matrix(argv, -1);
}

static bool	parse(char ***argv)
{
	*argv = ft_split(*argv[1]);
	if (!*argv || bad_syntax(*argv))
		return (err_free(*argv, true));
	return (false);
}

int	main(int argc, char **argv)
{
	t_token	*a;
	t_token	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1] == ""))
		return (1);
	if (argc == 2)
		stack(&a, parse(&argv[1]), argv);
	else
		stack(&a, false, argv + 1);
	if (!tidy_stack(a))
		push_swap(&a, &b);
	demolish(&a);
}
