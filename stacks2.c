
#include "stack_sorting.h"

t_stack	*stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	set_index(t_stack **stack)
{
	int		index;
	t_stack	*tmp;

	tmp = *stack;
	index = 1;
	while (*stack)
	{
		(*stack)->index = index;
		index++;
		*stack = (*stack)->next;
	}
	*stack = tmp;
}

void	transfer_index(t_stack **stackindex, t_stack **stacka)
{
	t_stack	*tmpi;
	t_stack	*tmpa;

	tmpi = *stackindex;
	tmpa = *stacka;
	while (*stackindex)
	{
		while (*stacka)
		{
			if ((*stackindex)->content == (*stacka)->content)
				(*stacka)->index = (*stackindex)->index;
			*stacka = (*stacka)->next;
		}
		*stacka = tmpa;
		*stackindex = (*stackindex)->next;
	}
	*stackindex = tmpi;
}

t_stack	**create_indexed(t_stack **a, char **r_argv, int r_argc)
{
	int		i;
	t_stack	*tmp;

	tmp = NULL;
	i = r_argc - 1;
	if (r_argc >= 2)
	{
		while (i >= 0)
		{
			stackadd_front(a, stacknew(atoi(r_argv[i])));
			stackadd_front(&tmp, stacknew(atoi(r_argv[i])));
			i--;
		}
	}
	bubble_sort(&tmp);
	set_index(&tmp);
	transfer_index(&tmp, a);
	while (tmp)
		pop(&tmp);
	free (tmp);
	free_split(r_argv);
	return (a);
}

void	free_stack(t_stack **stack)
{
	while (*stack)
		pop(stack);
	free (stack);
}
