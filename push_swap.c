#include "push_swap.h"

void	data_init(t_data *data)
{
	data->stack_a.head = NULL;
	data->stack_a.tail = NULL;
	data->stack_a.size = 0;

	data->stack_b.head = NULL;
	data->stack_b.tail = NULL;
	data->stack_b.size = 0;

	data->bench = 0;
	data->total_ops = 0;
}