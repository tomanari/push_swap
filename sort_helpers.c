/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by malves-a          #+#    #+#             */
/*   Updated: 2026/09/01 15:38:47 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (is_sorted(stack_a) == 1)
		return ;
	sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	a0;
	int	a1;
	int	a2;

	if (stack_a->size <= 1 || is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
	{
		sa(stack_a);
		return ;
	}
	a0 = stack_a->values[0];
	a1 = stack_a->values[1];
	a2 = stack_a->values[2];
	if (a0 > a1 && a0 > a2)
		ra(stack_a);
	else if (a1 > a0 && a1 > a2)
		rra(stack_a);
	if (!is_sorted(stack_a))
		sa(stack_a);
}
