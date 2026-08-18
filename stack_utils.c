#include "push_swap.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->num = num;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
		stack->size++;
	}
}
