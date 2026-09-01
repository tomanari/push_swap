/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:13:57 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/20 18:14:03 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char character)
{
	return (character == ' ' || character == '\t' || character == '\n'
		|| character == '\v' || character == '\f' || character == '\r');
}

static int	count_words_in_str(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_space(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

int	count_total_elements(int argc, char **argv)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < argc)
	{
		total += count_words_in_str(argv[i]);
		i++;
	}
	return (total);
}
