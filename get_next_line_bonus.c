/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:25:52 by iharch            #+#    #+#             */
/*   Updated: 2024/12/26 16:28:52 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *rd, int fd)
{
	ssize_t		num_rd;
	char		*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(rd), rd = NULL, NULL);
	num_rd = 1;
	while (num_rd > 0)
	{
		num_rd = read(fd, buffer, BUFFER_SIZE);
		if (num_rd > 0)
		{
			buffer[num_rd] = '\0';
			rd = ft_strjoin(rd, buffer);
			if (!rd)
				return (free(buffer), buffer = NULL, rd);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
	}
	free(buffer);
	if (num_rd == -1)
		return (free(rd), rd = NULL, NULL);
	return (rd);
}

char	*ft_line(char *rd)
{
	int		i;
	char	*line;

	i = 0;
	if (!rd || !rd[0])
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (rd[i] == '\n')
		i++;
	line = ft_substr(rd, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_rest(char *rd)
{
	char	*str;
	int		i;

	i = 0;
	if (!rd)
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (rd[i] == '\n')
		i++;
	str = ft_substr(rd, i, ft_strlen(rd) - i);
	if (str == NULL || *str == '\0')
	{
		free(str);
		str = NULL;
	}
	if (rd)
	{
		free(rd);
		rd = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rd[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd > OPEN_MAX)
		return (NULL);
	rd[fd] = ft_read(rd[fd], fd);
	if (!rd[fd])
		return (NULL);
	line = ft_line(rd[fd]);
	if (!line)
		return (free(rd[fd]), rd[fd] = NULL, NULL);
	rd[fd] = ft_rest(rd[fd]);
	return (line);
}
