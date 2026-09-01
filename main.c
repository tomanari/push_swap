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

static t_strategy	get_used(t_strategy s, double d)
{
	if (s != ADAPTIVE)
		return (s);
	if (d < 0.2)
		return (SIMPLE);
	if (d < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

static int	prepare_stacks(int argc, char **argv, t_data *data,
		t_config *cfg)
{
	int	start;
	int	total;

	start = parse_config(argc, argv, cfg);
	if (start < 0 || start == argc)
		return (0);
	total = count_total_elements(argc - start + 1, argv + start - 1);
	if (total <= 0)
		return (0);
	data->a = init_stack(total);
	data->b = init_stack(total);
	if (!data->a || !data->b)
	{
		free_stack(data->a);
		free_stack(data->b);
		return (0);
	}
	if (!parse_args_from(argc, argv, start, data->a)
		|| has_duplicate(data->a))
	{
		free_stack(data->a);
		free_stack(data->b);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_stats		stats;
	t_config	cfg;
	double		dis;

	if (argc < 2)
		return (0);
	data.a = NULL;
	data.b = NULL;
	stats = (t_stats){0};
	if (!prepare_stacks(argc, argv, &data, &cfg))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	data.a->stats = &stats;
	data.b->stats = &stats;
	dis = compute_disorder(data.a);
	if (!is_sorted(data.a))
		sort_selected(data.a, data.b, cfg.strategy, dis);
	if (cfg.bench)
		print_benchmark(data.a, dis, get_used(cfg.strategy, dis));
	free_stack(data.a);
	free_stack(data.b);
	return (0);
}
