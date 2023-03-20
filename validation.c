
#include "stack_sorting.h"

char	**real_argv(char **argv)
{
	char	**real_argv;
	char	*str_argv;
	int		i ;

	i = 1;
	str_argv = my_strdup("");
	while (argv[i])
	{	
		str_argv = my_strjoin(str_argv, argv[i]);
		if (argv[i + 1] != NULL)
			str_argv = my_strjoin(str_argv, " ");
		i++;
	}
	real_argv = my_split(str_argv, ' ');
	free (str_argv);
	return (real_argv);
}

int	real_argc(char **real_argv)
{
	int	i;

	i = 0;
	while (real_argv[i])
		i++;
	return (i);
}

int	char_isvalid(char **r_argv)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (r_argv[i])
	{
		if (my_isdigit(r_argv[i][0]) || ((r_argv[i][0] == '+' ||
						r_argv[i][0] == '-') && my_isdigit(r_argv[i][1])))
		{
			while (r_argv[i][len] && my_isdigit(r_argv[i][len]))
				len++;
			if (r_argv[i][len] != '\0')
				return (0);
		}
		else
			return (0);
		len = 1;
		i++;
	}
	return (1);
}

long	my_atoil(const char *str)
{
	long	number;
	int		index;
	long	signal;

	number = 0;
	index = 0;
	signal = 1;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signal = signal * -1;
		index++;
	}
	while (my_isdigit(str[index]))
	{
		number = number + (str[index] - '0');
		index++;
		if (my_isdigit(str[index]))
			number = number * 10;
	}
	if ((signal * number < -2147483648 || signal * number > 2147483647))
		return (3000000000);
	return (signal * number);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free (str[i++]);
	free(str);
}
