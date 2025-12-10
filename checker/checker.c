/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:47:58 by jalosta-          #+#    #+#             */
/*   Updated: 2025/12/10 21:47:11 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "checker.h"
// #include "../push_swap.h"

// int get_instructions(int fd)
// {
    
// }

// void handle_instuctions(t_stack *a, t_stack *b, char *ins)
// {
//     if (!strcmp(ins, "sa\n"))
// 		sa(a);
// 	else if (!strcmp(ins, "sb\n"))
// 		sb(b);
//     else if (!strcmp(ins, "pa\n"))
// 		pa(b, a);
// 	else if (!strcmp(ins, "pb\n"))
// 		pb(a, b);
// 	else if (!strcmp(ins, "ra\n"))
// 		ra(a);
// 	else if (!strcmp(ins, "rb\n"))
// 		rb(b);
// 	else if (!strcmp(ins, "rr\n"))
// 		rr(a, b);
// 	else if (!strcmp(ins, "rra\n"))
// 		rra(a);
// 	else if (!strcmp(ins, "rrb\n"))
// 		rrb(b);
// 	else if (!strcmp(ins, "rrr\n"))
// 		rrr(a, b);
// 	else
// 		error(a, b);
// }

// int main(int argc, char **argv)
// {
//     t_stack	a;
//     t_stack *b;
// 	int		c;

// 	if (argc < 2)
// 		return (0);
// 	a.top = NULL;
// 	a.bot = NULL;
// 	a.size = 0;
// 	c = argc - 1;
// 	while (c)
// 		parser(argv[c--], &a);
//     parse_instructions(get_instructions(STDIN_FILENO));
//     handle_instructions(a, );
//     if (sorted(a.top))
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);
// 	demolish(a);
// }