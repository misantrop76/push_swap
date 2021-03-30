/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:36:26 by mminet            #+#    #+#             */
/*   Updated: 2021/03/30 17:20:19 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

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

void	add_one(t_swap *swap, int val)
{
	int	*New;
	int	i;

	New = malloc(sizeof(int) * swap->taille1 + 1);
	i = 0;
	while (i < swap->taille1)
	{
		New[i] = swap->pile1[i];
		i++;
	}
	New[i] = val;
	if (swap->pile1)
		free(swap->pile1);
	swap->pile1 = New;
	swap->taille1++;
}

int	check_error_parse(char **av, t_swap *swap)
{
	int		i;
	int		j;
	char	**str;
	int		len;

	i = 1;
	len = 0;
	if (swap->op == 1)
		i++;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		j = 0;
		while (str[j])
		{
			add_one(swap, my_atoi(str[j]));
			j++;
		}
		ft_free_split(str);
		i++;
	}
	return (check_double(swap));
}
