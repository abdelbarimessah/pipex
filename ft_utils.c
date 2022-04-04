/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:05:34 by amessah           #+#    #+#             */
/*   Updated: 2022/04/04 01:00:20 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	int i;
	
	i = 0;
	if(!str)
		return(0);
	while(str[i])
	{
		i++;
	}
	return(i);
}

static int	free_thing(char **tab, int index)
{
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	return (0);
}

static int	count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static char	*create_word(const char *s, int start, int end)
{
	char	*word;
	int		i;
	int		word_len;

	i = 0;
	word_len = end - start;
	word = (char *)malloc((word_len * sizeof(char )) + 1);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	fill_the_splited_array(char **str, const char *s, char c)
{
	int		start;
	int		end;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			end = i;
			str[k] = create_word(s, start, end);
			if ((str[k]) == NULL)
				return (free_thing(str, k));
			k++;
		}
		else
			i++;
	}
	str[k] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		checker;

	checker = 1;
	if (!s)
		return (NULL);
	str = (char **)malloc(((count_word(s, c) + 1) * (sizeof(char *))));
	if (str == NULL)
		return (NULL);
	checker = fill_the_splited_array(str, s, c);
	if (checker == 0)
		return (NULL);
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	a;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((a + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1 && s2)
	{
		while (s1[i])
			str[k++] = s1[i++];
		i = 0;
		while (s2[i])
			str[k++] = s2[i++];
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}

void	ft_free(char **tab)
{
	int i;
	i = 0;

	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	if(tab)
		free(tab);
}