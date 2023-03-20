
#include "stack_sorting.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;

	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp3 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
	*stack = tmp2;
}

void	swap_a(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	swap(stack);
	my_printf("sa\n");
}

void	swap_b(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	swap(stack);
	my_printf("sb\n");
}

void	swap_ss(t_stack **stacka, t_stack **stackb)
{
	if ((!(*stacka) || !(*stacka)->next) && (!(*stackb) || !(*stackb)->next))
		return ;
	swap(stacka);
	swap(stackb);
	my_printf("ss\n");
}
