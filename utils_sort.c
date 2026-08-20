/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:42:25 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 15:32:56 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_maxindex(t_stack *stack_a)
{
	int	max_index;
	int	i;

	max_index = 0;
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] > stack_a->values[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	find_minindex(t_stack *stack_a)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] < stack_a->values[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	sort_top(t_stack *stack_a)
{
	
}

void	sort_bottom(t_stack *stack_a)
{
	int	max_index;

	max_index = find_maxindex(stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	if (max_index == 0)
		ra(stack_a);
	if (max_index == 1)
		rra(stack_a);
}