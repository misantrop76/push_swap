#include "push_swap.h"

void	ft_free(t_swap *swap, int i)
{
	if (swap->pile1)
		free(swap->pile1);
	if (swap->pile2)
		free(swap->pile2);
	swap->pile1 = NULL;
	swap->pile2 = NULL;
	if (i)
		write(1, "Error\n", 5);
	exit(EXIT_SUCCESS);
}

void	get_down(int *pile, int len, int j)
{
	int		tmp;
	int		i;

	i = len - 1;
	if (len <= 1)
		return ;
	tmp = pile[i];
	i++;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	j = 0;
	pile[0] = tmp;
}

void	get_up(int *pile, int len, int j)
{
	int		tmp;
	int		i;

	i = 0;
	if (len <= 1)
		return ;
	tmp = pile[0];
	while (i < len)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	j = 0;
	pile[len - 1] = tmp;
}

int	is_int(char *str)
{
	long int	value;
	int			sign;

	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		value = value * 10 + (*str - '0');
		str++;
	}
	if ((value * sign) <= 2147483647 && (value * sign) >= -2147483648)
		return (1);
	else
		return (0);
}

int	my_atoi(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit(write(1, "Error\n", 6));
		i++;
	}
	if (!is_int(str))
		exit(write(1, "Error\n", 6));
	return (ft_atoi(str));
}
