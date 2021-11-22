/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:22:18 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/22 14:18:11 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static unsigned int	ft_len(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			return (count);
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}*/

static unsigned int	c_strlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * c_strlen(s, c) + sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
			i++;
		tab[j++] = ft_strsub(s, start, i - start);
	}
	tab[j] = 0;
	return (tab);
}

/*static char	*c_strdup(const char *s, int start, int finish)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc((sizeof(char) * (finish - start + 1)));
	if (!str)
		return (NULL);
	while (start < finish)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static unsigned int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word;

	i = 0;
	word = 0;
	while (*s)
	{
		if ((*s == c) && (word == 1))
			word = 0;
		if ((word == 0) && (*s != c))
		{
			word = 1;
			i++;
		}
		s++;
	}
	return (i);
}

char	**ft_strsplit(const char *s, char c)
{
	int				start;
	unsigned int	i;
	unsigned int	j;
	char			**tab;

	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[j++] = c_strdup(s, start, i);
			start = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}*/

/*char	**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	words = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (words--)
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		tab[i] = ft_strsub(s, 0, c_strlen(s, c));
		if (!tab)
			return (NULL);
		s = s + c_strlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}*/