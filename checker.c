#include "push_swap.h"

int		my_atoi(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit(write(1, "Error4\n", 6));
		i++;
	}
	return (ft_atoi(str));
}

int		check_error_parse(char **av, t_swap *swap, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		swap->pile1[i] = my_atoi(av[i + 1]);
		i++;
	}
	return (1);
}

int		is_sorted(int *pile, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	exec(t_swap *swap, char *buffer)
{
	if (!ft_strncmp(buffer, "rra", 3))
		get_down(swap->pile1, swap->taille1, 1, &swap->i);
	else if (!ft_strncmp(buffer, "rrb", 3))
		get_down(swap->pile2, swap->taille2, 2, &swap->i);
	else if (!ft_strncmp(buffer, "rrr", 3))
	{
		get_down(swap->pile1, swap->taille1, 1, &swap->i);
		get_down(swap->pile2, swap->taille2, 2, &swap->i);
	}
	else if (!ft_strncmp(buffer, "pa", 2))
		insert_pa(swap);
	else if (!ft_strncmp(buffer, "pb", 2))
		insert_pb(swap);
	else if (!ft_strncmp(buffer, "ra", 2))
		get_up(swap->pile1, swap->taille1, 1, &swap->i);
	else if (!ft_strncmp(buffer, "rb", 2))
		get_up(swap->pile2, swap->taille2, 2, &swap->i);
	else if (!ft_strncmp(buffer, "rr", 2))
	{
		get_up(swap->pile1, swap->taille1, 1, &swap->i);
		get_up(swap->pile2, swap->taille2, 2, &swap->i);
	}
	else if (!ft_strncmp(buffer, "sa", 2))
		switch_first(swap, 1);
	else if (!ft_strncmp(buffer, "sb", 2))
		switch_first(swap, 2);
	else if (!ft_strncmp(buffer, "ss", 2))
	{
		switch_first(swap, 1);
		switch_first(swap, 2);
	}
}

int main(int ac, char **av)
{
	t_swap swap;
	char *buffer;

	buffer = NULL;
	swap.i = 0;
	swap.taille2 = 0;
	swap.taille1 = ac - 1;
	swap.pile1 = malloc(sizeof(int) * swap.taille1);
	if (!(check_error_parse(av, &swap, swap.taille1)))
		return(write(1, "Error\n", 6));
	if (swap.taille1 == 0)
		return(write(1, "Error\n", 6));
	int i = 0;
	while (get_next_line(&buffer))
	{
		if (ft_strlen(buffer) > 3)
			return (write(1, "Error\n", 6));
		exec(&swap, buffer);
		i++;
		free(buffer);
		buffer = NULL;
	}
	if (is_sorted(swap.pile1, swap.taille1) && swap.taille2 == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}