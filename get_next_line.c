/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:04:48 by iharch            #+#    #+#             */
/*   Updated: 2024/12/25 18:15:10 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(char *rd, int fd)
{
	int num_rd;
	char *buffer;
	
	buffer = NULL;
	buffer = malloc ((ssize_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	num_rd = 1;
	while (num_rd > 0  && !ft_strchr(rd, '\n'))
	{
		num_rd = read(fd, buffer, BUFFER_SIZE);
		if (num_rd > 0)
		{
			buffer[num_rd] = '\0';
			rd = ft_strjoin(rd, buffer);
			if (!rd)
				return (free(buffer), buffer = NULL, free(rd), rd =  NULL);
		}
	}
	free (buffer);
	if (num_rd == -1)
		return(free(rd), NULL);
	return (rd);
}
char *ft_line(char *rd)
{
	int i;
	char *line;
	
	i = 0;
	if (!rd)
		return (free(rd),rd = NULL, NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (rd[i] == '\n')
		i++;
	line = ft_substr(rd, 0 , i);
	if (!line || line[0] == '\0')
		return (free(line), line = NULL, NULL);
	return (line);
}
char *ft_rest(char *rd)
{
	char *str;
	int i;
	int j;
	
	i = 0;
	if (rd[i] == '\0')
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	i++;
	j = ft_strlen(rd) - i;
	str = ft_substr(rd, i, j);
	if (!str)
		return (free(rd), NULL);
	free(rd);
	return (str);
}
char *get_next_line(int fd)
{
	static char *rd;
	char        *line;

	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	rd = ft_read(rd, fd);
	if (!rd)
		return(free(rd), NULL);
	line = ft_line(rd);
	if (!line)
		return (free(line), line = NULL, free(rd), rd = NULL, NULL);
	rd = ft_rest(rd);
	return (line);
}
