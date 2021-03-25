/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:23:49 by mminet            #+#    #+#             */
/*   Updated: 2021/03/25 17:00:12 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**mktab(char const *s, char c, char **tab)
{
	int	a;
	int	i;
	int	j;

	a = 0;
	i = 0;
	j = 0;
	while (s[a] != '\0')
	{
		while (s[a] != '\0' && s[a] == c)
			a++;
		while (s[a] != '\0' && s[a] != c)
			tab[i][j++] = s[a++];
		if (j != 0)
			tab[i++][j] = '\0';
		j = 0;
	}
	tab[i] = 0;
	return (tab);
}

static int	size(char const *s, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		size++;
		while (s[i] == c && s[i])
			i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		k;

	if (!s)
		return (0);
	i = 0;
	a = 0;
	tab = malloc(sizeof(char *) * (size(s, c) + 1));
	while (s[i] == c && s[i] != '\0')
		i++;
	while (a < size(s, c))
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0' && s[i++] != '\0')
			k++;
		tab[a] = malloc(sizeof(char) * (k + 1));
		a++;
	}
	return (mktab(s, c, tab));
}
