/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiron-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:07:49 by egiron-t          #+#    #+#             */
/*   Updated: 2021/05/20 12:58:44 by egiron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	afinadodelinea(char **bloque, char **line, int sizelectura)
{
	char	*t;
	char	*t2;

	if (!sizelectura && !*bloque)
	{
		*line = ft_strdup("");
		return (0);
	}
	t = ft_strchr(*bloque, '\n');
	if (t)
	{
		*t = '\0';
		t2 = ft_strdup(1 + t);
		*line = ft_strdup(*bloque);
		free(*bloque);
		*bloque = t2;
	}
	else
	{
		*line = *bloque;
		*bloque = 0;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*persiste[4096];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			sizelectura;

	sizelectura = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE < 1 || !line || sizelectura < 0)
		return (-1);
	while (sizelectura > 0)
	{
		buffer[sizelectura] = 0;
		if (!persiste[fd])
			persiste[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(persiste[fd], buffer);
			free(persiste[fd]);
			persiste[fd] = temp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		sizelectura = read(fd, buffer, BUFFER_SIZE);
	}
	return (afinadodelinea(&persiste[fd], line, sizelectura));
}
