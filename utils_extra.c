
#include "stack_sorting.h"

void	printstack(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;

	size_a = stacksize(*a);
	size_b = stacksize(*b);
	my_printf("\n\n");
	my_printf("  %p\t\t %p\n", a, b);
	my_printf("%s\t\t\t %s\t\n", "---------", "---------");
	while (size_a || size_b)
	{
		if (size_a >= size_b)
		{
			my_printf("%i %p \t\t ", (*a)->content, (*a)->next);
			a = &(*a)->next;
			size_a--;
		}
		if (size_b > size_a)
		{
			my_printf("%i %p ", (*b)->content, (*b)->next);
			b = &(*b)->next;
			size_b--;
		}
		my_printf("\n");
	}
	my_printf("%s\t\t\t %s\t\n", "---------", "---------");
	my_printf("%s\t\t\t %s\t\n", "    a    ", "     b     ");
}
