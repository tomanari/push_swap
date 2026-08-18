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
	t_node	*stack_a;
	t_node	*conteiner;

	conteiner = stack_a;
	while (conteiner != NULL)
	{
		printf("%d\n", conteiner->num);
		conteiner = conteiner->next;
	}
	return (0);
}
