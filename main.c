/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:15:53 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/14 17:46:12 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_token	*ft_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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

/* check if stack is sorted in ascending order.
 * if stack is NULL or has one token, true.
 * else, compare each token with the next one.
 * if any token is greater than the next one, false.
 * if all tokens are in ascending order, true.
*/
bool	stack_tidy(t_token *token)
{
	if (!token)
		return (true);
	while (token->next)
	{
		if (token->value > token->next->value)
			return (false);
		token = token->next;
	}
	return (true);
}

/* create a new node with token and add it to the back of stack.
 * if stack is NULL, do nothing.
 * if malloc fails, do nothing.
*/
static void	stack_token(t_token **stack, int nbr)
{
	t_token	*token;

	if (!stack)
		return ;
	token = malloc(sizeof(t_token));
	if (!token)
		return ;
	token->value = nbr;
	token->next = NULL;
	ft_lstadd_back(stack, token);
}

/* create stack a from matrix of parameters.
 * check for duplicates and out of bounds integers.
 * if error, demolish stack a and free matrix if needed.
 * exit with error message.
*/
static void	stack(t_token **a, bool free_argv, char **argv)
{
	long	nbr;
	int		i;

    i = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			err_demolish(a, argv, free_argv);
		if (err_dup(*a, (int)nbr))
			err_demolish(a, argv, free_argv);
		stack_token(a, (int)nbr);
        i++;
	}
	if (free_argv)
		free_matrix(argv, -1);
}

/* parse single parameter into several and create stack a.
 * check for bad syntax in each parameter.
 * if bad syntax, free matrix and exit with error.
 * return matrix of parameters.
*/
static char **parse(char **argv)
{
	int		i;
	argv = ft_split(*argv);
	if (!argv)
		error();
	i = 0;
	while (argv[i])
	{
		if (bad_syntax(*argv))
		{
			free_matrix(argv, -1);
			error();
		}
		i++;
	}
	return (argv);
}

/* if one parameter, parse it into several and create stack a.
 * else create stack a from several parameters.
 * check stack a for duplicates and out of bounds integers.
 * if error, demolish stack a and exit.
 * if no error, sort stack a using stack b as auxiliary.
 * demolish stack a and b and exit.
*/
int	main(int argc, char **argv)
{
	t_token	*a;
	t_token	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
    {
        argv = parse(argv + 1);
		stack(&a, true, argv);
    }
	else
		stack(&a, false, argv + 1);
	if (!stack_tidy(a))
	{
		// push_swap(&a, &b);
		printf("Stack untidy\n");
		demolish(&a);
		return (1);
	}
    printf("Stack A: ");
    while (a)
    {
        printf("%d ", a->value);
        a = a->next;
    }
    printf("\n");
	demolish(&a);
}
