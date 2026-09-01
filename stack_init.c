/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:32 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/18 16:46:08 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*alloc_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->values = malloc(sizeof(int) * capacity);
	if (!stack->values)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	stack->stats = NULL;
	return (stack);
}

t_stack	*init_stack(int capacity)
{
	if (capacity <= 0)
		return (NULL);
	return (alloc_stack(capacity));
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->values)
		free(stack->values);
	free(stack);
}
