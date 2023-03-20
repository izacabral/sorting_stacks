
#include "stack_sorting.h"

static void	push(t_stack **stack_send, t_stack **stack_rec)
{
	t_stack	*tmp;

	tmp = (*stack_send)->next;
	stackadd_front(stack_rec, *stack_send);
	*stack_send = tmp;
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	if (!(*stack_b))
		return ;
	push(stack_b, stack_a);
	my_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a))
		return ;
	push(stack_a, stack_b);
	my_printf("pb\n");
}
