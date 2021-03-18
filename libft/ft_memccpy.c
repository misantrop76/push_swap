/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:51:47 by mminet            #+#    #+#             */
/*   Updated: 2020/02/28 16:04:50 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	i = 0;
	s = src;
	d = dest;
	while (n--)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			i++;
			return (dest + i);
		}
		s++;
		d++;
		i++;
	}
	return (0);
}
