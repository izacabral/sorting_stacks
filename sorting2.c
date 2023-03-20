
#include "stack_sorting.h"

void	order_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 4)
	{
		while ((*stack_a)->index != 1)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	if (size == 5)
	{
		while ((*stack_a)->index != 1 && (*stack_a)->index != 2)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
		while ((*stack_a)->index != 1 && (*stack_a)->index != 2)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	if (!check_order(stack_a))
		order_three(stack_a);
	if (check_order(stack_b))
		swap_b(stack_b);
	while (*stack_b)
		push_a(stack_b, stack_a);
}

int	get_highest_bits(int size)
{
	int	highest_bits;

	highest_bits = 0;
	while (size >> highest_bits != 0)
		highest_bits++;
	return (highest_bits);
}

static void	iterate_a(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	times;

	times = 0;
	size = stacksize(*a);
	while (times < size && !check_order(a))
	{
		if (((*a)->index & (1 << bit)) == 0)
			push_b(a, b);
		else
			rotate_a(a);
		times++;
	}
}

static void	iterate_b(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	times;

	times = 0;
	size = stacksize(*b);
	while (times < size && !check_order(a))
	{
		if (((*b)->index & (1 << (bit + 1))) == 0)
			rotate_b(b);
		else
			push_a(b, a);
		times++;
	}
}

void	order_radix(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	highest_bits;
	int	bit;

	bit = 0;
	highest_bits = get_highest_bits(size);
	while (bit < highest_bits)
	{
		iterate_a(stack_a, stack_b, bit);
		iterate_b(stack_a, stack_b, bit);
		bit++;
	}
	while (*stack_b)
		push_a(stack_b, stack_a);
}
