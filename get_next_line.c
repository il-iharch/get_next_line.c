/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:04:48 by iharch            #+#    #+#             */
/*   Updated: 2024/12/24 11:47:34 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(char *rd, int fd)
{
	int num_rd;
	char *buffer;
	
	buffer = NULL;
	buffer = malloc (sizeof(char) * (ssize_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	num_rd = 1;
	while (num_rd > 0 && buffer)
	{
		num_rd = read(fd, buffer, BUFFER_SIZE);
		if (num_rd < 0)
			return (free(buffer), buffer = NULL, NULL);
		buffer[num_rd] = '\0';
		rd = ft_strjoin(rd, buffer);
		if (!rd)
			return (free(buffer), buffer = NULL, free(rd), rd =  NULL);
		if (ft_strchr(rd, '\n'))
			break;
	}
	free (buffer);
	return (rd);
}
char *ft_line(char *rd)
{
	int i;
	char *line;
	
	i = 0;
	if (!rd || rd[0] == '\0')
		return (free(rd), rd = NULL, NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	i++;
	line = ft_substr(rd, 0 , i);
	 if (line[0] == '\0' || !line)
		return (free(line), line = NULL, NULL);
	return (line);
}
char *ft_rest(char *rd)
{
	char *str;
	int i;
	int j;
	
	i = 0;
	while (rd[i] && rd[i] != '\n')
		i++;
	i++;
	j = ft_strlen(rd) - i;
	str = ft_substr(rd, i, j);
	free(rd);
	return (str);
}
char *get_next_line(int fd)
{
	static char *rd;
	char        *line;
	int num_rd;
	
	if (fd < 0 || BUFFER_SIZE <= 0 )
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
void f()
{
	system("leaks");
}
int main()
{
	// atexit(f);
	int fd1 = open ("fd", O_CREAT | O_RDWR, 0777);
	write(fd1, "hello\nworld!",12);
	int fd2 = open ("fd", O_CREAT | O_RDWR, 0777);
	write(fd2, "hello\nworld!",12);
	int fd3= open ("fd", O_CREAT | O_RDWR, 0777);
	write(fd3, "hello\nworld!",12);
	
	int fd4 = open ("fd", O_CREAT | O_RDWR, 0777);
	write(fd4, "hello\nworld!",12);
	
	int fd5 = open ("fd", O_CREAT | O_RDWR, 0777);
	write(fd5, "hello\nworld!",12);
	
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd4));
	printf("%s",get_next_line(fd5));
	
	// printf("%s",s);
   
	
}
