/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:46:29 by mminet            #+#    #+#             */
/*   Updated: 2021/03/17 12:01:48 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(int content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(size_t))))
		return (0);
	if (new == NULL)
	{
		new->next = NULL;
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
