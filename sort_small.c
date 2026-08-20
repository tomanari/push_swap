/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 12:23:56 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 16:32:14 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (is_sorted(stack_a) == 1)
		return ;
	sa(stack_a);
}

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

void	sort_three(t_stack *stack_a)
{
	sort_bottom(stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	sort_two(stack_a);
}

void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;	
	sort_top(stack_a);
	pb(stack_a, stack_b);
	if (size == 5)
	{
		sort_top(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_b);
	if (size == 5)
		pa(stack_b);
}
