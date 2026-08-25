/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:58:31 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 18:58:43 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack_a, int value)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (i <stack_a->size)
	{
		if (stack_a->values[i] < value)
			index++;
		i++;
	}
	return (index);
}

void	ft_chunk_index(t_stack *stack_a)
{
	int	*indexes;
	int	i;

	i = 0;
	indexes = malloc(sizeof(int) * stack_a->size);
	if (!indexes)
		return ;
	while (i < stack_a->size)
	{
		indexes[i] = get_index(stack_a, stack_a->values[i]);
		i++;
	}
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->values[i]= indexes[i];
		i++;
	}
	free(indexes);
}

void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	chunk;
	int	start;
	int	end;

	chunk = 0;
	chunk_size = ft_sqrt(stack_a->size);
	start = chunk * chunk_size;
	end = (chunk + 1) * chunk_size;
	

}
