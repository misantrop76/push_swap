/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:37:04 by mminet            #+#    #+#             */
/*   Updated: 2021/03/25 16:59:05 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mkchr(char *s2, const char *s1, int b, int e)
{
	int	i;

	i = 0;
	while (b != (e + 1))
		s2[i++] = s1[b++];
	s2[i] = '\0';
	return (s2);
}

static int	ft_cmp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	begin(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_cmp(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1);
	i--;
	while (i != 0)
	{
		if (ft_cmp(s1[i], set) == 0)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	int		b;
	int		e;
	int		i;

	if (!s1)
		return (0);
	i = 0;
	b = begin(s1, set);
	e = end(s1, set);
	if ((e + 1) - b > 0)
		s2 = malloc(sizeof(char) * ((e + 1) - b + 1));
	else
	{
		s2 = ft_calloc(1, 1);
		return (s2);
	}
	return (mkchr(s2, s1, b, e));
}
