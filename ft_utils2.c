/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:24:29 by amessah           #+#    #+#             */
/*   Updated: 2022/04/03 23:44:30 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_error(char *str)
{
	write(1, strerror(errno), 25);
	write(1, ": ", 2);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);
	exit(0);
}

char	*join(char *str1, char *str2, char *str3)
{
	int i;
	int j;
	int len;
	char *str;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3);	
	str = (char *)malloc(sizeof(char) * (len + 1));
	if(!str)
		return (NULL);
	while(str1[i])
		str[j++] = str1[i++];
	i = 0;
	while(str2[i])
		str[j++] = str2[i++];
	i = 0;
	while(str3[i])
		str[j++] = str3[i++];
	str[j] = '\0';
	return (str);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	i = 0;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	if (dst || src)
	{
		while (i < n)
		{
			dst1[i] = src1[i];
			i++;
		}
		return (dst);
	}
	return (0);
}

int	get_next_line_pipex(char **line)
{
	int i;
	int j;
	int r;
	char *buffer;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if(!buffer)
		return (0);
	r = read(0, &j, 1);
	while(r && j != '\n' && j != '\0')
	{
		if(j != '\n' && j != '\0')
			buffer[i] = j;
		i++;
		r = read(0, &j, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return(r);
}