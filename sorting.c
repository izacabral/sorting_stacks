
#include "stack_sorting.h"

static void	m_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	tmp = *stack;
	size = stacksize(*stack);
	while (size - 1)
	{
		while ((*stack)->next)
		{
			if ((*stack)->content > (*stack)->next->content)
			{
				m_swap(&(*stack)->content, &(*stack)->next->content);
			}
			*stack = (*stack)->next;
		}
		*stack = tmp;
		size--;
	}
}

int	check_order(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	choose_ordering(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !check_order(stack_a))
	{
		(void) stack_b;
		swap_a(stack_a);
	}
	else if (size == 3 && !check_order(stack_a))
	{
		(void) stack_b;
		order_three(stack_a);
	}
	else if ((size >= 4 && size <= 5) && (!check_order(stack_a)))
		order_five(stack_a, stack_b, size);
	else
		order_radix(stack_a, stack_b, size);
}

void	order_three(t_stack **stack_a)
{	
	int	one;
	int	two;
	int	three;

	one = (*stack_a)->content;
	two = (*stack_a)->next->content;
	three = (*stack_a)->next->next->content;
	if ((one < two) && (one < three))
	{
		rev_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (one < two)
		rev_rotate_a(stack_a);
	else if ((one > two) && (one < three))
		swap_a(stack_a);
	else if ((one > two) && (one > three) && (two > three))
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if ((one > two) && (two < three))
		rotate_a(stack_a);
}
