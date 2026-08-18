/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:27:39 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/17 16:21:56 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_data	*data;
	t_node	*node;

	data_init(data);

	node = new_node(3);
	add_node(&data->stack_a, node);

	node = new_node(5);
	add_node(&data->stack_a, node);

	node = new_node(7);
	add_node(&data->stack_a, node);

	print_stack(&data->stack_a);

	return (0);
}
