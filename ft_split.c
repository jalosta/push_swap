/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:18:17 by jalosta-          #+#    #+#             */
/*   Updated: 2025/10/14 17:26:12 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_count(char *s, size_t count)
{
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (*s)
		{
			count++;
			while (*s && !ft_isspace(*s))
				s++;
		}
	}
	return (count);
}

static void	*free_all(char **s, int count)
{
	while (--count >= 0)
		free(s[count]);
	free(s);
	return (NULL);
}

static int	copy_word(char **result, char *start, size_t len, int i)
{
	int	j;

	j = 0;
	result[i] = malloc(len + 1);
	if (!result[i])
		return (0);
	while (j < len)
	{
		result[i][j] = start[j];
		j++;
	}
	result[i][len] = '\0';
	return (1);
}

char	**ft_split(char *s)
{
	char	**result;
	char	*start;
	int		i;

	result = malloc((word_count(s, 0) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		start = s;
		while (*s && !ft_isspace(*s))
			s++;
		if (s > start)
		{
			if (!copy_word(result, start, s - start, i))
				return (free_all(result, i));
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
