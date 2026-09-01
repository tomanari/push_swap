/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:24:33 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/25 19:03:38 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strcmp(const char *s1, const char *s2);

typedef struct s_stack
{
	int				*values;
	long			size;
	int				capacity;
	struct s_stats	*stats;
}	t_stack;

typedef struct s_stats
{
	long	counts[11];
	long	total;
}	t_stats;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted_array;
	int		chunk_size;
}	t_data;

char	**ft_split(char const *s, char c);
void	free_tokens(char **tokens);
int		count_total_elements(int argc, char **argv);
int		count_words(char const *s, char c);
int		ft_atoi_safe(char *str, int *result);
int		parse_args(int argc, char **argv, t_stack *stack);
int		parse_args_from(int argc, char **argv, int start, t_stack *stack);
int		parse_config(int argc, char **argv, t_config *config);

t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		has_duplicate(t_stack *a);
int		is_sorted(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
void	sort_selected(t_stack *a, t_stack *b, t_strategy strategy,
			double disorder);
double	compute_disorder(t_stack *a);
void	normalize_stack(t_stack *stack);
void	sort_copy(int *copy, int size);

int		ft_haschunk(t_stack *stack_a, int start, int end);
int		ft_sqrt(int n);
int		find_maxindex(t_stack *stack_a);
int		find_minindex(t_stack *stack_a);
void	ft_push_max(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_top(t_stack *stack_a);
void	sort_bottom(t_stack *stack_a);

void	ft_swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	ft_push(t_stack *from, t_stack *to);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	ft_reverse(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	ft_rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	ft_sort_small(t_stack *a, t_stack *b);
void	ft_chunk_sort(t_stack *a, t_stack *b);
void	ft_sort_radix(t_stack *a, t_stack *b);
void	ft_sort_simple(t_stack *a, t_stack *b);

void	print_operation(char *operation, t_stack *stack);
void	print_benchmark(t_stack *a, double disorder, t_strategy strategy);
char	*strategy_name(t_strategy strategy);
char	*strategy_complexity(t_strategy strategy);
int		operation_index(char *operation);

#endif
