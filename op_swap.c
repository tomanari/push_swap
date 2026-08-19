#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	temp;
	
	if(!stack || stack->size < 2)
		return ;
	temp = stack->values[0];
	stack->values[0] = stack->values [1];
	stack->values[1] = temp;
}

void	sa(t_stack *stack_a)
{
	ft_swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}