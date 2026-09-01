/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:32:19 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/25 16:10:21 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	root;

	if (n <= 0)
		return (0);
	root = 1;
	while (root * root < n)
		root++;
	return (root);
}

int	ft_haschunk(t_stack *stack_a, int start, int end)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] >= start && stack_a->values[i] < end)
			return (1);
		i++;
	}
	return (0);
}

void	normalize_stack(t_stack *stack)
{
	int	*copy;
	int	i;
	int	j;

	copy = malloc(sizeof(int) * stack->size);
	if (!copy)
		return ;
	i = 0;
	while (i < stack->size)
	{
		copy[i] = stack->values[i];
		i++;
	}
	sort_copy(copy, stack->size);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size && copy[j] != stack->values[i])
			j++;
		stack->values[i] = j;
		i++;
	}
	free(copy);
}
