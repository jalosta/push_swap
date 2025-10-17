/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:14:11 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/17 19:01:31 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
    t_token *a;
    
    if (argc < 2 || !argv[1][0])
        return 0;
    if (argc == 2)
        argv = ft_split(argv[1]);
    stack(&a, argv, argc);
}