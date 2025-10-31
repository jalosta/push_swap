/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:20:38 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/31 12:45:38 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void handle_instructions(t_context *c)
{
    char *instruction;
    
    read(0, instruction, 3);
    while (instruction[0] != '\0')
    {
        if (strcmp(instruction, "sa\n") == 0)
            swap(&c->a);
        else if (strcmp(instruction, "sb\n") == 0)
            swap(&c->b);
        else if (strcmp(instruction, "ss\n") == 0)
        {
            swap(&c->a);
            swap(&c->b);
        }
        else if (strcmp(instruction, "pa\n") == 0)
            push(&c->b, &c->a);
        else if (strcmp(instruction, "pb\n") == 0)
            push(&c->a, &c->b);
        else if (strcmp(instruction, "ra\n") == 0)
            rot(&c->a);
        else if (strcmp(instruction, "rb\n") == 0)
            rot(&c->b);
        else if (strcmp(instruction, "rr\n") == 0)
        {
            rot(&c->a);
            rot(&c->b);
        }
        else if (strcmp(instruction, "rra\n") == 0)
            rev_rot(&c->a);
        else if (strcmp(instruction, "rrb\n") == 0)
            rev_rot(&c->b);
        else if (strcmp(instruction, "rrr\n") == 0)
        {
            rev_rot(&c->a);
            rev_rot(&c->b);
        }
        else
            error(2, c);
        memset(instruction, 0, sizeof(instruction));
        read(0, instruction, 3);
    }
}

int	main(int argc, char **argv)
{
	t_context	c;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	initialize(&c.a, &c.b);
	if (argc == 2)
		parse(argv[1], &c);
	else
	{
		while (argc > 1)
			stack(tokenize(argv[--argc], &c), &c);
	}
	if (!c.a.size)
		error(1, &c);
	index_tokens(&c.a);
	c.price = 0;
	demolish(&c.a);
	demolish(&c.b);
}
