/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("simple");
	if (strategy == MEDIUM)
		return ("medium");
	if (strategy == COMPLEX)
		return ("complex");
	return ("adaptive");
}

const char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM)
		return ("O(n sqrt(n))");
	return ("O(n log(n))");
}

static void	write_text(int fd, const char *text)
{
	int	length;

	length = 0;
	while (text[length])
		length++;
	write(fd, text, length);
}

static void	write_long(int fd, long value)
{
	char	buffer[24];
	int	index;

	index = 23;
	buffer[index--] = '\0';
	if (value == 0)
		buffer[index--] = '0';
	if (value < 0)
	{
		write(fd, "-", 1);
		value = -value;
	}
	while (value > 0)
	{
		buffer[index--] = '0' + value % 10;
		value /= 10;
	}
	write_text(fd, &buffer[index + 1]);
}

void	print_benchmark(t_stack *a, double disorder, t_strategy strategy)
{
	long	*i;
	long	percentage;

	i = a->stats->counts;
	percentage = (long)(disorder * 10000.0 + 0.5);
	write_text(2, "[bench] disorder: ");
	write_long(2, percentage / 100);
	write(2, ".", 1);
	if (percentage % 100 < 10)
		write(2, "0", 1);
	write_long(2, percentage % 100);
	write_text(2, "%\n[bench] strategy: ");
	write_text(2, strategy_name(strategy));
	write_text(2, " (");
	write_text(2, strategy_complexity(strategy));
	write_text(2, ")\n[bench] operations: ");
	write_long(2, a->stats->total);
	write_text(2, "\n[bench] counts: sa=");
	write_long(2, i[0]); write_text(2, " sb="); write_long(2, i[1]);
	write_text(2, " ss="); write_long(2, i[2]); write_text(2, " pa="); write_long(2, i[3]);
	write_text(2, " pb="); write_long(2, i[4]); write_text(2, " ra="); write_long(2, i[5]);
	write_text(2, " rb="); write_long(2, i[6]); write_text(2, " rr="); write_long(2, i[7]);
	write_text(2, " rra="); write_long(2, i[8]); write_text(2, " rrb="); write_long(2, i[9]);
	write_text(2, " rrr="); write_long(2, i[10]); write(2, "\n", 1);
}

static int	operation_index(char *operation)
{
	char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int	i;

	i = 0;
	while (i < 11)
	{
		if (strcmp(operation, names[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	print_operation(char *operation, t_stack *stack)
{
	int	i;
	int	index;

	if (stack && stack->stats)
	{
		index = operation_index(operation);
		if (index >= 0)
		{
			stack->stats->counts[index]++;
			stack->stats->total++;
		}
	}

	i = 0;
	while (operation[i])
	{
		write(1, &operation[i], 1);
		i++;
	}
	write(1, "\n", 1);
}