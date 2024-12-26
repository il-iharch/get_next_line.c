/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:26:17 by iharch            #+#    #+#             */
/*   Updated: 2024/12/26 16:42:44 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = malloc((i + j + 1) * sizeof(char));
	if (s3 == 0)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (free(s1), s1 = NULL, s3);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	len_str;

	i = 0;
	if (!str)
		return (NULL);
	len_str = ft_strlen(str);
	if (start > len_str)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (len_str - start < len)
		len = len_str - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < len_str && i < len && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}
//18446744073709551615