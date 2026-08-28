/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:58:31 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/25 16:10:51 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_max(t_stack *stack_b, int max_index)
{
	int	i;

	i = 0;
	if (max_index <= stack_b->size / 2)
	{
		while (i < max_index)
		{
			rb(stack_b);
			i++;
		}
	}
	else
	{
		while (i < stack_b->size - max_index)
		{
			rrb(stack_b);
			i++;
		}
	}
}

static void	ft_process_chunk(t_stack *stack_a, t_stack *stack_b,
	int start, int end)
{
	while (ft_haschunk(stack_a, start, end))
	{
		if (stack_a->values[0] >= start
			&& stack_a->values[0] < end)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void	ft_push_max(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;

	while (stack_b->size > 0)
	{
		max_index = find_maxindex(stack_b);
		ft_rotate_max(stack_b, max_index);
		pa(stack_a, stack_b);
	}
}

void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	chunk;
	int	start;
	int	end;
	int	total;

	chunk = 0;
	total = stack_a->size;
	chunk_size = ft_sqrt(total);
	start = chunk * chunk_size;
	end = (chunk + 1) * chunk_size;
	while (start < total)
	{
		ft_process_chunk(stack_a, stack_b, start, end);
		chunk++;
		start = chunk * chunk_size;
		end = (chunk + 1) * chunk_size;
	}
	ft_push_max(stack_a, stack_b);
}
