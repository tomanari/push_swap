#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to)
{
	int	temp;
	int i;

	if (!from || !to || from->size == 0)
		return ;

	temp = from->values[0];
	i = 0;
	while (i < from->size - 1)
	{
		from->values[i] = from->values[i + 1];
		i++;
	}
	i = to->size;
	while(i > 0)
	{
		to->values[i] = to->values[i - 1];
		i--;
	}
	to->size++;
	to->values[0] = temp;
	from->size--;
}
