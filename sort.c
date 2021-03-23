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

int		get_max_pos(int *pile, int len)
{
	int max;
	int i_max;
	int i;

	i = 0;
	i_max = 0;
	max = pile[0];
	while(i < len)
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

void	sort_a(t_swap *swap)
{
	int nb_pb = 0;
	int pos;

	if (is_sorted(swap->pile1, swap->taille1))
		return;
	while(swap->taille1)
	{
		pos = get_min_pos(swap->pile1, swap->taille1);
		if (pos == 0)
		{
			insert_pb(swap);
			nb_pb++;
		}
		else if(pos <= (swap->taille1 / 2))
			get_up(swap->pile1, swap->taille1, 1, &swap->i);
		else	
			get_down(swap->pile1, swap->taille1, 1, &swap->i);
		if (is_sorted(swap->pile1, swap->taille1))
			break;
	}
	while (nb_pb)
	{
		insert_pa(swap);
		nb_pb--;
	}
}

void	sort_b(t_swap *swap)
{
	int nb_pa = 0;
	int pos;

	if (is_sorted(swap->pile2, swap->taille2))
		return;
	while(swap->taille2)
	{
		pos = get_min_pos(swap->pile2, swap->taille2);
		if (pos == 0)
		{
			insert_pa(swap);
			nb_pa++;
		}
		else if(pos <= (swap->taille2 / 2))
			get_up(swap->pile2, swap->taille2, 2, &swap->i);
		else	
			get_down(swap->pile2, swap->taille2, 2, &swap->i);
		if (is_sorted(swap->pile2, swap->taille2))
			break;
	}
	while (nb_pa)
	{
		insert_pb(swap);
		nb_pa--;
	}
}

void	merge_a_b(t_swap *swap)
{
	int len_a = swap->taille1;

	while (swap->taille2 && len_a)
	{
		if (swap->pile1[0] > swap->pile2[0])
		{
			insert_pa(swap);
			len_a++;
		}
		else
		{
			get_up(swap->pile1, swap->taille1, 1, &swap->i);
			len_a--;
		}
	}
	while(swap->taille2)
	{
		insert_pa(swap);
		get_up(swap->pile1, swap->taille1, 1, &swap->i);
	}
}

void	sort_default(t_swap *swap)
{
	int half;

	half = (swap->taille1 / 2);
	while(half)
	{
		insert_pb(swap);
		half--;
	}
	sort_a(swap);
	sort_b(swap);
	merge_a_b(swap);
	while (get_min_pos(swap->pile1, swap->taille1) != 0)
		if(get_min_pos(swap->pile1, swap->taille1) < (swap->taille1 / 2))
			get_up(swap->pile1, swap->taille1, 1, &swap->i);
		else
			get_down(swap->pile1, swap->taille1, 1, &swap->i);
}

int		nb_rest(t_swap *swap, int scale)
{
	int nb;
	int i = 0;

	nb = 0;
	while (i < swap->taille1)
	{
		if (swap->pile1[i] <= scale)
			nb++;
		i++;
	}
	return (nb);
}

int		get_best_number(t_swap *swap, int scale)
{
	int pos;
	int i;
	int nbr1;
	int nbr2;

	i = 0;
	while (i < swap->taille1)
	{
		if (swap->pile1[i] <= scale)
			break;
		i++;
	}
	pos = i;
	i = swap->taille1 - 1;
	while (swap->pile1[i] > scale)
		i--;
	if (i == pos)
		return (i);
	nbr1 = pos;
	nbr2 = i;
	if (pos > swap->taille1)
		nbr1 = swap->taille1 - pos;
	if (i > swap->taille1)
		nbr2 = swap->taille1 - i;
	if (nbr1 <= nbr2)
		return (pos);
	return(i);
}

void	sort_all(t_swap *swap, int deg)
{
	int min;
	int max;
	int scale;
	int pos;

	min = get_min(swap->pile1, swap->taille1);
	max = get_max(swap->pile1, swap->taille1);
	scale = min + ((max - min) / 5);
	while (swap->taille1)
	{
		if (nb_rest(swap, scale) == 0)
			scale += ((max - min) / deg);
		pos = (get_best_number(swap, scale));
		if (pos == 0)
			insert_pb(swap);
		else if(pos < (swap->taille1 / 2))
			get_up(swap->pile1, swap->taille1, 1, &swap->i);
		else
			get_down(swap->pile1, swap->taille1, 1, &swap->i);
	}
	while (swap->taille2)
	{
		pos = get_max_pos(swap->pile2, swap->taille2);
		if (pos == 0)
			insert_pa(swap);
		else if(pos <= (swap->taille2 / 2))
			get_up(swap->pile2, swap->taille2, 2, &swap->i);
		else
			get_down(swap->pile2, swap->taille2, 2, &swap->i);
	}
}

