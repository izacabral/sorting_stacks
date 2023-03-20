
#include "stack_sorting.h"

void	stack_sorting(t_stack *a, t_stack *b, char **r_argv, int r_argc)
{
	create_indexed(&a, r_argv, r_argc);
	choose_ordering(&a, &b, r_argc);
	printstack(&a, &b);
	while (a)
		pop(&a);
	free (a);
	free (b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**r_argv;
	int		r_argc;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	r_argv = real_argv(argv);
	r_argc = real_argc(r_argv);
	if (r_argc < 2 && char_isvalid(r_argv))
	{
		free_split(r_argv);
		return (0);
	}
	if (!isvalid_argv(argv))
	{
		free_split(r_argv);
		error();
		return (0);
	}
	stack_sorting(a, b, r_argv, r_argc);
	return (0);
}
