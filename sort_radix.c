/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:54:51 by malves-a          #+#    #+#             */
/*   Updated: 2026/09/01 15:38:29 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_copy(int *copy, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (copy[i] > copy[j])
			{
				tmp = copy[i];
				copy[i] = copy[j];
				copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	value_rank(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}

static int	*sorted_values(t_stack *a)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * a->size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		copy[i] = a->values[i];
		i++;
	}
	sort_copy(copy, a->size);
	return (copy);
}

static void	radix_pass(t_stack *a, t_stack *b, int *sorted, int bit)
{
	int	count;
	int	size;

	size = a->size;
	count = a->size;
	while (count-- > 0)
	{
		if ((value_rank(sorted, size, a->values[0]) >> bit) & 1)
			ra(a);
		else
			pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}

void	ft_sort_radix(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	bits;
	int	bit;
	int	max;

	sorted = sorted_values(a);
	if (!sorted)
		return ;
	max = a->size - 1;
	bits = 0;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	bit = 0;
	while (bit < bits)
	{
		radix_pass(a, b, sorted, bit);
		bit++;
	}
	free(sorted);
}
