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
