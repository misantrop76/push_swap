/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:08:56 by mminet            #+#    #+#             */
/*   Updated: 2021/03/25 16:14:33 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include "libft/libft.h"

typedef struct s_swap
{
	int i;
	int *pile1;
	int *pile2;
	int taille1;
	int taille2;
}				t_swap;

int		is_sorted(int *pile, int len);
void	switch_first(t_swap *swap, int a);
void	insert_pb(t_swap *swap);
void	insert_pa(t_swap *swap);
void	get_up(int *pile, int len, int j);
void	get_down(int *pile, int len, int j);
int		get_min(int *pile, int len);
int		get_max(int *pile, int len);
int		get_max_pos(int *pile, int len);
void	sort_three(t_swap *swap, int *pile, int len, int i);
void	sort_five(t_swap *swap);
int		get_next_line(char **line);
void	sort_all(t_swap *swap, int deg);
int		is_int(char *str);
int		my_atoi(char *str);
void	ft_free(t_swap *swap, int i);

#endif
