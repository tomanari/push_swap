/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:17:54 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 18:14:38 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stats	stats;
	t_config	config;
	double	disorder;
	int		total;
	int		start;
	t_strategy	used;

	if (argc < 2)
		return (0);
	start = parse_config(argc, argv, &config);
	if (start < 0 || start == argc)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	total = count_total_elements(argc - start + 1, argv + start - 1);
	if (total <= 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack(total);
	b = init_stack(total);
	if (!a || !b)
		error_exit(a, b);
	stats = (t_stats){0};
	a->stats = &stats;
	b->stats = &stats;
	if (!parse_args_from(argc, argv, start, a) || has_duplicate(a))
		error_exit(a, b);
	disorder = compute_disorder(a);
	used = config.strategy;
	if (used == ADAPTIVE)
	{
		if (disorder < 0.2)
			used = SIMPLE;
		else if (disorder < 0.5)
			used = MEDIUM;
		else
			used = COMPLEX;
	}
	if (!is_sorted(a))
		sort_selected(a, b, config.strategy, disorder);
	if (config.bench)
		print_benchmark(a, disorder, used);
	free_stack(a);
	free_stack(b);
	return (0);
}
