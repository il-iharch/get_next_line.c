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

    buffer = malloc((ssize_t)BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    num_rd = 1;
    while (num_rd > 0 && !ft_strchr(rd, '\n'))
    {
        num_rd = read(fd, buffer, BUFFER_SIZE);
        if (num_rd > 0)
        {
            buffer[num_rd] = '\0';
            char *temp = rd;
            rd = ft_strjoin(rd, buffer);
            free(temp);
            if (!rd)
                return (free(buffer), NULL);
        }
    }
    free(buffer);
    if (num_rd == -1)
        return (free(rd), NULL);
    return (rd);
}

char *ft_line(char *rd)
{
    int i;
    char *line;

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

char *ft_rest(char *rd)
{
    char *str;
    int i;

    i = 0;
    while (rd[i] && rd[i] != '\n')
        i++;
    if (rd[i] == '\0')
        return (free(rd), NULL);
    i++;
    str = ft_substr(rd, i, ft_strlen(rd) - i);
    if (!str)
        return (free(rd), NULL);
    free(rd);
    return (str);
}

char *get_next_line(int fd)
{
    static char *rd;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
        return (NULL);
    rd = ft_read(rd, fd);
    if (!rd)
        return (NULL);
    line = ft_line(rd);
    rd = ft_rest(rd);
    return (line);
}
