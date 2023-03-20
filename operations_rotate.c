
#include "stack_sorting.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*last;

	tmp1 = *stack;
	tmp2 = (*stack)->next;
	last = stacklast(*stack);
	tmp1->next = NULL;
	last->next = tmp1;
	*stack = tmp2;
}

void	rotate_a(t_stack **stack)
{
	if (!(*stack))
		return ;
	rotate(stack);
	my_printf("ra\n");
}

void	rotate_b(t_stack **stack)
{
	if (!stack)
		return ;
	rotate(stack);
	my_printf("rb\n");
}

void	rotate_rr(t_stack **stacka, t_stack **stackb)
{
	if (!stacka || !stackb)
		return ;
	rotate(stacka);
	rotate(stackb);
	my_printf("rr\n");
}
