#include "push_swap.h"

int	check_double(t_swap *swap)
{
	int	i;
	int	val;
	int	a;

	i = 0;
	while (i < swap->taille1)
	{
		val = swap->pile1[i];
		a = 0;
		while (a < swap->taille1)
		{
			if (swap->pile1[a] == val && a != i)
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

int	check_error_parse(char **av, t_swap *swap, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		swap->pile1[i] = my_atoi(av[i + 1]);
		i++;
	}
	return (check_double(swap));
}

int	get_min(int *pile, int len)
{
	int	i;
	int	min;

	i = 0;
	min = pile[0];
	while (i < len)
	{
		if (pile[i] < min)
			min = pile[i];
		i++;
	}
	return (min);
}

int	is_sorted(int *pile, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_swap	swap;

	swap.taille2 = 0;
	swap.taille1 = ac - 1;
	if (!(ac - 1))
		return (0);
	swap.pile1 = malloc(sizeof(int) * swap.taille1);
	if (!(check_error_parse(av, &swap, swap.taille1)))
		ft_free(&swap, 1);
	if (swap.taille1 == 0)
		ft_free(&swap, 1);
	if (is_sorted(swap.pile1, swap.taille1))
		ft_free(&swap, 0);
	if (swap.taille1 <= 3)
		sort_three(&swap, swap.pile1, swap.taille1, 1);
	else if (swap.taille1 <= 5)
		sort_five(&swap);
	else if (swap.taille1 <= 10)
		sort_all(&swap, 2);
	else if (swap.taille1 <= 200)
		sort_all(&swap, 9);
	else
		sort_all(&swap, 11);
	ft_free(&swap, 0);
	return (0);
}
