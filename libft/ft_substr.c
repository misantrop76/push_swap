/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:59:04 by mminet            #+#    #+#             */
/*   Updated: 2021/03/25 16:59:24 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	int				i;
	unsigned int	a;

	a = 0;
	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * len + 1);
	while (len > 0)
	{
		dest[i] = s[i + start];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
