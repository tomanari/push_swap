/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:08 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 16:05:32 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_strategy_flag(const char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(flag, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(flag, "--complex") == 0)
		return (COMPLEX);
	if (ft_strcmp(flag, "--adaptive") == 0)
		return (ADAPTIVE);
	return (-1);
}

static int	parse_flag(char *arg, t_config *config)
{
	int		strategy;

	if (ft_strcmp(arg, "--bench") == 0)
	{
		config->bench = 1;
		return (0);
	}
	strategy = parse_strategy_flag(arg);
	if (strategy == -1)
		return (-1);
	config->strategy = strategy;
	return (0);
}

int	parse_config(int argc, char **argv, t_config *config)
{
	int	i;

	if (!config)
		return (-1);
	config->strategy = ADAPTIVE;
	config->bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (parse_flag(argv[i], config) == -1)
			return (-1);
		i++;
	}
	return (i);
}
