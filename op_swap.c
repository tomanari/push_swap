/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:20:45 by mtomanar          #+#    #+#             */
/*   Updated: 2026/09/01 15:39:07 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = temp;
}

void	sa(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	ft_swap(stack_a);
	print_operation("sa", stack_a);
}

void	sb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	ft_swap(stack_b);
	print_operation("sb", stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if ((!stack_a || stack_a->size < 2)
		&& (!stack_b || stack_b->size < 2))
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	print_operation("ss", stack_a);
}
