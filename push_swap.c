/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:36:25 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 14:36:51 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_init(t_data *data)
{
	data->stack_a.head = NULL;
	data->stack_a.tail = NULL;
	data->stack_a.size = 0;
	data->stack_b.head = NULL;
	data->stack_b.tail = NULL;
	data->stack_b.size = 0;
	data->bench = 0;
	data->total_ops = 0;
}
