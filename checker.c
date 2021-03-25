#include "push_swap.h"

int	check_error_parse(char **av, t_swap *swap, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		swap->pile1[i] = my_atoi(av[i + 1]);
		i++;
	}
	return (1);
}

int	is_sorted(int *pile, int len)
{
	int		i;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	exec2(t_swap *swap, char *buffer)
{
	if (!ft_strncmp(buffer, "sa", 3))
		switch_first(swap, 1);
	else if (!ft_strncmp(buffer, "sb", 3))
		switch_first(swap, 2);
	else if (!ft_strncmp(buffer, "ss", 3))
	{
		switch_first(swap, 1);
		switch_first(swap, 2);
	}
	else
		ft_free(swap, 1);
}

void	exec(t_swap *swap, char *buffer)
{
	if (!ft_strncmp(buffer, "rra", 4))
		get_down(swap->pile1, swap->taille1, 1);
	else if (!ft_strncmp(buffer, "rrb", 4))
		get_down(swap->pile2, swap->taille2, 2);
	else if (!ft_strncmp(buffer, "rrr", 4))
	{
		get_down(swap->pile1, swap->taille1, 1);
		get_down(swap->pile2, swap->taille2, 2);
	}
	else if (!ft_strncmp(buffer, "pa", 3))
		insert_pa(swap);
	else if (!ft_strncmp(buffer, "pb", 3))
		insert_pb(swap);
	else if (!ft_strncmp(buffer, "ra", 3))
		get_up(swap->pile1, swap->taille1, 1);
	else if (!ft_strncmp(buffer, "rb", 3))
		get_up(swap->pile2, swap->taille2, 2);
	else if (!ft_strncmp(buffer, "rr", 3))
	{
		get_up(swap->pile1, swap->taille1, 1);
		get_up(swap->pile2, swap->taille2, 2);
	}
	else
		exec2(swap, buffer);
}

int	main(int ac, char **av)
{
	t_swap	swap;
	char	*buffer;

	buffer = NULL;
	if (ac == 1)
		return (0);
	swap.taille2 = 0;
	swap.taille1 = ac - 1;
	swap.pile1 = malloc(sizeof(int) * swap.taille1);
	if (!(check_error_parse(av, &swap, swap.taille1)))
		ft_free(&swap, 1);
	while (get_next_line(&buffer))
	{
		exec(&swap, buffer);
		free(buffer);
		buffer = NULL;
	}
	free(buffer);
	buffer = NULL;
	if (is_sorted(swap.pile1, swap.taille1) && swap.taille2 == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free(&swap, 0);
}
