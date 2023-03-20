
#include "stack_sorting.h"

int	argv_is_number(char **r_argv)
{
	int	i;
	int	*nb_argv;

	i = real_argc(r_argv);
	nb_argv = malloc(sizeof(int) * i);
	if (!nb_argv)
		return (0);
	i = 0;
	while (r_argv[i])
	{
		if (my_atoil(r_argv[i]) == 3000000000)
		{
			free (nb_argv);
			return (0);
		}
		nb_argv[i] = my_atoil(r_argv[i]);
		i++;
	}
	free (nb_argv);
	return (1);
}

int	has_duplicate(char **r_argv, int size)
{
	int	i;
	int	flag;
	int	j;

	i = 0;
	j = i + 1;
	flag = 0;
	while (i <= size)
	{
		while (j <= size - 1)
		{
			if (my_atoi(r_argv[i]) == my_atoi(r_argv[j]))
				flag = flag + 1;
			if (flag >= 1)
			{	
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	isvalid_argv(char **argv)
{
	char	**r_argv;
	int		r_argc;

	r_argv = real_argv(argv);
	r_argc = real_argc(r_argv);
	if (char_isvalid(r_argv) && argv_is_number(r_argv)
		&& has_duplicate(r_argv, r_argc))
	{
		free_split (r_argv);
		return (1);
	}
	else
	{
		free_split(r_argv);
		return (0);
	}
}

void	error(void)
{
	write (2, "Error\n", 6);
}
