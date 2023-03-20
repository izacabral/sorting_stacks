
#ifndef STACK_SORTING_H
# define STACK_SORTING_H

# include "mylibc/mylibc.h"
# include "mylibc/my_printf/my_printf.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

// stacks
t_stack	*stacknew(int content);
void	stackadd_front(t_stack **stack, t_stack *new);
int		stacksize(t_stack *stack);
void	stackadd_back(t_stack **stack, t_stack *new);
void	pop(t_stack **stack);

// stacks2
t_stack	*stacklast(t_stack *stack);
void	set_index(t_stack **stack);
void	transfer_index(t_stack **stackindex, t_stack **stacka);
t_stack	**create_indexed(t_stack **a, char **r_argv, int r_argc);
void	free_stack(t_stack **stack);

// operations_swap
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap_ss(t_stack **stacka, t_stack **stackb);

// operationts_push
void	push_a(t_stack **stack_b, t_stack **stack_a);
void	push_b(t_stack **stack_a, t_stack **stack_b);

// operations_rotate
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_rr(t_stack **stacka, t_stack **stackb);

// operations_revrotate
void	rev_rotate_a(t_stack **stack);
void	rev_rotate_b(t_stack **stack);
void	rev_rotate_ab(t_stack **stacka, t_stack **stackb);

// validation
char	**real_argv(char **argv);
int		real_argc(char **real_argv);
int		char_isvalid(char **r_argv);
long	my_atoil(const char *str);
void	free_split(char	**str);

// validation2
int		argv_is_number(char **r_argv);
int		has_duplicate(char **r_argv, int size);
int		isvalid_argv(char **argv);
void	error(void);

// sorting
void	bubble_sort(t_stack **stack);
int		check_order(t_stack **stack);
void	choose_ordering(t_stack **stack_a, t_stack **stack_b, int size);
void	order_three(t_stack **stack_a);

// sorting2
void	order_five(t_stack **stack_a, t_stack **stack_b, int size);
void	order_radix(t_stack **stack, t_stack **t_stack_b, int size);

// utils_extra
void	printstack(t_stack **a, t_stack **b);

#endif
