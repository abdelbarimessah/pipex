/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:04:37 by amessah           #+#    #+#             */
/*   Updated: 2022/04/10 00:19:53 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
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

static int	checker(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (const char)c)
			return (1);
		i++;
	}
	return (0);
}

static int	front_index(const char *s1, const char *set)
{
	int	i;
	int	savefront;

	i = -1;
	savefront = 0;
	while (s1[++i])
	{
		if (checker(s1[i], set))
			savefront++;
		else
			break ;
	}
	return (savefront);
}

static int	back_index(const char *s1, int i, const char *set)
{
	int	saveback;

	saveback = i;
	while (i-- > 0)
	{	
		if (checker(s1[i], set))
			saveback = i;
		else
			break ;
	}
	return (saveback);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		savefront;
	int		saveback;
	int		i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	savefront = front_index(s1, set);
	i = ft_strlen(s1);
	if (savefront == i)
		return (ft_strdup(""));
	saveback = back_index(s1, i, set);
	result = (char *)malloc(sizeof(char) * (saveback - savefront + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (savefront < saveback)
		result[i++] = s1[savefront++];
	result[i] = '\0';
	return (result);
}
