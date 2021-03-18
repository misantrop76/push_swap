/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:08:56 by mminet            #+#    #+#             */
/*   Updated: 2021/03/18 13:18:23 by mminet           ###   ########lyon.fr   */
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
	int n;
}				t_swap;

void	switch_first(t_list *lst, int a);
void	insert(t_list **src, t_list **dest, int a);
void	print_list(t_list *pile1, t_list *pile2);
void	get_up(t_list **lst, int a);
void	get_down(t_list **lst, int a);

#endif
