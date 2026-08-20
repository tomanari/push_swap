/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:09:00 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 18:33:53 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	ft_simple(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->size;
	while (i != 0)
	{
		sort_top(stack_a);
		ft_pb(stack_a, stack_b);
		i--;
	}
	i = stack_b->size;
	while (i != 0)
	{
		ft_pa(stack_a, stack_b);
		i--;
	}
}