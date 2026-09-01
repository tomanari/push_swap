/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:28:39 by mtomanar          #+#    #+#             */
/*   Updated: 2026/09/01 16:30:59 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *a, int v)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < a->size)
		if (a->values[i++] < v)
			c++;
	return (c);
}

void	normalize_stack(t_stack *s)
{
	int	*c;
	int	i;

	c = malloc(sizeof(int) * s->size);
	if (!c)
		return ;
	i = 0;
	while (i < s->size)
	{
		c[i] = get_index(s, s->values[i]);
		i++;
	}
	i = 0;
	while (i < s->size)
	{
		s->values[i] = c[i];
		i++;
	}
	free(c);
}

int	ft_sqrt(int n)
{
	int	root;

	if (n <= 0)
		return (0);
	root = 1;
	while (root * root < n)
		root++;
	return (root);
}

int	ft_haschunk(t_stack *stack_a, int start, int end)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] >= start && stack_a->values[i] < end)
			return (1);
		i++;
	}
	return (0);
}
