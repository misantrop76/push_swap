/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:12:29 by mminet            #+#    #+#             */
/*   Updated: 2021/03/25 15:32:08 by mminet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdel(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	char	*s;

	s = malloc(sizeof(char) * (size + 1));
	*s = '\0';
	return (s);
}

char	*ft_get_line(int *ret, char *rest)
{
	char	*buffer;
	char	*rest2;

	buffer = malloc(sizeof(char) * 11);
	*ret = read(0, buffer, 10);
	buffer[*ret] = '\0';
	rest2 = rest;
	rest = ft_strjoin(rest, buffer);
	ft_strdel(buffer);
	ft_strdel(rest2);
	return (rest);
}

int	get_next_line(char **line)
{
	static char	*rest = NULL;
	char		*line2;
	char		*str;
	int			ret;

	ret = 1;
	if (!rest)
		rest = ft_strnew(0);
	while (ret)
	{
		str = ft_strchr(rest, '\n');
		if (str != 0)
		{
			*str = '\0';
			*line = ft_strdup(rest);
			line2 = rest;
			rest = ft_strdup(str + 1);
			ft_strdel(line2);
			return (1);
		}
		rest = ft_get_line(&ret, rest);
	}
	*line = ft_strdup(rest);
	ft_strdel(rest);
	return (0);
}
