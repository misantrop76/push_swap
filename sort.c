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
		write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	sort_three(t_swap *swap, int *pile, int len, int i)
{
	if (len == 2 || (pile[0] > pile[1]
			&& pile[1] < pile[2] && pile[0] < pile[2]))
		switch_first(swap, i);
	else if (pile[0] > pile[1] && pile[1] > pile[2] && pile[0] > pile[2])
	{
		switch_first(swap, i);
		get_down(pile, len, 1);
	}
	else if (pile[0] > pile[1] && pile[1] < pile[2] && pile[0] > pile[2])
		get_up(pile, len, i);
	else if (pile[0] < pile[1] && pile[1] > pile[2] && pile[0] < pile[2])
	{
		switch_first(swap, i);
		get_up(pile, len, i);
	}
	else if (pile[0] < pile[1] && pile[1] > pile[2] && pile[0] > pile[2])
		get_down(pile, len, i);
}

int	get_max_pos(int *pile, int len)
{
	int	max;
	int	i_max;
	int	i;

	i = 0;
	i_max = 0;
	max = pile[0];
	while (i < len)
	{
		if (max < pile[i])
		{
			max = pile[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

int	get_min_pos(int *pile, int len)
{
	int	min;
	int	i_min;
	int	i;

	i = 0;
	i_min = 0;
	min = pile[0];
	while (i < len)
	{
		if (min > pile[i])
		{
			min = pile[i];
			i_min = i;
		}
		i++;
	}
	return (i_min);
}

void	sort_five(t_swap *swap)
{
	insert_pb(swap);
	insert_pb(swap);
	if (!is_sorted(swap->pile1, swap->taille1))
		sort_three(swap, swap->pile1, swap->taille1, 1);
	while (swap->taille2)
	{
		if (swap->pile2[0] > get_max(swap->pile1, swap->taille1)
			|| swap->pile2[0] < get_min(swap->pile1, swap->taille1))
			while (swap->pile1[0] != get_min(swap->pile1, swap->taille1))
				get_up(swap->pile1, swap->taille1, 1);
		else
		{
			while (swap->pile2[0] > swap->pile1[0]
				|| swap->pile2[0] < swap->pile1[swap->taille1 - 1])
				get_up(swap->pile1, swap->taille1, 1);
		}
		insert_pa(swap);
	}
	if (get_min_pos(swap->pile1, swap->taille1) * 2 <= swap->taille1)
		while (swap->pile1[0] != get_min(swap->pile1, swap->taille1))
			get_up(swap->pile1, swap->taille1, 1);
	else
		while (swap->pile1[0] != get_min(swap->pile1, swap->taille1))
			get_down(swap->pile1, swap->taille1, 1);
}
