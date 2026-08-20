/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:20:37 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 14:34:09 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to)
{
	int	temp;
	int	i;

	if (!from || !to || from->size == 0)
		return ;
	temp = from->values[0];
	i = 0;
	while (i < from->size - 1)
	{
		from->values[i] = from->values[i + 1];
		i++;
	}
	i = to->size;
	while (i > 0)
	{
		to->values[i] = to->values[i - 1];
		i--;
	}
	to->size++;
	to->values[0] = temp;
	from->size--;
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
}
