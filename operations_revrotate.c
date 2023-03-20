
#include "stack_sorting.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*p_lastnode;
	t_stack	*tmp1;

	tmp1 = *stack;
	p_lastnode = *stack;
	while (p_lastnode->next->next)
		p_lastnode = p_lastnode->next;
	p_lastnode->next->next = tmp1;
	*stack = p_lastnode->next;
	p_lastnode->next = NULL;
}

void	rev_rotate_a(t_stack **stack)
{
	if (!(*stack))
		return ;
	rev_rotate(stack);
	my_printf("rra\n");
}

void	rev_rotate_b(t_stack **stack)
{
	if (!(*stack))
		return ;
	rev_rotate(stack);
	my_printf("rrb\n");
}

void	rev_rotate_ab(t_stack **stacka, t_stack **stackb)
{
	if (!(*stacka) || !(*stackb))
		return ;
	rev_rotate(stacka);
	rev_rotate(stackb);
	my_printf("rrr\n");
}
