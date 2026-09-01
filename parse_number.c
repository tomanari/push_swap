/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:13 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 16:14:12 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_over(long num, int sign, int digit)
{
	if (num > INT_MAX / 10)
		return (1);
	if (num == INT_MAX / 10 && digit > 7 + (sign == -1))
		return (1);
	return (0);
}

static int	get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_safe(char *str, int *result)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = get_sign(str, &i);
	num = 0;
	if (!str || !result || str[i] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num_over(num, sign, str[i] - '0'))
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	if (str[i] != '\0')
		return (0);
	*result = (int)(sign * num);
	return (1);
}

static int	parse_token(char *token, t_stack *a)
{
	int	value;

	if (ft_atoi_safe(token, &value) == 0)
		return (0);
	a->values[a->size] = value;
	a->size++;
	return (1);
}

int	parse_args_from(int argc, char **argv, int start, t_stack *a)
{
	int		i;
	int		j;
	char	**tokens;

	i = start;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j])
		{
			if (!parse_token(tokens[j], a))
			{
				free_tokens(tokens);
				return (0);
			}
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	return (1);
}
