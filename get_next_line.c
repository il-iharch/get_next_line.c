/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:49:45 by iharch            #+#    #+#             */
/*   Updated: 2024/12/21 17:46:53 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_last(char *rd)
{
	int	st;
	int	i;

	i = 0;
	st = ft_strlen(rd);
	while (rd[i] && rd[i] != '\n')
		i++;
	i++;
	rd = ft_substr(rd, i, st);
	return (rd);
}

static char	*ft_line(char *rd)
{
	int		i;
	char	*line;

	i = 0;
	while (rd[i] && rd[i] != '\n')
	{
		i++;
	}
	line = ft_substr(rd, 0, i + 1);
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

static char	*ft_read(char *rd, char *buffer, int fd)
{
	ssize_t	num;

	num = 1;
	buffer = malloc(sizeof(char) * (ssize_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (num > 0)
	{
		num = read(fd, buffer, BUFFER_SIZE);
		buffer[num] = '\0';
		rd = ft_strjoin(rd, buffer);
		if (ft_strchr(rd, '\n'))
			break ;
	}
	free(buffer);
	return (rd);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rd;
	char		*line;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	rd = ft_read(rd, buffer, fd);
	line = ft_line(rd);
	rd = ft_last(rd);
	return (line);
}
