/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:35:36 by mminet            #+#    #+#             */
/*   Updated: 2021/03/30 17:36:12 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_list(t_swap *swap)
{
	int	i;

	i = 0;
	write(1, "\nPile A		Pile B\n", 16);
	while (i < swap->taille1 || i < swap->taille2)
	{
		if (i < swap->taille1 && i < swap->taille2)
		{
			ft_putnbr_fd(swap->pile1[i], 0);
			write(1, "		", 2);
			ft_putnbr_fd(swap->pile2[i], 0);
		}
		else if (i < swap->taille1)
			ft_putnbr_fd(swap->pile1[i], 0);
		else if (i < swap->taille2)
		{
			write(1, "		", 2);
			ft_putnbr_fd(swap->pile2[i], 0);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	exec2(t_swap *swap, char *buffer)
{
	if (!ft_strncmp(buffer, "rr", 3))
	{
		get_up(swap->pile1, swap->taille1, 1);
		get_up(swap->pile2, swap->taille2, 2);
	}
	else if (!ft_strncmp(buffer, "sa", 3))
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
	else
		exec2(swap, buffer);
	if (swap->op == 1)
		print_list(swap);
	free(buffer);
	buffer = NULL;
}

int	main(int ac, char **av)
{
	t_swap	swap;
	char	*buffer;

	buffer = NULL;
	if (ac == 1)
		return (0);
	swap.taille2 = 0;
	swap.taille1 = 0;
	swap.op = 0;
	if (!ft_strncmp(av[1], "-v", 3))
		swap.op = 1;
	swap.pile1 = malloc(sizeof(int) * swap.taille1);
	if (!(check_error_parse(av, &swap)))
		ft_free(&swap, 1);
	while (get_next_line(&buffer))
		exec(&swap, buffer);
	free(buffer);
	buffer = NULL;
	if (is_sorted(swap.pile1, swap.taille1) && swap.taille2 == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free(&swap, 0);
}
