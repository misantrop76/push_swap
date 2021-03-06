/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:36:39 by mminet            #+#    #+#             */
/*   Updated: 2021/03/30 17:14:16 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	swap.taille1 = 0;
	swap.op = 0;
	if (!(ac - 1))
		return (0);
	if (!(check_error_parse(av, &swap)))
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
