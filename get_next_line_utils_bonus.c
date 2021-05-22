/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiron-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:07:17 by egiron-t          #+#    #+#             */
/*   Updated: 2021/05/20 12:59:17 by egiron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		x;
	int		i;
	char	*dest;

	x = 0;
	i = 0;
	while (src[x] != '\0')
		x++;
	dest = (char *)malloc(x + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *strin, int c)
{
	int			i;
	int			x;
	char		y;

	y = c;
	x = ft_strlen(strin);
	i = 0;
	while (i < x + 1)
	{
		if (strin[i] == y)
			return ((char *)strin + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*str;

	if (s1 && s2)
	{
		l1 = ft_strlen((char *)s1);
		l2 = ft_strlen((char *)s2);
		str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
		if (!str)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[l1] = s2[i];
			l1++;
		}
		str[l1] = '\0';
		return (str);
	}
	return (NULL);
}
