/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:19:36 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/20 18:56:47 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	if (!a || a->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (a->values[i] > a->values[j++])
				mistakes++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
