/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:37:04 by mminet            #+#    #+#             */
/*   Updated: 2021/03/30 13:37:07 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	pile[0] = tmp;
	if (j == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
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
	pile[len - 1] = tmp;
	if (j == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

int	get_max(int *pile, int len)
{
	int	i;
	int	max;

	i = 0;
	max = pile[0];
	while (i < len)
	{
		if (pile[i] > max)
			max = pile[i];
		i++;
	}
	return (max);
}
