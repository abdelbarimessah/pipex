/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:55:20 by amessah           #+#    #+#             */
/*   Updated: 2022/04/04 01:00:30 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char	*ft_strchr(const char *s, int c)
{
	char	c1;
	char	*str;
	int		i;

	c1 = (char )c;
	str = (char *)s;
	i = 0;
	if (c1 == '\0')
		return (str + ft_strlen(str));
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*get_buffer(int fd, char *str)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*rest(char *s)
{
	char	*nrest;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	len = ft_strlen(&s[i + 1]) + 1;
	nrest = (char *)malloc(sizeof(char) * len);
	if (!nrest)
		return (NULL);
	i++;
	while (s[i])
		nrest[j++] = s[i++];
	nrest[j] = '\0';
	free(s);
	return (nrest);
}

char	*get_next_line(int fd)
{	
	static char	*getbuffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	getbuffer = get_buffer(fd, getbuffer);
	if (!getbuffer)
		return (NULL);
	line = get_line(getbuffer);
	getbuffer = rest(getbuffer);
	return (line);
}
