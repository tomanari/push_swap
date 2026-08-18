/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:24:33 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/17 16:46:40 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
	{
		int						num;
		int						index;
		struct s_node	*next;
		struct s_node	*prev;
	} t_node;

typedef	struct s_stack
	{
		t_node	*head;
		t_node	*tail;
		int			size;
	} t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;

	int			bench;
	int			total_ops;
}	t_data;

t_node	*new_node(int num);
void	add_node(t_stack *stack, t_node *node);

void	data_init(t_data *data);

void	print_stack(t_stack *stack);

#endif
