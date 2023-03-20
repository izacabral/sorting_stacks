
#include "stack_sorting.h"

t_stack	*stacknew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

int	stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*stacknode;

	if (*stack == NULL)
		*stack = new;
	else
	{
		stacknode = *stack;
		while (stacknode->next)
			stacknode = stacknode->next;
		stacknode->next = new;
	}
}

void	pop(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->content = 0;
	free(tmp);
}
