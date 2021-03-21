#include "push_swap.h"

void	sort_three(t_swap *swap, int *pile, int len, int i)
{
	if (len == 2)
	{
		switch_first(swap, i);
		return;
	}
	if (pile[0] > pile[1] && pile[1] < pile[2] && pile[0] < pile[2])
	{
		switch_first(swap, i);
		return;
	}
	if (pile[0] > pile[1] && pile[1] > pile[2] && pile[0] > pile[2])
	{
		switch_first(swap, i);
		get_down(pile, len, 1, &swap->i);
		return;
	}
	if (pile[0] > pile[1] && pile[1] < pile[2] && pile[0] > pile[2])
	{
		get_up(pile, len, i, &swap->i);
		return;
	}
	if (pile[0] < pile[1] && pile[1] > pile[2] && pile[0] < pile[2])
	{
		switch_first(swap, i);
		get_up(pile, len, i, &swap->i);
		return;
	}
	if (pile[0] < pile[1] && pile[1] > pile[2] && pile[0] > pile[2])
	{
		get_down(pile, len, i, &swap->i);
		return;
	}
}

int		get_min_pos(int *pile, int len)
{
	int min;
	int i_min;
	int i;

	i = 0;
	i_min = 0;
	min = pile[0];
	while(i < len)
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
		if(!is_sorted(swap->pile1, swap->taille1))
			sort_three(swap, swap->pile1, swap->taille1, 1);
		while (swap->taille2)
		{
			if(swap->pile2[0] > get_max(swap->pile1, swap->taille1) || swap->pile2[0] < get_min(swap->pile1, swap->taille1))
				while (swap->pile1[0] != get_min(swap->pile1, swap->taille1))
					get_up(swap->pile1, swap->taille1, 1, &swap->i);
			else
			{
				while(swap->pile2[0] > swap->pile1[0] || swap->pile2[0] < swap->pile1[swap->taille1 - 1])
					get_up(swap->pile1, swap->taille1, 1, &swap->i);
			}
			insert_pa(swap);
		}
		if (get_min_pos(swap->pile1, swap->taille1) * 2 <= swap->taille1)
			while (swap->pile1[0] != get_min(swap->pile1, swap->taille1))
				get_up(swap->pile1, swap->taille1, 1, &swap->i);
		else
			while (swap->pile1[0] != get_min(swap->pile1, swap->taille1))
				get_down(swap->pile1, swap->taille1, 1, &swap->i);
}

void	sort_default(t_swap *swap)
{
	int pos;

	while (swap->taille1 > 3)
	{
		pos = get_min_pos(swap->pile1, swap->taille1);
		//printf("pos = %d\n", pos);
		if (pos == 0)
			insert_pb(swap);
		else if ((pos * 2) <= swap->taille1)
			get_up(swap->pile1, swap->taille1, 1, &swap->i);
		else
			get_down(swap->pile1, swap->taille1, 1, &swap->i);
	}
	if (!is_sorted(swap->pile1, swap->taille1))
		sort_three(swap, swap->pile1, swap->taille1, 1);
	while (swap->taille2)
		insert_pa(swap);
}

