/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:36:55 by mminet            #+#    #+#             */
/*   Updated: 2021/03/30 13:36:59 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_rest(t_swap *swap, int scale)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (i < swap->taille1)
	{
		if (swap->pile1[i] <= scale)
			nb++;
		i++;
	}
	return (nb);
}

int	get_best_number2(t_swap *swap, int scale)
{
	int	i;

	i = 0;
	while (i < swap->taille1)
	{
		if (swap->pile1[i] <= scale)
			break ;
		i++;
	}
	return (i);
}

int	get_best_number(t_swap *swap, int scale)
{
	int	pos;
	int	i;
	int	nbr1;
	int	nbr2;

	pos = get_best_number2(swap, scale);
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
	return (i);
}

void	sort_all2(t_swap *swap, int pos)
{
	while (swap->taille2)
	{
		pos = get_max_pos(swap->pile2, swap->taille2);
		if (pos == 0)
			insert_pa(swap);
		else if (pos <= (swap->taille2 / 2))
			get_up(swap->pile2, swap->taille2, 2);
		else
			get_down(swap->pile2, swap->taille2, 2);
	}
}

void	sort_all(t_swap *swap, int deg)
{
	int	min;
	int	max;
	int	scale;
	int	pos;

	min = get_min(swap->pile1, swap->taille1);
	max = get_max(swap->pile1, swap->taille1);
	scale = min + ((max - min) / deg);
	while (swap->taille1)
	{
		if (nb_rest(swap, scale) == 0)
			scale += ((max - min) / deg);
		pos = (get_best_number(swap, scale));
		if (pos == 0)
			insert_pb(swap);
		else if (pos < (swap->taille1 / 2))
			get_up(swap->pile1, swap->taille1, 1);
		else
			get_down(swap->pile1, swap->taille1, 1);
	}
	sort_all2(swap, pos);
}
